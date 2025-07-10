void __thiscall vostok::render::material_effects_instance_cook::gather_request_user_data(
        vostok::render::material_effects_instance_cook *this,
        vostok::variant<32> *user_data,
        vostok::render::effect_manager::compare_predicate<vostok::render::res_shader_technique> *root_config,
        vostok::render::effect_options_descriptor *additional_parameters)
{
  vostok::render::enum_render_stage_type v4; // edi
  vostok::render::custom_config *v5; // ebx
  char *v6; // ebp
  vostok::render::custom_config_value *v7; // ecx
  vostok::variant<32> *v8; // esi
  vostok::detail::abstract_type_helper *v9; // ecx
  vostok::render::custom_config_value *v10; // ecx
  vostok::render::custom_config_value *v11; // ecx
  const vostok::render::custom_config_value *v12; // eax
  __int32 v13; // esi
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *v14; // eax
  stlp_std::priv::_Rb_tree_node_base *M_right; // ebx
  vostok::render::custom_config_value *v16; // ecx
  const vostok::render::custom_config_value *v17; // eax
  stlp_std::priv::_Rb_tree_node_base **v18; // eax
  vostok::render::custom_config *m_object; // ebp
  stlp_std::priv::_Rb_tree_node_base **v20; // edi
  vostok::render::custom_config *v21; // esi
  vostok::render::grass_render_model *v22; // ecx
  vostok::variant<32> *v23; // esi
  vostok::detail::abstract_type_helper *m_helper; // ecx
  vostok::render::custom_config *v25; // eax
  vostok::render::custom_config *v26; // esi
  vostok::render::grass_render_model *v27; // ecx
  void *m_reconstruction_info_actuality_tick_high; // esi
  stlp_std::priv::_Rb_tree_node_base **v29; // ebp
  vostok::render::custom_config *v30; // esi
  __int32 v31; // ebx
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *v32; // eax
  stlp_std::priv::_Rb_tree_node_base *v33; // eax
  vostok::render::grass_render_model *v34; // ecx
  vostok::detail::abstract_type_helper *v35; // ecx
  void *v36; // esi
  vostok::render::effect_options_descriptor *v37; // [esp-8h] [ebp-38h]
  const char *v38; // [esp+0h] [ebp-30h]
  bool has_gstage; // [esp+17h] [ebp-19h]
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> gstage_config; // [esp+18h] [ebp-18h]
  unsigned int i; // [esp+1Ch] [ebp-14h]
  unsigned int crc; // [esp+20h] [ebp-10h] BYREF
  unsigned int gstage_config_crc; // [esp+24h] [ebp-Ch]
  char *__k; // [esp+28h] [ebp-8h] BYREF
  vostok::intrusive_ptr<vostok::render::custom_config,vostok::render::custom_config,vostok::threading::simple_lock> config; // [esp+2Ch] [ebp-4h] BYREF

  v4 = gbuffer_render_stage;
  v5 = 0;
  has_gstage = 0;
  gstage_config.m_object = 0;
  gstage_config_crc = 0;
  i = 0;
  do
  {
    v6 = (char *)vostok::render::stage_type_to_string(v4);
    if ( vostok::render::custom_config_value::value_exists((vostok::render::custom_config_value *)v6, v38) )
    {
      if ( v4 == gbuffer_render_stage )
        has_gstage = 1;
      vostok::render::custom_config_value::operator[](v7, v6);
      vostok::render::custom_config_value::operator[](v10, (const char *)&stru_9609EC);
      v12 = vostok::render::custom_config_value::operator[](v11, "effect_id");
      v13 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind + 108;
      __k = (char *)v12->data;
      v14 = stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::_M_find<char const *>(
              &__k,
              (stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind + 108));
      if ( v14 == (stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *)v13 )
        M_right = 0;
      else
        M_right = v14[6]._M_header._M_data._M_right;
      v37 = additional_parameters;
      vostok::render::custom_config_value::operator[]((vostok::render::custom_config_value *)&crc, v6);
      v17 = vostok::render::custom_config_value::operator[](v16, (const char *)&stru_9609EC);
      vostok::render::merge_effect_options(&config, v17, v37, &crc);
      v18 = (stlp_std::priv::_Rb_tree_node_base **)vostok::memory::doug_lea_allocator::malloc_impl(
                                                     (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                     0x10u);
      m_object = config.m_object;
      v20 = v18;
      if ( v18 )
      {
        v21 = 0;
        if ( config.m_object )
        {
          v21 = config.m_object;
          _InterlockedExchangeAdd(&config.m_object->m_reference_count, 1u);
        }
        *v18 = M_right;
        v18[1] = 0;
        if ( v21 )
        {
          v18[1] = (stlp_std::priv::_Rb_tree_node_base *)v21;
          _InterlockedExchangeAdd(&v21->m_reference_count, 1u);
        }
        v18[2] = (stlp_std::priv::_Rb_tree_node_base *)crc;
        *((_BYTE *)v18 + 12) = 1;
        if ( v21 && !_InterlockedExchangeAdd(&v21->m_reference_count, 0xFFFFFFFF) )
        {
          if ( v21->call_destructors )
            vostok::render::custom_config_value::call_data_destructor(&v21->m_root);
          if ( v21->own_buffer )
          {
            v22 = vostok::render::g_allocator.m_object;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free((void *)HIDWORD(v22->m_reconstruction_info_actuality_tick), v21);
          }
        }
      }
      else
      {
        v20 = 0;
      }
      v23 = &user_data[i];
      m_helper = v23->m_helper;
      if ( m_helper )
      {
        m_helper->destroy(m_helper, v23->m_storage);
        v23->m_helper = 0;
      }
      v23->m_type_id = vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get();
      if ( v23 != (vostok::variant<32> *)-8 )
        *(_DWORD *)v23->m_storage = v20;
      *(_DWORD *)v23->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *>::`vftable';
      v23->m_helper = (vostok::detail::abstract_type_helper *)v23;
      if ( !i )
      {
        v25 = 0;
        if ( m_object )
        {
          v25 = m_object;
          _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
        }
        v26 = gstage_config.m_object;
        gstage_config.m_object = v25;
        if ( v26 && !_InterlockedExchangeAdd(&v26->m_reference_count, 0xFFFFFFFF) )
        {
          if ( v26->call_destructors )
            vostok::render::custom_config_value::call_data_destructor(&v26->m_root);
          if ( v26->own_buffer )
          {
            v27 = vostok::render::g_allocator.m_object;
            BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
            vostok_mspace_free((void *)HIDWORD(v27->m_reconstruction_info_actuality_tick), v26);
          }
        }
        gstage_config_crc = crc;
      }
      if ( m_object && !_InterlockedExchangeAdd(&m_object->m_reference_count, 0xFFFFFFFF) )
      {
        if ( m_object->call_destructors )
          vostok::render::custom_config_value::call_data_destructor(&m_object->m_root);
        if ( m_object->own_buffer )
        {
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, m_object);
        }
      }
      v4 = i;
      v5 = gstage_config.m_object;
    }
    else
    {
      v8 = &user_data[v4];
      v9 = v8->m_helper;
      if ( v9 )
      {
        v9->destroy(v9, v8->m_storage);
        v8->m_helper = 0;
      }
      v8->m_type_id = vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get();
      if ( v8 != (vostok::variant<32> *)-8 )
        *(_DWORD *)v8->m_storage = 0;
      *(_DWORD *)v8->m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *>::`vftable';
      v8->m_helper = (vostok::detail::abstract_type_helper *)v8;
    }
    i = ++v4;
  }
  while ( (unsigned int)v4 < num_render_stages );
  if ( has_gstage )
  {
    v29 = (stlp_std::priv::_Rb_tree_node_base **)vostok::memory::doug_lea_allocator::malloc_impl(
                                                   (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                                   0x10u);
    if ( v29 )
    {
      v30 = 0;
      if ( v5 )
      {
        v30 = v5;
        _InterlockedExchangeAdd(&v5->m_reference_count, 1u);
      }
      v31 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind + 108;
      root_config = &stru_960AE0.m_techniques._M_t._M_key_compare;
      v32 = stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::_M_find<char const *>(
              (char **)&root_config,
              (stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *)(`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_conflicted_action_to_bind + 108));
      if ( v32 == (stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *)v31 )
        v33 = 0;
      else
        v33 = v32[6]._M_header._M_data._M_right;
      *v29 = v33;
      v29[1] = 0;
      if ( v30 )
      {
        v29[1] = (stlp_std::priv::_Rb_tree_node_base *)v30;
        _InterlockedExchangeAdd(&v30->m_reference_count, 1u);
      }
      v29[2] = (stlp_std::priv::_Rb_tree_node_base *)gstage_config_crc;
      *((_BYTE *)v29 + 12) = 1;
      if ( v30 && !_InterlockedExchangeAdd(&v30->m_reference_count, 0xFFFFFFFF) )
      {
        if ( v30->call_destructors )
          vostok::render::custom_config_value::call_data_destructor(&v30->m_root);
        if ( v30->own_buffer )
        {
          v34 = vostok::render::g_allocator.m_object;
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free((void *)HIDWORD(v34->m_reconstruction_info_actuality_tick), v30);
        }
      }
      v5 = gstage_config.m_object;
    }
    else
    {
      v29 = 0;
    }
    v35 = user_data[28].m_helper;
    if ( v35 )
    {
      v35->destroy(v35, user_data[28].m_storage);
      user_data[28].m_helper = 0;
    }
    user_data[28].m_type_id = vostok::detail::type_to_int<vostok::render::effect_compile_data *>::get();
    if ( user_data != (vostok::variant<32> *)-1352 )
      *(_DWORD *)user_data[28].m_storage = v29;
    *(_DWORD *)user_data[28].m_helper_storage = &vostok::detail::concrete_type_helper<vostok::render::effect_compile_data *>::`vftable';
    user_data[28].m_helper = (vostok::detail::abstract_type_helper *)&user_data[28];
  }
  if ( v5 && !_InterlockedExchangeAdd(&v5->m_reference_count, 0xFFFFFFFF) )
  {
    if ( v5->call_destructors )
      vostok::render::custom_config_value::call_data_destructor(&v5->m_root);
    if ( v5->own_buffer )
    {
      v36 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v36, v5);
    }
  }
}
