// biến số dư
int sodu, sodu_hientai = 0;
int otp = 0, otp_doichieu;

// biến của vé số ba miền
bool veso_bamien_laplai_so = true;
int veso_bamien_cosan;
bool veso_bamien_xacthuc_otp = true;
int veso_bamien_laplai_mua;
int veso_bamien_laplai_so1;

// biến của nap card
int napcard_mocnap = 0;
bool napcard_laplai = true;
int napcard_mathe;
bool napcard_xacthuc_otp;
int napcard_laplai_mua;
int napcard_laplai_so1;
int napcard_laplai_naptien;

// biến dùng cho switch case khi user ko nhập đúng theo yêu cầu (nhập chữ)
bool select_switch_case = false;

void f_s_naptien();
void f_s_chuyenkhoan();
void f_s_chuyenkhoan1();
void f_s_laisuat();
void f_s_laisuat_gui();
void f_s_laisuat_vay();
void f_s_veso();
void f_s_veso_vietlot();
void f_s_veso_bamien();
void veso_mienbac();
void veso_mientrung();
void veso_miennam();
void f_s_thanhtoan();
void f_s_thanhtoan_dien();
void f_s_thanhtoan_nuoc();
void f_s_napcard();
void f_s_napcard_mocnap();
void f_s_napcard_thuchien();