int __cdecl load_iv(char **fromp, unsigned __int8 *to)
{
  int num; // ecx
  int v3; // esi
  char *v4; // edi
  int v5; // ebp
  int v6; // esi
  char v7; // al
  char v8; // bl
  char v9; // bl
  unsigned __int8 *v10; // eax

  v3 = num;
  v4 = *fromp;
  if ( num > 0 )
    memset((int)to, 0, num);
  v5 = 2 * v3;
  v6 = 0;
  if ( v5 <= 0 )
  {
LABEL_14:
    *fromp = v4;
    return 1;
  }
  while ( 1 )
  {
    v7 = *v4;
    if ( *v4 < 48 || v7 > 57 )
      break;
    v8 = v7 - 48;
LABEL_13:
    v9 = v8 << (4 * ((v6 & 1) == 0));
    v10 = &to[v6 / 2];
    ++v6;
    *v10 |= v9;
    ++v4;
    if ( v6 >= v5 )
      goto LABEL_14;
  }
  if ( v7 >= 65 && v7 <= 70 )
  {
    v8 = v7 - 55;
    goto LABEL_13;
  }
  if ( v7 >= 97 && v7 <= 102 )
  {
    v8 = v7 - 87;
    goto LABEL_13;
  }
  ERR_put_error(9u, 101, 103, ".\\crypto\\pem\\pem_lib.c", 557);
  return 0;
}
