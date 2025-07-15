int __usercall read_string_inner@<eax>(ui_st *ui@<edi>, ui_string_st *uis, int echo, int strip_nl)
{
  _BYTE *v4; // eax
  int v5; // eax
  int v7; // [esp+8h] [ebp-208h]
  char string[512]; // [esp+Ch] [ebp-204h] BYREF

  intr_signal = 0;
  v7 = 0;
  ps = 0;
  pushsig((int)ui);
  ps = 2;
  string[0] = 0;
  if ( echo )
  {
    if ( !fgets(string, 511, tty_in) )
      goto error_3;
  }
  else
  {
    noecho_fgets(string, 511);
  }
  if ( !feof(tty_in) && !ferror(tty_in) )
  {
    strchr(string, 0xAu);
    if ( v4 )
    {
      if ( strip_nl )
        *v4 = 0;
    }
    else if ( !read_till_nl() )
    {
      goto error_3;
    }
    UI_set_result(ui, uis, string);
    if ( v5 >= 0 )
      v7 = 1;
  }
error_3:
  if ( intr_signal == 2 )
    v7 = -1;
  if ( !echo )
    fprintf((int)ui, tty_out, "\n");
  if ( ps >= 1 )
    popsig((int)ui);
  OPENSSL_cleanse(string, 512);
  return v7;
}
