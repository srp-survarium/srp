void __usercall swap(char *a@<eax>, char *b@<ecx>, unsigned int width@<edx>)
{
  unsigned int v3; // esi
  char v4; // dl

  v3 = width;
  if ( a != b && width )
  {
    do
    {
      v4 = *a;
      *a = *b;
      --v3;
      *b = v4;
      ++a;
      ++b;
    }
    while ( v3 );
  }
}
