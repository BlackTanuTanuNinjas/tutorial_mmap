# Qiita

下記の記事を参照してください

https://qiita.com/B_tanuki/items/f3f38fe0afabd048beaf

# C

`Makefile` を用意しているので、`make` を実行するだけで各ソースファイルをまとめてコンパイルできます。

```zsh
cd c_src
make
```

また、Linux 上で実行する場合は、次のコメントアウトを外してください

```c
#define _GNU_SOURCE
```

# Rust

Rust 側のコードは `examples/` ディレクトリに配置しているため、以下の形式で実行してください

```zsh
cargo run --example <ファイル名>
```

たとえば、`write_char.rs` を実行する場合は次のとおりです

```zsh
cargo run --example write_char
```
