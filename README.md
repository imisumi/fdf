<h1 align="center">FDF</h1>

This repository contains the FDF (Fil De Fer) project for 42, a simple wireframe renderer using the MLX42 libary.

## About ##

FDF is a 42 project that takes a map file as input and generates a wireframe representation of it. It uses basic graphical algorithms to create a 3D effect by connecting points in space.

## Installation

```bash 
➜  ~ git clone https://github.com/imisumi/fdf.git
➜  ~ cd fdf
➜  ~ make
```

## Usage ##

```bash 
➜  ~ ./fdf ./maps/42.fdf
```

| Controls | Description |
| ------------ | ------------ |
| `x` \| `y` \| `z` + `-` \| `+` | Move X-Y-Z axis |
| `x` \| `y` \| `z` + `[` \| `]` | Rotate X-Y-Z axis |
| `SHIFT` - `↑` \| `↓` | Scale up and down, shift multiplies by 5 |
| `x` \| `y` \| `z` + `;` \| `'` | Translates the origin of the map |
| `<` \| `>` | Flatten or inflate the Y-level of the map |


## Links ##

- [MLX42 libary](https://github.com/codam-coding-college/MLX42)

&#xa0;
<a href="#top">Back to top</a>
