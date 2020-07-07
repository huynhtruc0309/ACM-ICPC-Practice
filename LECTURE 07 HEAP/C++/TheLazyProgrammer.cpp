/*
Nhận xét:
+ Deadline trước làm trước
+ Cần giảm: T ngày -> trả thêm T/ai
=====================================
Sắp xếp theo deadline tăng dần
Với mỗi công việc (ai; bi; di)
    total_time += bi
    Với total_time > di:
        T = total_time - di
        while (pq.size() > 0)
            top = pq.top(); pq.pop();
            Nếu top.b > T:
                result += T/top.a
                total_time = di
                T = 0
                pq.push(Job(top.a, top.b - T))
            Ngược lại
                result += top.b/top.a
                total_time -= top.b
                T -= top.b
*/