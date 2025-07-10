void __usercall vostok::render::environment_probe::remove_collision(
        vostok::render::environment_probe *this@<ecx>,
        int a2@<eax>)
{
  void **v3; // esi
  vostok::render::grass_render_model *m_object; // eax
  vostok::render::grass_render_model *v5; // ebx
  _BYTE *v6; // ebp
  void **v7; // esi
  vostok::render::grass_render_model *v8; // edi
  _BYTE *v9; // ebx

  if ( *(_DWORD *)(a2 + 420) && *(_DWORD *)(a2 + 428) )
    (*(void (__thiscall **)(_DWORD, _DWORD))(**(_DWORD **)(a2 + 420) + 4))(*(_DWORD *)(a2 + 420), *(_DWORD *)(a2 + 428));
  v3 = *(void ***)(a2 + 428);
  m_object = vostok::render::g_allocator.m_object;
  v5 = vostok::render::g_allocator.m_object;
  if ( v3 )
  {
    v6 = __RTCastToVoid(v3);
    (*((void (__thiscall **)(void **, _DWORD))*v3 + 11))(v3, 0);
    ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))v5->is_increasing_quality)(v5, v6);
    m_object = vostok::render::g_allocator.m_object;
  }
  v7 = *(void ***)(a2 + 424);
  v8 = m_object;
  if ( v7 )
  {
    (*(void (__thiscall **)(void **, vostok::render::grass_render_model *))*v7)(v7, m_object);
    v9 = __RTCastToVoid(v7);
    (*((void (__thiscall **)(void **, _DWORD))*v7 + 32))(v7, 0);
    ((void (__thiscall *)(vostok::render::grass_render_model *, _BYTE *))v8->is_increasing_quality)(v8, v9);
  }
}
