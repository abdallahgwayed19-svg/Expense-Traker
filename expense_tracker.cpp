#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

// هيكل بيانات لتمثيل المصروف الواحد
struct Expense {
    string description;
    double amount;
    string category;
};

// دالة لإضافة مصروف جديد
void addExpense(vector<Expense>& expenses) {
    Expense e;
    cout << "\n--- إضافة مصروف جديد ---\n";
    cout << "أدخل وصف المصروف (مثل: عشاء، مواصلات): ";
    cin.ignore();
    getline(cin, e.description);
    
    cout << "أدخل المبلغ: ";
    cin >> e.amount;
    
    cout << "أدخل الفئة (مثل: طعام، ترفيه، فواتير): ";
    cin.ignore();
    getline(cin, e.category);
    
    expenses.push_back(e);
    cout << "تمت إضافة المصروف بنجاح!\n\n";
}

// دالة لعرض جميع المصروفات المضافة
void displayExpenses(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "\nلا توجد مصروفات مسجلة حتى الآن.\n\n";
        return;
    }
    
    cout << "\n---------------- قائمة المصروفات ----------------\n";
    for (size_t i = 0; i < expenses.size(); ++i) {
        cout << i + 1 << ". الوصف: " << expenses[i].description 
             << " | المبلغ: " << expenses[i].amount 
             << " | الفئة: " << expenses[i].category << "\n";
    }
    cout << "------------------------------------------------\n\n";
}

// دالة لحساب إجمالي المصروفات
void showTotalExpenses(const vector<Expense>& expenses) {
    if (expenses.empty()) {
        cout << "\nإجمالي المصروفات الحالي هو: 0.0\n\n";
        return;
    }
    
    double total = 0;
    for (const auto& e : expenses) {
        total += e.amount;
    }
    cout << "\n========================================\n";
    cout << " إجمالي المصروفات الكلي هو: " << total << "\n";
    cout << "========================================\n\n";
}

int main() {
    vector<Expense> expenses;
    int choice;

    // تغيير ترميز الكونسول لدعم اللغة العربية في ويندوز إن أمكن
    #ifdef _WIN32
    system("chcp 65001 > nul");
    #endif

    while (true) {
        cout << "--- نظام متابعة المصروفات (Expense Tracker) ---\n";
        cout << "1. إضافة مصروف جديد\n";
        cout << "2. عرض جميع المصروفات\n";
        cout << "3. حساب إجمالي المصروفات\n";
        cout << "4. الخروج من البرنامج\n";
        cout << "اختر رقم العملية: ";
        cin >> choice;

        if (choice == 1) {
            addExpense(expenses);
        } else if (choice == 2) {
            displayExpenses(expenses);
        } else if (choice == 3) {
            showTotalExpenses(expenses);
        } else if (choice == 4) {
            cout << "شكراً لاستخدامك البرنامج. إلى اللقاء!\n";
            break;
        } else {
            cout << "اختيار غير صحيح، يرجى المحاولة مجدداً.\n\n";
        }
    }
    return 0;
}
