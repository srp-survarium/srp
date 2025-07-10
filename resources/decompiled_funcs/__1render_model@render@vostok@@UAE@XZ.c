void __usercall vostok::render::render_model::~render_model(vostok::render::render_model *this@<ecx>, int a2@<edi>)
{
  unsigned __int8 v2; // al
  int v3; // ecx
  vostok::render::grass_render_model *m_object; // ebp
  void (__thiscall ***v5)(_DWORD, _DWORD); // esi
  _BYTE *v6; // ebx
  void *m_reconstruction_info_actuality_tick_high; // esi
  void *v8; // eax
  void *v9; // esi
  void *v10; // eax
  void *v11; // esi
  unsigned __int8 i; // [esp+Fh] [ebp-1h]

  v2 = 0;
  *(_DWORD *)a2 = &stru_962594.m_signatures;
  for ( i = 0; v2 < *(_BYTE *)(a2 + 304); i = v2 )
  {
    v3 = *(_DWORD *)(a2 + 300);
    m_object = vostok::render::g_allocator.m_object;
    v5 = *(void (__thiscall ****)(_DWORD, _DWORD))(v3 + 4 * v2);
    if ( v5 )
    {
      v6 = __RTCastToVoid(*(void ***)(v3 + 4 * v2));
      (**v5)(v5, 0);
      if ( v6 )
      {
        m_reconstruction_info_actuality_tick_high = (void *)HIDWORD(m_object->m_reconstruction_info_actuality_tick);
        BYTE2(m_object->m_children_resources.m_lock) = 0;
        vostok_mspace_free(m_reconstruction_info_actuality_tick_high, v6);
      }
    }
    v2 = i + 1;
  }
  if ( *(_DWORD *)(a2 + 288) )
  {
    v8 = *(void **)(a2 + 288);
    if ( v8 )
    {
      v9 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
      BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
      vostok_mspace_free(v9, v8);
      *(_DWORD *)(a2 + 288) = 0;
    }
  }
  v10 = *(void **)(a2 + 296);
  if ( v10 )
  {
    v11 = (void *)HIDWORD(vostok::render::g_allocator.m_object->m_reconstruction_info_actuality_tick);
    BYTE2(vostok::render::g_allocator.m_object->m_children_resources.m_lock) = 0;
    vostok_mspace_free(v11, v10);
    *(_DWORD *)(a2 + 296) = 0;
  }
  vostok::resources::unmanaged_resource::~unmanaged_resource((vostok::resources::unmanaged_resource *)a2);
}
