ui_st *__usercall UI_new@<eax>(unsigned int a1@<edi>)
{
  const ui_method_st **v1; // esi
  const ui_method_st *v3; // eax

  v1 = (const ui_method_st **)CRYPTO_malloc(24, ".\\crypto\\ui\\ui_lib.c", 80);
  if ( v1 )
  {
    v3 = default_UI_meth;
    if ( !default_UI_meth )
    {
      v3 = UI_OpenSSL();
      default_UI_meth = v3;
    }
    *v1 = v3;
    v1[1] = 0;
    v1[2] = 0;
    v1[5] = 0;
    CRYPTO_new_ex_data(a1);
    return (ui_st *)v1;
  }
  else
  {
    ERR_put_error(0x28u, 104, 65, ".\\crypto\\ui\\ui_lib.c", 83);
    return 0;
  }
}
