inline char NC(void)
{
  static char buf[100000], *p1 = buf, *p2 = buf;
  if (p1 == p2) {
    p2 = (p1 = buf) + fread(buf, 1, 100000, stdin);
    if (p1 == p2) return EOF;
  }
  return *p1++;
}

inline void readInt(int &x) {
    static char c; c = NC(); 
    static int minus; minus = 1;
    for (x = 0; !(c >= '0' && c <= '9'); c = NC()) if(c == '-') minus = -1;
    for (; c >= '0' && c <= '9'; x = x * 10 + c - '0', c = NC()); x *= minus;
}

