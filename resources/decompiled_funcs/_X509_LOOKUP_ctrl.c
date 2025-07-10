int __cdecl X509_LOOKUP_ctrl(x509_lookup_st *ctx)
{
  x509_lookup_method_st *method; // eax
  int (*ctrl)(void); // eax

  method = ctx->method;
  if ( !method )
    return -1;
  ctrl = (int (*)(void))method->ctrl;
  if ( ctrl )
    return ctrl();
  else
    return 1;
}
