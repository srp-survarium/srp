vostok::render::res_pass *__thiscall vostok::render::effect_compiler::end_pass(
        vostok::render::effect_compiler *this,
        vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> pass)
{
  vostok::render::res_pass *m_object; // ebp
  vostok::render::res_pass *v3; // edi
  vostok::render::shader_constant_binding **v4; // ebx
  vostok::render::res_state *v5; // eax
  vostok::render::res_xs<vostok::render::vs_data> *v6; // eax
  stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *v7; // ecx
  vostok::render::res_xs<vostok::render::gs_data> *gs; // eax
  vostok::render::res_xs<vostok::render::ps_data> *v9; // eax
  vostok::render::res_pass *v10; // eax
  vostok::render::res_pass *v11; // eax
  vostok::render::res_pass *v12; // ecx
  vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *v13; // eax
  stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *p_m_input_layout; // ecx
  vostok::render::shader_constant_binding *v15; // eax
  vostok::render::shader_constant_binding *v16; // ecx
  vostok::render::shader_constant_binding *v17; // esi
  const vostok::render::res_xs_hw<vostok::render::vs_data> *m_reference_count; // eax
  bool v19; // zf
  vostok::render::res_xs_hw<vostok::render::gs_data> *v20; // eax
  vostok::render::res_xs_hw<vostok::render::ps_data> *v21; // eax
  vostok::render::res_xs<vostok::render::ps_data> *v22; // eax
  vostok::render::res_xs<vostok::render::gs_data> *v23; // eax
  vostok::render::res_xs<vostok::render::vs_data> *v24; // eax
  vostok::render::res_state *v25; // edi
  const stlp_std::__false_type *v27; // [esp+0h] [ebp-40h]
  unsigned int v28; // [esp+4h] [ebp-3Ch]
  bool v29; // [esp+8h] [ebp-38h]
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::ps_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> ps; // [esp+14h] [ebp-2Ch] BYREF
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::gs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> v31; // [esp+18h] [ebp-28h] BYREF
  vostok::intrusive_ptr<vostok::render::res_xs<vostok::render::vs_data>,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> vs; // [esp+1Ch] [ebp-24h] BYREF
  vostok::intrusive_ptr<vostok::render::res_state,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> state; // [esp+20h] [ebp-20h] BYREF
  vostok::render::res_pass v34; // [esp+24h] [ebp-1Ch] BYREF

  m_object = pass.m_object;
  if ( !LOBYTE(pass.m_object[1321].m_input_layout.m_object) )
  {
    v3 = 0;
    if ( s_no_effect_result.m_type == type_unset )
    {
      LOBYTE(pass.m_object) = 0;
      s_no_effect_result.m_type = type_recursive;
      vostok::command_line::iterate_keys<vostok::command_line::key_initializator>();
    }
    if ( s_no_effect_result.m_type == type_recursive )
    {
      v4 = (vostok::render::shader_constant_binding **)&m_object[1320];
      vostok::render::shader_constant_table::apply_bindings(
        (const vostok::render::shader_constant_bindings *)&m_object[1320],
        (vostok::render::shader_constant_table *)&m_object[17].m_input_layout);
      vostok::render::shader_constant_table::apply_bindings(
        (const vostok::render::shader_constant_bindings *)&m_object[1320],
        (vostok::render::shader_constant_table *)&m_object[452]);
      vostok::render::shader_constant_table::apply_bindings(
        (const vostok::render::shader_constant_bindings *)&m_object[1320],
        (vostok::render::shader_constant_table *)&m_object[886].m_state);
      v5 = vostok::render::resource_manager::create_state(
             (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
             (vostok::render::state_descriptor *)&m_object[2].m_state);
      state.m_object = 0;
      if ( v5 )
      {
        ++v5->m_reference_count;
        state.m_object = v5;
      }
      v6 = (vostok::render::res_xs<vostok::render::vs_data> *)vostok::render::resource_manager::create_vs(
                                                                (stlp_std::priv::_Rb_tree_node_base *)&m_object[17].m_vs,
                                                                (stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                                                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
      vs.m_object = 0;
      if ( v6 )
      {
        ++v6->m_reference_count;
        vs.m_object = v6;
      }
      gs = (vostok::render::res_xs<vostok::render::gs_data> *)vostok::render::resource_manager::create_gs(
                                                                (stlp_std::priv::_Rb_tree_node_base *)&m_object[451].m_ps,
                                                                v7,
                                                                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
      v31.m_object = 0;
      if ( gs )
      {
        ++gs->m_reference_count;
        v31.m_object = gs;
      }
      v9 = (vostok::render::res_xs<vostok::render::ps_data> *)vostok::render::resource_manager::create_ps(
                                                                (stlp_std::priv::_Rb_tree_node_base *)&m_object[885].m_input_layout,
                                                                (stlp_std::priv::_Rb_tree<vostok::render::res_xs<vostok::render::vs_data> *,vostok::render::resource_manager::compare_shader_predicate<vostok::render::vs_data>,vostok::render::res_xs<vostok::render::vs_data> *,stlp_std::priv::_Identity<vostok::render::res_xs<vostok::render::vs_data> *>,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::vs_data> *>,vostok::render::std_allocator<vostok::render::res_xs<vostok::render::vs_data> *> > *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                                                (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3]);
      ps.m_object = 0;
      if ( v9 )
      {
        ++v9->m_reference_count;
        ps.m_object = v9;
      }
      vostok::render::res_pass::res_pass(&v34, &state, &vs, &v31, &ps);
      v11 = vostok::render::effect_manager::create_pass(
              (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
              v10);
      pass.m_object = 0;
      if ( v11 )
      {
        ++v11->m_reference_count;
        pass.m_object = v11;
        v3 = v11;
      }
      vostok::render::res_pass::~res_pass(v12, (int)&v34);
      v13 = *(vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> **)&m_object[1320].m_registered;
      p_m_input_layout = (stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> > > *)&m_object[1320].m_input_layout;
      if ( v13 == (vostok::intrusive_ptr<vostok::render::shader_constant_buffer,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *)m_object[1321].m_reference_count )
      {
        stlp_std::priv::_Impl_vector<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>,vostok::render::std_allocator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy>>>::_M_insert_overflow_aux(
          p_m_input_layout,
          (stlp_std::reverse_iterator<vostok::intrusive_ptr<vostok::render::res_pass,vostok::render::resource_intrusive_base,vostok::threading::single_threading_policy> *> *)&m_object[1320].m_input_layout,
          v13,
          &pass,
          v27,
          v28,
          v29);
        v3 = pass.m_object;
      }
      else
      {
        if ( v13 )
        {
          v13->m_object = 0;
          if ( v3 )
          {
            v13->m_object = (vostok::render::shader_constant_buffer *)v3;
            ++v3->m_reference_count;
          }
        }
        *(_DWORD *)&m_object[1320].m_registered += 4;
      }
      vostok::render::state_descriptor::reset(
        (vostok::render::state_descriptor *)p_m_input_layout,
        (int)&m_object[2].m_state);
      v15 = (vostok::render::shader_constant_binding *)m_object[1320].m_state.m_object;
      v16 = *v4;
      if ( *v4 != v15 )
      {
        v17 = stlp_std::priv::__copy<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding *,int>(
                v15,
                v16,
                (vostok::render::shader_constant_binding *)m_object[1320].m_state.m_object);
        stlp_std::__destroy_range_aux<vostok::render::shader_constant_binding *,vostok::render::shader_constant_binding>(
          v17,
          (vostok::render::shader_constant_binding *)m_object[1320].m_state.m_object);
        v3 = pass.m_object;
        m_object[1320].m_state.m_object = (vostok::render::res_state *)v17;
      }
      m_reference_count = (const vostok::render::res_xs_hw<vostok::render::vs_data> *)m_object[2].m_reference_count;
      m_object[2].m_reference_count = 0;
      if ( m_reference_count )
      {
        v19 = m_reference_count->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::resource_manager::release_impl<vostok::render::vs_data>(
            (vostok::render::resource_manager *)v16,
            (int)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            m_reference_count);
      }
      v20 = *(vostok::render::res_xs_hw<vostok::render::gs_data> **)&m_object[1].m_registered;
      *(_DWORD *)&m_object[1].m_registered = 0;
      if ( v20 )
      {
        v19 = v20->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::resource_manager::release_impl<vostok::render::gs_data>(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v20);
      }
      v21 = (vostok::render::res_xs_hw<vostok::render::ps_data> *)m_object[1].m_input_layout.m_object;
      m_object[1].m_input_layout.m_object = 0;
      if ( v21 )
      {
        v19 = v21->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::resource_manager::release_impl<vostok::render::ps_data>(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v21);
      }
      ++m_object[1321].m_ps.m_object;
      if ( v3 )
      {
        v19 = v3->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::effect_manager::delete_pass(
            (vostok::render::effect_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind,
            v3);
      }
      v22 = ps.m_object;
      if ( ps.m_object )
      {
        v19 = ps.m_object->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v22);
      }
      v23 = v31.m_object;
      if ( v31.m_object )
      {
        v19 = v31.m_object->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v23);
      }
      v24 = vs.m_object;
      if ( vs.m_object )
      {
        v19 = vs.m_object->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v24);
      }
      v25 = state.m_object;
      if ( state.m_object )
      {
        v19 = state.m_object->m_reference_count-- == 1;
        if ( v19 )
          vostok::render::resource_manager::release(
            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
            v25);
      }
    }
  }
  return m_object;
}
