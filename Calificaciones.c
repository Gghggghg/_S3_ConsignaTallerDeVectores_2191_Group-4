#include <stdio.h>
#define ESTUDIANTES 5
#define ASIGNATURAS 3

int main() {
    float calificaciones[ESTUDIANTES][ASIGNATURAS];
    float promedioEstudiante[ESTUDIANTES];
    float promedioAsignatura[ASIGNATURAS];
    float maxEstudiante[ESTUDIANTES], minEstudiante[ESTUDIANTES];
    float maxAsignatura[ASIGNATURAS], minAsignatura[ASIGNATURAS];
    int aprobados[ASIGNATURAS], reprobados[ASIGNATURAS];
    int estudianteMaxAsignatura[ASIGNATURAS], estudianteMinAsignatura[ASIGNATURAS];

    // Entrada de datos con validación
    for (int i = 0; i < ESTUDIANTES; i++) {
        for (int j = 0; j < ASIGNATURAS; j++) {
            do {
                printf("Ingrese la calificacion del estudiante %d en la asignatura %d (0-10): ", i+1, j+1);
                scanf("%f", &calificaciones[i][j]);
            } while (calificaciones[i][j] < 0 || calificaciones[i][j] > 10);
        }
    }
   
    return 0;
}

