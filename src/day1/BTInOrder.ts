function walk(curr: BinaryNode<number> | null, path: number[]): void{
    if(!curr){
        return;
    }

    //pre

    //recurse
    walk(curr.left, path);

    path.push(curr.value);

    walk(curr.right, path);

    //post
}
export default function in_order_search(head: BinaryNode<number>): number[] {
    const path: number[] = [];

    walk(head, path);

    return path;
}
