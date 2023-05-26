## IV. Triển khai
1. Priority Queue
    - ```void enqueue(struct queue_t *q, struct pcb_t *proc)```: Thêm 1 process proc vào cuối hàng đợi q.
    - ```struct pcb_t *dequeue(struct queue_t *q)```: Lấy 1 process từ đầu hàng đợi q.
2. Scheduler
    - ```struct pcb_t *get_mlq_proc(void)```: Lấy 1 process từ ready-queue theo **MLQ policy**, sử dụng khóa mutex để bảo vệ hàng đợi.