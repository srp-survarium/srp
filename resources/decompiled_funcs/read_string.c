int __cdecl read_string(ui_st *ui, ui_string_st *uis)
{
  char *v2; // eax
  char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  unsigned __int8 data; // al
  int result; // eax
  const char *v9; // edi
  const char *v10; // eax
  unsigned __int8 v11; // al
  _iobuf *v12; // [esp-4h] [ebp-Ch]
  _iobuf *v13; // [esp-4h] [ebp-Ch]
  int v14; // [esp-4h] [ebp-Ch]
  _iobuf *v15; // [esp-4h] [ebp-Ch]

  v2 = (char *)&X509_EXTENSION_get_object(uis)[-1].flags + 3;
  if ( !v2 )
  {
    v15 = tty_out;
    v10 = UI_get0_output_string(uis);
    fputs(v10, v15);
    fflush(tty_out);
    v14 = 1;
    goto LABEL_10;
  }
  v3 = v2 - 1;
  if ( !v3 )
  {
    v6 = UI_get0_output_string(uis);
    fprintf(tty_out, "Verifying - %s", v6);
    fflush(tty_out);
    data = (unsigned __int8)X509_EXTENSION_get_data(uis);
    result = read_string_inner(ui, uis, data & 1, 1);
    if ( result <= 0 )
      return result;
    v9 = UI_get0_test_string(uis);
    if ( strcmp(UI_get0_result_string(uis), v9) )
    {
      fprintf(tty_out, "Verify failure\n");
      fflush(tty_out);
      return 0;
    }
    return 1;
  }
  if ( v3 != (char *)1 )
    return 1;
  v12 = tty_out;
  v4 = UI_get0_output_string(uis);
  fputs(v4, v12);
  v13 = tty_out;
  v5 = UI_get0_action_string(uis);
  fputs(v5, v13);
  fflush(tty_out);
  v14 = 0;
LABEL_10:
  v11 = (unsigned __int8)X509_EXTENSION_get_data(uis);
  return read_string_inner(ui, uis, v11 & 1, v14);
}
