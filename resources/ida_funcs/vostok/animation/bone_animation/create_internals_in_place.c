void __userpurge vostok::animation::bone_animation::create_internals_in_place(
        vostok::animation::bone_animation *this@<ecx>,
        const vostok::animation::bi_spline_bone_animation_baked *bd@<eax>,
        char *memory)
{
  vostok::animation::bone_animation *v4; // esi
  int v5; // eax
  const vostok::animation::bi_spline_channel_animation_baked *v6; // edi
  unsigned int v7; // eax
  bool v8; // zf
  int v9; // [esp+10h] [ebp-8h]
  int v10; // [esp+14h] [ebp-4h]

  v4 = this;
  v5 = (char *)bd - (char *)this;
  v10 = v5;
  v9 = 9;
  while ( 1 )
  {
    v6 = *(const vostok::animation::bi_spline_channel_animation_baked **)((char *)&v4->m_channels[0].m_time_channel.m_knots_count
                                                                        + v5);
    vostok::animation::poly_curve<vostok::animation::poly_curve_order3_domain<float,1>>::create_in_place_internals(
      v4->m_channels,
      v6,
      memory);
    v7 = vostok::animation::poly_knots_count(v6);
    v4 = (vostok::animation::bone_animation *)((char *)v4 + 8);
    v8 = v9-- == 1;
    memory += 20 * v7;
    if ( v8 )
      break;
    v5 = v10;
  }
}
