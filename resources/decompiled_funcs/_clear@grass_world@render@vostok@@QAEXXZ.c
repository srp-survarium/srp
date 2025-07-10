void __thiscall vostok::render::grass_world::clear(
        vostok::render::grass_world *this,
        vostok::render::grass_world *thisa)
{
  vostok::render::grass_world *v2; // edi
  vostok::render::grass_template **M_start; // eax
  vostok::render::grass_template *v4; // ebp
  void **v5; // edi
  void **i; // ebx
  void *v7; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **M_finish; // eax
  vostok::render::grass_template *v10; // ecx
  void **v11; // esi
  vostok::render::grass_render_model *m_object; // esi
  void **v13; // eax
  void **v14; // ecx
  void **v15; // esi
  vostok::render::grass_template **it_t; // [esp+Ch] [ebp-8h]
  vostok::render::grass_template **end_t; // [esp+10h] [ebp-4h]

  v2 = thisa;
  vostok::render::grass_world::remove_patches(this, thisa);
  M_start = (vostok::render::grass_template **)thisa->m_templates._M_impl._M_start;
  it_t = M_start;
  end_t = (vostok::render::grass_template **)thisa->m_templates._M_impl._M_finish;
  if ( M_start != end_t )
  {
    while ( 1 )
    {
      v4 = *M_start;
      v5 = (*M_start)->m_instances._M_impl._M_start;
      for ( i = (*M_start)->m_instances._M_impl._M_finish; v5 != i; ++v5 )
      {
        v7 = *v5;
        if ( *v5 )
        {
          m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
          BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
          vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v7);
        }
      }
      M_finish = v4->m_instances._M_impl._M_finish;
      v10 = (vostok::render::grass_template *)v4->m_instances._M_impl._M_start;
      if ( v10 != (vostok::render::grass_template *)M_finish )
      {
        v11 = stlp_std::priv::__copy_ptrs<void * *,void * *>(M_finish, M_finish, (void **)&v10->m_render_model.m_object);
        stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
        v4->m_instances._M_impl._M_finish = v11;
      }
      m_object = vostok::render::g_allocator.m_object;
      vostok::render::grass_template::~grass_template(v10);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free((void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick), v4);
      if ( ++it_t == end_t )
        break;
      M_start = it_t;
    }
    v2 = thisa;
  }
  v13 = v2->m_templates._M_impl._M_finish;
  v14 = v2->m_templates._M_impl._M_start;
  if ( v14 != v13 )
  {
    v15 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v13, v13, v14);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    thisa->m_templates._M_impl._M_finish = v15;
  }
}
