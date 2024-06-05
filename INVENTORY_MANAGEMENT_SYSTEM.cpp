#include <iostream>
#include <string>
#include <cctype> // for tolower function
using namespace std;

struct description {
    string weapon;
    int stock, min_val, max_val;
};

// Function to add contents in the description's array
void item_card(description *m, string *name, int *num, int *min, int *max) {
    for(int i = 0; i < 5; i++) {
        m[i].weapon = name[i];
        m[i].stock = num[i];
        m[i].min_val = min[i];
        m[i].max_val = max[i];
    }
}

// Function to display the details
void display(description m[]) {
    for(int i = 0; i < 5; i++) { 
        cout << i + 1 << "__Name : " << m[i].weapon << "__Stock Available : " << m[i].stock << endl;
    }
    for(int i = 0; i < 5; i++) {
        if(m[i].stock < m[i].min_val) {
            cout << m[i].weapon << ": will be out of stock soon....Order it has " << m[i].min_val - m[i].stock << " units less than minimum value" << endl;
        } else if(m[i].stock > m[i].max_val) {
            cout << m[i].weapon << ": Don't order More .... Sufficient Stock is available with " << m[i].stock - m[i].max_val << " extra units" << endl;
        }
    } 
}

// Function to handle selling of items
void sell(description m[]) {
    while(true) {
        int i_no, u_no;
        cout << "Can You tell me Your Item No. You Wanna Sell: ";
        cin >> i_no;
        cout << "Can You tell me number of units You Wanna Sell: ";
        cin >> u_no;
        
        if(i_no >= 1 && i_no <= 5 && u_no <= m[i_no-1].stock) {
            m[i_no-1].stock -= u_no;
        } else {
            cout << "Invalid input or insufficient stock. Try again." << endl;
            continue;
        }
        
        char u_input;
        cout << "Do You Wanna see Updated Stock List (Y/N): ";
        cin >> u_input;
        if(tolower(u_input) == 'y') {
            display(m);      //calling display function 
        }
        
        char cont_input;
        cout << "Do you want to sell more items (Y/N): ";
        cin >> cont_input;
        if(tolower(cont_input) != 'y') {
            break;
        }
    }
}

// Function to handle buying of items
void buy(description m[]) {
    while(true) {
        int i_no, u_no;
        cout << "Can You tell me Your Item No. You Wanna Buy: ";
        cin >> i_no;
        cout << "Can You tell me number of units You Wanna Buy: ";
        cin >> u_no;
        
        if(i_no >= 1 && i_no <= 5) {
            m[i_no-1].stock += u_no;
        } else {
            cout << "Invalid input. Try again." << endl;
            continue;
        }
        
        char u_input;
        cout << "Do You Wanna see Updated Stock List (Y/N): ";
        cin >> u_input;
        if(tolower(u_input) == 'y') {
            display(m);
        }
        
        char cont_input;
        cout << "Do you want to buy more items (Y/N): ";
        cin >> cont_input;
        if(tolower(cont_input) != 'y') {
            break;
        }
    }
}

// Function to prompt the user to buy or sell items
void buy_or_sell(description m[]) {
    char to_sell;
    cout << "Do You Have any Order Placed or Are You Selling Something (Y/N): ";
    cin >> to_sell;
    if(tolower(to_sell) == 'y') {
        sell(m);         //calling sell function
    } else {
        cout << "Based on your input, I am assuming you don't want to sell anything. Thanks for using me." << endl;
    }
    
    char to_buy;
    cout << "Do You wanna order something or Are You Buying Something (Y/N): ";
    cin >> to_buy;
    if(tolower(to_buy) == 'y') {
        buy(m);          //calling buy function
    } else {
        cout << "Based on your input, I am assuming you don't want to buy anything. Thanks for using me." << endl;
    }
}

int main() {
    bool drones_initialized = false, guns_initialized = false, missiles_initialized = false, jets_initialized = false;
    description drones[5], guns[5], missiles[5], jets[5];

    while (true) {
        string flight_brothers[4] = {"DRONES", "JETS", "GUNS", "MISSILES"};
        cout << "Flight_Brothers Offers You:" << endl;
        for(int i = 0; i < 4; i++) {
            cout << i + 1 << "_" << flight_brothers[i] << endl;
        }
        int item_no;
        cout << "Tell me the Item Number Whose info you want to see: ";
        cin >> item_no;
        
        switch(item_no) {
            case 1: { // DRONES
                if (!drones_initialized) {
                    string name[5] = {"AasiFly", "Lucifer-08", "Kingfisher-2", "Rolex", "SilentBEE"};
                    int stock[5] = {23, 53, 61, 70, 88};
                    int min_stock[5] = {25, 29, 33, 21, 37};
                    int max_stock[5] = {70, 76, 80, 65, 85};
                    
                    item_card(drones, name, stock, min_stock, max_stock);
                    drones_initialized = true;
                }
                display(drones);
                buy_or_sell(drones);
                break;
            }
            case 2: { // JETS
                if (!guns_initialized) {
                    string name[5] = {"F-16 Viper", "F-22 raptor", "Germen Me 262", "BAE Hawk", "HAL HTT-40"};
                    int stock[5] = {28, 57, 67, 10, 89};
                    int min_stock[5] = {25, 29, 33, 21, 37};
                    int max_stock[5] = {70, 76, 80, 65, 85};
                    
                    item_card(jets, name, stock, min_stock, max_stock);
                    guns_initialized = true;
                }
                display(jets);
                buy_or_sell(jets);
                break;
            }
            case 3: { // GUNS
                if (!missiles_initialized) {
                    string name[5] = {"UZI", "Tec-9", "AK-47", "AWP", "MP-5"};
                    int stock[5] = {32, 35, 57, 98, 12};
                    int min_stock[5] = {25, 29, 33, 21, 37};
                    int max_stock[5] = {70, 76, 80, 65, 85};
                    
                    item_card(guns, name, stock, min_stock, max_stock);
                    missiles_initialized = true;
                }
                display(guns);
                buy_or_sell(guns);
                break;
            }
            case 4: { // MISSILES
                if (!jets_initialized) {
                    string name[5] = {"ArrowBone-3", "Divya-7", "Hit-ler", "PseudoRadium-5", "Bang_Air"};
                    int stock[5] = {28, 57, 67, 10, 89};
                    int min_stock[5] = {25, 29, 33, 21, 37};
                    int max_stock[5] = {70, 76, 80, 65, 85};
                    
                    item_card(missiles, name, stock, min_stock, max_stock);
                    jets_initialized = true;
                }
                display(missiles);
                buy_or_sell(missiles);
                break;
            }
            default: {
                cout << "Invalid item number." << endl;
                break;
            }
        }
        
        char chk_ctgry;
        cout << "Do You Wanna Check Out Some Other Category (Y/N): ";
        cin >> chk_ctgry ;
        if (tolower(chk_ctgry) != 'y') {
            break;
        }
    }

    return 0;
}
