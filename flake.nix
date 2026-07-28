{
  description = "SRP — Survarium Restoration Project: server-side reimplementation (Rust)";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

    rust-overlay = {
      url = "github:oxalica/rust-overlay";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { self, nixpkgs, rust-overlay }:
    let
      system = "x86_64-linux";

      pkgs = import nixpkgs {
        inherit system;
        overlays = [ rust-overlay.overlays.default ];
      };

      # Nightly toolchain — the workspace uses `edition = "2024"` and several
      # nightly `#![feature(...)]` gates (generic_atomic, iter_intersperse,
      # slice_split_once), so stable will not build it.
      rust = pkgs.rust-bin.nightly.latest.default.override {
        extensions = [ "rust-src" "rustfmt" "clippy" "rust-analyzer" ];
      };
    in
    {
      devShells.${system}.default = pkgs.mkShell {
        name = "srp";

        nativeBuildInputs = [
          pkgs.pkg-config
        ];

        buildInputs = [
          rust
          pkgs.openssl
          # Used by scripts/dev-bootstrap.sh to run the servers in tmux windows.
          pkgs.tmux
        ];

        # The `openssl` crate defaults to vendoring (compiling OpenSSL from
        # source). Use the system (Nix) OpenSSL via pkg-config instead so the
        # dev shell stays hermetic and fast.
        env = {
          OPENSSL_NO_VENDOR = "1";
          PKG_CONFIG_PATH = "${pkgs.openssl.dev}/lib/pkgconfig";
        };
      };
    };
}
