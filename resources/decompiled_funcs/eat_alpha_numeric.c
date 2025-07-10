char *__cdecl eat_alpha_numeric(char *p)
{
  conf_st *conf; // ecx
  char *result; // eax
  _BYTE *meth_data; // edx

  result = p;
  meth_data = conf->meth_data;
  while ( 1 )
  {
    while ( (*(_WORD *)&meth_data[2 * (unsigned __int8)*result] & 0x20) != 0 )
    {
      if ( (meth_data[2 * (unsigned __int8)result[1]] & 8) != 0 )
        ++result;
      else
        result += 2;
    }
    if ( (*(_WORD *)&meth_data[2 * (unsigned __int8)*result] & 0x307) == 0 )
      break;
    ++result;
  }
  return result;
}
