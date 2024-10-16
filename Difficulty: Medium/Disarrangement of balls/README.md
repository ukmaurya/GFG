<h2><a href="https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card">Disarrangement of balls</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">You are given <strong>n </strong>balls numbered from 1 to <strong>n</strong> and there are <strong>n</strong> baskets numbered from 1 to <strong>n</strong> in front of you. The <strong>i</strong><sup>th</sup> basket is meant for the <strong>i</strong><sup>th</sup> ball. Calculate the number of ways in which <strong>no</strong>&nbsp;ball&nbsp;goes into its&nbsp;respective basket.</span></p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2
<strong>Output:</strong> 1
<strong>Explanation:</strong> The balls are numbered 1 and 2. 
Then there is only one way to dearrange them. 
The (number-basket) pairs will be [(1-2),(2-1)].</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 3
<strong>Output:</strong> 2
<strong>Explanation:</strong> The (number-basket) pairs are 
[(1-3),(2-1),(3-2)] and [(1-2),(2-3),(3-1)].</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You do not need to read input or print anything. Your task is to complete the function <strong>disarrange()</strong>, which takes an integer <strong>n</strong> as input parameter and returns the number of ways to disarrange them. As the number can be very big return it modulo <strong>10<sup>9</sup> + 7</strong></span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n)<br><strong>Expected Auxiliary Space: </strong>O(1)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 10<sup>5</sup></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Combinatorial</code>&nbsp;