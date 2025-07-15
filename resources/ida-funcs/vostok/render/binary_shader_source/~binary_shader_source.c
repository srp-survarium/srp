void __thiscall vostok::render::binary_shader_source::~binary_shader_source(vostok::render::binary_shader_source *this)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_shader_source; // esi

  p_shader_source = &this->shader_source;
  this->__vftable = (vostok::render::binary_shader_source_vtbl *)&vostok::render::binary_shader_source::`vftable';
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::operator=(
    &this->shader_source,
    0);
  vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&this->shader_name.m_pointer);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(p_shader_source);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
}
