void __thiscall vostok::render::scene_view::~scene_view(vostok::render::scene_view *this)
{
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **v2; // esi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *i; // ebx
  vostok::render::decal_instance **m_begin; // ecx
  vostok::render::render_surface_instance **v5; // ecx

  v2 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_10D1C + (_DWORD)this);
  this->__vftable = (vostok::render::scene_view_vtbl *)&vostok::render::scene_view::`vftable';
  for ( i = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)((char *)&dword_10D1C + (_DWORD)this);
        i != v2[1];
        ++i )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(i);
  }
  v2[1] = *v2;
  this->m_visible_ambient_lights.m_end = this->m_visible_ambient_lights.m_begin;
  this->m_visible_ambient_volumes.m_end = this->m_visible_ambient_volumes.m_begin;
  this->m_visible_particle_instances.m_end = this->m_visible_particle_instances.m_begin;
  this->m_visible_environment_probes.m_end = this->m_visible_environment_probes.m_begin;
  m_begin = this->m_visible_decals.m_begin;
  this->m_visible_decals.m_end = m_begin;
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::clear(
    (vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::light,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > *)m_begin,
    (unsigned int)i,
    (const char *)this,
    (const char *)v2,
    (vostok::render::light *)&this->m_visible_lights);
  this->m_visible_opaque_repeated_instances.m_end = this->m_visible_opaque_repeated_instances.m_begin;
  this->m_visible_gbuffer_forward_models.m_end = this->m_visible_gbuffer_forward_models.m_begin;
  this->m_visible_forward_models.m_end = this->m_visible_forward_models.m_begin;
  this->m_visible_opaque_models.m_end = this->m_visible_opaque_models.m_begin;
  this->m_visible_models.m_end = this->m_visible_models.m_begin;
  v5 = this->m_visible_moved_models.m_begin;
  this->m_visible_moved_models.m_end = v5;
  vostok::render::environment_properties::~environment_properties(
    (vostok::render::environment_properties *)v5,
    (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_environment_properties);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->next_scene_view);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
