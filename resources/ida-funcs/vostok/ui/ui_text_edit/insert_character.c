void __thiscall vostok::ui::ui_text_edit::insert_character(vostok::ui::ui_text_edit *this, int ch, char a3)
{
  bool v3; // zf
  char *m_begin; // eax
  char *m_end; // edx
  unsigned int v6; // ecx
  char *v7; // eax
  vostok::buffer_string v8; // [esp+8h] [ebp-19Ch] BYREF
  _BYTE v9[512]; // [esp+14h] [ebp-190h] BYREF
  char vars0; // [esp+214h] [ebp+70h] BYREF

  v3 = *(_BYTE *)(ch + 687) == 0;
  m_begin = v9;
  m_end = v9;
  v8.m_begin = v9;
  v8.m_end = v9;
  v8.m_max_end = &vars0;
  v9[0] = 0;
  if ( v3 )
  {
    vostok::buffer_string::substr(0, (char *)*(unsigned __int16 *)(ch + 678), &v8, (vostok::buffer_string *)(ch + 72));
    *v8.m_end++ = a3;
    *v8.m_end = 0;
    vostok::buffer_string::append(
      &v8,
      *(const char **)(ch + 76),
      (char *)(*(_DWORD *)(ch + 72) + *(unsigned __int16 *)(ch + 678)));
  }
  else
  {
    if ( &v8 != (vostok::buffer_string *)(ch + 72) )
    {
      vostok::buffer_string::operator=((vostok::buffer_string *)(ch + 72), &v8);
      m_end = v8.m_end;
      m_begin = v8.m_begin;
    }
    v6 = *(unsigned __int16 *)(ch + 678);
    if ( v6 >= m_end - m_begin )
    {
      *m_end = a3;
      *++v8.m_end = 0;
    }
    else
    {
      v7 = &m_begin[v6];
      *v7 = a3;
      if ( !a3 )
        v8.m_end = v7;
    }
  }
  (*(void (__thiscall **)(int, char *))(*(_DWORD *)(ch + 4) + 8))(ch + 4, v8.m_begin);
  (*(void (__thiscall **)(int, _DWORD, _DWORD))(*(_DWORD *)ch + 4))(ch, (unsigned __int16)(*(_WORD *)(ch + 678) + 1), 0);
}
