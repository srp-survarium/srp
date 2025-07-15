void __usercall survarium::damage_zone::start_hitting_fx(
        survarium::damage_zone *this@<ecx>,
        survarium::damage_zone *a2@<esi>)
{
  unsigned int v2; // edi
  int v3; // ebx
  unsigned int v4; // ebx
  const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *v5; // eax
  unsigned int v6; // ebx
  const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *v7; // edi
  unsigned int m_effect_points_count; // [esp+8h] [ebp-8h]
  unsigned int m_sound_points_count; // [esp+Ch] [ebp-4h]
  int v10; // [esp+Ch] [ebp-4h]
  int v11; // [esp+Ch] [ebp-4h]

  v2 = 0;
  if ( a2->m_continuous_hit )
  {
    m_sound_points_count = a2->m_sound_points_count;
    if ( m_sound_points_count )
    {
      v3 = 0;
      do
      {
        this = (survarium::damage_zone *)&a2->m_hit_sound_emitters[v2];
        if ( this->survarium::damage_zone_core::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable
          && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
        {
          survarium::damage_zone::emit_sound(
            this,
            (int)a2,
            (const vostok::resources::resource_ptr<vostok::sound::sound_emitter,vostok::resources::unmanaged_intrusive_base> *)this,
            &a2->m_hit_sound_instances[v2],
            &a2->m_sound_points[v3]);
        }
        ++v2;
        ++v3;
      }
      while ( v2 < m_sound_points_count );
    }
  }
  else
  {
    v4 = a2->m_sound_points_count;
    if ( v4 )
    {
      v10 = 0;
      do
      {
        v5 = &a2->m_hit_sound_emitters[v2];
        if ( v5->m_object )
        {
          this = (survarium::damage_zone *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
          if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
            survarium::damage_zone::emit_sound_once(
              (survarium::damage_zone *)&a2->m_sound_points[v10],
              (int)a2,
              v5,
              &a2->m_sound_points[v10]);
        }
        ++v10;
        ++v2;
      }
      while ( v2 < v4 );
    }
  }
  v6 = 0;
  m_effect_points_count = a2->m_effect_points_count;
  if ( m_effect_points_count )
  {
    v11 = 0;
    do
    {
      v7 = (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&a2->m_hit_particles[v6];
      if ( v7->m_object )
      {
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          survarium::damage_zone::play_particle(
            v7,
            (survarium::pure_game_effect_emitter_base *)this,
            a2,
            &a2->m_effect_points[v11]);
      }
      ++v11;
      ++v6;
    }
    while ( v6 < m_effect_points_count );
  }
}
