# Scheduler

## I. Giải thuật sử dụng: 
    Multi-Level Queue (MFQ)
## II. Mô tả giải thuật
- Mỗi process với cùng độ ưu tiên sẽ được đặt vào cùng một hàng đợi ready-queue.
- **MLQ policy**: Khi hàng đợi P thực hiện đủ số lần slot (slot = MAX_PRIORITY - prio) thì tạm dừng, chuyển thực thi cho hàng đợi Q có ưu tiên thấp hơn. Khi các hàng đợi có độ ưu tiên thấp đã thực hiện hết số lần slot cho phép sẽ quay lại lần lặp kế tiếp với P là hàng đợi có độ ưu tiên cao được thực thi trước với số lần slot được tính.
- CPU thực thi mỗi process theo RR-style. Sau khi hết time slice, process được đưa vào cuối hàng đợi với độ ưu tiên như cũ. CPU tiếp tục chọn process theo **MLQ policy** để thực thi.
## III. So sánh với các giải thuật scheduler khác
Nhược điểm của các giải thuật khác:
- FCFS: CPU phải thực thi 1 process liên tục cho đến khi kết thúc -> tăng waiting time đối với các process có CPU burst ngắn. 
- SJF: Không thể biết chính xác CPU time của process kế tiếp, có khả năng gây ra starvation.
- RR: Time slice lớn -> FCFS. Time slice nhỏ -> context switch.
- PS-normal: có khả năng gây ra starvation.

Ưu điểm của MFQ:
- Response time: Các process có độ ưu tiên cao được thực thi trước.
- Not starvation: Mỗi ready-queue có số lần slot nhất định trong chu kì thực thi của các hàng đợi.
- Fairly: Giải thuật cho mỗi hàng đợi là Round Robin.
## IV. Triển khai
1. Priority Queue
    - void enqueue(struct queue_t *q, struct pcb_t *proc): Thêm 1 process proc vào cuối hàng đợi q.
    - struct pcb_t *dequeue(struct queue_t *q): Lấy 1 process từ đầu hàng đợi q.
2. Scheduler
    - struct pcb_t *get_mlq_proc(void): Lấy 1 process từ ready-queue theo **MLQ policy**, sử dụng khóa mutex để bảo vệ hàng đợi.
## V. Kết quả
1. TEST 0:


