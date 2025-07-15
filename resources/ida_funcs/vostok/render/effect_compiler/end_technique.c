void __usercall vostok::render::effect_compiler::end_technique(
        vostok::render::effect_compiler *this@<ecx>,
        int a2@<esi>)
{
  vostok::render::res_shader_technique *effect_technique; // eax
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *v3; // ecx
  vostok::render::res_shader_technique *v4; // ebp
  int v5; // edi
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v6; // eax
  stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *> *v7; // edi
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v8; // eax
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v9; // ecx
  vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v10; // ebx
  const stlp_std::__false_type *v12; // [esp+0h] [ebp-14h]
  unsigned int v13; // [esp+4h] [ebp-10h]
  bool v14; // [esp+8h] [ebp-Ch]
  vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> se; // [esp+10h] [ebp-4h] BYREF

  if ( !*(_BYTE *)(a2 + 37008) )
  {
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(se.m_object) = 0;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      effect_technique = vostok::render::effect_manager::create_effect_technique(
                           (stlp_std::priv::_Rb_tree_node_base *)(a2 + 36972),
                           (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind);
      v4 = 0;
      se.m_object = 0;
      if ( effect_technique )
      {
        ++effect_technique->m_reference_count;
        v4 = effect_technique;
        se.m_object = effect_technique;
      }
      v5 = *(_DWORD *)(a2 + 36996);
      v6 = *(vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(v5 + 284);
      v7 = (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *> *)(v5 + 280);
      if ( v6 == (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)v7[2].current )
      {
        stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_shader_technique,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_insert_overflow_aux(
          v3,
          v7,
          v6,
          &se,
          v12,
          v13,
          v14);
      }
      else
      {
        if ( v6 )
        {
          v6->m_object = 0;
          if ( v4 )
          {
            v6->m_object = (vostok::render::shader_constant_buffer *)v4;
            ++v4->m_reference_count;
          }
        }
        ++v7[1].current;
      }
      v8 = *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36984);
      v9 = *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36980);
      if ( v9 != v8 )
      {
        v10 = stlp_std::priv::__copy<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *,int>(
                v8,
                v9,
                *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36984));
        stlp_std::_Destroy_Range<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *>(
          v10,
          *(vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)(a2 + 36984));
        *(_DWORD *)(a2 + 36984) = v10;
      }
      ++*(_DWORD *)(a2 + 37000);
      *(_DWORD *)(a2 + 37004) = 0;
      if ( v4 )
      {
        if ( v4->m_reference_count-- == 1 )
          vostok::render::resource_intrusive_base::destroy<vostok::render::res_shader_technique>(v4);
      }
    }
  }
}
