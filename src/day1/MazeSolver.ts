const dirs = [
    [-1, 0],[0, -1], [1, 0], [0, 1]
]

function walk(maze: string[], wall: string, seen: boolean[][], curr: Point, end: Point, path: Point[]): boolean {
    if(curr.x < 0 || curr.x >= maze[0].length ||
        curr.y < 0 || curr.y >= maze.length){
        return false;
    }

    if(maze[curr.y][curr.x] === wall){
        return false;
    }

    if(seen[curr.y][curr.x]){
        return false;
    }

    if(curr.y === end.y && curr.x === end.x){
        path.push(end);
        return true;
    }

    seen[curr.y][curr.x] = true;
    path.push(curr);

    for(let d = 0; d < dirs.length; d++){
        const [x, y] = dirs[d];

        if(walk(maze, wall, seen, {x: curr.x + x, y: curr.y + y}, end, path)){
            return true;
        }
    }

    path.pop();

    return false;
}

export default function solve(maze: string[], wall: string, start: Point, end: Point): Point[] {
    const seen: boolean[][] = [];
    const path: Point[] = [];

    for(let i = 0; i < maze.length; i++){
        seen.push(new Array(maze[0].length).fill(false));
    }

    walk(maze, wall, seen, start, end, path);

    return path;
}
