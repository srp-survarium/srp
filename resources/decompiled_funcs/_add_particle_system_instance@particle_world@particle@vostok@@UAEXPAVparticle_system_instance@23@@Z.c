void __thiscall vostok::particle::particle_world::add_particle_system_instance(
        vostok::particle::particle_world *this,
        vostok::particle::particle_system_instance_impl *instance)
{
  vostok::ai::sound_player *v2; // ecx
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v3; // [esp-8h] [ebp-84h] BYREF
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v4; // [esp-4h] [ebp-80h] BYREF
  vostok::particle::particle_world *thisa; // [esp+0h] [ebp-7Ch]
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v6; // [esp+2Ch] [ebp-50h]
  vostok::sound::encoded_sound_interface *(__thiscall *v7)(vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *); // [esp+3Ch] [ebp-40h]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v8; // [esp+40h] [ebp-3Ch]
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v9; // [esp+60h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> result; // [esp+6Ch] [ebp-10h] BYREF
  bool v11; // [esp+77h] [ebp-5h]
  vostok::particle::particle_system_instance_impl *impl; // [esp+78h] [ebp-4h]

  thisa = this;
  impl = instance;
  v4.m_object = (vostok::ai::sound_player *)this;
  v9 = &v4;
  vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
    &v4,
    (vostok::ai::sound_player *)instance);
  v8 = vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,656,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::find(
         &thisa->m_ticked_instances_list,
         &result,
         (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)v4.m_object);
  if ( v8->m_object )
    v7 = vostok::intrusive_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::c_ptr;
  else
    v7 = 0;
  v11 = v7 != 0;
  vostok::intrusive_ptr<vostok::ai::behaviour,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&result);
  if ( !v11 )
  {
    v4.m_object = 0;
    v3.m_object = v2;
    v6 = &v3;
    vostok::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::ai::sound_player,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
      &v3,
      (vostok::ai::sound_player *)impl);
    vostok::intrusive_list<vostok::particle::particle_system_instance_impl,vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>,656,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::push_back(
      &thisa->m_ticked_instances_list,
      (vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base>)v3.m_object,
      (bool *)v4.m_object);
  }
}
