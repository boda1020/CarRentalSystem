# 🚗 Car Rental System

![Version](https://img.shields.io/badge/version-2.0-blue.svg)
![Platform](https://img.shields.io/badge/platform-Windows-green.svg)
![Language](https://img.shields.io/badge/language-C%2B%2B%2FCLI-orange.svg)

---

## 📖 Overview

Car Rental System is a comprehensive desktop application for managing vehicle rental operations. Built with **C++/CLI** and **Windows Forms**, this system provides a complete solution for car rental businesses to manage their fleet, customers, rentals, returns, and invoices.

The system is **fully portable** and uses **text files** for data storage, requiring no database installation (no SQL Server, no XAMPP).

---

## ✨ Features

### 🔐 Splash Screen
- Professional startup screen
- Secure admin access indicator
- Smooth transition to dashboard

### 📊 Dashboard
- Real-time statistics cards:
  - Total Cars in Fleet
  - Available Cars
  - Total Customers
  - Active Rentals
- Recent Rentals table with VIEW and DELETE actions
- Utilization trends display
- Top performing vehicle categories with progress bars
- Fleet expansion announcements

### 🚗 Cars Management
- Add new cars (automatic ID generation)
- Edit existing car details
- Delete cars with confirmation
- Filter cars by type: ALL, SEDAN, SUV
- Real-time stats update
- Data persistence in `cars.txt`
- Statistics cards: Total Fleet, Available, On Rental, Maintenance

### 👥 Customers Management
- Add new customers
- Edit customer information
- Delete customers with confirmation
- View customer details
- Generate customer invoices
- Data persistence in `customers.txt`
- Statistics cards: Total Customers, Active Rentals, Compliance Rate, New This Month
- Recent activity panel
- System alerts for expired documents

### 📅 Rentals Management
- Select customer from dropdown (loaded from file)
- Select car with price display (loaded from file)
- Set rental days and start date
- Automatic cost calculation:
  - Daily Rate Base
  - Insurance Premium (10%)
  - Total Estimate
- Additional notes field
- Save rental to `rentals.txt`
- Real-time price update on selection change

### 🔄 Returns Management
- Select customer and car from dropdowns
- Display active rental information
- Extra charges calculation dynamically:
  - Smoking detection fee (+$150)
  - Fuel surcharge (if not full)
  - Damage deduction
- Real-time total calculation
- Return confirmation with summary
- Progress saving functionality

### 📄 Invoices
- Auto-generated invoice number
- Customer information display
- Rental details
- Itemized charges table
- Save as TXT file
- Print-ready format
- Professional layout with company info

### 🗂️ Data Storage
All data is stored in simple **text files** inside the `Data` folder:

| File | Columns |
|------|---------|
| `cars.txt` | CarID, Model, Type, DailyRate, Status |
| `customers.txt` | CustomerID, Name, Email, Phone, Status |
| `rentals.txt` | RentalNo, CustomerID, CarID, StartDate, EndDate, Days, Total, Status |

---

## 🛠️ Technology Stack

| Component | Technology |
|-----------|------------|
| Language | C++/CLI (.NET Framework 4.8) |
| UI Framework | Windows Forms |
| Data Storage | Text Files (CSV format) |
| IDE | Visual Studio 2022 |
| Platform | Windows 10/11 (x64) |

---

## 📁 Project Structure

```text
CarRentalSystem/
├── Data/
│ ├── cars.txt
│ ├── customers.txt
│ └── rentals.txt
├── Forms/
│ ├── SplashForm.h
│ ├── DashboardForm.h
│ ├── CarsForm.h
│ ├── CustomersForm.h
│ ├── RentalsForm.h
│ ├── ReturnsForm.h
│ └── InvoiceForm.h
├── Helpers/
│ └── FileHelper.h
├── Program.cpp
└── CarRentalSystem.sln
```
---

## 🚀 Installation & Setup

### Prerequisites
- Windows 10/11 (64-bit)
- .NET Framework 4.8 or higher
- Visual Studio 2022 (for development)

### Steps to Run

1. **Clone or download** the project
2. **Open** `CarRentalSystem.sln` in Visual Studio 2022
3. **Build** the solution (Ctrl+Shift+B)
4. **Run** the application (F5)

### First Time Setup

The `Data` folder and text files will be created automatically on first run. 
For initial data, you can manually create:

### Data\cars.txt
### Data\customers.txt
### Data\rentals.txt


---

## 🎮 How to Use

### 1. Start the Application
- Run `CarRentalSystem.exe`
- Click **Enter Dashboard** to access the main menu

### 2. Manage Cars
- Navigate to **CARS** from sidebar
- Click **ADD CAR** to add new vehicle
- Click **DELETE** to remove a car (with confirmation)
- Use **ALL, SEDAN, SUV** filters to view specific types
- View statistics cards (Total Fleet, Available, On Rental, Maintenance)

### 3. Manage Customers
- Navigate to **CUSTOMERS**
- Click **ADD CUSTOMER** to add new customer
- Use **EDIT** to modify customer details
- Use **DELETE** to remove a customer (with confirmation)
- Use **VIEW** to see customer details
- Use **INVOICE** to generate customer invoice

### 4. Create Rental
- Navigate to **RENTALS**
- Select customer from dropdown
- Select car from dropdown (prices auto-load)
- Set rental days (minimum 1, maximum 365)
- Select start date
- Cost calculates automatically
- Add additional notes if needed
- Click **CONFIRM RENTAL** to save

### 5. Process Return
- Navigate to **RETURNS**
- Select customer from dropdown
- Select car from dropdown
- Active rental information auto-loads
- Set extra charges:
  - Check "Smoking detected" for $150 fee
  - Adjust fuel surcharge as needed
  - Adjust damage deduction as needed
- Click **RETURN VEHICLE** to complete
- Use **SAVE PROGRESS** to save current state

### 6. Generate Invoice
- From Customers form, click **INVOICE** button
- Invoice opens with customer data
- Rental details auto-populate
- Click **PRINT INVOICE** to save as TXT file
- Click **CLOSE** to return

---

## 🔧 Troubleshooting

| Issue | Solution |
|-------|----------|
| "Could not find Data folder" | Create `Data` folder manually next to the `.exe` file |
| No data showing in tables | Ensure text files exist in `Data` folder with proper CSV format |
| Car model shows "Unknown" | Check if CarID in rentals.txt matches a car in cars.txt |
| Customer name shows "Unknown" | Check if CustomerID in rentals.txt matches a customer in customers.txt |
| Build errors | Clean solution (Build → Clean Solution) then Rebuild |
| LINK errors | Ensure all required .cpp files are included in the project |

---

## 📈 Future Enhancements

- [ ] Migrate to SQLite database for better performance
- [ ] User authentication system with roles
- [ ] Reports generation (PDF/Excel)
- [ ] Email notifications for rentals and returns
- [ ] Backup and restore functionality
- [ ] Dark mode theme
- [ ] Search and advanced filtering
- [ ] Printable reports with charts

---

## 🗂️ Helper Functions Reference

### FileHelper.h
```cpp
static List<String^>^ ReadAllLines(String^ fileName);
static void WriteAllLines(String^ fileName, List<String^>^ lines);
