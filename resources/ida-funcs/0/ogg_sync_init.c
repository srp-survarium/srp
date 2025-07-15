int __cdecl ogg_sync_init(ogg_sync_state *oy)
{
  if ( oy )
  {
    oy->storage = -1;
    *(_QWORD *)&oy->data = 0;
    *(_QWORD *)&oy->fill = 0;
    *(_QWORD *)&oy->unsynced = 0;
    oy->bodybytes = 0;
  }
  return 0;
}
