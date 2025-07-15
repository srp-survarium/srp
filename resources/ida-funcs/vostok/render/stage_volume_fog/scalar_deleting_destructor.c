vostok::render::stage_volume_fog *__thiscall vostok::render::stage_volume_fog::`scalar deleting destructor'(
        vostok::render::stage_volume_fog *this,
        char a2)
{
  vostok::render::sphere_geometry *v3; // ecx

  this->__vftable = (vostok::render::stage_volume_fog_vtbl *)&vostok::render::stage_volume_fog::`vftable';
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_exponential_volume_fog_effect);
  vostok::render::sphere_geometry::~sphere_geometry(v3, (int)&this->m_fog_sphere_geometry);
  vostok::intrusive_ptr<vostok::render::res_geometry,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>::dec(&this->m_fog_box_geometry.m_geometry);
  this->__vftable = (vostok::render::stage_volume_fog_vtbl *)&vostok::render::stage::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
