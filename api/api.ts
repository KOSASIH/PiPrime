import express, { Request, Response } from 'express';
import bodyParser from 'body-parser';

interface User {
  id: string;
  name: string;
  email: string;
}

const users: User[] = [
  { id: '1', name: 'John Doe', email: 'john@example.com' },
  { id: '2', name: 'Jane Doe', email: 'jane@example.com' },
];

const app = express();
app.use(bodyParser.json());

app.get('/users', (req: Request, res: Response) => {
  res.json(users);
});

app.get('/users/:id', (req: Request, res: Response) => {
  const id = req.params.id;
  const user = users.find((u) => u.id === id);
  if (user) {
    res.json(user);
  } else {
    res.status(404).json({ error: 'User not found' });
  }
});

app.post('/users', (req: Request, res: Response) => {
  const user: User = req.body;
  users.push(user);
  res.json({ message: 'User created' });
});

app.put('/users/:id', (req: Request, res: Response) => {
  const id = req.params.id;
  const user: User = req.body;
  const idx = users.findIndex((u) => u.id === id);
  if (idx !== -1) {
    users[idx] = user;
    res.json({ message: 'User updated' });
  } else {
    res.status(404).json({ error: 'User not found' });
  }
});

app.delete('/users/:id', (req: Request, res: Response) => {
  const id = req.params.id;
  const idx = users.findIndex((u) => u.id === id);
  if (idx !== -1) {
    users.splice(idx, 1);
    res.json({ message: 'User deleted' });
  } else {
    res.status(404).json({ error: 'User not found' });
  }
});

app.listen(3000, () => {
  console.log('Server started on port 3000');
});
