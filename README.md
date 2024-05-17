CITY JUMP
1. Cách lấy chương trình và chạy chương trình:

Chuyển repo này vào tài khoản riêng của bạn
Máy đã cài đặt các chương trình SDL2, SDL Image, SDL Mixer, SDL ttf
Đối với Code Block :
Liên kết Linker settings: -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf
Vị trí thư mục include: Search directories | Compilers
Vị trí thư mục lib: Search directories | Linker
Dẫn đường link từng thư mục trên của SDL2, SDL Image, SDL Mixer, SDL ttf vào các đường dẫn như trên
Các bước trên cần thiết để cài thư viên SDL2 để có thể chạy được chương trình
Nhấp đúp GAME_.cbp và compile để chạy chương trình

2. Mô tả chung về trò chơi:

Đây là 1 tựa game lấy ý tưởng từ game Dino Sword
Bạn sẽ điều khiển nhân vật của mình để vượt qua hay tiêu diệt kẻ địch bằng cách sử dụng bàn phím

4. Các kĩ thuật lập trình được sử dụng:

Mảng
Struct
Con trỏ
Đồ họa (Hình ảnh, âm thanh, text, sự kiện chuột và bàn phím)
Tách file
Cấu trúc rẽ nhánh
Vòng lặp

5. Kết luận:
Chương trình chỉ mới được hoàn thiện cơ bản về phần logic và phần hình ảnh, âm thanh khi chơi game
Nên tách thành nhiều file cho dễ quản lý và dễ fix hơn