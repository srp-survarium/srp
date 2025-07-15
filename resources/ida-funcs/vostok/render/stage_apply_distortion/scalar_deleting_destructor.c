vostok::render::stage_apply_distortion *__thiscall vostok::render::stage_apply_distortion::`scalar deleting destructor'(
        vostok::render::stage_apply_distortion *this,
        char a2)
{
  this->__vftable = (vostok::render::stage_apply_distortion_vtbl *)&vostok::render::stage_apply_distortion::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_olta_effect);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_sh_apply_distortion);
  this->__vftable = (vostok::render::stage_apply_distortion_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
