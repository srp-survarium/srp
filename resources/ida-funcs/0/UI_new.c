ui_st *__usercall UI_new@<eax>(int a1@<edi>, int a2@<ebx>)
{
  _DWORD *v2; // esi
  const ui_method_st *v4; // eax

  v2 = CRYPTO_malloc(24, ".\\crypto\\ui\\ui_lib.c", 80);
  if ( v2 )
  {
    v4 = default_UI_meth;
    if ( !default_UI_meth )
    {
      v4 = UI_OpenSSL();
      default_UI_meth = v4;
    }
    *v2 = v4;
    v2[1] = 0;
    v2[2] = 0;
    v2[5] = 0;
    CRYPTO_new_ex_data(a1, a2);
    return (ui_st *)v2;
  }
  else
  {
    ERR_put_error(a2, 0x28u, 104, 65, ".\\crypto\\ui\\ui_lib.c", 83);
    return 0;
  }
}
