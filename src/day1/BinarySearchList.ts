export default function bs_list(haystack: number[], needle: number): boolean {
    let L: number = 0;
    let R: number = haystack.length;

    do{
        const mid = Math.floor((R + L) / 2);

        if(haystack[mid] == needle){
            return true;
        }
        else if(haystack[mid] < needle){
            L = mid + 1;
        }
        else{
            R = mid;
        }
    }while(L < R)

    return false;
}
