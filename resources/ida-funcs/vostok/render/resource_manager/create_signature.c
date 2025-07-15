vostok::render::res_signature *__userpurge vostok::render::resource_manager::create_signature@<eax>(
        ID3D10Blob *signature@<edi>,
        vostok::render::res_signature *this)
{
  ID3D10Blob_vtbl *v2; // eax
  vostok::render::res_signature *v3; // ebx
  vostok::render::resource_manager *v4; // esi
  unsigned int m_signature; // esi
  vostok::memory::doug_lea_allocator *v7; // esi
  char *v8; // eax
  vostok::memory::doug_lea_allocator *v9; // ecx
  char *v10; // eax
  stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *> > *v11; // ecx
  char *v12; // esi
  stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *> > *v13; // [esp-8h] [ebp-2Ch]
  stlp_std::priv::_Rb_tree_node_base v14; // [esp-4h] [ebp-28h] BYREF
  ID3D10Blob *v15; // [esp+Ch] [ebp-18h]
  char v16; // [esp+10h] [ebp-14h]
  char v17[4]; // [esp+14h] [ebp-10h] BYREF
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_signature *,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *> >,bool> *result; // [esp+18h] [ebp-Ch]
  vostok::render::res_signature *__x; // [esp+1Ch] [ebp-8h] BYREF

  v2 = signature->lpVtbl;
  v3 = 0;
  v14._M_right = 0;
  v15 = signature;
  v16 = 0;
  v2->AddRef(signature);
  __x = (vostok::render::res_signature *)&v14._M_right;
  v4 = (vostok::render::resource_manager *)((char *)&loc_93900 + (_DWORD)this);
  result = (stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_signature *,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *> >,bool> *)((char *)&loc_93900 + (_DWORD)this);
  stlp_std::set<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::std_allocator<vostok::render::res_signature *>>::find<vostok::render::res_signature *>(
    &__x,
    (stlp_std::set<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::std_allocator<vostok::render::res_signature *> > *)((char *)&loc_93900 + (_DWORD)this),
    (stlp_std::priv::_Rb_tree_iterator<vostok::render::res_signature *,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *> > *)&this);
  if ( this == (vostok::render::res_signature *)v4 )
  {
    if ( v15 )
    {
      v15->Release(v15);
      v15 = 0;
    }
    v7 = vostok::render::g_allocator;
    v8 = type_info::raw_name(&vostok::render::res_signature `RTTI Type Descriptor');
    v10 = vostok::memory::doug_lea_allocator::malloc_impl(
            v9,
            (int)v7,
            0xCu,
            v8,
            (const char *const)&v14._M_parent->_M_color,
            (const char *const)&v14._M_left->_M_color,
            (const unsigned int)v14._M_right);
    v12 = v10;
    if ( v10 )
    {
      *(_DWORD *)v10 = 0;
      *((_DWORD *)v10 + 1) = signature;
      v10[8] = 0;
      signature->AddRef(signature);
      v3 = (vostok::render::res_signature *)v12;
    }
    *(_DWORD *)&v14._M_color = &this;
    v13 = (stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *> > *)result;
    this = v3;
    v3->m_is_registered = 1;
    stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *>>::insert_unique(
      v11,
      (int)v17,
      v13,
      v14);
    return v3;
  }
  else
  {
    m_signature = (unsigned int)this[1].m_signature;
    if ( v15 )
      v15->Release(v15);
    return (vostok::render::res_signature *)m_signature;
  }
}
