char *__cdecl eat_ws(char *p)
{
  conf_st *conf; // ecx
  char *result; // eax
  _WORD *meth_data; // edx
  __int16 i; // cx

  result = p;
  meth_data = conf->meth_data;
  for ( i = meth_data[(unsigned __int8)*p]; (i & 0x10) != 0; i = meth_data[(unsigned __int8)*++result] )
  {
    if ( (i & 8) != 0 )
      break;
  }
  return result;
}
