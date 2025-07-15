int __usercall load_iv@<eax>(int a1@<ecx>, int a2@<ebx>, char **fromp, unsigned __int8 *to)
{
  char *v5; // edi
  int v6; // ebp
  int v7; // esi
  char v8; // al
  unsigned __int8 *v9; // eax

  v5 = *fromp;
  if ( a1 > 0 )
    memset((int)to, 0, a1);
  v6 = 2 * a1;
  v7 = 0;
  if ( v6 <= 0 )
  {
LABEL_14:
    *fromp = v5;
    return 1;
  }
  while ( 1 )
  {
    v8 = *v5;
    if ( *v5 < 48 || v8 > 57 )
      break;
    a2 = v8 - 48;
LABEL_13:
    LOBYTE(a2) = (_BYTE)a2 << (4 * ((v7 & 1) == 0));
    v9 = &to[v7 / 2];
    ++v7;
    *v9 |= a2;
    ++v5;
    if ( v7 >= v6 )
      goto LABEL_14;
  }
  if ( v8 >= 65 && v8 <= 70 )
  {
    a2 = v8 - 55;
    goto LABEL_13;
  }
  if ( v8 >= 97 && v8 <= 102 )
  {
    a2 = v8 - 87;
    goto LABEL_13;
  }
  ERR_put_error(a2, 9u, 101, 103, ".\\crypto\\pem\\pem_lib.c", 557);
  return 0;
}
