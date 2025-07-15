void __usercall survarium::game::deinitialize_modules(survarium::game *this@<ecx>, int a2@<edi>)
{
  int v2; // esi
  int v3; // ebp
  _BYTE *v4; // ebx

  v2 = *(_DWORD *)(a2 + 144);
  v3 = *(_DWORD *)(v2 + 16);
  v4 = __RTCastToVoid((void **)v2);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 56))(v2, 0);
  (*(void (__thiscall **)(int, _BYTE *))(*(_DWORD *)v3 + 24))(v3, v4);
  *(_DWORD *)(a2 + 144) = 0;
  ((void (__thiscall *)(vostok::input::input_world *, _DWORD))s_world_2.m_variable->~vostok::input::input_world)(
    s_world_2.m_variable,
    0);
  s_world_2.m_initialized = 0;
  *(_DWORD *)(a2 + 140) = 0;
}
