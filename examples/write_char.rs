use memmap2::MmapMut;

fn main() {
    let mut mmap = MmapMut::map_anon(4096).expect("mmap failed");

    mmap[0] = b'A';
    println!("{}", mmap[0] as char);
}