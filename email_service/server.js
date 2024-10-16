import express from 'express';
import { Resend } from 'resend';
import dotenv from 'dotenv';
import path from 'path';

const __dirname = path.dirname(new URL(import.meta.url).pathname);

dotenv.config({ path: path.resolve(__dirname, '../.env') });

const app = express();
const resend = new Resend(process.env.RESEND_API_KEY);

app.use(express.json());

app.post('/send-email', async (req, res) => {
    const { email, nombre, codigo } = req.body;
    try {
        const data = await resend.emails.send({
            from: "admin@vizcacha.lol",
            to: [email],
            subject: 'Correo de verificación',
            html: 
`

            <!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>email_message</title>
    <link href='http://fonts.googleapis.com/css?family=Roboto:400,100,100italic,300,300italic,400italic,500,500italic,700,700italic,900italic,900' rel='stylesheet' type='text/css'>
</head>
<body>
    <h1>Gracias por verificar tu correo con nosotros</h1>
    <h3>Hola ${nombre}, haz click al siguiente enlace para verificar tu correo</h3>
    <img src="https://hackathonvirtual.softaki.com/fisi.png" alt="">
</body>
<style>
    body{
        background-color: #ffffff;
    }
    h1{
        color: #000000;
        text-align: center;
        margin-top: 200px;
        font-family: "roboto";
    }
    h3{
        color: #000000;
        text-align: center;
        font-family: "roboto";
    }
    img{
        display: block;
        margin: 0 auto;
        margin-top: 20px;
    }
    a{
        color:#0353a4;
        text-align: center;
        font-family: "roboto";
        display: block;
        text-align: center;
        margin-top: 20px;
        
    }
</style>
</html>` 
        });
        res.json({ message: 'Email sent successfully', data });
    } catch (error) {
        res.status(500).json({ error: 'Error sending email', details: error.message });
    }
});

app.listen(3000, () => console.log('Email service running on http://localhost:3000'));
