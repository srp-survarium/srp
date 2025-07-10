char *__usercall scan_dquote@<eax>(conf_st *conf@<edx>, char *p)
{
  char v2; // cl
  _BYTE *meth_data; // edx
  int v4; // esi
  char *result; // eax

  v2 = p[1];
  meth_data = conf->meth_data;
  v4 = *p;
  for ( result = p + 1; (meth_data[2 * (unsigned __int8)v2] & 8) == 0; ++result )
  {
    if ( v2 == v4 )
    {
      if ( result[1] != v4 )
        break;
      ++result;
    }
    v2 = result[1];
  }
  if ( *result == v4 )
    ++result;
  return result;
}
