void __thiscall vostok::particle::particle_world::stop(
        vostok::particle::particle_world *this,
        vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> instance,
        float time)
{
  vostok::resources::unmanaged_resource *m_object; // eax
  float v4; // xmm0_4

  m_object = instance.m_object;
  _InterlockedExchange(&instance.m_object->m_is_playing, 0);
  v4 = time;
  BYTE1(m_object[2].m_prev_in_global_list) = 1;
  *(float *)&m_object[2].m_prev_in_global_delay_delete_list = v4;
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&instance);
}
