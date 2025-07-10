vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_texture@<eax>(
        vostok::render::effect_compiler *this@<esi>,
        vostok::render::res_texture *texture@<edi>,
        vostok::render::xs_descriptor<vostok::render::vs_data> *a3@<ecx>,
        const char *name,
        bool streamed,
        unsigned int num_last_mips_used)
{
  if ( !this->m_shaders_cache_mode )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      if ( this->m_vs_hw.m_object )
      {
        a3 = (vostok::render::xs_descriptor<vostok::render::vs_data> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
        if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
          vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture(
            (vostok::render::xs_descriptor<vostok::render::vs_data> *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr,
            (int)&this->m_vs_descriptor,
            name,
            texture);
      }
      if ( this->m_gs_hw.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture(
          a3,
          (int)&this->m_gs_descriptor,
          name,
          texture);
      }
      if ( this->m_ps_hw.m_object
        && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture(
          a3,
          (int)&this->m_ps_descriptor,
          name,
          texture);
      }
    }
  }
  return this;
}
