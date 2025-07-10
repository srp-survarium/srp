int __usercall general_allocate_string@<eax>(
        ui_st *prompt_freeable@<ecx>,
        UI_string_types type@<edx>,
        char *result_buf@<ebx>,
        ui_st *ui,
        const char *prompt,
        int input_flags,
        int minsize,
        int maxsize,
        const char *test_buf)
{
  ui_string_st *v9; // esi
  stack_st_UI_STRING *v10; // eax
  int result; // eax

  v9 = general_allocate_prompt(prompt, type, result_buf, prompt_freeable, input_flags);
  if ( !v9 )
    return -1;
  if ( !ui->strings )
  {
    v10 = (stack_st_UI_STRING *)sk_new_null();
    ui->strings = v10;
    if ( !v10 )
    {
      free_string(v9);
      return -1;
    }
  }
  v9->_.string_data.result_minsize = minsize;
  v9->_.string_data.result_maxsize = maxsize;
  v9->_.string_data.test_buf = test_buf;
  result = sk_push(&ui->strings->stack, (char *)v9);
  if ( result <= 0 )
    --result;
  return result;
}
