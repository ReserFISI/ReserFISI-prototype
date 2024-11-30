DO $$ 
BEGIN
    IF NOT EXISTS (SELECT 1 FROM pg_tables WHERE schemaname = 'public' AND tablename = 'alumnos') THEN
        CREATE TABLE "alumnos" (
            "ID_Alumno" SERIAL PRIMARY KEY,
            "Nombre" VARCHAR(100) NOT NULL,
            "Correo_Electronico" VARCHAR(100) NOT NULL UNIQUE,
            "Telefono" VARCHAR(15)
        );
    END IF;

    IF NOT EXISTS (SELECT 1 FROM pg_tables WHERE schemaname = 'public' AND tablename = 'estudiante') THEN
        CREATE TABLE "estudiante" (
            "ID_Estudiante" SERIAL PRIMARY KEY,
            "ID_Alumno" INT NOT NULL,
            FOREIGN KEY ("ID_Alumno") REFERENCES "alumnos"("ID_Alumno") ON DELETE CASCADE
        );
    END IF;

    IF NOT EXISTS (SELECT 1 FROM pg_tables WHERE schemaname = 'public' AND tablename = 'tercio') THEN
        CREATE TABLE "tercio" (
            "ID_Tercio" SERIAL PRIMARY KEY,
            "ID_Alumno" INT NOT NULL,
            "Nombre_Tercio" VARCHAR(100) NOT NULL,
            FOREIGN KEY ("ID_Alumno") REFERENCES "alumnos"("ID_Alumno") ON DELETE CASCADE
        );
    END IF;

    IF NOT EXISTS (SELECT 1 FROM pg_tables WHERE schemaname = 'public' AND tablename = 'espacio') THEN
        CREATE TABLE "espacio" (
            "ID_Espacio" SERIAL PRIMARY KEY,
            "Nombre_Espacio" VARCHAR(100) NOT NULL UNIQUE,
            "Tipo_Espacio" VARCHAR(50),
            "Capacidad" INT
        );
    END IF;

    IF NOT EXISTS (SELECT 1 FROM pg_tables WHERE schemaname = 'public' AND tablename = 'unidad') THEN
        CREATE TABLE "unidad" (
            "ID_Unidad" SERIAL PRIMARY KEY,
            "Nombre" VARCHAR(100) NOT NULL UNIQUE
        );
    END IF;

    IF NOT EXISTS (SELECT 1 FROM pg_tables WHERE schemaname = 'public' AND tablename = 'reserva') THEN
        CREATE TABLE "reserva" (
            "ID_Reserva" SERIAL PRIMARY KEY,
            "ID_Alumno" INT NOT NULL,
            "ID_Espacio" INT NOT NULL,
            "ID_Unidad" INT,
            "Fecha_Solicitud" DATE NOT NULL,
            "Fecha_Reserva" DATE NOT NULL,
            "Estado_Reserva" VARCHAR(50) NOT NULL,
            FOREIGN KEY ("ID_Alumno") REFERENCES "alumnos"("ID_Alumno") ON DELETE CASCADE,
            FOREIGN KEY ("ID_Espacio") REFERENCES "espacio"("ID_Espacio") ON DELETE CASCADE,
            FOREIGN KEY ("ID_Unidad") REFERENCES "unidad"("ID_Unidad") ON DELETE CASCADE
        );
    END IF;

END $$;

/*
-- Insertar datos en la tabla alumnos (si no existen)
INSERT INTO "alumnos" ("Nombre", "Correo_Electronico", "Telefono") VALUES
('Juan Perez', 'juan.perez@email.com', '987654321'),
('Maria Garcia', 'maria.garcia@email.com', '912345678'),
('Carlos Torres', 'carlos.torres@email.com', '923456789'),
('Ana Lopez', 'ana.lopez@email.com', '934567890'),
('Luis Ramirez', 'luis.ramirez@email.com', '945678901');

-- Insertar datos en la tabla estudiante (si no existen)
INSERT INTO "estudiante" ("ID_Alumno") VALUES
(1), (2), (3), (4), (5);

-- Insertar datos en la tabla tercio
INSERT INTO "tercio" ("ID_Alumno", "Nombre_Tercio") VALUES
(1, 'Tercio Superior'),
(2, 'Tercio Medio'),
(3, 'Tercio Inferior'),
(4, 'Cuarto Superior'),
(5, 'Quinto Superior');

-- Insertar datos en la tabla espacio
INSERT INTO "espacio" ("Nombre_Espacio", "Tipo_Espacio", "Capacidad") VALUES
('Aula 101', 'Aula', 30),
('Laboratorio 1', 'Laboratorio', 20),
('Sala de Conferencias', 'Sala', 50),
('Aula 102', 'Aula', 35),
('Laboratorio 2', 'Laboratorio', 25);

-- Insertar datos en la tabla unidad
INSERT INTO "unidad" ("Nombre") VALUES
('Facultad de Ingeniería de Sistemas'),
('Facultad de Ciencias Sociales'),
('Facultad de Derecho'),
('Facultad de Medicina'),
('Facultad de Arquitectura');

-- Insertar datos en la tabla reserva
INSERT INTO "reserva" ("ID_Alumno", "ID_Espacio", "ID_Unidad", "Fecha_Solicitud", "Fecha_Reserva", "Estado_Reserva") VALUES
(1, 1, 1, '2024-09-01', '2024-09-15', 'Pendiente'),
(2, 2, 2, '2024-09-05', '2024-09-18', 'Aprobada'),
(3, 3, 3, '2024-09-07', '2024-09-20', 'Rechazada'),
(4, 4, 4, '2024-09-10', '2024-09-22', 'Aprobada'),
(5, 5, 5, '2024-09-12', '2024-09-25', 'Pendiente');
*/