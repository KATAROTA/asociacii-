#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Doctor;

class Patient{
	private:
		string p_name;
		vector <Doctor *> m_doctor;
		void addDoctor(Doctor *doc);
	
	public:
		Patient(string name) 
			: p_name(name) {
			cout << "created patient w name " << p_name << endl;
		}
		~Patient() {
			cout << "destructed petient " << p_name << endl;
			
		}
		string getName() const {
			return p_name;
		}
		friend ostream& operator <<(ostream &out, const Patient& pat);
		
		friend class Doctor;
		
		
};


class Doctor {
	private:
		string p_name;
		vector <Patient*> m_patient;
	
	public:
		Doctor(string name) 
			:p_name(name) {
			cout << "docstor war created w name: " << p_name << endl;
			
			
		}
		~Doctor() {
			cout << "Docstor was destructed" << endl;
		}
		void addPatient(Patient *pat) {
			m_patient.push_back(pat);
			pat -> addDoctor(this);
			
			
		}

		friend ostream& operator << (ostream& out, const Doctor& doc) {
			int lenght = doc.m_patient.size();
			if (lenght == 0) {
				out << doc.p_name <<  "no patients for now" << endl;
				return out;		
			}
			out << doc.p_name << " is seeing patients ";
			for (int count=0; count < lenght; ++count) {
				out << doc.m_patient[count] ->getName() + " ";
				
				
			}
			return out;
		}
			string getName() const {
				return p_name;
			}
			
			
		};
		
void Patient::addDoctor(Doctor* doc) {
	m_doctor.push_back(doc);
	
	 
}
ostream& operator << (ostream& out, const Patient& pat) {
			int lenght = pat.m_doctor.size();
			if (lenght == 0) {
				out << pat.p_name <<  "no doctor for now" << endl;
				return out;		
			}
			out << pat.p_name << " is seeing doctors";
			for (int count=0; count < lenght; ++count) {
				out << pat.m_doctor[count] ->getName() + " ";
				
				
			}
			return out;
		}
			
	
		
		
		
int main() {
	Patient *p1 = new Patient("Anton");
	Patient *p2 = new Patient("lexa");
	Patient *p3 = new Patient("soshue");
	Patient *p4 = new Patient("naidihui");
	Doctor *d1 = new Doctor("Dr.George");
	Doctor *d2 = new Doctor("Dr.Renni");
	d2->addPatient(p1);
	d1->addPatient(p2);
	d2->addPatient(p3);
	d1->addPatient(p4);
	
	cout << *d1 <<endl;
	cout << "----------------------------" <<endl;
	cout << *d2 <<endl;
	
	
	
	
}
