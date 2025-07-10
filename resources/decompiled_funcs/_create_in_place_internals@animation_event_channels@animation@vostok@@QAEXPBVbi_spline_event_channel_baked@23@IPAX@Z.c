void __userpurge vostok::animation::animation_event_channels::create_in_place_internals(
        vostok::animation::animation_event_channels *this@<ecx>,
        unsigned int *a2@<edi>,
        const vostok::animation::bi_spline_event_channel_baked *event_channels,
        _BYTE *memory_buff,
        void *i)
{
  int v5; // ebp
  unsigned int v6; // ecx
  int v7; // edx
  char *v8; // eax
  unsigned __int16 *p_m_knots_count; // ebx
  int v10; // eax
  unsigned int ia; // [esp+8h] [ebp-4h]
  _BYTE *memory_buffa; // [esp+14h] [ebp+8h]

  v5 = 0;
  v6 = 0;
  a2[1] = memory_buff - (_BYTE *)a2;
  if ( *a2 )
  {
    v7 = 0;
    do
    {
      v8 = (char *)&a2[v7] + a2[1];
      if ( v8 )
      {
        *((_DWORD *)v8 + 8) = -1;
        *((_DWORD *)v8 + 9) = -1;
      }
      ++v6;
      v7 += 11;
    }
    while ( v6 < *a2 );
  }
  memory_buffa = &memory_buff[44 * *a2];
  ia = 0;
  if ( *a2 )
  {
    p_m_knots_count = &event_channels->m_knots_count;
    do
    {
      vostok::animation::event_channel::create_in_place_internals(
        (const vostok::animation::bi_spline_event_channel_baked *)(p_m_knots_count - 4),
        (vostok::animation::event_channel *)((char *)&a2[v5] + a2[1]),
        memory_buffa);
      if ( *p_m_knots_count )
        v10 = 5 * *p_m_knots_count;
      else
        v10 = 0;
      memory_buffa += v10;
      v5 += 11;
      p_m_knots_count += 8;
      ++ia;
    }
    while ( ia < *a2 );
  }
}
