vostok::render::binary_shader_source *__thiscall vostok::render::binary_shader_source::`scalar deleting destructor'(
        vostok::render::binary_shader_source *this,
        char a2)
{
  vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> *p_shader_source; // edi
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v5; // [esp+8h] [ebp-4h] BYREF

  this->__vftable = (vostok::render::binary_shader_source_vtbl *)&stru_984D24.m_available_macros.m_buffer[4];
  p_shader_source = &this->shader_source;
  v5.m_object = this->shader_source.m_object;
  this->shader_source.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v5);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(p_shader_source);
  vostok::resources::unmanaged_resource::~unmanaged_resource(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
