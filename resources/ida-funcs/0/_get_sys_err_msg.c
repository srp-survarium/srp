char *__cdecl _get_sys_err_msg(int m)
{
  int v1; // esi

  v1 = m;
  if ( m < 0 || m >= *__sys_nerr() )
    v1 = *__sys_nerr();
  return __sys_errlist()[v1];
}
