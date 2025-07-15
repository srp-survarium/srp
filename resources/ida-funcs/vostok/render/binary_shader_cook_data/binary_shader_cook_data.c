void __userpurge vostok::render::binary_shader_cook_data::binary_shader_cook_data(
        vostok::render::res_effect *in_effect_resource@<eax>,
        vostok::render::binary_shader_cook_data *this,
        vostok::render::shader_configuration in_configuration,
        vostok::shared_string in_shader_name,
        vostok::render::enum_shader_type in_shader_type,
        bool in_is_need_check_time)
{
  this->configuration = in_configuration;
  this->effect_resource = in_effect_resource;
  this->shader_name.m_pointer.m_object = 0;
  if ( in_shader_name.m_pointer.m_object )
  {
    vostok::intrusive_ptr<vostok::strings::shared::profile,vostok::strings::shared::detail::intrusive_base,vostok::threading::simple_lock>::dec(&this->shader_name.m_pointer);
    this->shader_name = in_shader_name;
    _InterlockedExchangeAdd(&in_shader_name.m_pointer.m_object->m_reference_count, 1u);
  }
  this->shader_type = in_shader_type;
  this->is_need_check_time = 1;
  if ( in_shader_name.m_pointer.m_object )
  {
    if ( !_InterlockedExchangeAdd(&in_shader_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::detail::intrusive_base::destroy(
        0,
        (vostok::hash_multiset<vostok::strings::shared::profile,vostok::strings::shared::profile *,4,vostok::detail::fixed_size_policy<32768>,vostok::strings::shared::manager::hash_function,vostok::strings::shared::manager::hash_function,vostok::threading::single_threading_policy> *)in_shader_name.m_pointer.m_object);
  }
}
