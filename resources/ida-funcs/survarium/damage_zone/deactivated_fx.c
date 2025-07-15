void __usercall survarium::damage_zone::deactivated_fx(
        survarium::damage_zone *this@<ecx>,
        survarium::damage_zone *a2@<esi>)
{
  unsigned int m_sound_points_count; // ebx
  unsigned int v3; // edi
  const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *v4; // eax
  unsigned int v5; // ebx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v6; // edi
  unsigned int m_effect_points_count; // [esp+8h] [ebp-8h]
  int v8; // [esp+Ch] [ebp-4h]
  int v9; // [esp+Ch] [ebp-4h]

  m_sound_points_count = a2->m_sound_points_count;
  v3 = 0;
  if ( m_sound_points_count )
  {
    v8 = 0;
    do
    {
      v4 = &a2->m_deactivated_sound_emitters[v3];
      if ( v4->m_object )
      {
        this = (survarium::damage_zone *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          survarium::damage_zone::emit_sound_once(
            (survarium::damage_zone *)&a2->m_sound_points[v8],
            (int)a2,
            v4,
            &a2->m_sound_points[v8]);
      }
      ++v8;
      ++v3;
    }
    while ( v3 < m_sound_points_count );
  }
  v5 = 0;
  m_effect_points_count = a2->m_effect_points_count;
  if ( m_effect_points_count )
  {
    v9 = 0;
    do
    {
      v6 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&a2->m_deactivated_particles[v5];
      if ( v6->m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          survarium::damage_zone::play_particle(
            v6,
            (survarium::pure_game_effect_emitter_base *)this,
            a2,
            &a2->m_effect_points[v9]);
      }
      ++v9;
      ++v5;
    }
    while ( v5 < m_effect_points_count );
  }
}
