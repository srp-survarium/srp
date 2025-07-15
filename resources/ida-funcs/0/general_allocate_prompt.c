ui_string_st *__usercall general_allocate_prompt@<eax>(
        const char *prompt@<esi>,
        UI_string_types type@<edi>,
        char *result_buf@<ebx>,
        ui_st *ui,
        int prompt_freeable)
{
  ui_string_st *result; // eax

  if ( prompt )
  {
    if ( (type == UIT_PROMPT || type == UIT_VERIFY || type == UIT_BOOLEAN) && !result_buf )
    {
      ERR_put_error(0, 0x28u, 109, 105, ".\\crypto\\ui\\ui_lib.c", 152);
      return 0;
    }
    else
    {
      result = (ui_string_st *)CRYPTO_malloc(32, ".\\crypto\\ui\\ui_lib.c", 154);
      if ( result )
      {
        result->out_string = prompt;
        result->input_flags = prompt_freeable;
        result->type = type;
        result->result_buf = result_buf;
        result->flags = ui != 0;
      }
    }
  }
  else
  {
    ERR_put_error((int)result_buf, 0x28u, 109, 67, ".\\crypto\\ui\\ui_lib.c", 147);
    return 0;
  }
  return result;
}
