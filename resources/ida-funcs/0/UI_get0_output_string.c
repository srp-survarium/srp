const char *__cdecl UI_get0_output_string(ui_string_st *uis)
{
  const char *result; // eax

  result = (const char *)uis;
  if ( uis )
    return uis->out_string;
  return result;
}
