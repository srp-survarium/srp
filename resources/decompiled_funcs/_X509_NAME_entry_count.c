X509_name_st *__cdecl X509_NAME_entry_count(X509_name_st *name)
{
  X509_name_st *result; // eax

  result = name;
  if ( name )
    return (X509_name_st *)sk_num(&name->entries->stack);
  return result;
}
