stlp_std::codecvt_base::result __thiscall stlp_std::codecvt<wchar_t,char,int>::do_out(
        stlp_std::codecvt<wchar_t,char,int> *this,
        int *__formal,
        const wchar_t *from,
        const wchar_t *from_end,
        const wchar_t **from_next,
        char *to,
        char *to_limit,
        char **to_next)
{
  char *v8; // edx
  const wchar_t *v9; // ebx
  char *v10; // ecx
  char **p_to_limit; // eax
  char *v12; // edi
  int v13; // ebp
  int v14; // eax
  char *v15; // esi
  const wchar_t *v16; // ecx
  char **v17; // ecx

  v8 = to;
  v9 = from;
  v10 = (char *)(to_limit - to);
  to = (char *)(from_end - from);
  to_limit = v10;
  p_to_limit = &to_limit;
  if ( (int)v10 >= (int)to )
    p_to_limit = &to;
  v12 = *p_to_limit;
  v13 = 2 * (_DWORD)*p_to_limit;
  v14 = v13 >> 1;
  v15 = v8;
  v16 = from;
  if ( v13 >> 1 > 0 )
  {
    do
    {
      *v15 = *(_BYTE *)v16;
      --v14;
      ++v16;
      ++v15;
    }
    while ( v14 > 0 );
    v9 = from;
  }
  v17 = to_next;
  *from_next = &v9[v13 / 2u];
  *v17 = &v12[(_DWORD)v8];
  return 0;
}
