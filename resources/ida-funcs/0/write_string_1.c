int __usercall write_string_1@<eax>(int a1@<ebx>, int a2@<edi>, ui_st *ui, ui_string_st *uis)
{
  const char *v4; // eax
  _iobuf *v6; // [esp-4h] [ebp-8h]

  if ( (unsigned int)&X509_EXTENSION_get_object(uis)[-1].flags <= 1 )
  {
    v6 = tty_out;
    v4 = UI_get0_output_string(uis);
    fputs(v4, v6);
    fflush(a1, a2, tty_out);
  }
  return 1;
}
