char *__usercall scan_quote@<eax>(conf_st *conf@<edx>, char *p)
{
  unsigned __int8 v2; // cl
  _WORD *meth_data; // esi
  int v4; // edi
  char *result; // eax
  __int16 v6; // dx
  int v7; // edx

  v2 = p[1];
  meth_data = conf->meth_data;
  v4 = *p;
  result = p + 1;
  v6 = meth_data[v2];
  if ( (v6 & 8) == 0 )
  {
    while ( (char)v2 != v4 )
    {
      if ( (v6 & 0x20) != 0 )
      {
        v7 = (unsigned __int8)*++result;
        if ( (meth_data[v7] & 8) != 0 )
          return result;
      }
      v2 = *++result;
      v6 = meth_data[v2];
      if ( (v6 & 8) != 0 )
        break;
    }
  }
  if ( *result == v4 )
    ++result;
  return result;
}
