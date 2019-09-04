import numpy as np
from sklearn import metrics
np.random.seed(10)

x1 = np.random.randint(low=0, high=2, size=100)
x2 = np.random.rand(100)

data = np.concatenate([x1[:, None],x2[:,None]], axis=1)


def cal_auc(data):
    pos_d = np.sort(data[data[:, 0] == 1], axis=0)
    neg_d = np.sort(data[data[:, 0] == 0], axis=0)

    up = 0
    for n in pos_d[:,1]:
        # print("n: ",n)
        left = bs_l(neg_d[:,1], n)
        right = bs_r(neg_d[:,1], n)
        # print('left: ',left)
        # print('right: ',right)
        if right == -1:
            continue
        if left == neg_d.shape[0]:
            print(up)
            up += neg_d.shape[0]
            continue

        if neg_d[:, 1][left] != n and neg_d[:, 1][right] != n:
            up += right + 1
        else:
            # print(up)
            up += left + 0.5*(right-left+1)
    return up / (pos_d.shape[0]*neg_d.shape[0])


def bs_l(arr, n):
    left = -1
    right = arr.shape[0]
    while right-left>1:
        mid = int( (left+right)/2 )
        if arr[mid]==n:
            right=mid
        elif arr[mid]>n:
            right=mid
        else:
            left=mid
    return right


def bs_r(arr, n):
    left=-1
    right=arr.shape[0]
    while right-left>1:
        mid = int( (left+right)/2 )
        if arr[mid] == n:
            left=mid
        elif arr[mid] > n:
            right=mid
        else:
            left=mid
    return left

fpr, tpr, thresholds = metrics.roc_curve(x1, x2, pos_label=1)
print(metrics.auc(fpr, tpr))
print(cal_auc(data))