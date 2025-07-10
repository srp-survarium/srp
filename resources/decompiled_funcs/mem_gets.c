int __cdecl mem_gets(bio_st *bp, char *buf, int size)
{
  int *ptr; // esi
  int v4; // ecx
  int result; // eax
  int v6; // esi
  unsigned int v7; // eax

  ptr = (int *)bp->ptr;
  BIO_clear_flags(bp, 15);
  v4 = *ptr;
  if ( size - 1 < *ptr )
    v4 = size - 1;
  if ( v4 > 0 )
  {
    v6 = ptr[1];
    v7 = 0;
    while ( *(_BYTE *)(v7 + v6) != 10 )
    {
      if ( (int)++v7 >= v4 )
        goto LABEL_10;
    }
    ++v7;
LABEL_10:
    result = mem_read(bp, buf, v7);
    if ( result > 0 )
      buf[result] = 0;
  }
  else
  {
    *buf = 0;
    return 0;
  }
  return result;
}
