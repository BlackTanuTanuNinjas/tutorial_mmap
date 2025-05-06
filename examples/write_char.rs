use memmap2::MmapMut;

fn main() {
    let mut mmap = MmapMut::map_anon(usize::MAX).expect("mmap");

    mmap[0] = b'A';
    println!("{}", mmap[0] as char);
}
