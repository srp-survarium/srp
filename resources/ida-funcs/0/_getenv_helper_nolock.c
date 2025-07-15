const char *__cdecl _getenv_helper_nolock(char *option)
{
  unsigned __int8 **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = (unsigned __int8 **)_environ;
  if ( !__env_initialized )
    return 0;
  if ( _environ || _wenviron && !__wtomb_environ() && (v1 = (unsigned __int8 **)_environ) != 0 )
  {
    if ( option )
    {
      strlen((unsigned __int8 *)option);
      v4 = v3;
      while ( *v1 )
      {
        strlen(*v1);
        if ( v5 > v4 && (*v1)[v4] == 61 && !_mbsnbicoll(v4, (int)v1, (char *)*v1, option, v4) )
          return (const char *)&(*v1)[v4 + 1];
        ++v1;
      }
    }
  }
  return 0;
}
