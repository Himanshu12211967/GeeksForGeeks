<h2><a href="https://www.geeksforgeeks.org/problems/negative-weight-cycle3504/1?sortBy=submissions&category%5B%5D=Graph&page=1&difficulty%5B%5D=1">Negative weight cycle</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a weighted directed graph with n nodes and m edges. Nodes are labeled from 0 to n-1, the task is to check if it contains a negative weight cycle or not.<br><strong>Note:&nbsp;</strong>edges[i] is&nbsp;defined as u, v and weight.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,-3}}
<strong>Output: </strong>1
<strong>Explanation: </strong>The graph contains negative weight
cycle as 0-&gt;1-&gt;2-&gt;0 with weight -1,-2,-3.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input: </strong>n = 3, edges = {{0,1,-1},{1,2,-2},
{2,0,3}}
<strong>Output: </strong>0
<strong>Explanation: </strong>The graph does not contain any
negative weight cycle.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read or print anyhting. Your task is to complete the function&nbsp;<strong>isNegativeWeightCycle()&nbsp;</strong>which takes n and edges as input paramater and returns 1 if graph contains negative weight cycle otherwise returns 0.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n*m)<br><strong>Expected Space Compelxity:&nbsp;</strong>O(n)</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= n &lt;= 100<br>0 &lt;= m &lt;= n*(n-1)</span><span style="font-size: 18px;">, where m is the total number of Edges in the directed graph.</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Cisco</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;