void __cdecl engine_cleanup_cb_free(st_engine_cleanup_item *item)
{
  item->cb();
  CRYPTO_free(item);
}
