vostok::render::effect_compiler *__userpurge vostok::render::effect_compiler::set_texture_impl@<eax>(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>,
        char *name,
        vostok::render::res_texture *texture,
        bool streamed,
        unsigned int num_last_mips_used,
        unsigned int __formal,
        float a8)
{
  if ( !byte_61F4C[a2]
    && !vostok::command_line::key::is_set((vostok::command_line::key *)this, (int)&s_no_effect_result) )
  {
    if ( *(_DWORD *)((char *)&loc_50338 + a2)
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture(
        (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_504E3 + a2 + 1),
        name,
        texture);
    }
    if ( *(_DWORD *)((char *)&loc_50332 + a2 + 2)
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture(
        (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_561F6 + a2 + 2),
        name,
        texture);
    }
    if ( *(_DWORD *)((char *)&loc_5032F + a2 + 1)
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      vostok::render::xs_descriptor<vostok::render::gs_data>::set_texture(
        (vostok::render::xs_descriptor<vostok::render::vs_data> *)((char *)&loc_5BF08 + a2),
        name,
        texture);
    }
  }
  return (vostok::render::effect_compiler *)a2;
}
