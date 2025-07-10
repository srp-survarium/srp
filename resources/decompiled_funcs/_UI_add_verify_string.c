int __cdecl UI_add_verify_string(
        ui_st *ui,
        const char *prompt,
        int flags,
        char *result_buf,
        int minsize,
        int maxsize,
        const char *test_buf)
{
  return general_allocate_string(0, UIT_VERIFY, result_buf, ui, prompt, flags, minsize, maxsize, test_buf);
}
