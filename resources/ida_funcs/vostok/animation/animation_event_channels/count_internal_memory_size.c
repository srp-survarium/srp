unsigned int __fastcall vostok::animation::animation_event_channels::count_internal_memory_size(
        unsigned int channels_count,
        const vostok::animation::bi_spline_event_channel_baked *channels)
{
  unsigned int result; // eax
  unsigned __int16 *p_m_knots_count; // edx
  unsigned int v4; // esi
  int v5; // ecx

  result = 44 * channels_count;
  if ( channels_count )
  {
    p_m_knots_count = &channels->m_knots_count;
    v4 = channels_count;
    do
    {
      if ( *p_m_knots_count )
        v5 = 5 * *p_m_knots_count;
      else
        v5 = 0;
      result += v5;
      p_m_knots_count += 8;
      --v4;
    }
    while ( v4 );
  }
  return result;
}
