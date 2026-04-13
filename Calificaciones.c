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

    // Calcular promedios por estudiante
    for (int i = 0; i < ESTUDIANTES; i++) {
        float suma = 0;
        maxEstudiante[i] = calificaciones[i][0];
        minEstudiante[i] = calificaciones[i][0];
        for (int j = 0; j < ASIGNATURAS; j++) {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > maxEstudiante[i]) maxEstudiante[i] = calificaciones[i][j];
            if (calificaciones[i][j] < minEstudiante[i]) minEstudiante[i] = calificaciones[i][j];
        }
        promedioEstudiante[i] = suma / ASIGNATURAS;
    }

    // Mostrar resultados
    printf("\n--- Resultados ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f\n",
               i+1, promedioEstudiante[i], maxEstudiante[i], minEstudiante[i]);
    }

   
    return 0;
}

