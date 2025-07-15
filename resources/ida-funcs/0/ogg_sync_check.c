int __thiscall ogg_sync_check(ogg_sync_state *oy)
{
  return (oy->storage >= 0) - 1;
}
