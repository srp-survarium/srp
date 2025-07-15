void __usercall UI_free(int a1@<edi>, int a2@<ebx>, ui_st *ui)
{
  if ( ui )
  {
    sk_pop_free(&ui->strings->stack, (void (__cdecl *)(void *))free_string);
    CRYPTO_free_ex_data(a1, a2);
    CRYPTO_free(ui);
  }
}
