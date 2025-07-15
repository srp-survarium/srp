char *__cdecl ogg_sync_buffer(ogg_sync_state *oy, int size)
{
  int returned; // eax
  int fill; // eax
  int v5; // edi
  unsigned __int8 *v6; // eax

  if ( oy->storage < 0 )
    return 0;
  returned = oy->returned;
  if ( returned )
  {
    oy->fill -= returned;
    if ( oy->fill > 0 )
      memmove(oy->data, &oy->data[returned], oy->fill);
    oy->returned = 0;
  }
  fill = oy->fill;
  if ( size > oy->storage - fill )
  {
    v5 = fill + size + 4096;
    if ( oy->data )
      v6 = (unsigned __int8 *)ogg_realloc_impl(oy->data, v5);
    else
      v6 = (unsigned __int8 *)ogg_malloc_impl(fill + size + 4096);
    if ( !v6 )
    {
      ogg_sync_clear(oy);
      return 0;
    }
    oy->data = v6;
    oy->storage = v5;
  }
  return (char *)&oy->data[oy->fill];
}
