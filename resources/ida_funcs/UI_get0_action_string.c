const char *__cdecl UI_get0_action_string(ui_string_st *uis)
{
  if ( uis && (uis->type == UIT_PROMPT || uis->type == UIT_BOOLEAN) )
    return uis->_.boolean_data.action_desc;
  else
    return 0;
}
