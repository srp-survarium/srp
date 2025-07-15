int __cdecl UI_add_input_string(ui_st *ui, const char *prompt, int flags, char *result_buf, int minsize, int maxsize)
{
  return general_allocate_string(0, UIT_PROMPT, result_buf, ui, prompt, flags, minsize, maxsize, 0);
}
