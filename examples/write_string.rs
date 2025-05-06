use memmap2::MmapMut;
use std::str;

fn main() {
    let mut mmap = MmapMut::map_anon(4096).expect("mmap");

    let message = b"Hello, World!";

    mmap[..message.len()].copy_from_slice(message);

    let text = str::from_utf8(&mmap[..message.len()]).expect("utf8");

    println!("{}", text);
}
