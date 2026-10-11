# SPDX-License-Identifier: GPL-3.0-or-later
{
  description = "Survarium Restoration Project: lobby, login, match and browser servers";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    rust-overlay = {
      url = "github:oxalica/rust-overlay";
      inputs.nixpkgs.follows = "nixpkgs";
    };
  };

  outputs = { nixpkgs, rust-overlay, ... }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; overlays = [ rust-overlay.overlays.default ]; };
      # The toolchain is pinned in rust-toolchain.toml, shared with rustup users.
      rust = pkgs.rust-bin.fromRustupToolchainFile ./rust-toolchain.toml;
    in {
      devShells.${system}.default = pkgs.mkShell {
        packages = [ rust pkgs.pkg-config pkgs.openssl pkgs.zstd pkgs.nasm ];
      };
    };
}
