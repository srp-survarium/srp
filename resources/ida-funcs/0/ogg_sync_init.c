int __cdecl ogg_sync_init(ogg_sync_state *oy)
{
  if ( oy )
  {
    oy->storage = -1;
    memset(oy, 0, sizeof(ogg_sync_state));
  }
  return 0;
}
