# USACO_Journey (Silver)
My journey in USACO (readme will be updated...)

###Advanced Tricks:

####* typedef <classname/object/ds> newName;
####  -> typedef pair<int, int> ppi;
####  -> typedef long long ll;
  
* freopen("problemname.in", "r", stdin); freopen("problemname.out", "w", stdout);

* struct Name {instancenames... int x1; int y1;}

  -> Name operation+(Name n1, Name n2) {//dostuff} //this overloads the plus sign for this instance! Amazing! 
  
  -> struct Points {int p1; int p2; int p3} 
  
  -> /*sort by p2s*/ Points A[3] = { {1, 2, 2}, {2, 3, 8}, {4, 1, 7} }; sort(A, A+3, []Points A, Points B { return A.p2>B.p2; } );
  
  -> 
