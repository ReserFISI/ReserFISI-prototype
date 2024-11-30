import React, { useState } from "react";
import {
  Box,
  Button,
  Table,
  TableBody,
  TableCell,
  TableContainer,
  TableHead,
  TableRow,
  Paper,
  Typography,
  TextField,
  Dialog,
  DialogActions,
  DialogContent,
  DialogTitle,
} from "@mui/material";

interface Alumno {
  id: number;
  nombre: string;
  correo: string;
  telefono: string;
}

interface Reserva {
  id: number;
  fechaSolicitud: string;
  fechaReserva: string;
  estado: string;
}

const ReserFISI: React.FC = () => {
  const [alumnos, setAlumnos] = useState<Alumno[]>([]);
  const [reservas, setReservas] = useState<Reserva[]>([]);
  const [popupAlumno, setPopupAlumno] = useState(false);
  const [popupReserva, setPopupReserva] = useState(false);

  const handleAddAlumno = () => {
    setPopupAlumno(true);
  };

  const handleDeleteAlumno = (id: number) => {
    setAlumnos((prev) => prev.filter((alumno) => alumno.id !== id));
  };

  const handleAddReserva = () => {
    setPopupReserva(true);
  };

  const handleEditReserva = (id: number) => {
    setPopupReserva(true);
  };

  const handleDeleteReserva = (id: number) => {
    setReservas((prev) => prev.filter((reserva) => reserva.id !== id));
  };

  return (
    <Box sx={{ padding: 4, backgroundColor: "#3366FF", color: "#fff", height: "100vh", width: "100%", display: "flex", flexDirection: "column"}}>
      <Typography variant="h4" align="center" gutterBottom>
        ReserFISI
      </Typography>
      <Box display="flex" justifyContent="space-between" gap={4}>
        {/* Tabla de los alumnos */}
        <Box flex={1}>
          <Typography variant="h6" align="center">Alumnos</Typography>
          <TableContainer component={Paper}>
            <Table stickyHeader>
              <TableHead>
                <TableRow>
                  <TableCell>ID</TableCell>
                  <TableCell>Nombre</TableCell>
                  <TableCell>Correo</TableCell>
                  <TableCell>Teléfono</TableCell>
                  <TableCell>Acciones</TableCell>
                </TableRow>
              </TableHead>
              <TableBody>
                {alumnos.map((alumno) => (
                  <TableRow key={alumno.id}>
                    <TableCell>{alumno.id}</TableCell>
                    <TableCell>{alumno.nombre}</TableCell>
                    <TableCell>{alumno.correo}</TableCell>
                    <TableCell>{alumno.telefono}</TableCell>
                    <TableCell>
                      <Button
                        variant="contained"
                        color="error"
                        onClick={() => handleDeleteAlumno(alumno.id)}
                      >
                        Eliminar
                      </Button>
                    </TableCell>
                  </TableRow>
                ))}
              </TableBody>
            </Table>
          </TableContainer>
          <Button
            variant="contained"
            color="primary"
            fullWidth
            onClick={handleAddAlumno}
            sx={{ marginTop: 2 }}
          >
            Añadir
          </Button>
        </Box>

        {/* Tabla de las reservas */}
        <Box flex={1}>
          <Typography variant="h6" align="center">Reservas</Typography>
          <TableContainer component={Paper}>
            <Table stickyHeader>
              <TableHead>
                <TableRow>
                  <TableCell>ID</TableCell>
                  <TableCell>Fecha de Solicitud</TableCell>
                  <TableCell>Fecha de Reserva</TableCell>
                  <TableCell>Estado</TableCell>
                  <TableCell>Acciones</TableCell>
                </TableRow>
              </TableHead>
              <TableBody>
                {reservas.map((reserva) => (
                  <TableRow key={reserva.id}>
                    <TableCell>{reserva.id}</TableCell>
                    <TableCell>{reserva.fechaSolicitud}</TableCell>
                    <TableCell>{reserva.fechaReserva}</TableCell>
                    <TableCell>{reserva.estado}</TableCell>
                    <TableCell>
                      <Button
                        variant="contained"
                        color="secondary"
                        onClick={() => handleEditReserva(reserva.id)}
                        sx={{ marginRight: 1 }}
                      >
                        Editar
                      </Button>
                      <Button
                        variant="contained"
                        color="error"
                        onClick={() => handleDeleteReserva(reserva.id)}
                      >
                        Eliminar
                      </Button>
                    </TableCell>
                  </TableRow>
                ))}
              </TableBody>
            </Table>
          </TableContainer>
          <Button
            variant="contained"
            color="primary"
            fullWidth
            onClick={handleAddReserva}
            sx={{ marginTop: 2 }}
          >
            Añadir
          </Button>
        </Box>
      </Box>

      {/* Popup para añadir nuevo alumno,  */}
      <Dialog open={popupAlumno} onClose={() => setPopupAlumno(false)}>
        <DialogTitle>Añadir Alumno</DialogTitle>
        <DialogContent>
          <TextField fullWidth label="Nombre" margin="dense" />
          <TextField fullWidth label="Correo" margin="dense" />
          <TextField fullWidth label="Teléfono" margin="dense" />
        </DialogContent>
        <DialogActions>
          <Button onClick={() => setPopupAlumno(false)}>Cancelar</Button>
          <Button onClick={() => setPopupAlumno(false)} color="primary">
            Guardar
          </Button>
        </DialogActions>
      </Dialog>
      {/* Popup para añadir nueva reserva,  */}
      <Dialog open={popupReserva} onClose={() => setPopupReserva(false)}>
        <DialogTitle>Ver reserva</DialogTitle>
        <DialogContent>
          <TextField fullWidth label="Fecha de solicitud" margin="dense" />
          <TextField fullWidth label="Fecha de reserva" margin="dense" />
          <TextField fullWidth label="Estado" margin="dense" />
          <TextField fullWidth label="Alumno solicitante" margin="dense" />
          <TextField fullWidth label="Espacio solicitado" margin="dense" />
        </DialogContent>
        <DialogActions>
          <Button onClick={() => setPopupReserva(false)}>Cancelar</Button>
          <Button onClick={() => setPopupReserva(false)} color="primary">
            Guardar
          </Button>
        </DialogActions>
      </Dialog>
    </Box>
  );
};

export default ReserFISI;