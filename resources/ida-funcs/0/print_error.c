int __cdecl print_error(const char *str, unsigned int len, ui_st *ui)
{
  const ui_method_st *meth; // edx
  int (__cdecl *ui_write_string)(ui_st *, ui_string_st *); // eax
  _DWORD v6[8]; // [esp+0h] [ebp-20h] BYREF

  meth = ui->meth;
  memset(&v6[2], 0, 24);
  v6[0] = 5;
  v6[1] = str;
  ui_write_string = meth->ui_write_string;
  if ( !ui_write_string || ui_write_string(ui, (ui_string_st *)v6) )
    return 0;
  else
    return -1;
}
