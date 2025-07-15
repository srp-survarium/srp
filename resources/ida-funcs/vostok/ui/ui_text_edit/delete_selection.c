void __thiscall vostok::ui::ui_text_edit::delete_selection(vostok::ui::ui_text_edit *this, int a2)
{
  vostok::buffer_string *v3; // esi
  char *v4; // eax
  vostok::buffer_string *v5; // ecx
  __int16 v6; // ax
  vostok::buffer_string v7; // [esp+Ch] [ebp-20Ch] BYREF
  _BYTE v8[512]; // [esp+18h] [ebp-200h] BYREF
  char vars0; // [esp+218h] [ebp+0h] BYREF
  char *v10; // [esp+220h] [ebp+8h]

  v7.m_begin = v8;
  v7.m_end = v8;
  v7.m_max_end = &vars0;
  v3 = (vostok::buffer_string *)(a2 + 72);
  v4 = (char *)*(unsigned __int16 *)(a2 + 680);
  v10 = v4;
  v8[0] = 0;
  vostok::buffer_string::substr(0, v4, &v7, v3);
  vostok::buffer_string::append(v5, *(const char **)(a2 + 76), &v3->m_begin[*(unsigned __int16 *)(a2 + 682)]);
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)(a2 + 4) + 8))(a2 + 4, v7.m_begin);
  (*(void (__thiscall **)(int, char *, int))(*(_DWORD *)a2 + 4))(a2, v10, 1);
  v6 = *(_WORD *)(a2 + 678);
  *(_WORD *)(a2 + 680) = v6;
  *(_WORD *)(a2 + 682) = v6;
}
