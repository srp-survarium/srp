int __usercall destroy_mspace@<eax>(char *msp@<eax>)
{
  int v1; // ebx
  char *v2; // esi
  int v3; // eax
  void *v4; // ecx
  unsigned int v5; // edi

  v1 = 0;
  v2 = msp + 444;
  if ( msp != (char *)-444 )
  {
    do
    {
      v3 = *((_DWORD *)v2 + 3);
      v4 = *(void **)v2;
      v5 = *((_DWORD *)v2 + 1);
      v2 = (char *)*((_DWORD *)v2 + 2);
      if ( (v3 & 1) != 0 && (v3 & 8) == 0 && !munmap((virtual_alloc_arena *)v5, v4, v5) )
        v1 += v5;
    }
    while ( v2 );
  }
  return v1;
}
