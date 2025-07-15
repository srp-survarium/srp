void __userpurge survarium::usable_object::deserialize_usable_object(
        survarium::usable_object *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::network_core::buffer_reader *reader,
        unsigned int time_offset)
{
  const unsigned __int8 *m_pointer; // ecx
  unsigned __int8 *v6; // ecx
  const unsigned __int8 *v7; // esi
  _DWORD *v8; // [esp+10h] [ebp-Ch]
  int v9; // [esp+14h] [ebp-8h]
  unsigned __int8 v10; // [esp+1Bh] [ebp-1h] BYREF
  unsigned __int8 v11; // [esp+27h] [ebp+Bh]
  unsigned __int8 v12; // [esp+27h] [ebp+Bh]

  a2[12] = 0;
  a2[13] = 0;
  a2[10] = 0;
  m_pointer = reader->m_pointer;
  v11 = *m_pointer;
  v6 = (unsigned __int8 *)(m_pointer + 1);
  reader->m_pointer = v6;
  if ( v11 )
  {
    v8 = a2 + 2;
    v9 = v11;
    do
    {
      v7 = reader->m_pointer;
      v12 = *v7;
      reader->m_pointer = v7 + 1;
      v10 = v12;
      vostok::buffer_vector<unsigned char>::push_back((vostok::buffer_vector<unsigned char> *)v6, (int)v8, &v10);
      --v9;
    }
    while ( v9 );
  }
}
