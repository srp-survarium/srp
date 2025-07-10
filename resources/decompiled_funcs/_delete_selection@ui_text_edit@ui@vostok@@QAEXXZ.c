void __usercall vostok::ui::ui_text_edit::delete_selection(vostok::ui::ui_text_edit *this@<ecx>, int a2@<esi>)
{
  unsigned __int16 v2; // ax
  int v3; // ebx
  unsigned __int8 *v4; // eax
  unsigned int v5; // edi
  __int16 v6; // ax
  vostok::fixed_string<512> result; // [esp+8h] [ebp-20Ch] BYREF
  _UNKNOWN *retaddr; // [esp+214h] [ebp+0h] BYREF

  result.m_begin = result.m_buffer;
  v2 = *(_WORD *)(a2 + 680);
  result.m_max_end = (char *)&retaddr;
  result.m_end = result.m_buffer;
  result.m_buffer[0] = 0;
  v3 = v2;
  vostok::buffer_string::substr((vostok::buffer_string *)(a2 + 72), 0, v2, &result);
  v4 = (unsigned __int8 *)(*(_DWORD *)(a2 + 72) + *(unsigned __int16 *)(a2 + 682));
  v5 = *(_DWORD *)(a2 + 76) - (_DWORD)v4;
  memcpy((unsigned __int8 *)result.m_end, v4, v5);
  result.m_end += v5;
  *result.m_end = 0;
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)(a2 + 4) + 8))(a2 + 4, result.m_begin);
  (*(void (__thiscall **)(int, int, int))(*(_DWORD *)a2 + 4))(a2, v3, 1);
  v6 = *(_WORD *)(a2 + 678);
  *(_WORD *)(a2 + 680) = v6;
  *(_WORD *)(a2 + 682) = v6;
}
