void __thiscall vostok::render::renderer::~renderer(
        vostok::render::renderer *this,
        stlp_std::reverse_iterator<vostok::render::stage * *> e)
{
  vostok::render::stage **current; // ebp
  _DWORD *v3; // esi
  vostok::render::grass_render_model *m_object; // edi
  void *v5; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  vostok::render::stage *v7; // esi
  vostok::render::grass_render_model *v8; // edi
  vostok::render::stage *v9; // eax
  void *v10; // esi
  vostok::render::stage **v11; // ecx
  vostok::render::stage **v12; // edi
  vostok::render::grass_render_model *v13; // ebx
  _BYTE *v14; // esi
  void *v15; // eax
  void *v16; // esi
  vostok::render::grass_render_model *v17; // edi
  _BYTE *v18; // esi
  void *v19; // eax
  void *v20; // esi
  vostok::render::grass_render_model *v21; // edi
  _BYTE *v22; // esi
  void *v23; // eax
  void *v24; // esi
  vostok::render::grass_render_model *v25; // edi
  _BYTE *v26; // esi
  void *v27; // eax
  void *v28; // esi
  vostok::render::grass_render_model *v29; // edi
  _BYTE *v30; // esi
  void *v31; // eax
  void *v32; // esi
  void *v33; // esi
  vostok::render::renderer **p_m_renderer; // eax
  void *v35; // esi
  vostok::render::renderer **v36; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v37; // ecx
  vostok::render::stage *v38; // eax
  vostok::render::stage *v39; // eax
  vostok::render::stage *v40; // eax
  vostok::render::stage *v41; // eax
  vostok::render::stage *v42; // eax
  vostok::render::stage *v43; // eax
  vostok::render::stage *v44; // eax
  bool v45; // zf
  vostok::render::stage *v46; // esi
  survarium::options_tab *v47; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v48; // eax
  vostok::render::stage *v49; // eax
  const vostok::render::res_texture *v50; // esi
  survarium::options_tab *v51; // edi
  const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v52; // eax
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v53; // ecx
  vostok::render::stage **v54; // esi
  int v55; // eax
  vostok::render::stage *v56; // ebx
  survarium::options_tab *v57; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v58; // eax
  stlp_std::priv::_Rb_tree_node_base *v59; // eax
  void *v60; // esi
  vostok::render::grass_render_model *v61; // esi
  _BYTE *v62; // edi
  vostok::render::stage **v63; // esi
  int v64; // eax
  vostok::render::stage *v65; // ebx
  survarium::options_tab *v66; // edi
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v67; // eax
  stlp_std::priv::_Rb_tree_node_base *v68; // eax
  void *v69; // esi
  vostok::render::grass_render_model *v70; // esi
  _BYTE *v71; // edi
  vostok::render::resource_manager **v72; // ebp
  int i; // esi
  _DWORD *v74; // eax
  stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::render_target *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::render_target *> > > v75; // [esp+Ch] [ebp-24h] BYREF
  int m_begin; // [esp+24h] [ebp-Ch] BYREF
  vostok::render::stage_vtbl *v77; // [esp+28h] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *v78; // [esp+2Ch] [ebp-4h] BYREF

  current = e.current;
  v3 = (_DWORD *)*((_DWORD *)e.current + 24);
  m_object = vostok::render::g_allocator.m_object;
  if ( v3 )
  {
    if ( *v3 )
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)*v3 + 8))(*v3);
    *v3 = 0;
    v5 = v3;
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
    BYTE2(m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v5);
    current[24] = 0;
  }
  v7 = current[25];
  v8 = vostok::render::g_allocator.m_object;
  if ( v7 )
  {
    if ( v7->__vftable )
      (*((void (__stdcall **)(vostok::render::stage_vtbl *))v7->~vostok::render::stage + 2))(v7->__vftable);
    v7->__vftable = 0;
    v9 = v7;
    v10 = (void *)HIDWORD(v8->m_reconstruction_info_actuality_tick);
    BYTE2(v8->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v10, v9);
    current[25] = 0;
  }
  v11 = (vostok::render::stage **)current[54];
  v12 = (vostok::render::stage **)current[55];
  for ( e.current = v11; v12 != v11; --v12 )
  {
    v13 = vostok::render::g_allocator.m_object;
    if ( *(v12 - 1) )
    {
      v14 = __RTCastToVoid((void **)&(*(v12 - 1))->__vftable);
      ((void (__thiscall *)(_DWORD, _DWORD))(*(v12 - 1))->~vostok::render::stage)(*(v12 - 1), 0);
      if ( v14 )
      {
        v15 = v14;
        v16 = (void *)HIDWORD(v13->m_reconstruction_info_actuality_tick);
        BYTE2(v13->m_children_resources.m_lock) = 0;
        vostok_mspace_free(v16, v15);
      }
      v11 = e.current;
      *(v12 - 1) = 0;
    }
  }
  v17 = vostok::render::g_allocator.m_object;
  if ( current[92] )
  {
    v18 = __RTCastToVoid((void **)&current[92]->__vftable);
    ((void (__thiscall *)(vostok::render::stage *, _DWORD))current[92]->~vostok::render::stage)(current[92], 0);
    if ( v18 )
    {
      v19 = v18;
      v20 = (void *)HIDWORD(v17->m_reconstruction_info_actuality_tick);
      BYTE2(v17->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v20, v19);
    }
    current[92] = 0;
  }
  v21 = vostok::render::g_allocator.m_object;
  if ( current[90] )
  {
    v22 = __RTCastToVoid((void **)&current[90]->__vftable);
    ((void (__thiscall *)(vostok::render::stage *, _DWORD))current[90]->~vostok::render::stage)(current[90], 0);
    if ( v22 )
    {
      v23 = v22;
      v24 = (void *)HIDWORD(v21->m_reconstruction_info_actuality_tick);
      BYTE2(v21->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v24, v23);
    }
    current[90] = 0;
  }
  v25 = vostok::render::g_allocator.m_object;
  if ( current[89] )
  {
    v26 = __RTCastToVoid((void **)&current[89]->__vftable);
    ((void (__thiscall *)(vostok::render::stage *, _DWORD))current[89]->~vostok::render::stage)(current[89], 0);
    if ( v26 )
    {
      v27 = v26;
      v28 = (void *)HIDWORD(v25->m_reconstruction_info_actuality_tick);
      BYTE2(v25->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v28, v27);
    }
    current[89] = 0;
  }
  v29 = vostok::render::g_allocator.m_object;
  if ( current[91] )
  {
    v30 = __RTCastToVoid((void **)&current[91]->__vftable);
    ((void (__thiscall *)(vostok::render::stage *, _DWORD))current[91]->~vostok::render::stage)(current[91], 0);
    if ( v30 )
    {
      v31 = v30;
      v32 = (void *)HIDWORD(v29->m_reconstruction_info_actuality_tick);
      BYTE2(v29->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v32, v31);
    }
    current[91] = 0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)(current + 146));
  v33 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  p_m_renderer = &current[139][-1].m_renderer;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v33, p_m_renderer);
  v35 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
  v36 = &current[140][-1].m_renderer;
  BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
  vostok_mspace_free(v35, v36);
  v38 = current[115];
  if ( v38 )
  {
    v37 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)_InterlockedExchangeAdd((volatile signed __int32 *)&v38[13], 0xFFFFFFFF);
    if ( !v37 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)&current[115][13],
        (vostok::resources::unmanaged_resource *)current[115]);
  }
  v39 = current[114];
  if ( v39 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v39[13], 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)&current[114][13],
      (vostok::resources::unmanaged_resource *)current[114]);
  v40 = current[113];
  if ( v40 )
  {
    v37 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)_InterlockedExchangeAdd((volatile signed __int32 *)&v40[13], 0xFFFFFFFF);
    if ( !v37 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)&current[113][13],
        (vostok::resources::unmanaged_resource *)current[113]);
  }
  v41 = current[112];
  if ( v41 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v41[13], 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)&current[112][13],
      (vostok::resources::unmanaged_resource *)current[112]);
  v42 = current[111];
  if ( v42 )
  {
    v37 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)_InterlockedExchangeAdd((volatile signed __int32 *)&v42[13], 0xFFFFFFFF);
    if ( !v37 )
      vostok::resources::unmanaged_intrusive_base::destroy(
        (vostok::resources::unmanaged_intrusive_base *)&current[111][13],
        (vostok::resources::unmanaged_resource *)current[111]);
  }
  v43 = current[110];
  if ( v43 && !_InterlockedExchangeAdd((volatile signed __int32 *)&v43[13], 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(
      (vostok::resources::unmanaged_intrusive_base *)&current[110][13],
      (vostok::resources::unmanaged_resource *)current[110]);
  v44 = current[86];
  if ( v44 )
  {
    v45 = v44->m_context-- == (vostok::render::renderer_context *)1;
    if ( v45 )
    {
      v46 = current[86];
      if ( HIBYTE(v46[27].m_context) )
      {
        v47 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
        e.current = (vostok::render::stage **)v46[9].__vftable;
        v48 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&e,
                (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                (const char **)&e);
        if ( v48 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v47 )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            &v75,
            (int)v47,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v48);
          vostok::render::resource_manager::release_impl(
            (const vostok::render::res_texture *)v46,
            (vostok::render::resource_manager *)v75._M_t._M_header._M_data._M_parent);
        }
      }
    }
  }
  v49 = current[85];
  if ( v49 )
  {
    v45 = v49->m_context-- == (vostok::render::renderer_context *)1;
    if ( v45 )
    {
      v50 = (const vostok::render::res_texture *)current[85];
      if ( v50->m_is_registered )
      {
        v51 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
        m_begin = (int)v50->m_name.m_string.m_begin;
        v52 = stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(
                v37,
                (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7],
                (const char **)&m_begin);
        if ( v52 != (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v51 )
        {
          stlp_std::map<vostok::fs_new::virtual_path_string,vostok::render::res_texture *,vostok::render::resource_manager::str_pred,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::erase(
            &v75,
            (int)v51,
            (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::render_target *> > >)v52);
          vostok::render::resource_manager::release_impl(
            v50,
            (vostok::render::resource_manager *)v75._M_t._M_header._M_data._M_parent);
        }
      }
    }
  }
  v53 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)current[54];
  current[55] = (vostok::render::stage *)v53;
  v54 = current + 38;
  for ( m_begin = 3; m_begin >= 0; --m_begin )
  {
    v55 = (int)*--v54;
    e.current = v54;
    if ( v55 )
    {
      v45 = (*(_DWORD *)(v55 + 4))-- == 1;
      if ( v45 )
      {
        v56 = *v54;
        if ( HIBYTE((*v54)[27].m_context) )
        {
          v57 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          v77 = v56[9].__vftable;
          v58 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(v53, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&v77);
          if ( v58 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v57 )
          {
            v59 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                    &v58->_M_header._M_data,
                    (stlp_std::priv::_Rb_tree_node_base **)&v57->m_options_count,
                    (stlp_std::priv::_Rb_tree_node_base **)&v57->m_type,
                    (stlp_std::priv::_Rb_tree_node_base **)&v57->m_game);
            if ( v59 )
            {
              v60 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v60, v59);
            }
            --v57->m_movie;
            v61 = vostok::render::g_allocator.m_object;
            v62 = __RTCastToVoid((void **)&v56->__vftable);
            ((void (__thiscall *)(vostok::render::stage *, _DWORD))v56->~vostok::render::stage)(v56, 0);
            if ( v62 )
            {
              BYTE2(v61->m_children_resources.m_lock) = 0;
              vostok_mspace_free((void *)HIDWORD(v61->m_reconstruction_info_actuality_tick), v62);
            }
            v54 = e.current;
          }
        }
      }
    }
  }
  v63 = current + 34;
  for ( m_begin = 3; m_begin >= 0; --m_begin )
  {
    v64 = (int)*--v63;
    e.current = v63;
    if ( v64 )
    {
      v45 = (*(_DWORD *)(v64 + 4))-- == 1;
      if ( v45 )
      {
        v65 = *v63;
        if ( HIBYTE((*v63)[27].m_context) )
        {
          v66 = `boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3] + 7;
          v78 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v65[9].__vftable;
          v67 = (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const,vostok::render::res_texture *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *>>>::_M_find<char const *>(v78, (const stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)&`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3][7], (const char **)&v78);
          if ( v67 != (stlp_std::priv::_Rb_tree<vostok::fs_new::virtual_path_string,vostok::render::resource_manager::str_pred,stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fs_new::virtual_path_string const ,vostok::render::res_texture *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fs_new::virtual_path_string,vostok::render::res_texture *> > > *)v66 )
          {
            v68 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(
                    &v67->_M_header._M_data,
                    (stlp_std::priv::_Rb_tree_node_base **)&v66->m_options_count,
                    (stlp_std::priv::_Rb_tree_node_base **)&v66->m_type,
                    (stlp_std::priv::_Rb_tree_node_base **)&v66->m_game);
            if ( v68 )
            {
              v69 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
              BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
              vostok_mspace_free(v69, v68);
            }
            --v66->m_movie;
            v70 = vostok::render::g_allocator.m_object;
            v71 = __RTCastToVoid((void **)&v65->__vftable);
            ((void (__thiscall *)(vostok::render::stage *, _DWORD))v65->~vostok::render::stage)(v65, 0);
            if ( v71 )
            {
              BYTE2(v70->m_children_resources.m_lock) = 0;
              vostok_mspace_free((void *)HIDWORD(v70->m_reconstruction_info_actuality_tick), v71);
            }
            v63 = e.current;
          }
        }
      }
    }
  }
  v72 = (vostok::render::resource_manager **)(current + 30);
  for ( i = 3; i >= 0; --i )
  {
    v74 = *--v72;
    if ( v74 )
    {
      v45 = (*v74)-- == 1;
      if ( v45 )
        vostok::render::resource_manager::release(
          *v72,
          (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
          (const char *)*v72);
    }
  }
}
