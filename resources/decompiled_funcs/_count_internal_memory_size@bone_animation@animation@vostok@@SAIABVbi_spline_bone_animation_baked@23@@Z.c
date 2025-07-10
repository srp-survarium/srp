int __cdecl vostok::animation::bone_animation::count_internal_memory_size(
        const vostok::animation::bi_spline_bone_animation_baked *bd)
{
  int v1; // ebx
  unsigned int i; // esi
  unsigned int v3; // eax

  v1 = 0;
  for ( i = 0; i < 9; ++i )
  {
    v3 = vostok::animation::poly_knots_count(bd->m_channel_animations[i].pointer);
    v1 += 20 * v3;
  }
  return v1;
}
