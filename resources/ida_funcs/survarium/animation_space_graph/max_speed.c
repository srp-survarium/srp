float __userpurge survarium::animation_space_graph::max_speed@<st0>(
        survarium::animation_space_graph *this@<ecx>,
        long double a2@<st0>,
        int a3)
{
  vostok::animation::animation_player *v3; // ecx
  const survarium::animation_space_vertex *v4; // esi
  int v5; // edi
  survarium::animation_space_vertex_id *movement; // eax
  float v7; // xmm0_4
  vostok::animation::mixing::n_ary_tree *v8; // ecx
  float v10; // [esp+14h] [ebp-8588h]
  survarium::animation_space_vertex_id result; // [esp+34h] [ebp-8568h] BYREF
  vostok::animation::animation_player player; // [esp+54h] [ebp-8548h] BYREF

  if ( *(float *)(a3 + 272) < 0.0 )
  {
    vostok::animation::animation_player::animation_player((vostok::animation::animation_player *)this, (int)&player);
    v4 = (const survarium::animation_space_vertex *)(a3 + 288);
    v5 = a3 + 288 + 292 * *(_DWORD *)(a3 + 276);
    *(_DWORD *)(a3 + 272) = 0;
    if ( a3 + 288 != v5 )
    {
      do
      {
        movement = survarium::animation_space_graph::get_movement(&result, &player, v4, v4, 1.0);
        a2 = sqrtf(
               (float)((float)(movement->translation.x * movement->translation.x)
                     + (float)(movement->translation.z * movement->translation.z))
             + (float)(movement->translation.y * movement->translation.y));
        v10 = a2;
        v7 = *(float *)(a3 + 272);
        if ( v7 <= v10 )
          v7 = a2;
        ++v4;
        *(float *)(a3 + 272) = v7;
      }
      while ( v4 != (const survarium::animation_space_vertex *)v5 );
    }
    vostok::animation::animation_player::reset(v3, &player, 1);
    vostok::animation::mixing::n_ary_tree::destroy(v8, (int)&player.m_mixing_tree);
    if ( player.m_mixing_tree.m_reference_counter.m_object )
      --player.m_mixing_tree.m_reference_counter.m_object->m_reference_count;
  }
  return a2;
}
