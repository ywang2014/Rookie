#数据挖掘领域十大经典算法

#### C4.5
C4.5，是机器学习算法中的一个分类决策树算法，
它是决策树(决策树也就是做决策的节点间的组织方式像一棵树，其实是一个倒树)核心算法
ID3的改进算法，所以基本上了解了一半决策树构造方法就能构造它。
决策树构造方法其实就是每次选择一个好的特征以及分裂点作为当前节点的分类条件。

C4.5相比于ID3改进的地方有：
1、用信息增益率来选择属性。
ID3选择属性用的是子树的信息增益，这里可以用很多方法来定义信息，ID3使用的是熵(entropy，熵是一种不纯度度量准则),

也就是熵的变化值.

而C4.5用的是信息增益率。对，区别就在于一个是信息增益，一个是信息增益率。
一般来说率就是用来取平衡用的，就像方差起的作用差不多，
比如有两个跑步的人，一个起点是10m/s的人、其10s后为20m/s；
另一个人起速是1m/s、其1s后为2m/s。
如果紧紧算差值那么两个差距就很大了，如果使用速度增加率(加速度，即都是为1m/s^2)来衡量，2个人就是一样的加速度。

因此，C4.5克服了ID3用信息增益选择属性时偏向选择取值多的属性的不足。

2、在树构造过程中进行剪枝，在构造决策树的时候，那些挂着几个元素的节点，不考虑最好，不然容易导致overfitting。
3、对非离散数据也能处理。
4、能够对不完整数据进行处理。


#### The k-means algorithm 即K-Means算法
k-means algorithm算法是一个聚类算法，把n的对象根据他们的属性分为k个分割(k < n)。
它与处理混合正态分布的最大期望算法(本十大算法第五条)很相似，因为他们都试图找到数据中自然聚类的中心。
它假设对象属性来自于空间向量，并且目标是使各个群组内部的均方误差总和最小。


#### Support vector machines
支持向量机，英文为Support Vector Machine，简称SV机（论文中一般简称SVM）。

它是一种监督式学习的方法，它广泛的应用于统计分类以及回归分析中。
支持向量机将向量映射到一个更高维的空间里，在这个空间里建立有一个最大间隔超平面。
在分开数据的超平面的两边建有两个互相平行的超平面，分隔超平面使两个平行超平面的距离最大化。
假定平行超平面间的距离或差距越大，分类器的总误差越小。

一个极好的指南是C.J.C Burges的《模式识别支持向量机指南》。
van der Walt 和 Barnard 将支持向量机和其他分类器进行了比较。


#### The Apriori algorithm
Apriori算法是一种最有影响的挖掘布尔关联规则频繁项集的算法。
其核心是基于两阶段频集思想的递推算法。

该关联规则在分类上属于单维、单层、布尔关联规则。
在这里，所有支持度大于最小支持度的项集称为频繁项集，简称频集。


#### 最大期望(EM)算法
在统计计算中，最大期望 （EM，Expectation–Maximization）算法是在概率
（probabilistic）模型中寻找参数最大似然估计的算法，其中概率模型依赖于无法观测的隐藏变量（Latent Variabl）。

最大期望经常用在机器学习和计算机视觉的数据集聚（Data Clustering）领域。


#### PageRank
PageRank是Google算法的重要内容。2001年9月被授予美国专利，专利人是Google创始人之一拉里•佩奇（Larry Page）。
因此，PageRank里的page不是指网页，而是指佩奇，即这个等级方法是以佩奇来命名的。

PageRank根据网站的外部链接和内部链接的数量和质量，衡量网站的价值。
PageRank背后的概念是，每个到页面的链接都是对该页面的一次投票， 被链接的越多，就意味着被其他网站投票越多。

这个就是所谓的“链接流行度”——衡量多少人愿意将他们的网站和你的网站挂钩。
PageRank这个概念引自学术中一篇论文的被引述的频度——即被别人引述的次数越多，一般判断这篇论文的权威性就越高。


#### AdaBoost
Adaboost是一种迭代算法，其核心思想是针对同一个训练集训练不同的分类器(弱分类器)，
然后把这些弱分类器集合起来，构成一个更强的最终分类器 (强分类器)。

其算法本身是通过改变数据分布来实现的，它根据每次训练集之中每个样本的分类是否正确，

以及上次的总体分类的准确率，来确定每个样本的权值。

将修改过权值的新数据集送给下层分类器进行训练，最后将每次训练得到的分类器融合起来，作为最后的决策分类器。


#### kNN: k-nearest neighbor classification
K最近邻(k-Nearest Neighbor，KNN)分类算法，是一个理论上比较成熟的方法，也是最简单的机器学习算法之一。

该方法的思路是：如果一个样本在特征空间中的k个最相似(即特征空间中最邻近)的样本中的

大多数属于某一个类别，则该样本也属于这个类别。


#### Naive Bayes
在众多的分类模型中，应用最为广泛的两种分类模型是决策树模型(Decision Tree Model)和
朴素贝叶斯模型（Naive Bayesian Model，NBC）。 
朴素贝叶斯模型发源于古典数学理论，有着坚实的数学基础，以及稳定的分类效率。

同时，NBC模型所需估计的参数很少，对缺失数据不太敏感，算法也比较简单。
理论上，NBC模型与其他分类方法相比具有最小的误差率。

但是实际上并非总是如此，这是因为NBC模型假设属性之间相互独立，这个假设在实际应用中
往往是不成立的，这给NBC模型的正确分类带来了一定影响。在属性个数比较多或者属性之
间相关性较大时，NBC模型的分类效率比不上决策树模型。

而在属性相关性较小时，NBC模型的性能最为良好。


#### CART: 分类与回归树
CART, Classification and Regression Trees。 在分类树下面有两个关键的思想：第一个
是关于递归地划分自变量空间的想法；第二个想法是用验证数据进行剪枝。
ok，日后择其一二详细研究、阐述，完。

[资源出处](http://blog.csdn.net/v_july_v/article/details/6142146)

==============

#### 1. C4.5

Quinlan, J. R. 1993. C4.5: Programs for Machine Learning.
Morgan Kaufmann Publishers Inc.
	
Google Scholar Count in October 2006: 6907

#### 2. CART

L. Breiman, J. Friedman, R. Olshen, and C. Stone. Classification and
Regression Trees. Wadsworth, Belmont, CA, 1984.

Google Scholar Count in October 2006: 6078

#### 3. K Nearest Neighbours (kNN)

Hastie, T. and Tibshirani, R. 1996. Discriminant Adaptive Nearest
Neighbor Classification. IEEE Trans. Pattern
Anal. Mach. Intell. (TPAMI). 18, 6 (Jun. 1996), 607-616. 
DOI= http://dx.doi.org/10.1109/34.506411

Google SCholar Count: 183

#### 4. Naive Bayes

Hand, D.J., Yu, K., 2001. Idiot's Bayes: Not So Stupid After All?
Internat. Statist. Rev. 69, 385-398.

Google Scholar Count in October 2006: 51


Statistical Learning
====================

#### 5. SVM

Vapnik, V. N. 1995. The Nature of Statistical Learning
Theory. Springer-Verlag New York, Inc.
		
Google Scholar Count in October 2006: 6441

#### 6. EM

McLachlan, G. and Peel, D. (2000). Finite Mixture Models. 
J. Wiley, New York.

Google Scholar Count in October 2006: 848


Association Analysis
====================

#### 7. Apriori

Rakesh Agrawal and Ramakrishnan Srikant. Fast Algorithms for Mining
Association Rules. In Proc. of the 20th Int'l Conference on Very Large
Databases (VLDB '94), Santiago, Chile, September 1994. 
http://citeseer.comp.nus.edu.sg/agrawal94fast.html

Google Scholar Count in October 2006: 3639

#### 8. FP-Tree

Han, J., Pei, J., and Yin, Y. 2000. Mining frequent patterns without
candidate generation. In Proceedings of the 2000 ACM SIGMOD
international Conference on Management of Data (Dallas, Texas, United
States, May 15 - 18, 2000). SIGMOD '00. ACM Press, New York, NY, 1-12.
DOI= http://doi.acm.org/10.1145/342009.335372

Google Scholar Count in October 2006: 1258


Link Mining
===========

#### 9. PageRank

Brin, S. and Page, L. 1998. The anatomy of a large-scale hypertextual
Web search engine. In Proceedings of the Seventh international
Conference on World Wide Web (WWW-7) (Brisbane,
Australia). P. H. Enslow and A. Ellis, Eds. Elsevier Science
Publishers B. V., Amsterdam, The Netherlands, 107-117. 
DOI= http://dx.doi.org/10.1016/S0169-7552(98)00110-X

Google Shcolar Count: 2558

#### 10. HITS

Kleinberg, J. M. 1998. Authoritative sources in a hyperlinked
environment. In Proceedings of the Ninth Annual ACM-SIAM Symposium on
Discrete Algorithms (San Francisco, California, United States, January
25 - 27, 1998). Symposium on Discrete Algorithms. Society for
Industrial and Applied Mathematics, Philadelphia, PA, 668-677.

Google Shcolar Count: 2240


Clustering
==========

 #### 11. K-Means

MacQueen, J. B., Some methods for classification and analysis of
multivariate observations, in Proc. 5th Berkeley Symp. Mathematical
Statistics and Probability, 1967, pp. 281-297.

Google Scholar Count in October 2006: 1579

 #### 12. BIRCH

Zhang, T., Ramakrishnan, R., and Livny, M. 1996. BIRCH: an efficient
data clustering method for very large databases. In Proceedings of the
1996 ACM SIGMOD international Conference on Management of Data
(Montreal, Quebec, Canada, June 04 - 06, 1996). J. Widom, Ed. 
SIGMOD '96. ACM Press, New York, NY, 103-114. 
DOI= http://doi.acm.org/10.1145/233269.233324

Google Scholar Count in October 2006: 853


Bagging and Boosting
====================

#### 13. AdaBoost

Freund, Y. and Schapire, R. E. 1997. A decision-theoretic
generalization of on-line learning and an application to
boosting. J. Comput. Syst. Sci. 55, 1 (Aug. 1997), 119-139. 
DOI= http://dx.doi.org/10.1006/jcss.1997.1504

Google Scholar Count in October 2006: 1576


Sequential Patterns
===================

#### 14. GSP

Srikant, R. and Agrawal, R. 1996. Mining Sequential Patterns:
Generalizations and Performance Improvements. In Proceedings of the
5th international Conference on Extending Database Technology:
Advances in Database Technology (March 25 - 29, 1996). P. M. Apers,
M. Bouzeghoub, and G. Gardarin, Eds. Lecture Notes In Computer
Science, vol. 1057. Springer-Verlag, London, 3-17.

Google Scholar Count in October 2006: 596

 #### 15. PrefixSpan

J. Pei, J. Han, B. Mortazavi-Asl, H. Pinto, Q. Chen, U. Dayal and
M-C. Hsu. PrefixSpan: Mining Sequential Patterns Efficiently by
Prefix-Projected Pattern Growth. In Proceedings of the 17th
international Conference on Data Engineering (April 02 - 06,
2001). ICDE '01. IEEE Computer Society, Washington, DC.
		 
Google Scholar Count in October 2006: 248


Integrated Mining
=================

#### 16. CBA

Liu, B., Hsu, W. and Ma, Y. M. Integrating classification and
association rule mining. KDD-98, 1998, pp. 80-86. 
http://citeseer.comp.nus.edu.sg/liu98integrating.html

Google Scholar Count in October 2006: 436
		 

Rough Sets
==========

 #### 17. Finding reduct

Zdzislaw Pawlak, Rough Sets: Theoretical Aspects of Reasoning about
Data, Kluwer Academic Publishers, Norwell, MA, 1992

Google Scholar Count in October 2006: 329


Graph Mining
============

 #### 18. gSpan

Yan, X. and Han, J. 2002. gSpan: Graph-Based Substructure Pattern
Mining. In Proceedings of the 2002 IEEE International Conference on
Data Mining (ICDM '02) (December 09 - 12, 2002). IEEE Computer
Society, Washington, DC.

[资源出处](http://www.cs.uvm.edu/~icdm/algorithms/CandidateList.shtml)