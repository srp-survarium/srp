int __usercall read_string@<eax>(int a1@<ebx>, int a2@<edi>, ui_st *ui, ui_string_st *uis)
{
  char *v4; // eax
  char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // eax
  unsigned __int8 data; // al
  int result; // eax
  const char *v11; // edi
  char *v12; // eax
  bool v13; // cf
  unsigned __int8 v14; // cl
  int v15; // eax
  const char *v16; // eax
  unsigned __int8 v17; // al
  _iobuf *v18; // [esp-4h] [ebp-Ch]
  _iobuf *v19; // [esp-4h] [ebp-Ch]
  int v20; // [esp-4h] [ebp-Ch]
  _iobuf *v21; // [esp-4h] [ebp-Ch]

  v4 = (char *)&X509_EXTENSION_get_object(uis)[-1].flags + 3;
  if ( !v4 )
  {
    v21 = tty_out;
    v16 = UI_get0_output_string(uis);
    fputs(v16, v21);
    fflush(a1, a2, tty_out);
    v20 = 1;
    goto LABEL_17;
  }
  v5 = v4 - 1;
  if ( !v5 )
  {
    v8 = UI_get0_output_string(uis);
    fprintf(a2, tty_out, "Verifying - %s", v8);
    fflush(a1, a2, tty_out);
    data = (unsigned __int8)X509_EXTENSION_get_data(uis);
    result = read_string_inner(ui, uis, data & 1, 1);
    if ( result <= 0 )
      return result;
    v11 = UI_get0_test_string(uis);
    v12 = UI_get0_result_string(uis);
    while ( 1 )
    {
      v13 = (unsigned __int8)*v12 < (unsigned int)*v11;
      if ( *v12 != *v11 )
        break;
      if ( !*v12 )
        goto LABEL_11;
      v14 = v12[1];
      v13 = v14 < (unsigned int)v11[1];
      if ( v14 != v11[1] )
        break;
      v12 += 2;
      v11 += 2;
      if ( !v14 )
      {
LABEL_11:
        v15 = 0;
        goto LABEL_13;
      }
    }
    v15 = -v13 - (v13 - 1);
LABEL_13:
    if ( v15 )
    {
      fprintf((int)v11, tty_out, "Verify failure\n");
      fflush(a1, (int)v11, tty_out);
      return 0;
    }
    return 1;
  }
  if ( v5 != (char *)1 )
    return 1;
  v18 = tty_out;
  v6 = UI_get0_output_string(uis);
  fputs(v6, v18);
  v19 = tty_out;
  v7 = UI_get0_action_string(uis);
  fputs(v7, v19);
  fflush(a1, a2, tty_out);
  v20 = 0;
LABEL_17:
  v17 = (unsigned __int8)X509_EXTENSION_get_data(uis);
  return read_string_inner(ui, uis, v17 & 1, v20);
}
