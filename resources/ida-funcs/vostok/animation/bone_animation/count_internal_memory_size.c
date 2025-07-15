int __cdecl vostok::animation::bone_animation::count_internal_memory_size(
        const vostok::animation::bi_spline_bone_animation_baked *bd)
{
  int v1; // ecx
  int v2; // edi
  unsigned int i; // esi

  v2 = 0;
  for ( i = 0; i < 9; ++i )
    v2 += 20 * vostok::animation::poly_knots_count(v1, bd->m_channel_animations[i].pointer);
  return v2;
}
