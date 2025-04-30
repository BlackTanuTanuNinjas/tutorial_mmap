use std::fs::File;

use memmap2::Mmap;

fn main() {
    let file = File::open("test.txt").expect("ファイルが開けません");

    let mmap = unsafe { Mmap::map(&file).expect("メモリが確保できません") };

    let text = str::from_utf8(&mmap).expect("読み込めません");

    println!("{}", text);
}
