int __cdecl ogg_sync_wrote(ogg_sync_state *oy, int bytes)
{
  int storage; // edx
  int v4; // ecx

  storage = oy->storage;
  if ( storage < 0 )
    return -1;
  v4 = bytes + oy->fill;
  if ( v4 > storage )
    return -1;
  oy->fill = v4;
  return 0;
}
