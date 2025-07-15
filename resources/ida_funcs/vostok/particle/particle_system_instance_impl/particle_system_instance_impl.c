void __thiscall vostok::particle::particle_system_instance_impl::particle_system_instance_impl(
        vostok::particle::particle_system_instance_impl *this)
{
  vostok::math::float4x4 *v1; // eax
  char v3; // [esp+60h] [ebp-40h] BYREF

  vostok::particle::particle_system_instance::particle_system_instance(this);
  this->__vftable = (vostok::particle::particle_system_instance_impl_vtbl *)&vostok::particle::particle_system_instance_impl::`vftable';
  survarium::weapon_core::cast_weapon_core((survarium::game_options *)&this->m_transform);
  this->m_next.m_object = 0;
  vostok::resources::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>::resource_ptr<vostok::render::static_model_instance,vostok::resources::unmanaged_intrusive_base>((vostok::render::stage_lights::lights_instance *)&this->m_scene);
  this->m_pinned = 0;
  vostok::threading::interlocked_exchange_pointer(&this->m_is_playing, 0);
  this->m_no_more_create = 0;
  this->m_paused = 0;
  this->m_visible = 1;
  this->m_current_lod = 0;
  this->m_old_lod = 0;
  this->m_num_lods = 1;
  this->m_use_lods = 1;
  LODWORD(this->m_lods[0].m_distance) = clear_value;
  LODWORD(this->m_lods_lerp_alpha) = clear_value;
  this->m_lerped = 0;
  this->m_ticked = 1;
  this->m_always_looping = 0;
  this->m_child_played = 0;
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator=(
    &this->m_next,
    0);
  v1 = (vostok::math::float4x4 *)survarium::weapon_core::cast_weapon_core((survarium::game_options *)&v3);
  qmemcpy((void *)&this->m_transform, vostok::math::float4x4::identity(v1), sizeof(this->m_transform));
  this->m_particle_system_time = *(float *)&FLOAT_0_0;
}
