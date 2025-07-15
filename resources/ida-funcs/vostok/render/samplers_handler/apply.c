void __usercall vostok::render::samplers_handler<1>::apply(
        vostok::render::samplers_handler<1> *this@<ecx>,
        unsigned int *a2@<esi>)
{
  unsigned int v2; // ecx
  unsigned int v3; // eax
  unsigned int i; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  ID3D11SamplerState *const *v7; // edi
  unsigned int v8; // [esp+4h] [ebp-4h]

  memset((int)(a2 + 2), 0, 0x40u);
  v2 = a2[18];
  if ( v2 )
    v3 = (*(_DWORD *)(v2 + 8) - *(_DWORD *)(v2 + 4)) >> 2;
  else
    v3 = 0;
  for ( i = *a2; i < v3; ++i )
    a2[i + 2] = *(_DWORD *)(*(_DWORD *)(a2[18] + 4) + 4 * i);
  v5 = *a2;
  if ( v3 > *a2 )
  {
    v6 = *a2;
    v8 = v3 - v5;
    if ( v5 < v3 - v5 )
    {
      v7 = (ID3D11SamplerState *const *)&a2[v5 + 2];
      do
      {
        if ( *v7 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetSamplers(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v6,
            1u,
            v7);
        ++v6;
        ++v7;
      }
      while ( v6 < v8 );
    }
  }
  a2[1] = 0;
  *a2 = 0;
}


void __usercall vostok::render::samplers_handler<2>::apply(
        vostok::render::samplers_handler<2> *this@<ecx>,
        unsigned int *a2@<esi>)
{
  unsigned int v2; // ecx
  unsigned int v3; // eax
  unsigned int i; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  ID3D11SamplerState *const *v7; // edi
  unsigned int v8; // [esp+4h] [ebp-4h]

  memset((int)(a2 + 2), 0, 0x40u);
  v2 = a2[18];
  if ( v2 )
    v3 = (*(_DWORD *)(v2 + 8) - *(_DWORD *)(v2 + 4)) >> 2;
  else
    v3 = 0;
  for ( i = *a2; i < v3; ++i )
    a2[i + 2] = *(_DWORD *)(*(_DWORD *)(a2[18] + 4) + 4 * i);
  v5 = *a2;
  if ( v3 > *a2 )
  {
    v6 = *a2;
    v8 = v3 - v5;
    if ( v5 < v3 - v5 )
    {
      v7 = (ID3D11SamplerState *const *)&a2[v5 + 2];
      do
      {
        if ( *v7 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetSamplers(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v6,
            1u,
            v7);
        ++v6;
        ++v7;
      }
      while ( v6 < v8 );
    }
  }
  a2[1] = 0;
  *a2 = 0;
}


void __usercall vostok::render::samplers_handler<0>::apply(
        vostok::render::samplers_handler<0> *this@<ecx>,
        unsigned int *a2@<esi>)
{
  unsigned int v2; // ecx
  unsigned int v3; // eax
  unsigned int i; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ebx
  ID3D11SamplerState *const *v7; // edi
  unsigned int v8; // [esp+4h] [ebp-4h]

  memset((int)(a2 + 2), 0, 0x40u);
  v2 = a2[18];
  if ( v2 )
    v3 = (*(_DWORD *)(v2 + 8) - *(_DWORD *)(v2 + 4)) >> 2;
  else
    v3 = 0;
  for ( i = *a2; i < v3; ++i )
    a2[i + 2] = *(_DWORD *)(*(_DWORD *)(a2[18] + 4) + 4 * i);
  v5 = *a2;
  if ( v3 > *a2 )
  {
    v6 = *a2;
    v8 = v3 - v5;
    if ( v5 < v3 - v5 )
    {
      v7 = (ID3D11SamplerState *const *)&a2[v5 + 2];
      do
      {
        if ( *v7 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetSamplers(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v6,
            1u,
            v7);
        ++v6;
        ++v7;
      }
      while ( v6 < v8 );
    }
  }
  a2[1] = 0;
  *a2 = 0;
}
