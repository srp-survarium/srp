int __usercall UI_process@<eax>(int a1@<ebx>, ui_st *ui)
{
  int (__cdecl *ui_open_session)(ui_st *); // eax
  int v3; // ebp
  int v5; // edi
  const ui_method_st *meth; // ebx
  char *v7; // eax
  int (__cdecl *ui_flush)(ui_st *); // eax
  int v9; // eax
  int i; // ebx
  const ui_method_st *v11; // edi
  char *v12; // eax
  int v13; // eax
  int (__cdecl *ui_close_session)(ui_st *); // eax

  ui_open_session = ui->meth->ui_open_session;
  v3 = 0;
  if ( ui_open_session && !ui_open_session(ui) )
    return -1;
  if ( (ui->flags & 0x100) != 0 )
    ERR_print_errors_cb(a1, (int (__cdecl *)(const char *, unsigned int, void *))print_error, ui);
  v5 = 0;
  if ( sk_num(&ui->strings->stack) > 0 )
  {
    while ( 1 )
    {
      meth = ui->meth;
      if ( ui->meth->ui_write_string )
      {
        v7 = sk_value(&ui->strings->stack, v5);
        if ( !meth->ui_write_string(ui, (ui_string_st *)v7) )
          break;
      }
      if ( ++v5 >= sk_num(&ui->strings->stack) )
        goto LABEL_10;
    }
LABEL_21:
    v3 = -1;
    goto err_212;
  }
LABEL_10:
  ui_flush = ui->meth->ui_flush;
  if ( ui_flush )
  {
    v9 = ui_flush(ui);
    if ( v9 == -1 )
    {
LABEL_22:
      v3 = -2;
      goto err_212;
    }
    if ( !v9 )
      goto LABEL_21;
    v3 = 0;
  }
  for ( i = 0; i < sk_num(&ui->strings->stack); ++i )
  {
    v11 = ui->meth;
    if ( ui->meth->ui_read_string )
    {
      v12 = sk_value(&ui->strings->stack, i);
      v13 = v11->ui_read_string(ui, (ui_string_st *)v12);
      if ( v13 == -1 )
        goto LABEL_22;
      if ( !v13 )
        goto LABEL_21;
      v3 = 0;
    }
  }
err_212:
  ui_close_session = ui->meth->ui_close_session;
  if ( ui_close_session && !ui_close_session(ui) )
    return -1;
  return v3;
}
