vostok::render::effect_compiler *__fastcall vostok::render::effect_compiler::set_texture(
        int a1,
        vostok::intrusive_ptr<vostok::render::res_texture,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *streamed,
        vostok::render::effect_compiler *this,
        const char *hlsl_name,
        vostok::shared_string phisical_name,
        unsigned int num_last_mips_used)
{
  const char *v6; // eax
  vostok::render::effect_compiler *v7; // esi
  bool v9; // [esp+0h] [ebp-4h]

  if ( phisical_name.m_pointer.m_object
    && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
  {
    v6 = (const char *)&phisical_name.m_pointer.m_object[1];
  }
  else
  {
    v6 = 0;
  }
  v7 = vostok::render::effect_compiler::set_texture(this, hlsl_name, v6, streamed, v9, num_last_mips_used);
  if ( phisical_name.m_pointer.m_object
    && !_InterlockedExchangeAdd(&phisical_name.m_pointer.m_object->m_reference_count, 0xFFFFFFFF) )
  {
    vostok::strings::shared::manager::remove(
      s_manager.m_variable,
      (vostok::strings::shared::profile *)s_manager.m_variable);
  }
  return v7;
}
