# Visualizing Convex Hull Algorithms 

This app primarily provides a means to visualize three important convex hull algorithms, specifically the **Jarvis March**, the **Graham Scan**, and the **Kirk-Patrick-Seidel** approaches. It's primary aim is to illustrate how these algorithms arrive at the required input's convex hull, and also investigates which one is superior depending on varying user inputs.

## General Specs
* the entire source code is written in **C++** with the GUI implemented 
  in **Qt** 
* all the source code files can be found in the 
  **2016A7PS0049H_csf364_a1/DAA-Hulls-final** directory
* the GUI will work only if the host system has **Qt framework _and_ Qt Creator** 
  installed on it 
* once installed, please delete the **DAA-Hulls.pro.user** file from the 
  **DAA-Hulls-final** directory and open the same directory as a project in Qt Creator; to initiate the GUI, simply hit the **Run** button on the side panel once all 
  the files in the directory have been opened in Qt Creator
* the entire documentation for all the source code files can be viewed as HTML
  pages: Go to **2016A7PS0049H_csf364_a1/docs_daa1/html and click on annotated.html** to view the same

# Report
Comparing results from the Jarvis March, Graham Scan, and Kirk Patrick Seidel algorithms.

## Testing Criteria
Keeping in mind that the running times of all three algorithms depend on the number of input points _(Jarvis March: O(nh), Graham Scan: O(nlogn), Kirk Patrick Seidel: O(nlogh)),_ five test cases with 10000, 15000, 25000, 40000, and 55000 input points were designed.

## Execution Time Observations
n | h | nh | nlogh | nlogn | Graham | Jarvis | KPS 
--- | --- | --- | --- | --- | --- | --- | --- 
10000 | 30 | 300000 | 49068.90596 | 132877.1238 | 0.009 | 0.003 | 0.045
15000 | 2708 | 67700000 | 171045.1804|208090.1232|0.012|1.241|0.499
25000|3052|76300000|289388.4812|365241.0119|0.023|1.562|0.780
40000|3416|136640000|469523.6904|611508.4952|0.035|3.004|1.155
55000|3676|202180000|651415.6578|866092.9199|0.048|4.036|1.595


## Jarvis March

In the Jarvis March method, every point on the hull entails an examination of all other points in the input to set to determine the next point. Due to this, the time complexity of this algorithm is _O(nh)_, where n is the number of input points and h the number of points on the convex hull of the polygon. In a worst-case scenario, where n = h, the time complexity worsens to _O(n2)_, i.e. when all the input points make up the hull. 

## Graham Scan

If the input set constitutes _n_ points, then the complexity of the algorithm is primarily dependent on the sorting algorithm used. So ideally, for a sorting algorithm that has a complexity of _O(nlogn)_, the complexity of the Graham Scan algorithm also becomes _O(nlogn)_ (the other two steps that precede and supersede the sorting step are both of _O(n)_ complexity).


## Kirk-Patrick-Seidel

The Kirk Patrick Seidel algorithm, like the Jarvis March, is both input and output dependent. Hence the complexity _O(nlogh)_, where _n_ is the number of input points and _h_ the number of points on the convex hull of the two-dimensional polygon. Upper-Hull and Lower-Hull procedures take _O(nlogh)_ time while both bridges take _O(n)_ worst case time to compute.

## Takeaways and Inferences

When only looking at complexities, the ideal algorithm to go to would be the Kirk Patrick Seidel algorithm, or the “Ultimate Convex Hull”, as its authors like to call it. However, like how the running times data table suggests, it may not be the case always. In fact, for any moderately sized set of input points (by moderate, we mean even of the likes 50000 and 100000), the Ultimate Convex Hull algorithm should not be employed.

The Kirk Patrick algorithm becomes the ideal choice theoretically only when the number of input points exceed the likes of millions, when the algorithm’s _constant_ (when determining the complexity of an algorithm, we usually ignore the constant; however, this becomes significant when comparing _logn_ and _logh_ in the complexities of the two algorithms) and the _logh_ values can actually do better than Graham Scan’s _constant_ and _logn_. For all other practical purposes, Graham’s Scan is far superior than Kirk Patrick.

Jarvis March can potentially be a good choice when the number of hull points are far less than the number of input points, especially when the difference is in the order of 1010 points. At such scenarios, Graham Scan would theoretically perform far poorer than Jarvis March, and obviously even Kirk Patrick. The superiority of Kirk Patrick over Jarvis March in such a scenario is completely subjective to the value of _h_, depending on which it can be almost similar (small _h_ values) vs far superior (very large _h_ values, large enough for there to be a significant difference between _h_ and _logh_).

---
_The problem statements addressed here in this repo were originally intended as a submission to a course project in the Design and Analysis of Algorithms course at BITS Pilani, Hyderabad Campus._

_This particular project was completed in collaboration with [Monith Sourya](https://github.com/monith-sourya)_. 
