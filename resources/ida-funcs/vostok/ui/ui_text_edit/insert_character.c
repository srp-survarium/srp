void __userpurge vostok::ui::ui_text_edit::insert_character(
        vostok::ui::ui_text_edit *this@<ecx>,
        int a2@<esi>,
        char ch)
{
  bool v3; // zf
  char *m_buffer; // edx
  char *m_end; // eax
  unsigned __int8 **v6; // ecx
  unsigned __int8 *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // ecx
  char *v10; // eax
  unsigned __int8 *v11; // eax
  unsigned int v12; // edi
  vostok::fixed_string<512> result; // [esp+8h] [ebp-20Ch] BYREF
  _UNKNOWN *retaddr; // [esp+214h] [ebp+0h] BYREF

  v3 = *(_BYTE *)(a2 + 687) == 0;
  m_buffer = result.m_buffer;
  m_end = result.m_buffer;
  result.m_begin = result.m_buffer;
  result.m_end = result.m_buffer;
  result.m_max_end = (char *)&retaddr;
  result.m_buffer[0] = 0;
  if ( v3 )
  {
    vostok::buffer_string::substr((vostok::buffer_string *)(a2 + 72), 0, *(unsigned __int16 *)(a2 + 678), &result);
    *result.m_end++ = ch;
    *result.m_end = 0;
    v11 = (unsigned __int8 *)(*(_DWORD *)(a2 + 72) + *(unsigned __int16 *)(a2 + 678));
    v12 = *(_DWORD *)(a2 + 76) - (_DWORD)v11;
    memcpy((unsigned __int8 *)result.m_end, v11, v12);
    v10 = &result.m_end[v12];
    goto LABEL_9;
  }
  v6 = (unsigned __int8 **)(a2 + 72);
  if ( &result != (vostok::fixed_string<512> *)(a2 + 72) )
  {
    v7 = *v6;
    v8 = *(_DWORD *)(a2 + 76) - (_DWORD)*v6;
    result.m_end = result.m_buffer;
    result.m_buffer[0] = 0;
    memcpy((unsigned __int8 *)result.m_buffer, v7, v8);
    result.m_end += v8;
    *result.m_end = 0;
    m_end = result.m_end;
    m_buffer = result.m_begin;
  }
  v9 = *(unsigned __int16 *)(a2 + 678);
  if ( v9 >= m_end - m_buffer )
  {
    *m_end = ch;
    v10 = result.m_end + 1;
LABEL_9:
    result.m_end = v10;
    *v10 = 0;
    goto LABEL_10;
  }
  m_buffer[v9] = ch;
  if ( !ch )
    result.m_end = &m_buffer[v9];
LABEL_10:
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)(a2 + 4) + 8))(a2 + 4, result.m_begin);
  (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)a2 + 4))(a2, (unsigned __int16)(*(_WORD *)(a2 + 678) + 1), 0);
}
