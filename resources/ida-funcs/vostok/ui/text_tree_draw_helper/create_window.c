void __userpurge vostok::ui::text_tree_draw_helper::create_window(
        vostok::ui::text_tree_draw_helper *this@<ecx>,
        _DWORD *a2@<edi>,
        const char *text,
        vostok::math::float2 pos,
        vostok::math::float2 sz)
{
  int v5; // esi
  int v6; // eax
  void (__thiscall ***v7)(_DWORD, vostok::math::float2 *); // eax
  int v8; // eax
  int v9; // eax
  int v10; // ebx
  int v11; // eax

  v5 = (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*a2 + 16))(*a2);
  if ( (a2[13] & 1) != 0 )
    v6 = a2[2];
  else
    v6 = a2[3];
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v5 + 4))(v5, v6);
  (**(void (__thiscall ***)(int, _DWORD))v5)(v5, a2[4]);
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v5 + 16))(v5, 0);
  (*(void (__thiscall **)(int, const char *))(*(_DWORD *)v5 + 8))(v5, text);
  v7 = (void (__thiscall ***)(_DWORD, vostok::math::float2 *))(*(int (__thiscall **)(int))(*(_DWORD *)v5 + 28))(v5);
  (**v7)(v7, &pos);
  v8 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 28))(v5);
  (*(void (__thiscall **)(int, vostok::math::float2 *))(*(_DWORD *)v8 + 8))(v8, &sz);
  v9 = (*(int (__thiscall **)(int))(*(_DWORD *)v5 + 28))(v5);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v9 + 16))(v9, 1);
  v10 = *(_DWORD *)a2[1];
  v11 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v5 + 28))(v5, 1);
  (*(void (__thiscall **)(_DWORD, int))(v10 + 64))(a2[1], v11);
}
