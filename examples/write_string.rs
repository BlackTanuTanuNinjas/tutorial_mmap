use memmap2::MmapMut;
use std::str;

fn main() {
    let mut mmap = MmapMut::map_anon(4096).expect("mmap失敗");

    let message = b"Hello, World!";

    mmap[..message.len()].copy_from_slice(message);

    let text = str::from_utf8(&mmap[..message.len()]).expect("UTF-8変換失敗");

    println!("{}", text);
}
