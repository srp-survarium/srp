void __usercall vostok::render::resource_manager::~resource_manager(
        vostok::render::resource_manager *this@<ecx>,
        int a2@<eax>)
{
  void **v3; // eax
  void **v4; // ecx
  void *v5; // esi
  void *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v8; // esi
  vostok::render::grass_render_model *m_object; // ebp
  void *v10; // eax
  void *v11; // esi
  void *v12; // esi
  vostok::render::grass_render_model *v13; // ebp
  void *v14; // eax
  void *v15; // esi
  vostok::render::res_texture *v16; // ecx
  int v17; // eax
  void *v18; // eax
  void *v19; // esi
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *v20; // ecx
  void *v21; // eax
  void *v22; // esi
  void *v23; // eax
  void *v24; // esi
  void *v25; // eax
  void *v26; // esi
  void *v27; // eax
  void *v28; // esi
  void *v29; // eax
  void *v30; // esi
  void *v31; // eax
  void *v32; // esi
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *v33; // ecx
  void *v34; // eax
  void *v35; // esi
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *v36; // ecx
  void *v37; // eax
  void *v38; // esi
  vostok::render::state_cache<ID3D11RasterizerState,D3D11_RASTERIZER_DESC> *v39; // ecx
  void *v40; // eax
  void *v41; // esi
  void *v42; // eax
  void *v43; // esi
  void *v44; // eax
  void *v45; // esi
  int v46; // eax
  void (__cdecl *v47)(int, int, int); // eax
  void *v48; // eax
  void *v49; // esi
  int v50; // eax

  if ( *(_DWORD *)(a2 + 400) != *(_DWORD *)(a2 + 404) )
  {
    do
    {
      v3 = *(void ***)(a2 + 400);
      v4 = *(void ***)(a2 + 404);
      v5 = *v3;
      if ( v3 + 1 != v4 )
        stlp_std::priv::__copy_ptrs<void * *,void * *>(v3 + 1, v4, v3);
      *(_DWORD *)(a2 + 404) -= 4;
      if ( v5 )
      {
        v6 = v5;
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
        BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      }
      this = *(vostok::render::resource_manager **)(a2 + 400);
    }
    while ( this != *(vostok::render::resource_manager **)(a2 + 404) );
  }
  v8 = *(void **)(a2 + 680);
  m_object = vostok::render::g_allocator.m_object;
  if ( v8 )
  {
    vostok::render::texture_storage::~texture_storage((vostok::render::texture_storage *)this);
    v10 = v8;
    v11 = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v11, v10);
    *(_DWORD *)(a2 + 680) = 0;
  }
  v12 = *(void **)(a2 + 684);
  v13 = vostok::render::g_allocator.m_object;
  if ( v12 )
  {
    vostok::render::texture_storage::~texture_storage((vostok::render::texture_storage *)this);
    v14 = v12;
    v15 = (void *)HIDWORD(v13->m_reconstruction_info_actuality_tick);
    BYTE2(v13->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v15, v14);
    *(_DWORD *)(a2 + 684) = 0;
  }
  vostok::resources::resources_manager::unregister_cook(shader_binary_source_class);
  v17 = *(_DWORD *)(a2 + 712);
  if ( v17 )
  {
    if ( !--*(_DWORD *)(v17 + 4) )
      vostok::render::res_texture::destroy_impl(v16, *(const vostok::render::res_texture **)(a2 + 712));
  }
  v18 = *(void **)(a2 + 700);
  if ( v18 )
  {
    v19 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v19, v18);
  }
  stlp_std::__destroy_range_aux<stlp_std::reverse_iterator<vostok::render::shader_constant_binding *>,vostok::render::shader_constant_binding>(
    *(stlp_std::reverse_iterator<vostok::render::shader_constant_binding *> *)(a2 + 672),
    *(stlp_std::reverse_iterator<vostok::render::shader_constant_binding *> *)(a2 + 668));
  v21 = *(void **)(a2 + 668);
  if ( v21 )
  {
    v22 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v22, v21);
  }
  if ( *(_DWORD *)(a2 + 656) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 640),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 644));
    *(_DWORD *)(a2 + 648) = a2 + 640;
    *(_DWORD *)(a2 + 644) = 0;
    *(_DWORD *)(a2 + 652) = a2 + 640;
    *(_DWORD *)(a2 + 656) = 0;
  }
  v23 = *(void **)(a2 + 628);
  if ( v23 )
  {
    v24 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v24, v23);
  }
  v25 = *(void **)(a2 + 616);
  if ( v25 )
  {
    v26 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v26, v25);
  }
  v27 = *(void **)(a2 + 604);
  if ( v27 )
  {
    v28 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v28, v27);
  }
  v29 = *(void **)(a2 + 592);
  if ( v29 )
  {
    v30 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v30, v29);
  }
  v31 = *(void **)(a2 + 580);
  if ( v31 )
  {
    v32 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v32, v31);
  }
  if ( *(_DWORD *)(a2 + 572) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 556),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 560));
    *(_DWORD *)(a2 + 564) = a2 + 556;
    *(_DWORD *)(a2 + 560) = 0;
    *(_DWORD *)(a2 + 568) = a2 + 556;
    *(_DWORD *)(a2 + 572) = 0;
  }
  if ( *(_DWORD *)(a2 + 548) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 532),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 536));
    *(_DWORD *)(a2 + 540) = a2 + 532;
    *(_DWORD *)(a2 + 536) = 0;
    *(_DWORD *)(a2 + 544) = a2 + 532;
    *(_DWORD *)(a2 + 548) = 0;
  }
  if ( *(_DWORD *)(a2 + 524) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 508),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 512));
    *(_DWORD *)(a2 + 516) = a2 + 508;
    *(_DWORD *)(a2 + 512) = 0;
    *(_DWORD *)(a2 + 520) = a2 + 508;
    *(_DWORD *)(a2 + 524) = 0;
  }
  if ( *(_DWORD *)(a2 + 500) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 484),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 488));
    *(_DWORD *)(a2 + 492) = a2 + 484;
    *(_DWORD *)(a2 + 488) = 0;
    *(_DWORD *)(a2 + 496) = a2 + 484;
    *(_DWORD *)(a2 + 500) = 0;
  }
  if ( *(_DWORD *)(a2 + 476) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 460),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 464));
    *(_DWORD *)(a2 + 468) = a2 + 460;
    *(_DWORD *)(a2 + 464) = 0;
    *(_DWORD *)(a2 + 472) = a2 + 460;
    *(_DWORD *)(a2 + 476) = 0;
  }
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::clear_state_array(
    v20,
    (_DWORD *)(a2 + 448));
  v34 = *(void **)(a2 + 448);
  if ( v34 )
  {
    v35 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v35, v34);
  }
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::clear_state_array(
    v33,
    (_DWORD *)(a2 + 436));
  v37 = *(void **)(a2 + 436);
  if ( v37 )
  {
    v38 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v38, v37);
  }
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::clear_state_array(
    v36,
    (_DWORD *)(a2 + 424));
  v40 = *(void **)(a2 + 424);
  if ( v40 )
  {
    v41 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v41, v40);
  }
  vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC>::clear_state_array(
    v39,
    (_DWORD *)(a2 + 412));
  v42 = *(void **)(a2 + 412);
  if ( v42 )
  {
    v43 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v43, v42);
  }
  v44 = *(void **)(a2 + 400);
  if ( v44 )
  {
    v45 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v45, v44);
  }
  if ( *(_DWORD *)(a2 + 392) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 376),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 380));
    *(_DWORD *)(a2 + 384) = a2 + 376;
    *(_DWORD *)(a2 + 380) = 0;
    *(_DWORD *)(a2 + 388) = a2 + 376;
    *(_DWORD *)(a2 + 392) = 0;
  }
  if ( *(_DWORD *)(a2 + 368) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 352),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 356));
    *(_DWORD *)(a2 + 360) = a2 + 352;
    *(_DWORD *)(a2 + 356) = 0;
    *(_DWORD *)(a2 + 364) = a2 + 352;
    *(_DWORD *)(a2 + 368) = 0;
  }
  if ( *(_DWORD *)(a2 + 344) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 328),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 332));
    *(_DWORD *)(a2 + 336) = a2 + 328;
    *(_DWORD *)(a2 + 332) = 0;
    *(_DWORD *)(a2 + 340) = a2 + 328;
    *(_DWORD *)(a2 + 344) = 0;
  }
  v46 = *(_DWORD *)(a2 + 272);
  if ( v46 )
  {
    if ( (v46 & 1) == 0 )
    {
      v47 = *(void (__cdecl **)(int, int, int))(v46 & 0xFFFFFFFE);
      if ( v47 )
        v47(a2 + 280, a2 + 280, 2);
    }
    *(_DWORD *)(a2 + 272) = 0;
  }
  v48 = *(void **)(a2 + 212);
  if ( v48 )
  {
    v49 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v49, v48);
  }
  if ( *(_DWORD *)(a2 + 204) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 188),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 192));
    *(_DWORD *)(a2 + 196) = a2 + 188;
    *(_DWORD *)(a2 + 192) = 0;
    *(_DWORD *)(a2 + 200) = a2 + 188;
    *(_DWORD *)(a2 + 204) = 0;
  }
  if ( *(_DWORD *)(a2 + 180) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 164),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 168));
    *(_DWORD *)(a2 + 172) = a2 + 164;
    *(_DWORD *)(a2 + 168) = 0;
    *(_DWORD *)(a2 + 176) = a2 + 164;
    *(_DWORD *)(a2 + 180) = 0;
  }
  if ( *(_DWORD *)(a2 + 156) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 140),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 144));
    *(_DWORD *)(a2 + 148) = a2 + 140;
    *(_DWORD *)(a2 + 144) = 0;
    *(_DWORD *)(a2 + 152) = a2 + 140;
    *(_DWORD *)(a2 + 156) = 0;
  }
  if ( *(_DWORD *)(a2 + 132) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 116),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 120));
    *(_DWORD *)(a2 + 124) = a2 + 116;
    *(_DWORD *)(a2 + 120) = 0;
    *(_DWORD *)(a2 + 128) = a2 + 116;
    *(_DWORD *)(a2 + 132) = 0;
  }
  if ( *(_DWORD *)(a2 + 108) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 92),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 96));
    *(_DWORD *)(a2 + 100) = a2 + 92;
    *(_DWORD *)(a2 + 96) = 0;
    *(_DWORD *)(a2 + 104) = a2 + 92;
    *(_DWORD *)(a2 + 108) = 0;
  }
  if ( *(_DWORD *)(a2 + 84) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 68),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 72));
    *(_DWORD *)(a2 + 76) = a2 + 68;
    *(_DWORD *)(a2 + 72) = 0;
    *(_DWORD *)(a2 + 80) = a2 + 68;
    *(_DWORD *)(a2 + 84) = 0;
  }
  if ( *(_DWORD *)(a2 + 60) )
  {
    stlp_std::priv::_Rb_tree<vostok::render::res_effect *,vostok::render::effect_manager::compare_predicate<vostok::render::res_effect>,vostok::render::res_effect *,stlp_std::priv::_Identity<vostok::render::res_effect *>,stlp_std::priv::_SetTraitsT<vostok::render::res_effect *>,vostok::render::std_allocator<vostok::render::res_effect *>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::texture_pool *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::texture_pool *> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::texture_pool *> > > *)(a2 + 44),
      *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 48));
    *(_DWORD *)(a2 + 52) = a2 + 44;
    *(_DWORD *)(a2 + 48) = 0;
    *(_DWORD *)(a2 + 56) = a2 + 44;
    *(_DWORD *)(a2 + 60) = 0;
  }
  v50 = *(_DWORD *)(a2 + 28);
  if ( v50 && !_InterlockedExchangeAdd((volatile signed __int32 *)(v50 + 208), 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)(*(_DWORD *)(a2 + 28) + 208),
      *(vostok::resources::unmanaged_resource **)(a2 + 28));
  `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] = 0;
}
