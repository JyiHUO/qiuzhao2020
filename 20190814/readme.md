# deepwalk
### Deepwalk的github说明
	*  [https://github.com/phanein/deepwalk](https://github.com/phanein/deepwalk) 
	* 输入格式无论是邻接表的形式还是edgelist的形式都转变成邻接表的形式
	* 有几个重要的参数
		* num_walks:每个点要进行多少次随机游走
		* walk_length:每个点要走的路径长度
		* data_size = nodes * num_walks * walk_length
	* random_walk的走法是遍历每一个点，每一个点使用random_choice的方式在Graph[node]的list里面随机选出一个邻接的点，最后放到一个大walk里面。walk的维度：（row=num_walk_per_node*num_node,  col=walk_length）
### 数据说明
	* 使用抖音数据：7w用户，350w物品
	* 数据形式：用户物品交互行为
### `transform.py`文件说明
	* 将用户交互行为的数据转化邻接表的形式
		* 算法思想，表一：groupby(item)[user]，表二groupby(user)[item]，遍历表一，在表二寻找邻接点
	* 由于图非常巨大，每个点的平均边数为1000，也就是说，num_edges_full_graph = 350w * 1000 = 350亿。
	* 我只允许每个点有10条边
### 训练情况
	* 构图5分钟，数据量：(1800w, 10)
	* word2vec部分需要用gpu训练，Mac测时会不准