# Materials-Management
# Đồ Án Quản Lý Vật Tư

Khóa 2017 - Giảng viên: Lưu Nguyễn Kỳ Thư.

Kết quả: 9 điểm.

Đề bài:
3.	Quản lý nhập xuất vật tư: Ta tổ chức các danh sách sau:
- Danh sách Vattu : cây nhị phân tìm kiếm ( MAVT (C10), TENVT, DVT (đơn vị tính), Số lượng tồn).
- Danh sách Nhanvien : danh sách tuyến tính là 1 mảng con trỏ (MANV, HO, TEN, PHAI, con trỏ dshd): con trỏ dshd sẽ trỏ đến danh sách các hóa đơn mà nhân viên đó đã lập. Danh sách nhân viên có tối đa 500 nhân viên.
- Danh sách HOADON : danh sách liên kết đơn(SoHD (C20), Ngày lập hóa đơn, Loai,  con trỏ cthd). Lọai chỉ nhận ‘N’ (phiếu nhập) hoặc ‘X’ (phiếu xuất), dscthd để lưu chi tiết các vật tư của hóa đơn đó.
- Danh sách CT_HOADON : danh sách tuyến tính ( MAVT, Soluong, Dongia, %VAT). Một hóa đơn có tối đa 20 vật tư.

Chương trình có các chức năng sau:

a. Nhập vật tư : cho phép cập nhật (thêm / xóa / hiệu chỉnh ) thông tin của vật tư; riêng số lượng tồn chỉ cho phép nhập khi đó là vật tư mới thêm.

b. In danh sách vật tư tồn kho : liệt kê ds vật tư ra màn hình theo thứ tự tên vật tư tăng dần.  Kết xuất : Mã VT		Tên vật tư		Đơn vị tính		Số lượng tồ

c. Nhập nhân viên: Cập nhập các nhân viên  dựa	 vào mã nhân viên, họ, tên không được rỗng.

d. In danh sách nhân viên theo thứ tự tên nhân viên tăng dần, nếu trùng tên thì tăng dần theo họ ra màn hình, 1 nhân viên / dòng.

e. Lập hóa đơn nhập/Lập hóa đơn xuất: nhập vào số hóa đơn, ngày lập, loại (chỉ nhận ký tự N hoặc X). Sau đó, tiếp tục cho phép nhập các vật tư của hóa đơn đó; Căn cứ vào loại hóa đơn, chương trình sẽ tự động cập nhật số lượng tồn. 
Lưu ý: - Nếu số lượng xuất không đủ hàng thì báo lỗi và in ra số lượng tồn hiện có trong kho; Chỉ được phép xóa vật tư đang lập của hóa đơn hiện tại. Khi hóa đơn đã ghi thì không được xóa các vật tư trog hóa đơn.

f/ In hóa đơn : In hóa đơn dựa vào số hóa đơn do ta nhập vào.

g/ Thống kê các hóa đơn trong 1 khỏang thời gian: nhập vào 2 thời điểm từ ngày , đến ngày, chương trình sẽ in ra các hóa đơn được lập trong khoảng thời gian như trên. Kết xuất:

     BẢNG LIỆT KÊ CÁC HÓA ĐƠN TRONG KHOẢNG THỜI GIAN
			Từ ngày : ##/##/####   Đến ngày : ##/##/####
    Số HĐ		Ngày lập     Loại HĐ		Họ tên NV lập		Trị giá hóa đơn
 h/ In 10 vật tư có doanh thu cao nhất trong 1 khoảng thời gian.
Lưu ý: Chương trình cho phép lưu các danh sách vào file; Kiểm tra các điều kiện khi nhập làm dữ liệu bị sai.

Tác giả:
- Nguyễn Đức Khải           
- MSSV: N17DCCN066
- Trần Nguyễn Chí Nhân      
- MSSV: N17DCCN115

Các chức năng được chia đều thành 2 phần cho mỗi thành viên:
- Khải: a, b, e, f.
- Nhân: c, d, g, h.
