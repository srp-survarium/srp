int __cdecl UI_process(ui_st *ui)
{
  int (__cdecl *ui_open_session)(ui_st *); // eax
  int v2; // ebp
  int v4; // edi
  const ui_method_st *meth; // ebx
  char *v6; // eax
  int (__cdecl *ui_flush)(ui_st *); // eax
  int v8; // eax
  int i; // ebx
  const ui_method_st *v10; // edi
  char *v11; // eax
  int v12; // eax
  int (__cdecl *ui_close_session)(ui_st *); // eax

  ui_open_session = ui->meth->ui_open_session;
  v2 = 0;
  if ( ui_open_session && !ui_open_session(ui) )
    return -1;
  if ( (ui->flags & 0x100) != 0 )
    ERR_print_errors_cb((int (__cdecl *)(const char *, unsigned int, void *))print_error, ui);
  v4 = 0;
  if ( sk_num(&ui->strings->stack) > 0 )
  {
    while ( 1 )
    {
      meth = ui->meth;
      if ( ui->meth->ui_write_string )
      {
        v6 = sk_value(&ui->strings->stack, v4);
        if ( !meth->ui_write_string(ui, (ui_string_st *)v6) )
          break;
      }
      if ( ++v4 >= sk_num(&ui->strings->stack) )
        goto LABEL_10;
    }
LABEL_21:
    v2 = -1;
    goto err_210;
  }
LABEL_10:
  ui_flush = ui->meth->ui_flush;
  if ( ui_flush )
  {
    v8 = ui_flush(ui);
    if ( v8 == -1 )
    {
LABEL_22:
      v2 = -2;
      goto err_210;
    }
    if ( !v8 )
      goto LABEL_21;
    v2 = 0;
  }
  for ( i = 0; i < sk_num(&ui->strings->stack); ++i )
  {
    v10 = ui->meth;
    if ( ui->meth->ui_read_string )
    {
      v11 = sk_value(&ui->strings->stack, i);
      v12 = v10->ui_read_string(ui, (ui_string_st *)v11);
      if ( v12 == -1 )
        goto LABEL_22;
      if ( !v12 )
        goto LABEL_21;
      v2 = 0;
    }
  }
err_210:
  ui_close_session = ui->meth->ui_close_session;
  if ( ui_close_session && !ui_close_session(ui) )
    return -1;
  return v2;
}
