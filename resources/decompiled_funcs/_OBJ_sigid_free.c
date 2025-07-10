void OBJ_sigid_free()
{
  if ( sig_app )
  {
    sk_pop_free(&sig_app->stack, (void (__cdecl *)(void *))policy_node_free);
    sig_app = 0;
  }
  if ( sigx_app )
  {
    sk_free(&sigx_app->stack);
    sigx_app = 0;
  }
}
