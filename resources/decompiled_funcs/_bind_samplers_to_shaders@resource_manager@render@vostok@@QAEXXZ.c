void __thiscall vostok::render::resource_manager::bind_samplers_to_shaders(
        vostok::render::resource_manager *this,
        vostok::render::resource_manager *thisa)
{
  vostok::render::resource_manager *v2; // ebp
  stlp_std::priv::_Rb_tree_node_base *i; // edi
  vostok::render::resource_manager *M_left; // eax
  _DWORD *v5; // esi
  unsigned int v6; // ebx
  int v7; // ebp
  vostok::render::resource_manager *v8; // eax
  stlp_std::priv::_Rb_tree_node_base *p_M_data; // edi
  _DWORD *v10; // esi
  unsigned int v11; // ebx
  int v12; // ebp
  stlp_std::priv::_Rb_tree_node_base *it; // [esp+10h] [ebp-4h]
  stlp_std::priv::_Rb_tree_iterator<vostok::render::res_xs<vostok::render::gs_data> *,stlp_std::priv::_SetTraitsT<vostok::render::res_xs<vostok::render::gs_data> *> > ita; // [esp+10h] [ebp-4h]
  vostok::render::resource_manager *thisb; // [esp+18h] [ebp+4h]

  v2 = thisa;
  for ( i = thisa->m_v_shaders._M_t._M_header._M_data._M_left;
        i != (stlp_std::priv::_Rb_tree_node_base *)&thisa->m_v_shaders;
        i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
  {
    vostok::render::res_sampler_list::rebind((vostok::render::res_sampler_list *)this);
  }
  M_left = (vostok::render::resource_manager *)thisa->m_g_shaders._M_t._M_header._M_data._M_left;
  it = (stlp_std::priv::_Rb_tree_node_base *)M_left;
  if ( M_left != (vostok::render::resource_manager *)&thisa->m_g_shaders )
  {
    while ( 1 )
    {
      v5 = *(_DWORD **)(M_left->sl_created + 16);
      v6 = 0;
      if ( (v5[2] - v5[1]) >> 2 )
      {
        v7 = 0;
        do
        {
          *(_DWORD *)(v5[1] + 4 * v6++) = vostok::render::resource_manager::find_registered_sampler(
                                            (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                            *(const char **)(v5[4] + v7));
          v7 += 44;
        }
        while ( v6 < (v5[2] - v5[1]) >> 2 );
        M_left = (vostok::render::resource_manager *)it;
        v2 = thisa;
      }
      it = stlp_std::priv::_Rb_global<bool>::_M_increment((stlp_std::priv::_Rb_tree_node_base *)M_left);
      if ( it == (stlp_std::priv::_Rb_tree_node_base *)&v2->m_g_shaders )
        break;
      M_left = (vostok::render::resource_manager *)it;
    }
  }
  v8 = (vostok::render::resource_manager *)v2->m_p_shaders._M_t._M_header._M_data._M_left;
  p_M_data = &v2->m_p_shaders._M_t._M_header._M_data;
  thisb = v8;
  ita._M_node = &v2->m_p_shaders._M_t._M_header._M_data;
  if ( v8 != (vostok::render::resource_manager *)&v2->m_p_shaders )
  {
    while ( 1 )
    {
      v10 = *(_DWORD **)(v8->sl_created + 16);
      v11 = 0;
      if ( (v10[2] - v10[1]) >> 2 )
      {
        v12 = 0;
        do
        {
          *(_DWORD *)(v10[1] + 4 * v11++) = vostok::render::resource_manager::find_registered_sampler(
                                              (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                                              *(const char **)(v10[4] + v12));
          v12 += 44;
        }
        while ( v11 < (v10[2] - v10[1]) >> 2 );
        v8 = thisb;
        p_M_data = ita._M_node;
      }
      thisb = (vostok::render::resource_manager *)stlp_std::priv::_Rb_global<bool>::_M_increment((stlp_std::priv::_Rb_tree_node_base *)v8);
      if ( thisb == (vostok::render::resource_manager *)p_M_data )
        break;
      v8 = thisb;
    }
  }
}
