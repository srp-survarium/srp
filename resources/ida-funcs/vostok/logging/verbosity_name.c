const char *__usercall vostok::logging::verbosity_name@<eax>(vostok::logging::verbosity verbosity@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax

  v1 = verbosity - 1;
  if ( !v1 )
    return "silent";
  v2 = v1 - 1;
  if ( !v2 )
    return "error";
  v3 = v2 - 1;
  if ( !v3 )
    return "warning";
  v4 = v3 - 1;
  if ( !v4 )
    return "info";
  if ( v4 == 1 )
    return (const char *)&stru_802CB8;
  return "trace";
}
