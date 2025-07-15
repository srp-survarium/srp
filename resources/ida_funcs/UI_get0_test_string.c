const char *__cdecl UI_get0_test_string(ui_string_st *uis)
{
  if ( uis && uis->type == UIT_VERIFY )
    return uis->_.string_data.test_buf;
  else
    return 0;
}
