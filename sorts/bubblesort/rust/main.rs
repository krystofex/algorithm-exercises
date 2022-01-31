
fn main() {
    let mut array:[f32;9] = [1000.0, 2.0, 3.4, 7.0, 50.0, 3.14, 71.0, 28.0, 12.0];  // values to sort

    for i in 0..array.len() - 1 {
        for j in 0..array.len() - 1 - i {
            if array[j] > array[j + 1] {    // if two elements are not sort, swap them
                let tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }   
    }

    println!("{:?}", array) // print sorted array
}