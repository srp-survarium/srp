void __usercall vostok::render::grass_world::remove_instance(vostok::render::grass_world *this@<ecx>, int a2@<eax>)
{
  int *v2; // edx
  int *v3; // ebx
  int v5; // ebp
  void **v6; // edi
  void **v7; // ecx
  void *v8; // eax
  void *m_reconstruction_info_actuality_tick_high; // esi
  void **v10; // eax

  v2 = *(int **)(a2 + 276);
  v3 = *(int **)(a2 + 280);
  if ( v2 != v3 )
  {
    while ( 1 )
    {
      v5 = *v2;
      v6 = *(void ***)(*v2 + 8);
      v7 = *(void ***)(*v2 + 12);
      if ( v6 != v7 )
        break;
LABEL_5:
      if ( ++v2 == v3 )
        return;
    }
    while ( 1 )
    {
      v8 = *v6;
      if ( *((vostok::render::grass_world **)*v6 + 19) == this )
        break;
      if ( ++v6 == v7 )
        goto LABEL_5;
    }
    m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v8);
    v10 = *(void ***)(v5 + 12);
    if ( v6 + 1 != v10 )
      stlp_std::priv::__copy_ptrs<void * *,void * *>(v6 + 1, v10, v6);
    *(_DWORD *)(v5 + 12) -= 4;
  }
}
