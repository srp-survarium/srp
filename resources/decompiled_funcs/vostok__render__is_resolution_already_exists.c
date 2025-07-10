char __usercall vostok::render::is_resolution_already_exists@<al>(
        const unsigned int *monitor_index@<eax>,
        const vostok::math::int2 *res@<edx>)
{
  int v2; // ecx
  vostok::math::int2 *i; // eax

  v2 = 0;
  for ( i = vostok::render::g_monitor_resolutions[*monitor_index]; i->x != res->x || i->y != res->y; ++i )
  {
    if ( (unsigned int)++v2 >= 0x200 )
      return 0;
  }
  return 1;
}
