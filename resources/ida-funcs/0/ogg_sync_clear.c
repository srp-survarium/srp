int __cdecl ogg_sync_clear(ogg_sync_state *oy)
{
  if ( oy )
  {
    if ( oy->data )
      ogg_free_impl(oy->data);
    memset(oy, 0, sizeof(ogg_sync_state));
  }
  return 0;
}
