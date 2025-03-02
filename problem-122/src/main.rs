use std::{collections::VecDeque, vec};

fn base_math() -> [i32; 201] {
    let mut arr: [i32; 201] = [200; 201];
    arr[0] = 0;
    arr[1] = 0;

    let mut queue: VecDeque<Vec<i32>> = VecDeque::new();
    queue.push_back(vec![1]);
    let mut cnt = 1;
    while !queue.is_empty() && cnt < 200 {
        let vec = queue.pop_front().unwrap();
        let max_val = *vec.last().unwrap();
        for i in 0..vec.len() {
            for j in i..vec.len() {
                let new_val = vec[i] + vec[j];
                if new_val < max_val || new_val > 200 {
                    continue;
                }
                if arr[new_val as usize] == 200 {
                    arr[new_val as usize] = vec.len() as i32;
                    //println!("{}, {}, {}", new_val, arr[new_val as usize], cnt);
                    cnt += 1;
                } else if vec.len() > arr[new_val as usize] as usize {
                    //Don't need to be considering paths that are not the most optimal
                    //Must still consider paths that are equal length, since the various permutations are important
                    continue;
                }
                let mut new_vec = vec.clone();
                new_vec.push(new_val);
                queue.push_back(new_vec);
            }
        }
    }
    return arr;
}

//https://projecteuler.net/problem=122
fn main() {
    let arr = base_math();
    let mut s = 0;
    for i in 2..201 {
        s += arr[i];
        //For Debugging:
        //println!("{}: {}", i, arr[i]);
    }
    println!("{}", s);
}
