void __userpurge survarium::hit_animations_selector::deserialize(
        survarium::hit_animations_selector *this@<ecx>,
        int a2@<eax>,
        vostok::network_core::buffer_reader *reader,
        const unsigned int time_offset)
{
  _DWORD *v5; // eax
  int v6; // edx
  const unsigned __int8 *m_pointer; // esi
  const unsigned __int8 *v8; // ecx
  int v9; // esi
  const unsigned __int8 *v10; // esi
  const unsigned __int8 *v11; // esi
  int v12; // [esp+Ch] [ebp-8h]
  int v13; // [esp+10h] [ebp-4h]

  *(_BYTE *)(a2 + 244) = vostok::network_core::buffer_reader::r<bool>(reader);
  v5 = (_DWORD *)(a2 + 12);
  v6 = 8;
  do
  {
    m_pointer = reader->m_pointer;
    v8 = m_pointer + 4;
    v9 = *(_DWORD *)m_pointer;
    reader->m_pointer = v8;
    *(v5 - 1) = time_offset + v9;
    v10 = reader->m_pointer;
    v13 = *(_DWORD *)v10;
    reader->m_pointer = v10 + 4;
    *v5 = v13;
    v11 = reader->m_pointer;
    v12 = *(_DWORD *)v11;
    reader->m_pointer = v11 + 4;
    v5[1] = v12;
    v5 += 6;
    --v6;
  }
  while ( v6 );
}
