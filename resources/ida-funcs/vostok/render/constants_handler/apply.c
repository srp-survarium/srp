void __usercall vostok::render::constants_handler<1>::apply(
        vostok::render::constants_handler<1> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // ecx
  signed int v5; // ebx
  ID3D11Buffer *const *v6; // edi
  signed int v7; // [esp+4h] [ebp-4h]

  memset((int)(a2 + 3), 0, 0x38u);
  v2 = a2[2];
  v3 = *a2;
  if ( v2 )
    v2 = (*(_DWORD *)(v2 + 788) - *(_DWORD *)(v2 + 784)) >> 2;
  while ( v3 < v2 )
  {
    a2[v3 + 3] = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2[2] + 784) + 4 * v3) + 96);
    ++v3;
  }
  v4 = *a2;
  if ( v2 > *a2 )
  {
    v5 = *a2;
    v7 = v2 - v4;
    if ( v4 < v2 - v4 )
    {
      v6 = (ID3D11Buffer *const *)&a2[v4 + 3];
      do
      {
        if ( *v6 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetConstantBuffers(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v5,
            1u,
            v6);
        ++v5;
        ++v6;
      }
      while ( v5 < v7 );
    }
  }
  a2[1] = 0;
  *a2 = 0;
}


void __usercall vostok::render::constants_handler<2>::apply(
        vostok::render::constants_handler<2> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // ecx
  signed int v5; // ebx
  ID3D11Buffer *const *v6; // edi
  signed int v7; // [esp+4h] [ebp-4h]

  memset((int)(a2 + 3), 0, 0x38u);
  v2 = a2[2];
  v3 = *a2;
  if ( v2 )
    v2 = (*(_DWORD *)(v2 + 788) - *(_DWORD *)(v2 + 784)) >> 2;
  while ( v3 < v2 )
  {
    a2[v3 + 3] = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2[2] + 784) + 4 * v3) + 96);
    ++v3;
  }
  v4 = *a2;
  if ( v2 > *a2 )
  {
    v5 = *a2;
    v7 = v2 - v4;
    if ( v4 < v2 - v4 )
    {
      v6 = (ID3D11Buffer *const *)&a2[v4 + 3];
      do
      {
        if ( *v6 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetConstantBuffers(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v5,
            1u,
            v6);
        ++v5;
        ++v6;
      }
      while ( v5 < v7 );
    }
  }
  a2[1] = 0;
  *a2 = 0;
}


void __usercall vostok::render::constants_handler<0>::apply(
        vostok::render::constants_handler<0> *this@<ecx>,
        int *a2@<esi>)
{
  int v2; // eax
  unsigned int v3; // ecx
  int v4; // ecx
  signed int v5; // ebx
  ID3D11Buffer *const *v6; // edi
  signed int v7; // [esp+4h] [ebp-4h]

  memset((int)(a2 + 3), 0, 0x38u);
  v2 = a2[2];
  v3 = *a2;
  if ( v2 )
    v2 = (*(_DWORD *)(v2 + 788) - *(_DWORD *)(v2 + 784)) >> 2;
  while ( v3 < v2 )
  {
    a2[v3 + 3] = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(a2[2] + 784) + 4 * v3) + 96);
    ++v3;
  }
  v4 = *a2;
  if ( v2 > *a2 )
  {
    v5 = *a2;
    v7 = v2 - v4;
    if ( v4 < v2 - v4 )
    {
      v6 = (ID3D11Buffer *const *)&a2[v4 + 3];
      do
      {
        if ( *v6 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetConstantBuffers(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v5,
            1u,
            v6);
        ++v5;
        ++v6;
      }
      while ( v5 < v7 );
    }
  }
  a2[1] = 0;
  *a2 = 0;
}
