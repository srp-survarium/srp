unsigned int __usercall bio_nread0@<eax>(bio_st *bio@<ecx>, char **buf@<edi>)
{
  unsigned int result; // eax
  _DWORD *v4; // ecx
  int v5; // esi
  unsigned int v6; // edx
  char v7; // [esp+7h] [ebp-1h] BYREF

  BIO_clear_flags(bio, 15);
  if ( !bio->init )
    return 0;
  v4 = *(_DWORD **)(*(_DWORD *)bio->ptr + 32);
  result = v4[2];
  v4[6] = 0;
  if ( !result )
    return bio_read(bio, &v7, 1u);
  v5 = v4[3];
  v6 = v4[4];
  if ( v6 < v5 + result )
    result = v6 - v5;
  if ( buf )
    *buf = (char *)(v5 + v4[5]);
  return result;
}
