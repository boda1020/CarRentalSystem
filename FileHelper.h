#pragma once
using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

public ref class FileHelper
{
public:
    static List<String^>^ ReadAllLines(String^ fileName)
    {
        List<String^>^ lines = gcnew List<String^>();
        String^ path = Application::StartupPath + "\\Data\\" + fileName;

        if (File::Exists(path))
        {
            StreamReader^ reader = gcnew StreamReader(path);
            while (!reader->EndOfStream)
                lines->Add(reader->ReadLine());
            reader->Close();
        }
        return lines;
    }

    static void WriteAllLines(String^ fileName, List<String^>^ lines)
    {
        String^ path = Application::StartupPath + "\\Data\\" + fileName;
        StreamWriter^ writer = gcnew StreamWriter(path);
        for each (String ^ line in lines)
            writer->WriteLine(line);
        writer->Close();
    }
};