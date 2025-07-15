void __thiscall vostok::render::res_effect::~res_effect(vostok::render::res_effect *this)
{
  vostok::fixed_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,32> *p_m_techniques; // esi
  vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **p_m_end; // ebx
  vostok::resources::resource_ptr<vostok::render::binary_shader_source,vostok::resources::unmanaged_intrusive_base> *i; // ebx

  p_m_techniques = &this->m_techniques;
  p_m_end = &this->m_techniques.m_end;
  this->__vftable = (vostok::render::res_effect_vtbl *)&vostok::render::res_effect::`vftable';
  vostok::buffer_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>::destroy(
    this->m_techniques.m_begin,
    &this->m_techniques.m_end);
  *p_m_end = p_m_techniques->m_begin;
  for ( i = this->cached_binary_shaders.m_begin; i != this->cached_binary_shaders.m_end; ++i )
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)i);
  this->cached_binary_shaders.m_end = this->cached_binary_shaders.m_begin;
  this->m_used_textures.m_end = this->m_used_textures.m_begin;
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
