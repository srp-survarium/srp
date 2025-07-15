void __thiscall survarium::game_world::unload(
        survarium::game_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  vostok::particle::particle_system_instance_impl *m_first; // eax
  survarium::game_world *v4; // ecx
  vostok::vfs::base_node<1> *v5; // ecx
  vostok::particle::particle_emitter_instance *m_last; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v7; // ecx
  vostok::render::game::renderer *v8; // ecx
  vostok::memory::doug_lea_allocator *v9; // ecx
  unsigned int i; // esi
  const char *v11; // [esp+0h] [ebp-34h]
  const char *v12; // [esp+4h] [ebp-30h]
  unsigned int v13; // [esp+8h] [ebp-2Ch]
  int v14[9]; // [esp+10h] [ebp-24h] BYREF

  m_object = a2.m_object;
  if ( a2.m_object[17].m_lods[0].m_emitter_instance_list.m_first
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    survarium::pvp_match_core::clear_resources(
      (survarium::pvp_match_core *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
      (int)a2.m_object[17].m_lods[0].m_emitter_instance_list.m_first);
  }
  m_first = (vostok::particle::particle_system_instance_impl *)m_object[17].m_lods[0].m_emitter_instance_list.m_first;
  m_object[17].m_lods[0].m_emitter_instance_list.m_first = 0;
  a2.m_object = m_first;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  survarium::game_world::switch_to_free_fly_camera(v4, m_object);
  v5 = m_object->m_fat_it.m_hashset->m_hashset.m_buffer[3413];
  if ( v5 )
    ((void (__thiscall *)(vostok::vfs::base_node<1> *))v5->m_mount_root.pointer->physical_path.pointer)(v5);
  survarium::camera_director::switch_to_camera((survarium::camera_director *)m_object->m_next_in_memory_type, 0);
  a2.m_object = (vostok::particle::particle_system_instance_impl *)m_object[1].m_lods[2].m_emitter_instance_list.m_last;
  m_object[1].m_lods[2].m_emitter_instance_list.m_last = 0;
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&a2);
  m_last = m_object->m_lods[8].m_emitter_instance_list.m_last;
  m_object->m_lods[8].m_distance = 0.0;
  BYTE1(m_object[1].m_deleter) = 0;
  m_object[1].m_sub_fat.m_parent = 0;
  v14[0] = 0;
  (*(void (__thiscall **)(_DWORD, int *))(**(_DWORD **)(LODWORD(m_last->m_second_transform.j.y) + 13912) + 48))(
    *(_DWORD *)(LODWORD(m_last->m_second_transform.j.y) + 13912),
    v14);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(v7, v14);
  vostok::render::game::renderer::hide_text_manager(
    v8,
    (const vostok::resources::resource_ptr<vostok::render::base_scene_view,vostok::resources::unmanaged_intrusive_base> *)m_object->m_fat_it.m_hashset->m_hashlocks[21].m_readers_writers_counter.writer_thread_id,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags,
    (survarium::flash_text_manager *)m_object->m_prev_in_memory_type);
  for ( i = 0; i < LODWORD(m_object[1].m_lods[2].m_time_fade_in); ++i )
    vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>::~intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy>((vostok::intrusive_ptr<survarium::game_effect,survarium::game_effect,vostok::threading::single_threading_policy> *)(LODWORD(m_object[1].m_lods[2].m_distance) + 4 * i));
  if ( LODWORD(m_object[1].m_lods[2].m_distance) )
  {
    vostok::memory::doug_lea_allocator::free_impl(
      v9,
      (int)survarium::g_allocator,
      (char *)LODWORD(m_object[1].m_lods[2].m_distance),
      v11,
      v12,
      v13);
    m_object[1].m_lods[2].m_distance = 0.0;
  }
  m_object[1].m_lods[2].m_time_fade_in = 0.0;
  m_object->m_raw_resource_ptr.m_object = 0;
  m_object->m_next_delay_delete = 0;
}
