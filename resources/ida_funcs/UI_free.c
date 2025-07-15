void __usercall UI_free(unsigned int a1@<edi>, ui_st *ui)
{
  if ( ui )
  {
    sk_pop_free(&ui->strings->stack, (void (__cdecl *)(void *))free_string);
    CRYPTO_free_ex_data(a1);
    CRYPTO_free(ui);
  }
}
