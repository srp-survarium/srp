X509_extension_st *__cdecl X509_EXTENSION_get_critical(X509_extension_st *ex)
{
  X509_extension_st *result; // eax

  result = ex;
  if ( ex )
    return (X509_extension_st *)(ex->critical > 0);
  return result;
}
