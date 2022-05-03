/*********************************************
 * Id: carr5440
 *
 * Compile: gcc -Wall
 * Run: ./a.out input.txt
 *
 * Quick Hull
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

struct Point {
    int x;
    int y;
};
int orientation(struct Point p, struct Point q, struct Point r);
void convexHull(struct Point points[], int n);
// main function
int main(int argc, char *argv[])
{
    int numPoints = (argc-1) / 2;
    struct Point* points = malloc(sizeof(struct Point) * numPoints);

    int j = 0;
    for (int i=1; i < argc-1; i += 2)
    {
        points[j].x = atoi(argv[i]);
        points[j].y = atoi(argv[i+1]);
        
        j++;
    }
    convexHull(points, j);

    for (int i=0; i < j; i++)
    {
        printf("(%d, %d) ", points[i].x, points[i].y);
    }


   return EXIT_SUCCESS;
}

 

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are collinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(struct Point p, struct Point q, struct Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}
 
// Prints convex hull of a set of n points.
void convexHull(struct Point points[], int n)
{
    // There must be at least 3 points
    if (n < 3) return;
 
    // Initialize Result
    struct Point* hullPoints = malloc(sizeof(struct Point)*n);
    struct Point* topPoints = malloc(sizeof(struct Point)*n);
    struct Point* topPoints = malloc(sizeof(struct Point)*n);
    
    int topIndx = 0;
    int bottomIndx = 0;
    int pointsIndx = 0;
 
    // Find the leftmost point
    int l = 0;
    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[l].x)
            l = i;
    }

 
    // Start from leftmost point, keep moving counterclockwise
    // until reach the start point again.  This loop runs O(h)
    // times where h is number of points in result or output.
    int p = l, q;
    do
    {
        // Add current point to result
        hullPoints[pointsIndx] = points[p];
 
        // Search for a point 'q' such that orientation(p, q,
        // x) is counterclockwise for all points 'x'. The idea
        // is to keep track of last visited most counterclock-
        // wise point in q. If any point 'i' is more counterclock-
        // wise than q, then update q.
        q = (p+1) % n;
        for (int i = 0; i < n; i++)
        {
           // If i is more counterclockwise than current q, then
           // update q
           if (orientation(points[p], points[i], points[q]) == 2)
               q = i;
        }
 
        // Now q is the most counterclockwise with respect to p
        // Set p as q for next iteration, so that q is added to
        // result 'hull'
        p = q;
 
    } while (p != l);  // While we don't come to first point
}