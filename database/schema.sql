CREATE TABLE productos (
    id SERIAL PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    precio NUMERIC(10,2) NOT NULL,
    stock INT NOT NULL,
    fecha_ingreso DATE NOT NULL,
    tipo VARCHAR(20) NOT NULL,
    es_organico BOOLEAN,
    requiere_refrigeracion BOOLEAN,
    fecha_caducidad DATE
);
