void __thiscall vostok::logging::log_file::goto_line(
        vostok::logging::log_file *this,
        void (__thiscall *line)(vostok::render::stage_screen_space_reflections *this),
        unsigned int a3)
{
  void (__thiscall *v3)(vostok::render::stage_screen_space_reflections *); // ebx
  unsigned int v4; // esi
  void (__thiscall ***v5)(_DWORD, _DWORD, int, _DWORD); // ecx
  __int64 v6; // rax
  vostok::logging::log_file *v7; // ecx
  int v8; // esi
  int v9; // [esp-8h] [ebp-18h]
  void (__cdecl *const *v10)(char); // [esp+0h] [ebp-10h]

  v3 = line;
  v4 = a3 >> 8;
  if ( a3 >> 8 >= (*((_DWORD *)line + 260) - *((_DWORD *)line + 259)) >> 2 )
    v4 = ((*((_DWORD *)line + 260) - *((_DWORD *)line + 259)) >> 2) - 1;
  v5 = (void (__thiscall ***)(_DWORD, _DWORD, int, _DWORD))*((_DWORD *)line + 256);
  v6 = *(int *)(*((_DWORD *)line + 259) + 4 * v4);
  *((_DWORD *)line + 4369) = HIDWORD(v6);
  v9 = *((_DWORD *)v3 + 4369);
  *((_DWORD *)v3 + 4368) = v6;
  (**v5)(v5, *((_DWORD *)v3 + 4368), v9, 0);
  v8 = a3 - (v4 << 8);
  if ( v8 )
  {
    line = vostok::memory::process_allocator::finalize_impl;
    do
    {
      vostok::logging::log_file::process_next_line<void (__cdecl *)(char)>(v7, v3, (void (__cdecl **)(char))&line, v10);
      --v8;
    }
    while ( v8 );
  }
}
