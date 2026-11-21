{
  description = "";
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
  };
  outputs = {
    self,
    nixpkgs,
    ...
  } @ inputs: let
    system = "x86_64-linux";
    pkgs = import nixpkgs {
      inherit system;
      config.allowUnfree = true;
    };
  in {
    devShells.${system}.default =
      pkgs.mkShell
      {
        nativeBuildInputs = with pkgs; [
          cmake
          gcc
          gnumake
          clang-tools
          wayland-scanner
          wayland
          wayland-protocols
          libxkbcommon
          pkg-config
        ];
        buildInputs = with pkgs; [
          wayland
          wayland-protocols
          libxkbcommon
          libffi
          libGL
          # libx11
          # libxrandr
          # libxinerama
          # libxcursor
          # libxi
          # libxext
          # mesa-demos
        ];
        LD_LIBRARY_PATH = with pkgs;
          lib.makeLibraryPath [
            libGL
            wayland
            libxkbcommon
            # libx11
            # libxrandr
            # libxinerama
            # libxcursor
            # libxi
            # libxext
          ];
      };
  };
}
