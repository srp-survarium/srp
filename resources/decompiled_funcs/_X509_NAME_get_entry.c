X509_name_entry_st *__cdecl X509_NAME_get_entry(X509_name_st *name, int loc)
{
  if ( name && sk_num(&name->entries->stack) > loc && loc >= 0 )
    return (X509_name_entry_st *)sk_value(&name->entries->stack, loc);
  else
    return 0;
}
