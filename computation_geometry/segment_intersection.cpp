/*
 * Given two segments, check if they are intersected with each other.
 *
 * This problem has strong application background and it is usually a meta component for complex algorithm.
 *
 * Insight:
 * When the two points of a segment locate on two sides of the other segment, there is an intersection.
 * Otherwise it doesn't
 *
 * Formally, suppose
 * segment 1 => (x1, y1) (x2, y2) => ax + by + c = 0
 * segment 2 => (x3, y3) (x4, y4) => kx + ny + m = 0
 *
 * intersection will happen when (a*x3 + b*y3 + c)*(a*x4 + b*y4 + c)<0 and (k*x1 + n*y1 + m)*(k*x2 + n*y2 + m)<0 
 *
 * otherwise, there is no intersection.
 * 
 */