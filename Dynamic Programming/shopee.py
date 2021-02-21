# 问题描述
# 虾皮要派人到SZ出差，给出了一年中要出差的时间
# 给出了 出差1, 7, 14, 30天公司的成本
# 让你给出出差计划 使得成本最低

def find(days):

    dp = [[0 if i == 0 else float('inf') for _ in range(4)] for i in range(len(days)+1)]

    for i in range(1, len(days)+1):

        s_index = check(days, 1, i-1)
        dp[i][0] = min(dp[s_index]) + 650

        s_index = check(days, 7, i-1)
        dp[i][1] = min(dp[s_index]) + 1200

        s_index = check(days, 14, i-1)
        dp[i][2] = min(dp[s_index]) + 2300

        s_index = check(days, 30, i-1)
        dp[i][2] = min(dp[s_index]) + 3100

    print(min(dp[-1]))

def check(days, sub, i):
    s_days = days[i] - sub +1
    if i > 0 and s_days > days[i-1]:
        s_index = i
    elif i == 0:
        s_index = 0
    else:
        for j in range(i-1, -1, -1):
            if j == 0:
                s_index = 0
                break
            else:
                if s_days <= days[j] and s_days > days[j-1]:
                    s_index = j
                    break
    return s_index

if __name__ == '__main__':

    days = [1,2,3,4,5,7, 15]
    find(days)