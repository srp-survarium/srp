unsigned int __userpurge xtoa_s@<eax>(
        unsigned int val@<eax>,
        char *buf@<ecx>,
        char *a3@<edi>,
        unsigned int sizeInTChars,
        unsigned int radix,
        int is_neg)
{
  char *v6; // esi
  int *v8; // eax
  char v9; // dl
  unsigned int v10; // et2
  char v11; // dl
  char *v12; // ecx
  char v13; // al
  unsigned int v14; // [esp-8h] [ebp-14h]
  unsigned int length; // [esp+8h] [ebp-4h]

  v6 = buf;
  if ( !buf )
  {
    *_errno() = 22;
    _invalid_parameter(0, (unsigned int)a3, 0x16u);
    return 22;
  }
  if ( !sizeInTChars )
    goto LABEL_4;
  *buf = 0;
  if ( sizeInTChars <= (unsigned int)(is_neg != 0) + 1 )
  {
LABEL_7:
    v8 = _errno();
    v14 = 34;
    goto LABEL_5;
  }
  if ( radix - 2 > 0x22 )
  {
LABEL_4:
    v8 = _errno();
    v14 = 22;
LABEL_5:
    *v8 = v14;
    _invalid_parameter(0, (unsigned int)a3, v14);
    return v14;
  }
  length = 0;
  if ( is_neg )
  {
    *buf++ = 45;
    length = 1;
    val = -val;
  }
  a3 = buf;
  do
  {
    v10 = val % radix;
    val /= radix;
    v9 = v10;
    if ( v10 <= 9 )
      v11 = v9 + 48;
    else
      v11 = v9 + 87;
    *buf++ = v11;
    ++length;
  }
  while ( val && length < sizeInTChars );
  if ( length >= sizeInTChars )
  {
    *v6 = 0;
    goto LABEL_7;
  }
  *buf = 0;
  v12 = buf - 1;
  do
  {
    v13 = *v12;
    *v12-- = *a3;
    *a3++ = v13;
  }
  while ( a3 < v12 );
  return 0;
}
