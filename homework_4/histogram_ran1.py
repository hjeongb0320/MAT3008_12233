import numpy as np
import matplotlib.pyplot as plt

# 파일에서 무작위 숫자 데이터 읽기
with open('ran1.txt', 'r') as file:
    data = [float(line.strip()) for line in file]

# 히스토그램 그리기
plt.hist(data, bins=100, range=(-3, 4), color='blue', alpha=0.7, density=True)
plt.title('Histogram of Random Numbers')
plt.xlabel('Value')
plt.ylabel('Frequency')

plt.show()