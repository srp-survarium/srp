int ENGINE_cleanup()
{
  if ( cleanup_stack )
  {
    sk_pop_free(&cleanup_stack->stack, (void (__cdecl *)(void *))engine_cleanup_cb_free);
    cleanup_stack = 0;
  }
  return RAND_set_rand_method(0);
}
