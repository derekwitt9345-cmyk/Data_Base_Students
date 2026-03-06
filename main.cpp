#include <iostream>
#include <cstring>

// Program made by Derek Witt \(^_^)/

class person {
protected:
    std::string name;
    std::string code;
    std::string email;
    std::string direction;
    std::string phone_number;
public:
    void enter();
    void exit();
    void search();
};

class professor : person {
protected:
    std::string ingress_date;
    std::string horary;
    std::string type;
public:
    void enter();
    void exit();
    void search(professor* professor_arreglo, int p_size);
    void errase(professor* professor_arreglo, int p_size);
};

class student : person {
protected:
    std::string credits;
    std::string promed;
    std::string major;
    std::string status;
public:
    void enter();
    void exit();
    void search(student* student_arreglo, int s_size);
    void errase(student* student_arreglo, int s_size);
};

// Entrada de datos de Clase padre [person]

void person::enter() {
    std::cout << "\nIngrese nombre: ";
     std::cin >> name;
    std::cout << "\nIngrese codigo: ";
     std::cin >> code;
    std::cout << "\nIngrese correo electronico: ";
     std::cin >> email;
    std::cout << "\nIngrese direccion: ";
     std::cin >> direction;
    std::cout << "\nNumero de telefono: ";
     std::cin >> phone_number;
}

// Salida de datos de Clase padre [person]

void person::exit() {
    std::cout << "\nNombre: " << name << "\nCodigo: " << code << "\nCorreo Electronico: " << email << "\nDireccion: " << direction << "\nNumero de telefono: " << phone_number << std::endl;
}

// Entrada de datos de Clase hija [professor]

void professor::enter() {
    person::enter();
    std::cout << "\nIngrese fecha de ingreso: ";
     std::cin >> ingress_date;
    std::cout << "\nIngrese horario: ";
     std::cin >> horary;
    std::cout << "\nIngrese tipo: ";
     std::cin >> type;
}

// Salida de datos de Clase hija [professor]

void professor::exit() {
    person::exit();
    std::cout << "\nFecha de ingreso: " << ingress_date << "\nHorario: " << horary << "\nType: " << type << std::endl;
}

// Busqueda de profesor

void professor::search(professor* professor_arreglo, int p_size) {
    std::string comparator;
    bool finded = false;
    std::cout << "\nCodigo Profesor: ";
    std::cin >> comparator;
    for (int i = 0; i < p_size && finded == false; i++) {
        if(comparator == professor_arreglo[i].code) {
            finded = true;
            std::cout << "Profesor " << i + 1 << " : ";
            professor_arreglo[i].exit();
            break;
        }
    }
    if (!finded) {
        std::cout << "\nNo encontrado. . ." << std::endl;
    }
}

// Elimina un Profesor de la base de datos

void professor::errase(professor* professor_arreglo, int p_size) {
    std::string comparator;
    bool finded = false;
    int bin = -1;
    std::cout << "\nCodigo Profesor: ";
    std::cin >> comparator;
    for (int i = 0; i < p_size && finded == false; i++) {
        if(comparator == professor_arreglo[i].code) {
            finded = true;
            bin = i;
            break;
        }
    }
    if (!finded) {
        std::cout << "\nNo encontrado. . ." << std::endl;
    }
    if (finded == true) {
        for (int i = bin; i < p_size - 1; i++) {
            professor_arreglo[i] = professor_arreglo[i + 1];
        }
        std::cout << "\nEliminado exitosamente. . .";
    }
    p_size--;
}

// Entrada de datos de Clase hija [student]

void student::enter() {
    person::enter();
    std::cout << "\nIngrese Promedio: ";
     std::cin >> promed;
    std::cout << "\nIngrese Creditos: ";
     std::cin >> credits;
    std::cout << "\nIngrese Carrera: ";
     std::cin >> major;
    std::cout << "\nIngrese Estatus: ";
     std::cin >> status;
}

// Salida de datos de Calse hija [student]

void student::exit() {
    person::exit();
    std::cout << "\nPromedio: " << promed << "\nCreditos: " << credits << "\nCarrera: " << major << "\nEstatus: " << status << std::endl;
}

// Busque da de estudiante

void student::search(student* student_arreglo, int s_size) {
    std::string comparator;
    bool finded = false;
    std::cout << "\nCodigo Estudiante: ";
    std::cin >> comparator;
    for (int i = 0; i < s_size && finded == false; i++) {
        if(comparator == student_arreglo[i].code) {
            finded = true;
            std::cout << "Estudiante " << i + 1 << " : ";
            student_arreglo[i].exit();
            break;
        }
    }
    if (!finded) {
        std::cout << "\nNo encontrado. . ." << std::endl;
    }
}

// Eliminar estudiante de la base de datos

void student::errase(student* student_arreglo, int s_size) {
    std::string comparator;
    bool finded = false;
    int bin = -1;
    std::cout << "\nCodigo Estudiante: ";
    std::cin >> comparator;
    for (int i = 0; i < s_size && finded == false; i++) {
        if(comparator == student_arreglo[i].code) {
            finded = true;
            bin = i;
            break;
        }
    }
    if (!finded) {
        std::cout << "\nNo encontrado. . ." << std::endl;
    }
    if (finded == true) {
        for (int i = bin; i < s_size - 1; i++) {
            student_arreglo[i] = student_arreglo[i + 1];
        }
        std::cout << "\nEliminado Exitosamente. . .";
    }
    s_size--;
}


int main(){
    int p_size = 10, s_size = 10, extra = 0, x = 0, i = 0;
    professor* professor_arreglo = nullptr;
    student* student_arreglo = nullptr;
    do {
        std::cout << "\n===== Base de Datos ====="
                     "\n1 - Ingreso de Profesores"
                     "\n2 - Salida de Profesores"
                     "\n3 - Ingreso de Estudiantes"
                     "\n4 - Salida de Estudiantes"
                     "\n5 - Buscar Estudiantes"
                     "\n6 - Buscar Profesores"
                     "\n7 - Eliminar Estudiante"
                     "\n8 - Eliminar Profesor"
                     "\n9 - Exit\n";
        std::cin >> x;
        switch (x) {
            case 1: {
                if (professor_arreglo != nullptr) {
                    delete[] professor_arreglo;
                    professor_arreglo = nullptr;
                }
                if (p_size > i) {
                    professor_arreglo = new professor[p_size];
                    std::cout << "\nProfesor " << i + 1 << " : ";
                    professor_arreglo[i].enter();
                    i++;
                }
                else {
                    std::cout << "\nIngrese nueva cantidad de Profesores : ";
                    std::cin >> extra;
                    p_size += extra;
                }
                break;
            }
            case 2: {
                if (professor_arreglo != nullptr) {
                    for (i = 0; i < p_size; i++) {
                        std::cout << "\nProfesor " << i + 1 << " : ";
                        professor_arreglo[i].exit();
                    }
                }
                else {
                    std::cout << "\nData Error. . ." << std::endl;
                }
                break;
            }
            case 3: {
                if (student_arreglo != nullptr) {
                    delete[] student_arreglo;
                    student_arreglo = nullptr;
                }
                if (s_size > i) {
                    student_arreglo = new student[s_size];
                    std::cout << "\nEstudiante " << i + 1 << " : ";
                    student_arreglo[i].enter();
                    i++;
                }
                else {
                    std::cout << "\nIngrese nueva cantidad de Alumnos [defualt: 10] : ";
                    std::cin >> extra;
                    s_size += extra;
                }
                break;
            }
            case 4: {
                if (student_arreglo != nullptr) {
                    for (i = 0; i < s_size; i++) {
                        std::cout << "\nEstudiante " << i + 1 << " : ";
                        student_arreglo[i].exit();
                    }
                }
                else {
                    std::cout << "\nData Error. . ." << std::endl;
                }
                break;
            }
            case 5: {
                student_arreglo[0].search(student_arreglo, s_size);
                break;
            }
            case 6: {
                professor_arreglo[0].search(professor_arreglo, p_size);
                break;
            }
            case 7: {
                student_arreglo[0].errase(student_arreglo, s_size);
                break;
            }
            case 8: {
                professor_arreglo[0].errase(professor_arreglo, p_size);
                break;
            }
            default: {
                std::cout << "A salido con exito. . .\n";
            }
        }
    }
    while (x != 9);
    return 0;
}
