void __thiscall survarium::weapon::play_weapon_fire_pfx(
        survarium::weapon *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  int m_allocator_high; // eax
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v4; // [esp-14h] [ebp-24h] BYREF
  const vostok::math::float4x4 *v5; // [esp-10h] [ebp-20h]
  vostok::math::float4x4 *v6; // [esp-Ch] [ebp-1Ch]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // [esp-8h] [ebp-18h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v8; // [esp-4h] [ebp-14h]
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v9; // [esp+Ch] [ebp-4h] BYREF

  v9.m_object = 0;
  m_object = a2.m_object;
  a2.m_object = 0;
  v8 = &v9;
  v7 = &a2;
  v6 = (vostok::math::float4x4 *)&m_object[1].m_lods[3].m_emitter_instance_list.gap4;
  v5 = (const vostok::math::float4x4 *)&m_object[1].m_lods[3].m_emitter_instance_list.gap4;
  m_allocator_high = HIBYTE(m_object[1].m_allocator);
  v4.m_object = (survarium::pure_game_effect_emitter_base *)this;
  vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v4,
    (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)(LODWORD(m_object[1].m_second_transform.c.z) + 4 * m_allocator_high));
  vostok::render::scene_renderer::play_particle_system(
    (vostok::render::scene_renderer *)&m_object[2].m_next_in_increase_quality_queue->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type,
    *(const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> **)((char *)&dword_200060 + m_object[2].m_next_in_increase_quality_queue->vostok::particle::particle_system_instance::m_fat_it.m_hashset->m_hashlocks[21].m_readers_writers_counter.writer_thread_id),
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&m_object[2].m_next_in_increase_quality_queue->vostok::particle::particle_system_instance::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::type,
    (const vostok::math::float4x4 *)v4.m_object,
    v5,
    v6,
    v7,
    v8);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&v9);
  if ( ++HIBYTE(m_object[1].m_allocator) == LOBYTE(m_object[1].m_allocator) )
    HIBYTE(m_object[1].m_allocator) = 0;
}
