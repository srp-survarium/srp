int __cdecl write_string_1(ui_st *ui, ui_string_st *uis)
{
  const char *v2; // eax
  _iobuf *v4; // [esp-4h] [ebp-8h]

  if ( (unsigned int)&X509_EXTENSION_get_object(uis)[-1].flags <= 1 )
  {
    v4 = tty_out;
    v2 = UI_get0_output_string(uis);
    fputs(v2, v4);
    fflush(tty_out);
  }
  return 1;
}
