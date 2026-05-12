#include "SplashForm.h"
#include "DashboardForm.h"

namespace CarRentalSystem {
    void SplashForm::btnEnter_Click(System::Object^ sender, System::EventArgs^ e)
    {
        this->Hide();
        DashboardForm^ dashboard = gcnew DashboardForm();
        dashboard->ShowDialog();
        this->Close();
    }
}