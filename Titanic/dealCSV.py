import csv
from numpy import *
import operator


csv_reader = csv.reader(open('train.csv', encoding='utf-8'))
dataSet = []
labels  = []
for row in csv_reader:
    labels.append(row[1])
    row = [row[2],row[4],row[5],row[9]]
    dataSet.append(row)
dataSet = dataSet[1:]
labels  = labels[1:]



for i in range (len(dataSet)):
    if(dataSet[i][1] == 'male'):
        dataSet[i][1] = 1
    elif(dataSet[i][1] == 'female'):
        dataSet[i][1] = 0
    else:dataSet[i][1] = 0.5
    if dataSet[i][2]=='':
        dataSet[i][2] = '0'
for i in range (len(dataSet)):
    dataSet[i][0] = float("".join([dataSet[i][0]]))
    dataSet[i][2] = float("".join([dataSet[i][2]]))
    dataSet[i][3] = float("".join([dataSet[i][3]]))





dataSet = array(dataSet)

trainData = dataSet[:500]
testData  = dataSet[501:]
trainLabels = labels[:500]
testLabels  = labels[501:]

trainData_mean = trainData.mean(axis=0)
trainData_std = trainData.std(axis=0)

testData_mean = testData.mean(axis=0)
testData_std  = testData.std(axis=0)



def standard_deviation_normalization(data_value, data_col_means,
                                 data_col_standard_deviation):


    data_shape = data_value.shape
    data_rows = data_shape[0]
    data_cols = data_shape[1]

    for i in range(0, data_rows, 1):
        for j in range(0, data_cols, 1):
            data_value[i][j] = \
                (data_value[i][j] - data_col_means[j]) / \
                data_col_standard_deviation[j]

standard_deviation_normalization(trainData,trainData_mean,trainData_std)
standard_deviation_normalization(testData,testData_mean,testData_std)



def classify(input, dataSet, label, k):

    dataSize = dataSet.shape[0]

    diff = tile(input, (dataSize, 1)) - dataSet
    sqdiff = diff ** 2
    squareDist = sum(sqdiff, axis=1)  ###行向量分别相加，从而得到新的一个行向量
    dist = squareDist ** 0.5
    sortedDistIndex = argsort(dist)  ##argsort()根据元素的值从大到小对元素进行排序，返回下标
    classCount = {}
    for i in range(k):
        voteLabel = label[sortedDistIndex[i]]

        classCount[voteLabel] = classCount.get(voteLabel, 0) + 1
    maxCount = 0
    for key, value in classCount.items():
        if value > maxCount:
            maxCount = value
            classes = key
    return classes

def getAccuracy(k_value):
    m=0
    for i in range(len(testData)):

        result = classify(testData[i],trainData,trainLabels,k_value)
        if(result==testLabels[i]):
            #print("第 "+ str(i+1) +" 个测试数据分类结果： 正确")
            m+=1
        #else:
            #print("第 "+ str(i+1) +" 个测试数据分类结果： 错误")
    accuracy = m/len(testData)
    print("k值为"+str(k_value)+"时，本模型对训练数据分类准确率为："+"%.1f%%" %(accuracy*100))


for n in range(1,50,1):
    getAccuracy(n)




