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
            //y encontrar maximos y minimos por estudiante
            if (calificaciones[i][j] > maxEstudiante[i]) maxEstudiante[i] = calificaciones[i][j];
            if (calificaciones[i][j] < minEstudiante[i]) minEstudiante[i] = calificaciones[i][j];
        }
        promedioEstudiante[i] = suma / ASIGNATURAS;
    }
   // Calcular promedios por asignatura   
    for (int j = 0; j < ASIGNATURAS; j++) {
    for (int j = 0; j < ASIGNATURAS; j++) {
        float suma = 0;
        maxAsignatura[j] = calificaciones[0][j];
        minAsignatura[j] = calificaciones[0][j];
        estudianteMaxAsignatura[j] = 1;
        estudianteMinAsignatura[j] = 1;
        aprobados[j] = 0;
        reprobados[j] = 0;
//y encontrar maximos y minimos por asignatura,
        for (int i = 0; i < ESTUDIANTES; i++) {
            suma += calificaciones[i][j];
            if (calificaciones[i][j] > maxAsignatura[j]) {
                maxAsignatura[j] = calificaciones[i][j];
                estudianteMaxAsignatura[j] = i+1;
            }
            if (calificaciones[i][j] < minAsignatura[j]) {
                minAsignatura[j] = calificaciones[i][j];
                estudianteMinAsignatura[j] = i+1;
            }
            //ademas de contar aprobados y reprobados  
            if (calificaciones[i][j] >= 6) aprobados[j]++;
            else reprobados[j]++;
        }
        promedioAsignatura[j] = suma / ESTUDIANTES;
    }

    // Mostrar resultados
    printf("\n--- Resultados ---\n");
    for (int i = 0; i < ESTUDIANTES; i++) {
        printf("Estudiante %d -> Promedio: %.2f | Max: %.2f | Min: %.2f\n",
               i+1, promedioEstudiante[i], maxEstudiante[i], minEstudiante[i]);
    }

    for (int j = 0; j < ASIGNATURAS; j++) {
        printf("Asignatura %d -> Promedio: %.2f | Max: (%.2f, Estudiante %d) | Min: (%.2f, Estudiante %d) | Aprobados: %d | Reprobados: %d\n",
               j+1, promedioAsignatura[j], maxAsignatura[j], estudianteMaxAsignatura[j],
               minAsignatura[j], estudianteMinAsignatura[j], aprobados[j], reprobados[j]);
    }

    return 0;
}

