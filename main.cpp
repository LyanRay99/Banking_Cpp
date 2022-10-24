#include <iostream>
#include <string>
#include <cctype>
#include <time.h>
#include <limits>
#include "smart_banking.h"

using namespace std;

// // biến số dư
// int sodu, sodu_hientai = 0;
// int otp = 0, otp_doichieu;

// // biến của vé số ba miền
// bool veso_bamien_laplai_so = true;
// int veso_bamien_cosan;
// bool veso_bamien_xacthuc_otp = true;
// int veso_bamien_laplai_mua;
// int veso_bamien_laplai_so1;

// // biến của nap card
// int napcard_mocnap = 0;
// bool napcard_laplai = true;
// int napcard_mathe;
// bool napcard_xacthuc_otp;
// int napcard_laplai_mua;
// int napcard_laplai_so1;
// int napcard_laplai_naptien;

// // biến dùng cho switch case khi user ko nhập đúng theo yêu cầu (nhập chữ)
// bool select_switch_case = false;

// void f_s_naptien();
// void f_s_chuyenkhoan();
// void f_s_chuyenkhoan1();
// void f_s_laisuat();
// void f_s_laisuat_gui();
// void f_s_laisuat_vay();
// void f_s_veso();
// void f_s_veso_vietlot();
// void f_s_veso_bamien();
// void veso_mienbac();
// void veso_mientrung();
// void veso_miennam();
// void f_s_thanhtoan();
// void f_s_thanhtoan_dien();
// void f_s_thanhtoan_nuoc();
// void f_s_napcard();
// void f_s_napcard_mocnap();
// void f_s_napcard_thuchien();

// khoảng cách
void khoangcach()
{
    cout << "----------------------------------------------------------" << endl;
}

// hàm dùng cho vé số 3 miên
void veso_bamien_support()
{
    // vòng quay chọn lại vé số
    while (veso_bamien_laplai_so == true)
    {
        srand(time(NULL));
        veso_bamien_cosan = rand() % 1000000000 + 100000000;
        cout << " Giá 1 vé là 10.000 đồng" << endl;
        if (sodu_hientai >= 10000)
        {
            cout << "Vé mang số: " << veso_bamien_cosan << endl;
            // ktr mã OTP
            while (veso_bamien_xacthuc_otp == true)
            {
                srand(time(NULL));
                otp = rand() % 1000000 + 100000;
                cout << "Mã OTP của quý khách trong giao dịch này là: " << otp << endl;
                cout << "Quý khách vui lòng nhập lại mã OTP" << endl;
                cin >> otp_doichieu;
                if (otp == otp_doichieu)
                {
                    cout << "Giao dịch thành công!" << endl;
                    cout << "Vé số có mã: " << veso_bamien_cosan << endl;
                    sodu_hientai -= 10000;
                    cout << "Số dư của quý khách là: " << sodu_hientai << endl;
                    veso_bamien_xacthuc_otp = false;
                    veso_bamien_laplai_so = false;

                    khoangcach();

                    cout << "Quý khách có muốn mua thêm không ?" << endl;
                    cout << " Có   : Nhấn phím 1" << endl;
                    cout << "Không : Nhấn phím 0" << endl;
                    khoangcach();
                    cin >> veso_bamien_laplai_mua;
                    int a = false;
                    if (veso_bamien_laplai_mua == 1)
                    {
                        a = true;
                    }
                    if (a == true)
                    {
                        veso_bamien_support();
                    }
                }
                else
                {
                    cout << "Mã OTP không đúng, Quý khách vui lòng lấy mã và nhập lại" << endl;
                }
            }
        }
        else
        {
            do
            {
                select_switch_case = false;
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> veso_bamien_laplai_so1;
                if (cin.fail())
                {
                    cout << "Lựa chọn không được chứa chữ!" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<int>::max(), '\n');
                    select_switch_case = true;
                    continue;
                }
            } while (select_switch_case == true);
            switch (veso_bamien_laplai_so1)
            {
            case 1:
                f_s_naptien();
                break;
            default:
                veso_bamien_laplai_so = false;
                break;
            }
        }
    }
}

// lời chào -------------------------------------------------------------------------------------------------------------
void f_info()
{
    cout << "Wellcome to MTT Bank!" << endl;
    cout << "Please sign in to use us service" << endl;
    khoangcach();
}

// kiểm tra tài khoản ---------------------------------------------------------------------------------------------------
void f_account()
{
    unsigned int id;
    bool id_sai;
    std::string pass{};
    bool saipass_so = false, saipass_kytu = false, saipass_inhoa = false;
    // ktr id +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    do
    {
        id_sai = false;
        cout << "Nhap ID: ";
        cin >> id;

        if (cin.fail())
        {
            cout << "ID không được chứa chữ!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            id_sai = true;
            continue;
        }

    } while (id < 100000 || id > 999999 || id_sai == true);
    khoangcach();
    do
    {
        // ktr pass có đúng 6 ký tự ko +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        do
        {
            cin.ignore();
            cout << "PASS: ";
            getline(cin, pass);
        } while (pass.length() != 6);
        // ktr pass có chứa số ko ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        for (int i = 0; i <= pass.length(); i++)
        {
            if (isdigit(pass[i]))
            {
                saipass_so = true;
            }
        }
        // ktr pass có chứa ký tự đặc biệt ko ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        for (int i = 0; i <= pass.length(); i++)
        {
            if (pass[i] == '!' || pass[i] == '@' || pass[i] == '#' || pass[i] == '$')
            {
                saipass_kytu = true;
            }
        }
        // ktr pass có chứa chữ in hoa ko ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        for (int i = 0; i <= pass.length(); i++)
        {
            if (pass[i] >= 'A' && pass[i] <= 'Z')
            {
                saipass_inhoa = true;
            }
        }
    } while (saipass_so == false || saipass_kytu == false || saipass_inhoa == false);
    khoangcach();
    cout << "Wellcome to you comeback!" << endl;
    khoangcach();
}

// chức năng ----------------------------------------------------------------------------------------------------------
void f_select()
{
    int select_chucnang;
    for (;;)
    {
        cout << "Quý khách có thể dùng các tính năng sau: " << endl;
        cout << " 1 - Nạp tiền" << endl;
        cout << " 2 - Chuyển khoản" << endl;
        cout << " 3 - Tính lãi suất" << endl;
        cout << " 4 - Mua vé số" << endl;
        cout << " 5 - Thanh toán hóa đơn" << endl;
        cout << " 6 - Nạp tiền điện thoai" << endl;
        cout << " Nhấn phím bất kỳ để thoát ứng dụng" << endl;

        do
        {
            khoangcach();
            select_switch_case = false;
            cout << "Lựa chọn không đúng!";
            cin >> select_chucnang;

            if (cin.fail())
            {
                cout << "Lựa chọn không hợp lệ!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                select_switch_case = true;
                continue;
            }
        } while (select_switch_case == true);

        switch (select_chucnang)
        {
        case 1: // nạp tiền
            f_s_naptien();
            break;
        case 2: // chuyển khoản
            f_s_chuyenkhoan();
            break;
        case 3: // tính lãi suất
            f_s_laisuat();
            break;
        case 4: // mua vietlot
            f_s_veso();
            break;
        case 5: // thanh toán điện/nước/internet
            f_s_thanhtoan();
            break;
        case 6: // nạp tiền điện thoại
            f_s_napcard();
            break;
        default:
            exit(0);
        }
    }
}

// 1 - nạp tiền
void f_s_naptien()
{
    int naptien_select;
    do
    {
        cout << "Vui lòng nhập số tiền cần nạp" << endl;
        cin >> sodu;
    } while (sodu < 0);
    sodu_hientai += sodu;
    cout << "Số dư của quý khách là: " << sodu_hientai << endl;

    // vòng lặp nạp tiền
    do
    {
        khoangcach();
        select_switch_case = false;
        cout << "Quý khách tiếp tục nạp tiền không ?" << endl;
        cout << " Có    : Nhấn phím 1" << endl;
        cout << " Không : Nhấn phím số bất kỳ" << endl;
        cin >> naptien_select;

        if (cin.fail())
        {
            cout << "Lựa chọn không hợp lệ!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            select_switch_case = true;
            continue;
        }
    } while (select_switch_case == true);
    switch (naptien_select)
    {
    case 1:
        f_s_naptien();
        break;
    default:
        khoangcach();
        break;
    }
}

// 2 - Chuyển khoản
void f_s_chuyenkhoan()
{
    int bank;

    for (;;)
    {
        do
        {
            select_switch_case = false;
            cout << "Chọn ngân hàng của người nhận" << endl;
            cout << " 1 - Vietcombank" << endl;
            cout << " 2 - Techcombank" << endl;
            cout << " 3 - BIDV " << endl;
            cout << " 4 - MB bank" << endl;
            cout << " 5 - Sacombank" << endl;
            cout << " 6 - Quay lại" << endl;
            cout << " Nhấn phím bất kỳ để thoát ứng dụng" << endl;
            cin >> bank;
            khoangcach();
            if (cin.fail())
            {
                cout << "Lựa chọn không hợp lệ!" << endl;
                cin.clear();
                cin.ignore(numeric_limits<int>::max(), '\n');
                select_switch_case = true;
                continue;
            }
        } while (select_switch_case == true);

        switch (bank)
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            f_s_chuyenkhoan1();
            break;
        case 6:
            return;
        default:
            exit(0);
        }
    }
}

// 2.1 - xử lý số tiền chuyển khoản
void f_s_chuyenkhoan1()
{
    int chuyenkhoan1_sotien;
    bool chuyenkhoan1_laplai = true;
    int chuyenkhoan1_laplai_select;
    bool chuyenkhoan1_laplai_stk = true;
    int stk_nguoinhan;
    while (chuyenkhoan1_laplai == true)
    {

        // ktr stk người nhận phải có 6 số
        while (chuyenkhoan1_laplai_stk == true)
        {

            cout << "Nhập số tài khoản người nhận" << endl;
            cin >> stk_nguoinhan;
            if (stk_nguoinhan >= 100000 && stk_nguoinhan <= 999999)
            {
                chuyenkhoan1_laplai_stk = false;
            }
            else
            {
                cout << "Số tài khoản không hợp lệ" << endl;
                cout << "Quý khách có muốn nhập lại số tài khoản người nhận" << endl;
                cout << " Thực hiện lại  : Nhấn phím 1" << endl;
                cout << " Quay lại       : Nhấn phím 0" << endl;
                cout << " Thoát ứng dụng : Nhấn phím bất kỳ" << endl;

                khoangcach();

                cin >> chuyenkhoan1_laplai_select;

                if (chuyenkhoan1_laplai_select == 1)
                {
                    chuyenkhoan1_laplai_stk = true;
                }
                else if (chuyenkhoan1_laplai_select == 0)
                {
                    return;
                }
                else
                {
                    exit(0);
                }
            }
        }

        khoangcach();

        cout << "Nhập số tiền cần chuyển: ";
        cin >> chuyenkhoan1_sotien;

        // ktr số dư có đủ để chuyển ko và ktr mã OTP
        if (chuyenkhoan1_sotien <= sodu_hientai)
        {
            do
            {
                srand(time(NULL));
                otp = rand() % 1000000 + 100000;
                cout << "Mã OTP của quý khách trong giao dịch này là: " << otp << endl;
                cout << "Quý khách vui lòng nhập lại mã OTP" << endl;
                cin >> otp_doichieu;
            } while (otp != otp_doichieu);

            cout << " Giao dịch thành công!" << endl;
            cout << " Người nhận : Nguyễn Văn Chính" << endl;
            cout << " Ngân hàng  : MB Bank" << endl;
            cout << " Số tiền    : " << chuyenkhoan1_sotien << endl;
            sodu_hientai -= chuyenkhoan1_sotien;
            khoangcach();
            cout << "Số dư của quý khách là: " << sodu_hientai << endl;
            khoangcach();
            break;
        }
        else
        {
            cout << "Số dư của quý khách không đủ để thực hiện dao dịch!" << endl;
            khoangcach();
        }

        // nhu cầu thực hiện lại giao dịch
        cout << "Bạn có muốn thực hiện lại giao dịch ?" << endl;
        cout << " Có       : Nhấn phím 1" << endl;
        cout << " Quay lại : Nhấn phím số bất kỳ" << endl;
        cin >> chuyenkhoan1_laplai;

        khoangcach();

        switch (chuyenkhoan1_laplai)
        {
        case 1:
            chuyenkhoan1_laplai = true;
            break;
        default:
            chuyenkhoan1_laplai = false;
            break;
        }
    }
}

// 3 - Tính lãi suất
void f_s_laisuat()
{
    int laisuat_select;
    for (;;)
    {
        cout << " 1 - Lãi suất tiền gửi" << endl;
        cout << " 2 - Lãi suất cho vay" << endl;
        cout << " 3 - Quay lại" << endl;
        cout << "Nhấn phím bất kỳ để thoát ứng dụng" << endl;
        khoangcach();
        cin >> laisuat_select;
        switch (laisuat_select)
        {
        case 1:
            f_s_laisuat_gui();
            break;
        case 2:
            f_s_laisuat_vay();
            break;
        case 3:
            return;
        default:
            exit(0);
        }
    }
}

// 3.1 - Lãi tiền gửi
void f_s_laisuat_gui()
{
    unsigned int laisuat_tien;
    int laisuat_time; // thời gian 10.5 tháng vẫn tính là 1 tháng nên dùng int
    float laisuat_phantram;
    unsigned int laisuat_tienlai;
    int laisuat_gui_select;
    cout << "Quý khách muốn gửi số tiền bao nhiêu ?" << endl;
    cin >> laisuat_tien;
    cout << "Với thời gian bao nhiêu tháng ?" << endl;
    cin >> laisuat_time;
    cout << "Với lãi suất bao nhiêu % ?" << endl;
    cin >> laisuat_phantram;
    khoangcach();
    cout << "  Kết quả:";
    cout << "- Số tiền gửi :" << laisuat_tien << " đồng" << endl;
    cout << "- Thời gian gửi :" << laisuat_time << " tháng" << endl;
    cout << "- Lãi suất :" << laisuat_phantram << "%" << endl;
    laisuat_tienlai = (laisuat_tien * ((laisuat_phantram / 100) / 12) * laisuat_time);
    cout << "=> Tiền lãi của Quý khách là " << laisuat_tienlai << endl;

    // vòng lặp tính lãi suất tiền gửi
    cout << "Quý khách muốn tiếp tục tính không ?" << endl;
    cout << " Có    : Nhấn phím 1" << endl;
    cout << " Không : Nhấn phím số bất kỳ" << endl;
    cin >> laisuat_gui_select;
    switch (laisuat_gui_select)
    {
    case 1:
        f_s_laisuat_gui();
        break;
    default:
        khoangcach();
        break;
    }
}

// 3.2 - Lãi vay
void f_s_laisuat_vay()
{
    unsigned int laisuat_tien;
    int laisuat_time; // thời gian 10.5 tháng vẫn tính là 1 tháng nên dùng int
    float laisuat_phantram;
    unsigned int laisuat_tienlai;
    int laisuat_gui_select;

    int laisuat_vay_tiengocconlai;

    int laisuat_vay_laithangdau;
    int laisuat_vay_laicacthangsau;

    cout << "Quý khách muốn gửi số tiền bao nhiêu ?" << endl;
    cin >> laisuat_tien;
    cout << "Với thời gian bao nhiêu tháng ?" << endl;
    cin >> laisuat_time;
    cout << "Với lãi suất bao nhiêu % ?" << endl;
    cin >> laisuat_phantram;
    khoangcach();
    cout << "  Kết quả:";
    cout << "- Số tiền vay :" << laisuat_tien << " đồng" << endl;
    cout << "- Thời gian vay :" << laisuat_time << " tháng" << endl;
    cout << "- Lãi suất :" << laisuat_phantram << "%" << endl;
    cout << " => Tiền gốc hàng tháng phải trả : " << laisuat_tien / laisuat_time << endl;

    int sum_tiengoc = laisuat_tien / laisuat_time; // biến dùng để chứa giá trị tiền gốc hàng tháng phải trả
    int laisuat_tien_for = laisuat_tien;
    int sum_tienlai = 0;

    for (int i = 1; i <= laisuat_time; i++)
    {
        laisuat_tien_for -= sum_tiengoc;
        cout << " => Tiền gốc còn lại tại tháng " << i << " : " << laisuat_tien_for << endl;
        cout << " => Tiền lãi tháng thứ " << i << " : " << int(laisuat_tien_for * (laisuat_phantram / 100)) / laisuat_time << endl;
        sum_tienlai += int(laisuat_tien_for * (laisuat_phantram / 100)) / laisuat_time;
    }
    cout << " => Tổng tiền : " << laisuat_tien + sum_tienlai << endl;
    // vòng lặp tính lãi suất tiền gửi
    cout << "Quý khách muốn tiếp tục tính không ?" << endl;
    cout << " Có    : Nhấn phím 1" << endl;
    cout << " Không : Nhấn phím số bất kỳ" << endl;
    cin >> laisuat_gui_select;
    switch (laisuat_gui_select)
    {
    case 1:
        f_s_laisuat_vay();
        break;
    default:
        khoangcach();
        break;
    }
}

// 4 - mua vé số
void f_s_veso()
{
    int veso_select;
    for (;;)
    {
        cout << "Quý khách muốn mua vé số nào ?" << endl;
        cout << " 1 - VietLot" << endl;
        cout << " 2 - Vé số ba miền" << endl;
        cout << " 3 - Quay lại" << endl;
        cout << "Nhấn phím bất kỳ để thoát ứng dụng" << endl;
        khoangcach();
        cin >> veso_select;
        switch (veso_select)
        {
        case 1:
            f_s_veso_vietlot();
            break;
        case 2:
            f_s_veso_bamien();
            break;
        case 3:
            return;
        default:
            exit(0);
        }

        khoangcach();
    }
}

// 4.1 - vietlot
void f_s_veso_vietlot()
{
    // biến case 1
    int veso_vietlot_select;
    int veso_tuchon;
    bool veso_vietlot_xacthuc_otp = true;
    int veso_vietlot_laplai_so1;
    bool veso_vietlot_laplai_so = true;
    int veso_vietlot_laplai_mua;
    // biến case 2
    int veso_cosan;

    cout << "Quý khách muốn mua số có sẵn hay tự chọn ?" << endl;
    cout << " 1 - Tự chọn số" << endl;
    cout << " 2 - Mua số có sẵn" << endl;
    cout << " 3 - Quay lại" << endl;
    cout << " Nhấn phím bất kỳ để thoát ứng dụng" << endl;

    khoangcach();

    cin >> veso_vietlot_select;
    switch (veso_vietlot_select)
    {
    case 1:
        // vòng lặp nhập lại vé số
        while (veso_vietlot_laplai_so == true)
        {
            cout << "Mời quý khách nhập số" << endl;
            cin >> veso_tuchon;

            // ktr vé số phải có đúng 9 chữ số
            if (veso_tuchon > 99999999 && veso_tuchon < 1000000000)
            {
                // ktr số dư còn đủ mua ko
                cout << " Giá 1 vé là 10.000 đồng" << endl;
                if (sodu_hientai >= 10000)
                {
                    // ktr mã OTP
                    while (veso_vietlot_xacthuc_otp == true)
                    {
                        srand(time(NULL));
                        otp = rand() % 1000000 + 100000;
                        cout << "Mã OTP của quý khách trong giao dịch này là: " << otp << endl;
                        cout << "Quý khách vui lòng nhập lại mã OTP" << endl;
                        cin >> otp_doichieu;
                        if (otp == otp_doichieu)
                        {
                            cout << "Giao dịch thành công!" << endl;
                            cout << "Vé số có mã: " << veso_tuchon << endl;
                            sodu_hientai -= 10000;
                            cout << "Số dư của quý khách là: " << sodu_hientai << endl;
                            veso_vietlot_xacthuc_otp = false;
                            veso_vietlot_laplai_so = false;

                            khoangcach();

                            cout << "Quý khách có muốn mua thêm không ?" << endl;
                            cout << " Có   : Nhấn phím 1" << endl;
                            cout << "Không : Nhấn phím 0" << endl;
                            khoangcach();
                            cin >> veso_vietlot_laplai_mua;
                            switch (veso_vietlot_laplai_mua)
                            {
                            case 1:
                                f_s_veso_vietlot();
                                break;
                            default:
                                break;
                            }
                        }
                        else
                        {
                            cout << "Mã OTP không đúng, Quý khách vui lòng lấy mã và nhập lại" << endl;
                        }
                    }
                }
                else
                {
                    cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                    cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                    cout << " Quay lại      : Nhấn phím 0" << endl;
                    khoangcach();
                    cin >> veso_vietlot_laplai_so1;
                    switch (veso_vietlot_laplai_so1)
                    {
                    case 1:
                        f_s_naptien();
                        break;
                    default:
                        veso_vietlot_laplai_so = false;
                        break;
                    }
                }
            }
            else
            {
                cout << "Giá trị quý khách đã chọn không hợp lệ" << endl;
                cout << "Quý khách có muốn nhập lại ko" << endl;
                cout << " Có       : Nhấn phím 1" << endl;
                cout << " Quay lại : Nhấn phím bất kỳ" << endl;
                khoangcach();
                cin >> veso_vietlot_laplai_so1;
                switch (veso_vietlot_laplai_so1)
                {
                case 1:
                    veso_vietlot_laplai_so = true;
                    break;
                default:
                    veso_vietlot_laplai_so = false;
                    break;
                }
            }
        }
        break;
    case 2:
        // vòng quay chọn lại vé số
        while (veso_vietlot_laplai_so == true)
        {
            srand(time(NULL));
            veso_cosan = rand() % 1000000000 + 100000000;
            cout << " Giá 1 vé là 10.000 đồng" << endl;
            if (sodu_hientai >= 10000)
            {
                cout << "Vé mang số: " << veso_cosan << endl;
                // ktr mã OTP
                while (veso_vietlot_xacthuc_otp == true)
                {
                    srand(time(NULL));
                    otp = rand() % 1000000 + 100000;
                    cout << "Mã OTP của quý khách trong giao dịch này là: " << otp << endl;
                    cout << "Quý khách vui lòng nhập lại mã OTP" << endl;
                    cin >> otp_doichieu;
                    if (otp == otp_doichieu)
                    {
                        cout << "Giao dịch thành công!" << endl;
                        cout << "Vé số có mã: " << veso_cosan << endl;
                        sodu_hientai -= 10000;
                        cout << "Số dư của quý khách là: " << sodu_hientai << endl;
                        veso_vietlot_xacthuc_otp = false;
                        veso_vietlot_laplai_so = false;

                        khoangcach();

                        cout << "Quý khách có muốn mua thêm không ?" << endl;
                        cout << " Có   : Nhấn phím 1" << endl;
                        cout << "Không : Nhấn phím 0" << endl;
                        khoangcach();
                        cin >> veso_vietlot_laplai_mua;
                        switch (veso_vietlot_laplai_mua)
                        {
                        case 1:
                            f_s_veso_vietlot();
                            break;
                        default:
                            break;
                        }
                    }
                    else
                    {
                        cout << "Mã OTP không đúng, Quý khách vui lòng lấy mã và nhập lại" << endl;
                    }
                }
            }
            else
            {
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;

                cin >> veso_vietlot_laplai_so1;
                switch (veso_vietlot_laplai_so1)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    veso_vietlot_laplai_so = false;
                    break;
                }
            }
        }
        break;
    case 3:
        return;
    default:
        exit(0);
    }
}

// 4.2 - vé số ba miền
void f_s_veso_bamien()
{
    int veso_bamien_select;

    cout << "Quý khách muốn mua vé số tỉnh ngoài" << endl;
    cout << " 1 - Đà Nẵng" << endl;
    cout << " 2 - Phú Yên" << endl;
    cout << " 3 - Komtum" << endl;
    cout << " 4 - Huế" << endl;
    cout << " 5 - Quay lai" << endl;
    cout << " Nhấn phím bất kỳ để thoát ứng dụng" << endl;
    khoangcach();
    cin >> veso_bamien_select;
    switch (veso_bamien_select)
    {
    case 1:
        veso_bamien_support();
        break;
    case 2:
        veso_bamien_support();
        break;
    case 3:
        veso_bamien_support();
        break;
    case 4:
        veso_bamien_support();
        break;
    case 5:
        veso_bamien_support();
        break;
    case 6:
        return;
    default:
        exit(0);
    }
}

// 5 - Thanh toán hóa đơn
void f_s_thanhtoan()
{
    int thanhtoan_select;
    for (;;)
    {
        khoangcach();
        cout << " 1 - Tiền điện" << endl;
        cout << " 2 - Tiền nước" << endl;
        cout << " 3 - Quay lại" << endl;
        cout << " Nhấn phím bất kỳ để thoát ứng dụng" << endl;
        khoangcach();
        cin >> thanhtoan_select;
        switch (thanhtoan_select)
        {
        case 1:
            f_s_thanhtoan_dien();
            break;
        case 2:
            f_s_thanhtoan_nuoc();
            break;
        case 3:
            return;
        default:
            exit(0);
        }
    }
}

// 5.1 - thanh toán tiền điện
void f_s_thanhtoan_dien()
{
    int thanhtoan_laplai_dien;
    for (;;)
    {
        int dienNang;
        cout << "Nhập điện năng tiêu thụ trong tháng: ";
        cin >> dienNang;
        if (dienNang > 0 && dienNang < 51)
        {
            int muc1 = dienNang * 1678;
            if (sodu_hientai >= muc1)
            {
                cout << "Tiền điện tháng này của bạn cho " << dienNang << " kWh là:" << endl;
                cout << "+ Từ 0 - 50 kWh: " << muc1 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc1 << " đồng" << endl;
                sodu_hientai -= muc1;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Tổng hóa đơn: " << muc1 << " đồng" << endl;
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_dien;
                switch (thanhtoan_laplai_dien)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (dienNang > 50 && dienNang < 101)
        {
            int muc2 = 50 * 1678 + (dienNang - 50) * 1734;
            if (sodu_hientai >= muc2)
            {
                cout << "Tiền điện tháng này của bạn cho " << dienNang << " kWh là:" << endl;
                cout << "+ Từ 0 - 50 kWh: " << 50 * 1678 << " đồng" << endl;
                cout << "+ Từ 51 - 100 kWh: " << (dienNang - 50) * 1734 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc2 << " đồng" << endl;
                sodu_hientai -= muc2;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Tổng hóa đơn: " << muc2 << " đồng" << endl;
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_dien;
                switch (thanhtoan_laplai_dien)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (dienNang > 100 && dienNang < 201)
        {
            int muc3 = 50 * 1678 + 50 * 1734 + (dienNang - 100) * 2014;
            if (sodu_hientai >= muc3)
            {
                cout << "Tiền điện tháng này của bạn cho " << dienNang << " kWh là:" << endl;
                cout << "+ Từ 0 - 50 kWh: " << 50 * 1678 << " đồng" << endl;
                cout << "+ Từ 51 - 100 kWh: " << 50 * 1734 << " đồng" << endl;
                cout << "+ Từ 101 - 200 kWh: " << (dienNang - 100) * 2014 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc3 << " đồng" << endl;
                sodu_hientai -= muc3;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Tổng hóa đơn: " << muc3 << " đồng" << endl;
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_dien;
                switch (thanhtoan_laplai_dien)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (dienNang > 200 && dienNang < 301)
        {
            int muc4 = 50 * 1678 + 50 * 1734 + 100 * 2014 + (dienNang - 200) * 2536;
            if (sodu_hientai >= muc4)
            {
                cout << "Tiền điện tháng này của bạn cho " << dienNang << " kWh là:" << endl;
                cout << "+ Từ 0 - 50 kWh: " << 50 * 1678 << " đồng" << endl;
                cout << "+ Từ 51 - 100 kWh: " << 50 * 1734 << " đồng" << endl;
                cout << "+ Từ 101 - 200 kWh: " << 100 * 2014 << " đồng" << endl;
                cout << "+ Từ 201 - 300 kWh: " << (dienNang - 200) * 2536 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc4 << " đồng" << endl;
                sodu_hientai -= muc4;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Tổng hóa đơn: " << muc4 << " đồng" << endl;
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_dien;
                switch (thanhtoan_laplai_dien)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (dienNang > 300 && dienNang < 401)
        {
            int muc5 = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (dienNang - 300) * 2834;
            if (sodu_hientai >= muc5)
            {
                cout << "Tiền điện tháng này của bạn cho " << dienNang << " kWh là:" << endl;
                cout << "+ Từ 0 - 50 kWh: " << 50 * 1678 << " đồng" << endl;
                cout << "+ Từ 51 - 100 kWh: " << 50 * 1734 << " đồng" << endl;
                cout << "+ Từ 101 - 200 kWh: " << 100 * 2014 << " đồng" << endl;
                cout << "+ Từ 201 - 300 kWh: " << 100 * 2536 << " đồng" << endl;
                cout << "+ Từ 301 - 400 kWh: " << (dienNang - 300) * 2834 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc5 << " đồng" << endl;
                sodu_hientai -= muc5;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Tổng hóa đơn: " << muc5 << " đồng" << endl;
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_dien;
                switch (thanhtoan_laplai_dien)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (dienNang > 400)
        {
            int muc6 = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (dienNang - 300) * 2927;
            if (sodu_hientai >= muc6)
            {
                cout << "Tiền điện tháng này của bạn cho " << dienNang << " kWh là:" << endl;
                cout << "+ Từ 0 - 50 kWh: " << 50 * 1678 << " đồng" << endl;
                cout << "+ Từ 51 - 100 kWh: " << 50 * 1734 << " đồng" << endl;
                cout << "+ Từ 101 - 200 kWh: " << 100 * 2014 << " đồng" << endl;
                cout << "+ Từ 201 - 300 kWh: " << 100 * 2536 << " đồng" << endl;
                cout << "+ Từ 301 - 400 kWh: " << 100 * 2834 << " đồng" << endl;
                cout << "+ Từ 400 kWh trở lên: " << (dienNang - 300) * 2927 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc6 << " đồng" << endl;
                sodu_hientai -= muc6;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Tổng hóa đơn: " << muc6 << " đồng" << endl;
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_dien;
                switch (thanhtoan_laplai_dien)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            cout << "Giá trị điện năng ko hợp lệ" << endl;
        }
    }
}

// 5.2 - thanh toán nước
void f_s_thanhtoan_nuoc()
{
    int thanhtoan_laplai_nuoc;
    for (;;)
    {
        khoangcach();
        int m3nuoc;
        cout << "Nhập khối lượng nước tiêu thụ trong tháng: ";
        cin >> m3nuoc;
        if (m3nuoc > 0 && m3nuoc < 11)
        {
            int muc_nuoc_1 = m3nuoc * 5973;
            if (sodu_hientai >= muc_nuoc_1)
            {
                cout << "Tiền nước tháng này của bạn cho " << m3nuoc << " m3 là:" << endl;
                cout << "+ Từ 0 - 10 m3: " << muc_nuoc_1 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc_nuoc_1 << " đồng" << endl;
                sodu_hientai -= muc_nuoc_1;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_nuoc;
                switch (thanhtoan_laplai_nuoc)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (m3nuoc > 10 && m3nuoc < 21)
        {
            int muc_nuoc_2 = 10 * 5973 + (m3nuoc - 10) * 7052;
            if (sodu_hientai >= muc_nuoc_2)
            {
                cout << "Tiền nước tháng này của bạn cho " << m3nuoc << " m3 là:" << endl;
                cout << "+ Từ 0 - 10 m3: " << 10 * 5973 << " đồng" << endl;
                cout << "+ Từ 11 - 20 m3: " << (m3nuoc - 10) * 7052 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc_nuoc_2 << " đồng" << endl;
                sodu_hientai -= muc_nuoc_2;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_nuoc;
                switch (thanhtoan_laplai_nuoc)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (m3nuoc > 20 && m3nuoc < 31)
        {
            int muc_nuoc_3 = 10 * 5973 + 10 * 7052 + (m3nuoc - 20) * 8669;
            if (sodu_hientai >= muc_nuoc_3)
            {
                cout << "Tiền nước tháng này của bạn cho " << m3nuoc << " m3 là:" << endl;
                cout << "+ Từ 0 - 10 m3: " << 10 * 5973 << " đồng" << endl;
                cout << "+ Từ 11 - 20 m3: " << 10 * 7052 << " đồng" << endl;
                cout << "+ Từ 21 - 30 m3: " << (m3nuoc - 20) * 8669 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc_nuoc_3 << " đồng" << endl;
                sodu_hientai -= muc_nuoc_3;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_nuoc;
                switch (thanhtoan_laplai_nuoc)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else if (m3nuoc > 30)
        {
            int muc_nuoc_4 = 10 * 5973 + 10 * 7052 + 10 * 8669 + (m3nuoc - 30) * 15929;
            if (sodu_hientai >= muc_nuoc_4)
            {
                cout << "Tiền nước tháng này của bạn cho " << m3nuoc << " m3 là:" << endl;
                cout << "+ Từ 0 - 10 m3: " << 10 * 5973 << " đồng" << endl;
                cout << "+ Từ 11 - 20 m3: " << 10 * 7052 << " đồng" << endl;
                cout << "+ Từ 21 - 30 m3: " << 10 * 8669 << " đồng" << endl;
                cout << "+ Từ 30 m3 trở lên: " << (m3nuoc - 30) * 15929 << " đồng" << endl;
                cout << "Tổng hóa đơn: " << muc_nuoc_4 << " đồng" << endl;
                sodu_hientai -= muc_nuoc_4;
                cout << " Số dư còn lại của Quý khách là: " << sodu_hientai << endl;
                khoangcach();
                return;
            }
            else
            {
                cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
                cout << " Nạp thêm tiền : Nhấn phím 1" << endl;
                cout << " Quay lại      : Nhấn phím 0" << endl;
                cin >> thanhtoan_laplai_nuoc;
                switch (thanhtoan_laplai_nuoc)
                {
                case 1:
                    f_s_naptien();
                    break;
                default:
                    break;
                }
            }
        }
        else
        {
            cout << "Giá trị mức nước tiêu thụ ko hợp lệ" << endl;
        }
    }
}

// 6 - Nạp tiền điện thoại
void f_s_napcard()
{
    int napcard_select;
    cout << "Chọn nhà mạng: " << endl;
    cout << " 1 - Mobiphone" << endl;
    cout << " 2 - Vinaphone" << endl;
    cout << " 3 - Vietnammobi" << endl;
    cout << " 4 - Viettel" << endl;
    cout << " 5 - Quay lại" << endl;
    cout << " Nhấn phím bất kỳ để thoát ứng dụng" << endl;
    khoangcach();
    cin >> napcard_select;
    switch (napcard_select)
    {
    case 1:
        f_s_napcard_mocnap();
        break;
    case 2:
        f_s_napcard_mocnap();
        break;
    case 3:
        f_s_napcard_mocnap();
        break;
    case 4:
        f_s_napcard_mocnap();
        break;
    case 5:
        return;
    default:
        exit(0);
    }
}

// 6.1 - Chọn mốc nạp
void f_s_napcard_mocnap()
{
    int napcard_mocnap_select;
    cout << " 1 - 10.000 đồng" << endl;
    cout << " 2 - 20.000 đồng" << endl;
    cout << " 3 - 50.000 đồng" << endl;
    cout << " 4 - 100.000 đồng" << endl;
    cout << " 5 - 200.000 đồng" << endl;
    cout << " 6 - 500.000 đồng" << endl;
    cout << " 7 - Quay lai" << endl;
    khoangcach();
    cin >> napcard_mocnap_select;

    switch (napcard_mocnap_select)
    {
    case 1:
        napcard_mocnap = 10000;
        f_s_napcard_thuchien();
        break;
    case 2:
        napcard_mocnap = 20000;
        f_s_napcard_thuchien();
        break;
    case 3:
        napcard_mocnap = 50000;
        f_s_napcard_thuchien();
        break;
    case 4:
        napcard_mocnap = 100000;
        f_s_napcard_thuchien();
        break;
    case 5:
        napcard_mocnap = 200000;
        f_s_napcard_thuchien();
        break;
    case 6:
        napcard_mocnap = 500000;
        f_s_napcard_thuchien();
        break;
    default:
        return;
    }
}

// 6.1.1 - Thực hiện nap card
void f_s_napcard_thuchien()
{

    // vòng quay mua card
    while (napcard_laplai == true)
    {
        srand(time(NULL));
        // mã số thẻ cào là 9 số
        napcard_mathe = rand() % 1000000000 + 100000000;
        // ktr số dư
        if (sodu_hientai >= napcard_mocnap)
        {

            napcard_xacthuc_otp = true;
            // ktr mã OTP
            while (napcard_xacthuc_otp == true)
            {
                srand(time(NULL));
                otp = rand() % 1000000 + 100000;
                cout << "Mã OTP của quý khách trong giao dịch này là: " << otp << endl;
                cout << "Quý khách vui lòng nhập lại mã OTP" << endl;
                cin >> otp_doichieu;
                if (otp == otp_doichieu)
                {
                    cout << "Giao dịch thành công!" << endl;

                    cout << "Mã thẻ: " << napcard_mathe << endl;
                    sodu_hientai -= napcard_mocnap;
                    cout << "Số dư của quý khách là: " << sodu_hientai << endl;
                    napcard_xacthuc_otp = false;
                    napcard_laplai = false;
                    khoangcach();
                }
                else
                {
                    cout << "Mã OTP không đúng, Quý khách vui lòng lấy mã và nhập lại" << endl;
                }
            }
        }
        else
        {
            cout << "Số dư của quý khách không đủ để thực hiện giao dịch này" << endl;
            khoangcach();
            cout << "Bạn có muốn nạp tiền ?" << endl;
            cout << " Có       : Nhấn phím 1" << endl;
            cout << " Quay lại : Nhấn phím số bất kỳ" << endl;
            cin >> napcard_laplai_naptien;
            switch (napcard_laplai_naptien)
            {
            case 1:
                f_s_naptien();
                break;
            default:
                break;
            }
        }
        cout << "Bạn có muốn thực hiện lại giao dịch ?" << endl;
        cout << " Có       : Nhấn phím 1" << endl;
        cout << " Quay lại : Nhấn phím số bất kỳ" << endl;
        cin >> napcard_laplai_so1;
        switch (napcard_laplai_so1)
        {
        case 1:
            f_s_napcard();
            break;
        default:
            napcard_laplai = false;
            break;
        }
    }
}

int main()
{
    f_info();
    f_account();
    f_select();
    return 0;
}