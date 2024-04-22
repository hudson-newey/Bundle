# BuildingBundle

Supported compilers: gcc (g++) on Linux

I have plans to support other platforms (Windows and MacOs), and compilers (CLang and CL).
However, I still need to fully flush out all the requirements on Linux gcc first.

---

1. Clone the repository

```sh
$ git clone https://github.com/hudson-newey/Bundle.git --recursive
>
```

We use `--recursive` here because I have added the third party library dependencies as submodules

See [.gitmodules](.gitmodules)

2. cd into the directory

```sh
$ cd ./bundle/
>
```

3. Make a `./build/` directory and cd into it

```sh
$ mkdir ./build/ && cd ./build/
>
```

4. Run cmake

```sh
$ cmake ..
>
```

5. Build bundle

```sh
$ make
>
```

6. Link alias the bundle binary

```sh
$ echo "alias b=$(pwd)/bundle" >> ~/.zshrc
>
```

If you are using Bash, change `~/.zshrc` to `~/.bashrc` in the command above
