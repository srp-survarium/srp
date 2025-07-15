void __userpurge ppmd_allocator::UnitsCpy(char *Dest@<eax>, unsigned int NU@<edx>, ppmd_allocator *this, void *Src)
{
  int v4; // ecx

  v4 = (char *)this - Dest;
  do
  {
    *(_QWORD *)Dest = *(_QWORD *)&Dest[v4];
    *((_DWORD *)Dest + 2) = *(_DWORD *)&Dest[v4 + 8];
    Dest += 12;
    --NU;
  }
  while ( NU );
}
