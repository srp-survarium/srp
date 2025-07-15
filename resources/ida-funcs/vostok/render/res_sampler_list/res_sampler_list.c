void __thiscall vostok::render::res_sampler_list::res_sampler_list(
        vostok::render::res_sampler_list *this,
        const vostok::fixed_vector<vostok::render::sampler_slot,16> *slots,
        _DWORD *a3)
{
  vostok::render::sampler_slot **p_m_end; // edi
  char *v4; // ebx
  vostok::buffer_vector<vostok::fixed_string<32> > *v5; // ecx
  unsigned int v6; // esi
  unsigned int v7; // edx
  _BYTE **v8; // ecx
  _DWORD *v9; // eax
  _BYTE *v10; // ecx
  unsigned int v11; // ecx
  int v12; // eax
  unsigned int v13; // [esp+10h] [ebp-8h]
  int sizeb; // [esp+14h] [ebp-4h]
  unsigned int size; // [esp+14h] [ebp-4h]
  unsigned int sizea; // [esp+14h] [ebp-4h]

  slots->m_begin = 0;
  p_m_end = &slots->m_end;
  v4 = &slots->m_buffer[1].m_store[48];
  slots->m_end = (vostok::render::sampler_slot *)&slots->m_buffer[0].m_store[4];
  slots->m_max_end = (vostok::render::sampler_slot *)&slots->m_buffer[0].m_store[4];
  *(_DWORD *)slots->m_buffer[0].m_store = &slots->m_buffer[1].m_store[48];
  *(_DWORD *)&slots->m_buffer[1].m_store[48] = &slots->m_buffer[1].m_store[60];
  *(_DWORD *)&slots->m_buffer[1].m_store[52] = &slots->m_buffer[1].m_store[60];
  *(_DWORD *)&slots->m_buffer[1].m_store[56] = (char *)slots + 1564;
  slots[1].m_buffer[2].m_store[28] = 0;
  sizeb = (a3[1] - *a3) / 84;
  vostok::buffer_vector<ID3D11SamplerState *>::resize(
    (vostok::buffer_vector<ID3D11SamplerState *> *)sizeb,
    (int *)&slots->m_end);
  vostok::buffer_vector<vostok::fixed_string<32>>::resize(v5, (int *)&slots->m_buffer[1].m_store[48], sizeb);
  v6 = sizeb;
  v7 = 0;
  if ( sizeb )
  {
    size = 0;
    do
    {
      *((_DWORD *)&(*p_m_end)->name.m_begin + v7) = 0;
      v8 = (_BYTE **)(size + *(_DWORD *)v4);
      size += 44;
      v9 = v8 + 1;
      v10 = *v8;
      *v9 = v10;
      *v10 = 0;
      *(_BYTE *)(*v9)++ = 0;
      ++v7;
      *(_BYTE *)*v9 = 0;
    }
    while ( v7 < v6 );
  }
  if ( v6 )
  {
    sizea = 0;
    v13 = v6;
    do
    {
      v11 = *a3 + sizea;
      v12 = *(_DWORD *)(v11 + 76);
      if ( v12 != -1 )
      {
        *((_DWORD *)&(*p_m_end)->name.m_begin + v12) = *(_DWORD *)(v11 + 80);
        vostok::buffer_string::operator=(
          (vostok::buffer_string *)(sizea + *a3),
          (vostok::buffer_string *)(*(_DWORD *)v4 + 44 * v12));
      }
      sizea += 84;
      --v13;
    }
    while ( v13 );
  }
}
