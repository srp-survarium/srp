void __thiscall vostok::fs_new::physical_path_iterator::operator++(
        vostok::fs_new::physical_path_iterator *this,
        _DWORD *do_debug_break)
{
  _DWORD *v2; // ebx
  unsigned int v3; // eax
  int v4; // ecx
  int v5; // edi
  _DWORD v6[81]; // [esp+10h] [ebp-14Ch] BYREF
  int v7; // [esp+154h] [ebp-8h]

  v2 = do_debug_break;
  if ( debug_macro_helper_ignore_always_3 || *do_debug_break )
  {
    vostok::fs_new::physical_path_initializer::physical_path_initializer(
      (vostok::fs_new::physical_path_initializer *)this,
      v6);
    v4 = *v2;
    v5 = v2[78];
    v7 = v2[79];
    if ( !(*(unsigned __int8 (__thiscall **)(int, _DWORD *, _DWORD *))(*(_DWORD *)v4 + 48))(v4, v2 + 78, v2 + 2) )
    {
      (*(void (__thiscall **)(_DWORD, int, int))(*(_DWORD *)*v2 + 52))(*v2, v5, v7);
      v2[78] = -1;
      v2[79] = -1;
    }
  }
  else
  {
    v3 = occurances_left_2;
    if ( occurances_left_2 == -1 )
      v3 = 10;
    occurances_left_2 = v3 - 1;
    if ( v3 )
    {
      HIBYTE(do_debug_break) = 0;
      vostok::debug::on_error(
        (bool *)&do_debug_break + 3,
        process_error_false,
        (bool *)"device",
        ".\\physical_path_info_iterator.cpp",
        "vostok::fs_new::physical_path_iterator::operator ++",
        (const char *)0x58);
      if ( vostok::debug::is_debugger_present() || HIBYTE(do_debug_break) )
        __debugbreak();
    }
  }
}
