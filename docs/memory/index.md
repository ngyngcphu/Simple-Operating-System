# Memory Management

## I. Các modules trong memory system
![Memory-Modules](../assets/mod-mem.png)
### 1. MM-VM Virtual Memory
- Không gian địa chỉ bộ nhớ ảo bao gồm:
    - Memory Area (mỗi area đại diện cho các segment của 1 process: data segment, code segment, stack segment, heap segment,...). Trong Assignment, ta chỉ sử dụng 1 memory area tương ứng vmaid = 0. 
    - Mỗi Memory Area bao gồm các Memory Region (region đang được sử dụng và region đang free).
- Lợi ích của việc thiết kế multiple segments:
    - Tổ chức bộ nhớ tốt hơn, dễ dàng quản lý và truy xuất dữ liệu: Stack segment quản lý các local variables và các function calls, Heap segment quản lý việc cấp phát động, Code segment quản lý các câu lệnh được thực thi,... Ngoài ra còn giúp hạn chế external fragmentation.
    - Giảm context switching: Khi CPU switch giữa các processes hoặc threads, chỉ những segments cần thiết mới được restore trở lại CPU để tiếp tục thực thi. Điều này hiệu quả và nhanh hơn thay vì restore toàn bộ không gian địa chỉ.
- Các operations trên virtual memory bao gồm:
    - ```ALLOC```: cấp phát 1 region memory.
    - ```FREE```: giải phóng 1 region memory.
    - ```READ```: đọc 1 byte giá trị tại 1 ô nhớ trong region memory.
    - ```WRITE```: viết 1 byte giá trị vào 1 ô nhớ trong region memory.
- 