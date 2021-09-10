def convert_to_second(time_str):
    time = list(map(int, time_str.split(":")))
    
    result = time[0]*3600 + time[1] * 60 + time[2]
    
    return result

def convert_to_datetime(time):
    datetime = [0,0,0]
    
    for i in range(2,-1,-1):
        if i != 0:
            datetime[i] = time%60
        else:
            datetime[i] = time
        time = time//60
    
    for i in range(3):
        datetime[i] = str(datetime[i])
        if len(datetime[i]) == 1:
            datetime[i] = "0" + datetime[i]
    
    result = datetime[0] + ":" + datetime[1] + ":" + datetime[2]
    
    return result
    

def solution(play_time, adv_time, logs):
    play_time_second = convert_to_second(play_time)
    adv_time_second = convert_to_second(adv_time)
    
    n = len(logs)
    logs_start = [0 for _ in range(n)]
    logs_end = [0 for _ in range(n)]
    
    for i in range(n):
        start, end = logs[i].split("-")
        logs_start[i] = convert_to_second(start)
        logs_end[i] = convert_to_second(end)
    
    
    total_time = [0 for _ in range(play_time_second + 1)]
    
    for i in range(n):
        total_time[logs_start[i]] += 1
        total_time[logs_end[i]] -= 1
    
    for i in range(1, play_time_second + 1):
        total_time[i] = total_time[i] + total_time[i - 1]
        
    for i in range(1, play_time_second + 1):
        total_time[i] = total_time[i] + total_time[i - 1]
    
    max_time = total_time[adv_time_second - 1]
    answer = 0
    for i in range(adv_time_second, play_time_second):
        if max_time < total_time[i] - total_time[i - adv_time_second]:
            max_time = total_time[i] - total_time[i - adv_time_second]
            answer = i - adv_time_second + 1
        
    answer = convert_to_datetime(answer)
    
    return answer
