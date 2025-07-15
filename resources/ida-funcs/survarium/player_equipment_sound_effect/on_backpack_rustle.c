void __thiscall survarium::player_equipment_sound_effect::on_backpack_rustle(
        survarium::player_equipment_sound_effect *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  vostok::particle::particle_system_instance_impl *m_object; // ebx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *m_lock; // eax
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v4; // esi
  vostok::sound::sound_instance_proxy *v5; // eax
  const vostok::sound::sound_receiver *v6; // [esp+0h] [ebp-1Ch]
  bool v7; // [esp+4h] [ebp-18h]
  vostok::math::float3 v8; // [esp+10h] [ebp-Ch] BYREF

  m_object = a2.m_object;
  if ( survarium::player::is_first_view((survarium::player *)this, a2.m_object->m_parent_resources.m_size) )
  {
    vostok::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<survarium::player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &a2,
      (const vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)((char *)&loc_11274 + m_object->m_parent_resources.m_size));
    if ( a2.m_object )
    {
      m_lock = (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *)m_object->m_parent_resources.m_lock;
      v4 = m_lock + 37;
      v5 = (vostok::sound::sound_instance_proxy *)((int (__thiscall *)(vostok::resources::resource_base *))m_lock[40].m_object->m_prev_in_memory_type->link_child_resource)(m_lock[40].m_object->m_prev_in_memory_type);
      vostok::sound::sound_emitter::emit_and_play_once(
        (vostok::sound::sound_emitter *)a2.m_object,
        v4,
        v5,
        &v8,
        (const vostok::sound::sound_producer *)1,
        v6,
        v7);
    }
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  }
}
