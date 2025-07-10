void __cdecl X509_VERIFY_PARAM_free(X509_VERIFY_PARAM_st *param)
{
  stack_st_ASN1_OBJECT *policies; // eax

  if ( param )
  {
    policies = param->policies;
    param->name = 0;
    param->purpose = 0;
    param->trust = 0;
    param->inh_flags = 0;
    param->flags = 0;
    param->depth = -1;
    if ( policies )
    {
      sk_pop_free(&policies->stack, (void (__cdecl *)(void *))ASN1_OBJECT_free);
      param->policies = 0;
    }
  }
  CRYPTO_free(param);
}
