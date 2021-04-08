# PQ Kyber port to Web Assembly

So you like NIST's PQ crypto finalists a?

## Requirements

- emsdk (emscripten.org)
- OpenSSL port to WebAssembly [wasmOpenSSL](https://github.com/d3k4z/wasmOpenSSL) or use the statically compiled ones in `./libs` 

## Usage

... still in progress ...

Use the makefile while editing paths to EMC compiler (EMCC=?)

Statically compiled `libcrypto` and `libssl` can be found in [./libs](./libs/) and needs to be copied to `{path_to_emsdk}/upstream/emscripten/system/lib`

## Demo

```
node --experimental-wasm-threads build/test.js
nnode --experimental-wasm-threads build/demo.js
```

## Compilation Security 

[-s DYNAMIC_EXECUTION=0](https://emscripten.org/docs/api_reference/emscripten.h.html#c.emscripten_run_script)
