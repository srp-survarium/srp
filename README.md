# SRP - Survarium Restoration Project

### Prerequisites

1. `rustc`
    * Install nightly version from `rustup`: `rustup default nightly`

2. `openssl`
    * Install newest version from here: https://openssl-library.org/source/
    * Set environment variables so that `rust` could find it:
    ```
    # For example in `$PROFILE` for PS.
    # Requires: `Set-ExecutionPolicy RemoteSigned -Scope CurrentUser` to be executed with administrator privileges

    $env:OPENSSL_DIR     = "C:\Program Files\OpenSSL-Win64";
    $env:OPENSSL_STATIC  = "true";
    $env:OPENSSL_LIB_DIR = 'C:\Program Files\OpenSSL-Win64\lib\VC\x64\MD';
    ```

3. Highly recommended to set global environment variables:
    * `GHIDRA_HOME` - Path to installed Ghidra
    * `IDA_HOME` - Path to installed IDA
    * `SURVARIUM_BIN` - Path to installed survarium.exe
    * Otherwise default paths will be used (matching my machine).
