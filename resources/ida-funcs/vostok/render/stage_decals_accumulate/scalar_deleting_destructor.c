vostok::render::stage_decals_accumulate *__thiscall vostok::render::stage_decals_accumulate::`scalar deleting destructor'(
        vostok::render::stage_decals_accumulate *this,
        char a2)
{
  this->__vftable = (vostok::render::stage_decals_accumulate_vtbl *)&vostok::render::stage_decals_accumulate::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_apply_decal_effect);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_opaque_geometry_mask_effect);
  this->__vftable = (vostok::render::stage_decals_accumulate_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
