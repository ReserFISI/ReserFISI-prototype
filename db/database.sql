DO $$
BEGIN
    IF NOT EXISTS (SELECT FROM pg_database WHERE datname = 'Papulince') THEN
        EXECUTE 'CREATE DATABASE Papulince';
    END IF;
END $$;

CREATE TABLE Alumnos (
    ID_Estudiante INT PRIMARY KEY,
    Nombre VARCHAR(100) NOT NULL,
    Correo_Electronico VARCHAR(100) NOT NULL,
    Telefono VARCHAR(15)
);

CREATE TABLE Espacio (
    ID_Espacio INT PRIMARY KEY,
    Nombre_Espacio VARCHAR(100) NOT NULL,
    Tipo_Espacio VARCHAR(50),
    Capacidad INT
);

CREATE TABLE Reserva (
    ID_Reserva INT PRIMARY KEY,
    Fecha_Solicitud DATE NOT NULL,
    Fecha_Reserva DATE NOT NULL,
    Estado_Reserva VARCHAR(50) NOT NULL
);

CREATE TABLE Unidad (
    ID_Unidad INT PRIMARY KEY,
    Nombre VARCHAR(100) NOT NULL
);

CREATE TABLE Tercio (
    ID_Tercio INT PRIMARY KEY,
    Nombre VARCHAR(100) NOT NULL
);


INSERT INTO Alumnos (ID_Estudiante, Nombre, Correo_Electronico, Telefono) VALUES
(1, 'Juan Perez', 'juan.perez@email.com', '987654321'),
(2, 'Maria Garcia', 'maria.garcia@email.com', '912345678'),
(3, 'Carlos Torres', 'carlos.torres@email.com', '923456789'),
(4, 'Ana Lopez', 'ana.lopez@email.com', '934567890'),
(5, 'Luis Ramirez', 'luis.ramirez@email.com', '945678901');

INSERT INTO Espacio (ID_Espacio, Nombre_Espacio, Tipo_Espacio, Capacidad) VALUES
(1, 'Aula 101', 'Aula', 30),
(2, 'Laboratorio 1', 'Laboratorio', 20),
(3, 'Sala de Conferencias', 'Sala', 50),
(4, 'Aula 102', 'Aula', 35),
(5, 'Laboratorio 2', 'Laboratorio', 25);

INSERT INTO Reserva (ID_Reserva, Fecha_Solicitud, Fecha_Reserva, Estado_Reserva) VALUES
(1, '2024-09-01', '2024-09-15', 'Pendiente'),
(2, '2024-09-05', '2024-09-18', 'Aprobada'),
(3, '2024-09-07', '2024-09-20', 'Rechazada'),
(4, '2024-09-10', '2024-09-22', 'Aprobada'),
(5, '2024-09-12', '2024-09-25', 'Pendiente');

INSERT INTO Unidad (ID_Unidad, Nombre) VALUES
(1, 'Facultad de Ingeniería de Sistemas'),
(2, 'Facultad de Ciencias Sociales'),
(3, 'Facultad de Derecho'),
(4, 'Facultad de Medicina'),
(5, 'Facultad de Arquitectura');

INSERT INTO Tercio (ID_Tercio, Nombre) VALUES
(1, 'Tercio Superior'),
(2, 'Tercio Medio'),
(3, 'Tercio Inferior'),
(4, 'Cuarto Superior'),
(5, 'Quinto Superior');