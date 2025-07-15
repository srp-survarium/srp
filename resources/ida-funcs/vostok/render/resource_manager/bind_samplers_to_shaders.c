void __usercall vostok::render::resource_manager::bind_samplers_to_shaders(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>)
{
  stlp_std::priv::_Rb_tree_node_base *i; // ebx
  vostok::render::resource_manager *v4; // ecx
  unsigned int sh_returned; // eax
  vostok::render::res_sampler_list **v6; // eax
  vostok::render::res_sampler_list *v7; // esi
  stlp_std::priv::_Rb_tree_node_base *v8; // eax
  stlp_std::priv::_Rb_tree_node_base *j; // ebx
  vostok::render::resource_manager *v10; // ecx
  unsigned int v11; // eax
  vostok::render::res_sampler_list **v12; // eax
  vostok::render::res_sampler_list *v13; // esi
  stlp_std::priv::_Rb_tree_node_base *v14; // eax
  stlp_std::priv::_Rb_tree_node_base *v15; // ebx
  bool v16; // zf
  int v17; // edi
  int v18; // eax
  vostok::render::res_sampler_list **v19; // eax
  vostok::render::res_sampler_list *v20; // esi
  vostok::render::resource_manager *v21; // [esp-4h] [ebp-18h]
  vostok::render::resource_manager *v22; // [esp-4h] [ebp-18h]
  vostok::render::resource_manager *v23; // [esp-4h] [ebp-18h]
  vostok::render::res_sampler_list *v24; // [esp+Ch] [ebp-8h]
  vostok::render::res_sampler_list *v25; // [esp+Ch] [ebp-8h]
  vostok::render::res_sampler_list *v26; // [esp+Ch] [ebp-8h]
  vostok::render::res_sampler_list *v27; // [esp+10h] [ebp-4h]
  vostok::render::res_sampler_list *v28; // [esp+10h] [ebp-4h]
  vostok::render::res_sampler_list *v29; // [esp+10h] [ebp-4h]

  for ( i = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 557400);
        i != (stlp_std::priv::_Rb_tree_node_base *)((char *)&loc_88150 + a2);
        i = v8 )
  {
    v4 = *(vostok::render::resource_manager **)&i[1]._M_color;
    sh_returned = v4->sh_returned;
    v24 = (vostok::render::res_sampler_list *)v4;
    if ( sh_returned )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v6 = (vostok::render::res_sampler_list **)(sh_returned + 940);
        v7 = *v6;
        v27 = v6[1];
        if ( *v6 != v27 )
        {
          do
          {
            v7->m_samplers.m_buffer[16] = (vostok::fixed_vector<ID3D11SamplerState *,32>::allign_helper)vostok::render::resource_manager::find_registered_sampler(v4, (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst, (const char *)v7->m_reference_count);
            v7 = (vostok::render::res_sampler_list *)((char *)v7 + 84);
          }
          while ( v7 != v27 );
          v4 = (vostok::render::resource_manager *)v24;
        }
      }
    }
    vostok::render::res_sampler_list::rebind((vostok::render::res_sampler_list *)v4, v4->sl_created);
    v8 = stlp_std::priv::_Rb_global<bool>::_M_increment(i);
    this = v21;
  }
  for ( j = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 557424);
        j != (stlp_std::priv::_Rb_tree_node_base *)(a2 + 557416);
        j = v14 )
  {
    v10 = *(vostok::render::resource_manager **)&j[1]._M_color;
    v11 = v10->sh_returned;
    v28 = (vostok::render::res_sampler_list *)v10;
    if ( v11 )
    {
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v12 = (vostok::render::res_sampler_list **)(v11 + 940);
        v13 = *v12;
        v25 = v12[1];
        if ( *v12 != v25 )
        {
          do
          {
            v13->m_samplers.m_buffer[16] = (vostok::fixed_vector<ID3D11SamplerState *,32>::allign_helper)vostok::render::resource_manager::find_registered_sampler(v10, (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst, (const char *)v13->m_reference_count);
            v13 = (vostok::render::res_sampler_list *)((char *)v13 + 84);
          }
          while ( v13 != v25 );
          v10 = (vostok::render::resource_manager *)v28;
        }
      }
    }
    vostok::render::res_sampler_list::rebind((vostok::render::res_sampler_list *)v10, v10->sl_created);
    v14 = stlp_std::priv::_Rb_global<bool>::_M_increment(j);
    this = v22;
  }
  v15 = *(stlp_std::priv::_Rb_tree_node_base **)((char *)&loc_88188 + a2);
  v29 = (vostok::render::res_sampler_list *)(a2 + 557440);
  v16 = v15 == (stlp_std::priv::_Rb_tree_node_base *)(a2 + 557440);
  while ( !v16 )
  {
    v17 = *(_DWORD *)&v15[1]._M_color;
    v18 = *(_DWORD *)(v17 + 4);
    if ( v18 )
    {
      this = (vostok::render::resource_manager *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
      if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
      {
        v19 = (vostok::render::res_sampler_list **)(v18 + 940);
        v20 = *v19;
        v26 = v19[1];
        if ( *v19 != v26 )
        {
          do
          {
            v20->m_samplers.m_buffer[16] = (vostok::fixed_vector<ID3D11SamplerState *,32>::allign_helper)vostok::render::resource_manager::find_registered_sampler(this, (int)vostok::quasi_singleton<vostok::render::resource_manager>::pinst, (const char *)v20->m_reference_count);
            v20 = (vostok::render::res_sampler_list *)((char *)v20 + 84);
          }
          while ( v20 != v26 );
        }
      }
    }
    vostok::render::res_sampler_list::rebind((vostok::render::res_sampler_list *)this, *(_DWORD *)(v17 + 16));
    v15 = stlp_std::priv::_Rb_global<bool>::_M_increment(v15);
    v16 = v15 == (stlp_std::priv::_Rb_tree_node_base *)v29;
    this = v23;
  }
}
