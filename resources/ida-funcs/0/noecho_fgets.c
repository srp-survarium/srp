unsigned int __usercall noecho_fgets@<eax>(char *buf@<ebx>, int size@<ecx>)
{
  int v2; // edi
  char *v3; // esi
  int v4; // eax
  HANDLE StdHandle; // eax

  v2 = size;
  v3 = buf;
  if ( size )
  {
    do
    {
      --v2;
      v4 = _getch();
      if ( v4 == 13 )
        v4 = 10;
      *v3++ = v4;
    }
    while ( v4 != 10 && v2 );
  }
  *v3 = 0;
  StdHandle = GetStdHandle(0xFFFFFFF6);
  FlushConsoleInputBuffer(StdHandle);
  return strlen(buf);
}
