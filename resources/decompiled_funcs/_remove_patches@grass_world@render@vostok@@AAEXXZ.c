void __usercall vostok::render::grass_world::remove_patches(vostok::render::grass_world *this@<ecx>, _DWORD *a2@<edi>)
{
  vostok::render::grass_patch *const *v2; // eax
  vostok::render::grass_patch **v3; // ebx
  vostok::render::grass_patch *v4; // esi
  vostok::render::grass_render_model *m_object; // ebp
  vostok::render::grass_patch *v6; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v8; // eax
  void **v9; // ecx
  void **v10; // esi
  void **v11; // eax
  void **v12; // ecx
  void **v13; // esi
  vostok::render::grass_patch *const *end_p; // [esp+10h] [ebp-4h]

  v2 = (vostok::render::grass_patch *const *)a2[73];
  v3 = (vostok::render::grass_patch **)a2[72];
  for ( end_p = v2; v3 != v2; ++v3 )
  {
    v4 = *v3;
    m_object = vostok::render::g_allocator.m_object;
    if ( *v3 )
    {
      vostok::render::grass_patch::~grass_patch((vostok::render::grass_patch *)this, *v3);
      v6 = v4;
      m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
      BYTE2(m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      v2 = end_p;
    }
  }
  v8 = (void **)a2[73];
  v9 = (void **)a2[72];
  if ( v9 != v8 )
  {
    v10 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v8, v8, v9);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    a2[73] = v10;
  }
  v11 = (void **)a2[76];
  v12 = (void **)a2[75];
  if ( v12 != v11 )
  {
    v13 = stlp_std::priv::__copy_ptrs<void * *,void * *>(v11, v11, v12);
    stlp_std::_Destroy<vostok::fs_new::virtual_path_string>();
    a2[76] = v13;
  }
}
