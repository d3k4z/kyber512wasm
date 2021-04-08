CC=/usr/bin/gcc
EMCC=/home/joe/emsdk/upstream/emscripten/emcc
LDFLAGS=--static -lcrypto

EMCOMPILE=-lcrypto -ldl -pthread -static -r
SOURCES= cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c reduce.c rng.c verify.c symmetric-fips202.c
HEADERS= api.h cbd.h fips202.h indcpa.h ntt.h params.h poly.h polyvec.h reduce.h rng.h verify.h symmetric.h
EMSCRIPTENDIR=${EMSDK}/upstream/emscripten

#emcc -o test.o test.c cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c reduce.c rng.c verify.c symmetric-fips202.c

wasm:
	$(EMCC) -o build/test.o test.c cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c reduce.c rng.c verify.c symmetric-fips202.c $(EMCOMPILE) --prefix=$(EMSCRIPTENDIR)/system
	$(EMCC) -o build/test.js build/test.o -s PROXY_TO_PTHREAD=1 -s USE_PTHREADS=1

# wasm:
# 	$(EMCC) -o test.o test.c cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c reduce.c rng.c verify.c symmetric-fips202.c $(EMCOMPILE)
# 	$(EMCC) -o test.js test.o -s PROXY_TO_PTHREAD=1 -s USE_PTHREADS

kyberdemo:
	$(EMCC) -o build/demo.o PQCgenKAT_kem.c cbd.c fips202.c indcpa.c kem.c ntt.c poly.c polyvec.c reduce.c rng.c verify.c symmetric-fips202.c $(EMCOMPILE)
	$(EMCC) -o build/demo.js build/demo.o -s PROXY_TO_PTHREAD=1 -s USE_PTHREADS

.PHONY: clean

clean:
	-rm test.o test.js test.wasm test.worker.js


