const express = require('express');
const { Readable } = require('stream');
const app = express();
const jsftp = require('jsftp');
const cors = require('cors');
const multer = require('multer');
const upload = multer();

const ftpDetails = {
  host: 'abuelkheir.freevar.com',
  user: 'abuelkheir.freevar.com',
  pass: '123456',
  port: 21,
};
const ftpClient = new jsftp(ftpDetails);
app.use(cors());
app.use(express.json());
app.use(express.urlencoded({ extended: false }));

app.get('/api', (req, res) => {
  res.send('Hello from API!');
});

app.post('/api/upload', upload.any(), (req, res) => {
  try {
    if (req.files && req.files[0]) {
      const bufferStream = new Readable();
      bufferStream.push(req.files[0].buffer);
      bufferStream.push(null);

      ftpClient.put(
        req.files[0].buffer,
        'embedded/' + req.files[0].originalname,
        (err) => {
          if (!err) {
            console.log('File uploaded to FTP server');
            res.status(200).json({ message: 'File uploaded to FTP server' });
          }
        }
      );
    }
  } catch (e) {
    console.log(e);
    res.status(500).json({ error: 'Failed to upload file to FTP server' });
  }
});

ftpClient.on('connect', () => {
  console.log('Connected to FTP server');
});

ftpClient.on('error', (err) => {
  console.error('FTP error:', err);
});

app.listen(3000, () => {
  console.log('Server is running on port 3000');
});
