vostok::render::res_geometry *__userpurge vostok::render::resource_manager::create_geometry@<eax>(
        vostok::render::res_declaration *dcl@<ecx>,
        vostok::render::untyped_buffer *vb@<eax>,
        vostok::render::resource_manager *this,
        unsigned int vertex_stride,
        vostok::render::untyped_buffer *ib)
{
  vostok::render::resource_manager *v7; // eax
  vostok::render::res_geometry *v8; // ecx
  unsigned int sl_created; // edi
  vostok::render::res_geometry *v11; // eax
  vostok::render::res_geometry *v12; // eax
  vostok::render::res_geometry *v13; // edi
  vostok::render::res_geometry *v14; // ecx
  vostok::render::res_geometry *geom; // [esp+Ch] [ebp-24h] BYREF
  vostok::render::res_geometry *__val[2]; // [esp+10h] [ebp-20h] BYREF
  vostok::render::res_geometry descriptor; // [esp+18h] [ebp-18h] BYREF

  descriptor.m_reference_count = 0;
  descriptor.m_vb.m_object = 0;
  if ( vb )
  {
    descriptor.m_vb.m_object = vb;
    ++vb->m_reference_count;
  }
  descriptor.m_ib.m_object = 0;
  if ( ib )
  {
    descriptor.m_ib.m_object = ib;
    ++ib->m_reference_count;
  }
  descriptor.m_vb_stride = vertex_stride;
  descriptor.m_dcl.m_object = 0;
  if ( dcl )
  {
    descriptor.m_dcl.m_object = dcl;
    ++dcl->m_reference_count;
  }
  descriptor.m_is_registered = 0;
  geom = &descriptor;
  v7 = (vostok::render::resource_manager *)stlp_std::priv::_Rb_tree<vostok::render::res_geometry *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>,vostok::render::res_geometry *,stlp_std::priv::_Identity<vostok::render::res_geometry *>,stlp_std::priv::_SetTraitsT<vostok::render::res_geometry *>,vostok::render::std_allocator<vostok::render::res_geometry *>>::_M_find<vostok::render::res_geometry const *>(
                                             &geom,
                                             (vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry> *)dcl,
                                             &this->m_geometries._M_t);
  if ( v7 == (vostok::render::resource_manager *)&this->m_geometries )
  {
    v11 = (vostok::render::res_geometry *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::render::g_allocator.m_object,
                                            0x18u);
    if ( v11 )
    {
      vostok::render::res_geometry::res_geometry(vb, ib, dcl, v11, vertex_stride);
      v13 = v12;
    }
    else
    {
      v13 = 0;
    }
    geom = v13;
    v13->m_is_registered = 1;
    stlp_std::priv::_Rb_tree<vostok::render::res_geometry *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>,vostok::render::res_geometry *,stlp_std::priv::_Identity<vostok::render::res_geometry *>,stlp_std::priv::_SetTraitsT<vostok::render::res_geometry *>,vostok::render::std_allocator<vostok::render::res_geometry *>>::insert_unique(
      (stlp_std::priv::_Rb_tree<vostok::render::res_geometry *,vostok::render::resource_manager::compare_member_predicate<vostok::render::res_geometry>,vostok::render::res_geometry *,stlp_std::priv::_Identity<vostok::render::res_geometry *>,stlp_std::priv::_SetTraitsT<vostok::render::res_geometry *>,vostok::render::std_allocator<vostok::render::res_geometry *> > *)__val,
      &this->m_geometries._M_t,
      (stlp_std::priv::_Rb_tree_node_base **)__val,
      &geom);
    vostok::render::res_geometry::~res_geometry(v14);
    return v13;
  }
  else
  {
    sl_created = v7->sl_created;
    vostok::render::res_geometry::~res_geometry(v8);
    return (vostok::render::res_geometry *)sl_created;
  }
}


vostok::render::res_geometry *__userpurge vostok::render::resource_manager::create_geometry@<eax>(
        stlp_std::forward_iterator_tag *decl@<eax>,
        vostok::render::resource_manager *this,
        unsigned int decl_size,
        unsigned int vertex_stride,
        vostok::render::untyped_buffer *vb,
        vostok::render::untyped_buffer *ib)
{
  vostok::render::res_declaration *declaration; // eax
  vostok::render::res_declaration *v7; // esi
  vostok::render::res_geometry *geometry; // edi

  declaration = vostok::render::resource_manager::create_declaration(
                  decl_size,
                  (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
                  decl);
  v7 = 0;
  if ( declaration )
  {
    ++declaration->m_reference_count;
    v7 = declaration;
  }
  geometry = vostok::render::resource_manager::create_geometry(v7, vb, this, vertex_stride, ib);
  if ( v7 )
  {
    if ( v7->m_reference_count-- == 1 )
      vostok::render::resource_manager::release(
        (vostok::render::resource_manager *)`boost::asio::error::get_misc_category'::`2'::`local static guard'.m_options[3],
        v7);
  }
  return geometry;
}
