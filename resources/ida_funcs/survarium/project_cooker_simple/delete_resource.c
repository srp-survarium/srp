void __thiscall survarium::project_cooker_simple::delete_resource(
        survarium::project_cooker_simple *this,
        vostok::resources::resource_base *resource)
{
  vostok::resources::resource_base *v2; // ebx
  void ***m_current_satisfaction_low; // edi
  void **v4; // esi
  int f; // ebp
  _BYTE *v6; // ebx
  void *v7; // esi
  stlp_std::priv::_Rb_tree_node_base *i; // edi
  int v9; // esi
  _BYTE *v10; // eax
  void ***color; // ebp
  void **v12; // esi
  int v13; // edi
  _BYTE *v14; // ebx
  void *v15; // esi
  void ***v16; // ebp
  void **v17; // esi
  int v18; // edi
  _BYTE *v19; // ebx
  void *v20; // esi
  void **type; // eax
  void **v22; // ecx
  void **v23; // esi
  int v24; // edi
  _BYTE *v25; // esi
  void *v26; // eax
  void *v27; // esi
  float it_e; // [esp+10h] [ebp-4h]
  survarium::game_object_ **it_ea; // [esp+10h] [ebp-4h]
  survarium::game_object_ **it_eb; // [esp+10h] [ebp-4h]

  v2 = resource;
  m_current_satisfaction_low = (void ***)LODWORD(resource[1].m_current_satisfaction);
  for ( it_e = resource[1].m_target_satisfaction;
        m_current_satisfaction_low != (void ***)LODWORD(it_e);
        ++m_current_satisfaction_low )
  {
    v4 = *m_current_satisfaction_low;
    f = (int)survarium::g_allocator.f_.f_;
    if ( *m_current_satisfaction_low )
    {
      v6 = __RTCastToVoid(*m_current_satisfaction_low);
      (*(void (__thiscall **)(void **, _DWORD))*v4)(v4, 0);
      if ( v6 )
      {
        v7 = *(void **)(f + 20);
        *(_BYTE *)(f + 42) = 0;
        vostok_mspace_free(v7, v6);
      }
      v2 = resource;
    }
  }
  for ( i = (stlp_std::priv::_Rb_tree_node_base *)v2[1].m_class_id;
        i != (stlp_std::priv::_Rb_tree_node_base *)&v2[1].m_current_quality_level;
        i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
  {
    v9 = (int)survarium::g_allocator.f_.f_;
    if ( i[1]._M_parent )
    {
      v10 = __RTCastToVoid((void **)i[1]._M_parent);
      if ( v10 )
      {
        *(_BYTE *)(v9 + 42) = 0;
        vostok_mspace_free(*(void **)(v9 + 20), v10);
      }
    }
  }
  if ( v2[1].grm_satisfaction_tree_hook.left_ )
  {
    stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::_M_erase(
      (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)&v2[1].m_current_quality_level,
      (stlp_std::priv::_Rb_tree_node_base *)v2[1].m_target_quality_level);
    v2[1].m_class_id = (vostok::resources::class_id_enum)&v2[1].m_current_quality_level;
    v2[1].m_target_quality_level = 0;
    v2[1].grm_satisfaction_tree_hook.parent_ = (boost::intrusive::rbtree_node<void *> *)&v2[1].m_current_quality_level;
    v2[1].grm_satisfaction_tree_hook.left_ = 0;
  }
  color = (void ***)v2[1].grm_satisfaction_tree_hook.color_;
  for ( it_ea = (survarium::game_object_ **)v2[1].m_next_in_memory_type; color != (void ***)it_ea; ++color )
  {
    v12 = *color;
    v13 = (int)survarium::g_allocator.f_.f_;
    if ( *color )
    {
      v14 = __RTCastToVoid(*color);
      (*((void (__thiscall **)(void **, _DWORD))*v12 + 3))(v12, 0);
      if ( v14 )
      {
        v15 = *(void **)(v13 + 20);
        *(_BYTE *)(v13 + 42) = 0;
        vostok_mspace_free(v15, v14);
      }
      v2 = resource;
    }
  }
  v16 = (void ***)v2[2].__vftable;
  for ( it_eb = (survarium::game_object_ **)v2[2].type; v16 != (void ***)it_eb; ++v16 )
  {
    v17 = *v16;
    v18 = (int)survarium::g_allocator.f_.f_;
    if ( *v16 )
    {
      v19 = __RTCastToVoid(*v16);
      (*(void (__thiscall **)(void **, _DWORD))*v17)(v17, 0);
      if ( v19 )
      {
        v20 = *(void **)(v18 + 20);
        *(_BYTE *)(v18 + 42) = 0;
        vostok_mspace_free(v20, v19);
      }
      v2 = resource;
    }
  }
  type = (void **)v2[2].type;
  v22 = (void **)&v2[2].~vostok::resources::resource_base;
  if ( v22 != type )
  {
    v23 = stlp_std::priv::__copy_ptrs<void * *,void * *>(type, type, v22);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    v2[2].type = (unsigned int)v23;
  }
  v24 = (int)survarium::g_allocator.f_.f_;
  v25 = __RTCastToVoid((void **)&v2->__vftable);
  ((void (__thiscall *)(vostok::resources::resource_base *, _DWORD))v2->~vostok::resources::resource_base)(v2, 0);
  if ( v25 )
  {
    v26 = v25;
    v27 = *(void **)(v24 + 20);
    *(_BYTE *)(v24 + 42) = 0;
    vostok_mspace_free(v27, v26);
  }
}
