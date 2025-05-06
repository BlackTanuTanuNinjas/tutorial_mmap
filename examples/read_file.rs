use std::fs::File;

use memmap2::Mmap;

fn main() {
    let file = File::open("test.txt").expect("file");

    let mmap = unsafe { Mmap::map(&file).expect("mmap") };

    let text = str::from_utf8(&mmap).expect("utf8");

    println!("{}", text);
}
