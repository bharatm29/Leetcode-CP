export default function two_crystal_balls(breaks: boolean[]): number {
    //Time complexity = O(sqrt(N));
    const len = breaks.length;
    const jumpAmt: number = Math.floor(Math.sqrt(len));

    let i = jumpAmt;

    for(; i < len; i += jumpAmt){
        if(breaks[i]){
            break;
        }
    }

    i -= jumpAmt;

    for(let j = i; j < len; j++){
        if(breaks[j]){
            return j;
        }
    }

    return  -1;
}
