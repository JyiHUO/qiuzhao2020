import pandas as pd
import numpy as np
from collections import defaultdict
import time
import pickle

uid_itemid = pd.read_csv("data/uid_item_id.csv")
'''
data format
uid itemid
0   2
0   3
1   4
1   2
...
'''
arr = uid_itemid.to_numpy()  # uid, itemid

uid_item_dict = defaultdict(list)
item_uid_dict = defaultdict(list)

N = arr.shape[0]
for i in range(N):
    print(i)
    uid_item_dict[arr[i][0]].append(arr[i][1])
    item_uid_dict[arr[i][1]].append(arr[i][0])

graph_adj = defaultdict(list)

s = time.time()
print("num of node: ", len(item_uid_dict.keys()))
for i, node in enumerate(item_uid_dict.keys()):
    print(i)
    count = 0
    for user in item_uid_dict[node]:
        for t_node in uid_item_dict[user]:
            if t_node == node:
                continue
            graph_adj[node].append(t_node)
            count += 1
            if count == 10:
                break
        if count == 10:
            break

e = time.time()
print(e - s)

# save the graph
with open("data/graph_adj.pickle", "wb") as f:
    pickle.dump(graph_adj, f)

with open("data/graph_adj.pickle", "rb") as f:
    graph = pickle.load(f)

with open("data/graph_adj.txt", "w+") as f:
    for i, k in enumerate(graph.keys()):
        line = str(k)
        print(i)
        for j in graph[k]:
            line += " "+str(j)
        f.write(line)
