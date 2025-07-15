vostok::render::resource_manager *__userpurge vostok::render::resource_manager::create_signature@<eax>(
        ID3D10Blob *signature@<eax>,
        vostok::render::resource_manager *this)
{
  unsigned int (__stdcall *AddRef)(IUnknown *); // ecx
  vostok::render::set<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature> > *p_m_signatures; // ebp
  int v5; // ecx
  stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *> > *v6; // eax
  unsigned int M_node_count; // esi
  vostok::render::resource_manager *v9; // eax
  stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *> > *v10; // ecx
  vostok::render::resource_manager *v11; // edi
  stlp_std::pair<stlp_std::priv::_Rb_tree_iterator<vostok::render::res_signature *,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *> >,bool> __k; // [esp+Ch] [ebp-14h] BYREF
  vostok::render::res_signature descriptor; // [esp+14h] [ebp-Ch] BYREF

  AddRef = signature->AddRef;
  descriptor.m_reference_count = 0;
  descriptor.m_signature = signature;
  descriptor.m_is_registered = 0;
  AddRef(signature);
  __k.first._M_node = (stlp_std::priv::_Rb_tree_node_base *)&descriptor;
  p_m_signatures = &this->m_signatures;
  v6 = stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *>>::_M_find<vostok::render::res_signature const *>(
         v5,
         (vostok::render::res_signature *const *)&__k,
         &this->m_signatures._M_t);
  if ( v6 == (stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *> > *)p_m_signatures )
  {
    if ( descriptor.m_signature )
      descriptor.m_signature->Release(descriptor.m_signature);
    v9 = (vostok::render::resource_manager *)vostok::memory::doug_lea_allocator::malloc_impl(
                                               (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                               0xCu);
    v11 = v9;
    if ( v9 )
    {
      v9->sh_created = 0;
      v9->sh_returned = (unsigned int)signature;
      LOBYTE(v9->tl_created) = 0;
      signature->AddRef(signature);
    }
    else
    {
      v11 = 0;
    }
    this = v11;
    LOBYTE(v11->tl_created) = 1;
    stlp_std::priv::_Rb_tree<vostok::render::res_signature *,vostok::render::resource_manager::compare_predicate<vostok::render::res_signature>,vostok::render::res_signature *,stlp_std::priv::_Identity<vostok::render::res_signature *>,stlp_std::priv::_SetTraitsT<vostok::render::res_signature *>,vostok::render::std_allocator<vostok::render::res_signature *>>::insert_unique(
      v10,
      &p_m_signatures->_M_t,
      &__k,
      (vostok::render::res_signature *const *)&this);
    return v11;
  }
  else
  {
    M_node_count = v6->_M_node_count;
    if ( descriptor.m_signature )
      descriptor.m_signature->Release(descriptor.m_signature);
    return (vostok::render::resource_manager *)M_node_count;
  }
}
