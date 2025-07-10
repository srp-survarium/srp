vostok::render::effect_compiler *__thiscall vostok::render::effect_compiler::set_constant<vostok::math::float2>(
        vostok::render::effect_constant_storage *source,
        vostok::render::effect_compiler *this,
        vostok::shared_string hlsl_name)
{
  vostok::render::effect_compiler *v3; // esi
  vostok::strings::shared::profile *m_object; // ecx
  vostok::render::shader_constant_binding binding; // [esp+8h] [ebp-14h] BYREF

  binding.m_source.m_pointer = vostok::render::effect_constant_storage::store_constant<vostok::math::float2>(
                                 source,
                                 *(const vostok::math::float2 *)&source->m_indexers._M_impl._M_start);
  binding.m_source.m_size = 8;
  binding.m_name.m_pointer.m_object = 0;
  if ( hlsl_name.m_pointer.m_object )
  {
    binding.m_name = hlsl_name;
    _InterlockedExchangeAdd(&hlsl_name.m_pointer.m_object->m_reference_count, 1u);
  }
  binding.m_type = rc_float;
  binding.m_class_id = rc_1x2;
  v3 = vostok::render::effect_compiler::bind_constant(this, &binding);
  if ( binding.m_name.m_pointer.m_object )
  {
    m_object = binding.m_name.m_pointer.m_object;
    if ( !_InterlockedExchangeAdd(&binding.m_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
      vostok::strings::shared::manager::remove(
        (vostok::strings::shared::manager *)m_object,
        (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  if ( hlsl_name.m_pointer.m_object
    && !_InterlockedExchangeAdd(&hlsl_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(0, (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  return v3;
}
