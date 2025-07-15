void __thiscall survarium::game::deinitialize_modules(survarium::game *this, int a2)
{
  int v2; // esi
  _BYTE *v3; // [esp+Ch] [ebp-8h]
  int v4; // [esp+10h] [ebp-4h]

  v2 = *(_DWORD *)(a2 + 168);
  v4 = *(_DWORD *)(v2 + 16);
  v3 = __RTCastToVoid((void **)v2);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v2 + 56))(v2, 0);
  (*(void (__thiscall **)(int, _BYTE *, const char *, const char *, int))(*(_DWORD *)v4 + 24))(
    v4,
    v3,
    "vostok::ui::destroy_world",
    ".\\ui_entry_point.cpp",
    19);
  *(_DWORD *)(a2 + 168) = 0;
  ((void (__thiscall *)(vostok::input::input_world *, _DWORD))s_world_4.m_variable->~vostok::input::input_world)(
    s_world_4.m_variable,
    0);
  s_world_4.m_initialized = 0;
  *(_DWORD *)(a2 + 164) = 0;
}
