void __userpurge vostok::animation::animation_event_channels::create_in_place_internals(
        vostok::animation::animation_event_channels *this@<ecx>,
        unsigned int *a2@<edi>,
        const vostok::animation::bi_spline_event_channel_baked *event_channels,
        unsigned int memory_buff,
        void *i)
{
  unsigned int v5; // ecx
  int v6; // edx
  char *v7; // eax
  unsigned __int16 *p_m_knots_count; // ebx
  int v9; // eax
  unsigned int v10; // [esp+4h] [ebp-8h]
  int v11; // [esp+8h] [ebp-4h]
  char *v12; // [esp+18h] [ebp+Ch]

  v5 = 0;
  a2[1] = memory_buff - (_DWORD)a2;
  if ( *a2 )
  {
    v6 = 0;
    do
    {
      v7 = (char *)&a2[v6] + a2[1];
      if ( v7 )
      {
        *((_DWORD *)v7 + 8) = -1;
        *((_DWORD *)v7 + 9) = -1;
      }
      ++v5;
      v6 += 11;
    }
    while ( v5 < *a2 );
  }
  v12 = (char *)(44 * *a2 + memory_buff);
  v10 = 0;
  if ( *a2 )
  {
    v11 = 0;
    p_m_knots_count = &event_channels->m_knots_count;
    do
    {
      vostok::animation::event_channel::create_in_place_internals(
        (const vostok::animation::bi_spline_event_channel_baked *)(p_m_knots_count - 4),
        (vostok::animation::event_channel *)((char *)&a2[v11] + a2[1]),
        v12);
      if ( *p_m_knots_count )
        v9 = 5 * *p_m_knots_count;
      else
        v9 = 0;
      v12 += v9;
      ++v10;
      v11 += 11;
      p_m_knots_count += 8;
    }
    while ( v10 < *a2 );
  }
}
