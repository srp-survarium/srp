ui_string_st *__cdecl X509_EXTENSION_get_data(ui_string_st *uis)
{
  ui_string_st *result; // eax

  result = uis;
  if ( uis )
    return (ui_string_st *)uis->input_flags;
  return result;
}
