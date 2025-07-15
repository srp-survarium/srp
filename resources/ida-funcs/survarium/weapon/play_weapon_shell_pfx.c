void __thiscall survarium::weapon::play_weapon_shell_pfx(
        survarium::weapon *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  float w; // ecx
  int v4; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v5; // [esp-14h] [ebp-28h] BYREF
  const vostok::math::float4x4 *v6; // [esp-10h] [ebp-24h]
  vostok::math::float4x4 *v7; // [esp-Ch] [ebp-20h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // [esp-8h] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v9; // [esp-4h] [ebp-18h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v10; // [esp+10h] [ebp-4h] BYREF

  m_object = a2.m_object;
  w = a2.m_object[1].m_second_transform.c.w;
  if ( w != 0.0 )
  {
    v10.m_object = 0;
    a2.m_object = 0;
    v9 = &v10;
    v8 = &a2;
    v7 = (vostok::math::float4x4 *)&m_object[1].m_lods[5].m_emitter_instance_list.gap4;
    v6 = (const vostok::math::float4x4 *)&m_object[1].m_lods[5].m_emitter_instance_list.gap4;
    v4 = BYTE2(m_object[1].m_allocator);
    v5.m_object = (survarium::pure_game_effect_emitter_base *)LODWORD(w);
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v5,
      (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(w) + 4 * v4));
    vostok::render::scene_renderer::play_particle_system(
      (vostok::render::scene_renderer *)&m_object[2].m_next_in_increase_quality_queue->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type,
      *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + m_object[2].m_next_in_increase_quality_queue->vostok::particle::particle_system_instance::m_fat_it.m_hashset->m_hashlocks[21].m_readers_writers_counter.writer_thread_id),
      (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object[2].m_next_in_increase_quality_queue->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type,
      (const vostok::math::float4x4 *)v5.m_object,
      v6,
      v7,
      v8,
      v9);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v10);
    if ( ++BYTE2(m_object[1].m_allocator) == BYTE1(m_object[1].m_allocator) )
      BYTE2(m_object[1].m_allocator) = 0;
  }
}
