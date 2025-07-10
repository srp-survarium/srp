stlp_std::codecvt_base::result __thiscall stlp_std::codecvt<wchar_t,char,int>::do_in(
        stlp_std::codecvt<wchar_t,char,int> *this,
        int *__formal,
        const char *from,
        const char *from_end,
        const char **from_next,
        wchar_t *to,
        wchar_t *to_limit,
        wchar_t **to_next)
{
  wchar_t *v8; // edi
  wchar_t **p_to_limit; // eax
  wchar_t *v10; // esi
  int v11; // eax
  wchar_t *v12; // edx
  const char *i; // ecx

  v8 = to;
  to_limit -= (int)to;
  to = (wchar_t *)(from_end - from);
  p_to_limit = &to_limit;
  if ( (int)to_limit >= from_end - from )
    p_to_limit = &to;
  v10 = *p_to_limit;
  v11 = (int)*p_to_limit;
  v12 = v8;
  for ( i = from; v11 > 0; ++v12 )
  {
    *v12 = *(unsigned __int8 *)i;
    --v11;
    ++i;
  }
  *from_next = &from[(_DWORD)v10];
  *to_next = &v8[(_DWORD)v10];
  return 0;
}
