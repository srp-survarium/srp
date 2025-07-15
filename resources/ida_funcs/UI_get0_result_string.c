char *__cdecl UI_get0_result_string(ui_string_st *uis)
{
  if ( uis && (unsigned int)(uis->type - 1) <= 1 )
    return uis->result_buf;
  else
    return 0;
}
