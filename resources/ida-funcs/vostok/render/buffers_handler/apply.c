void __usercall vostok::render::buffers_handler<1>::apply(
        vostok::render::buffers_handler<2> *this@<ecx>,
        unsigned __int8 *a2@<esi>)
{
  unsigned __int8 *v2; // edi
  int v3; // edx
  int v4; // ecx
  int *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  signed int v9; // ebx
  ID3D11ShaderResourceView *const *v10; // edi
  signed int v11; // [esp+8h] [ebp-4h]

  v2 = a2 + 12;
  memset((int)(a2 + 12), 0, 0x200u);
  v3 = *((_DWORD *)a2 + 1);
  if ( *(_DWORD *)a2 )
    v4 = (*(_DWORD *)(*(_DWORD *)a2 + 8) - *(_DWORD *)(*(_DWORD *)a2 + 4)) >> 2;
  else
    v4 = 0;
  while ( v3 < v4 )
  {
    v5 = (int *)(*(_DWORD *)(*(_DWORD *)a2 + 4) + 4 * v3);
    if ( *v5
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v6 = *v5;
      if ( *(_DWORD *)(v6 + 8) )
        v7 = *(_DWORD *)(v6 + 8);
      else
        v7 = 0;
      *(_DWORD *)&v2[4 * v3] = v7;
    }
    else
    {
      *(_DWORD *)&v2[4 * v3] = 0;
    }
    ++v3;
  }
  v8 = *((_DWORD *)a2 + 1);
  if ( v4 > v8 )
  {
    v9 = *((_DWORD *)a2 + 1);
    v11 = v4 - v8;
    if ( v8 < v4 - v8 )
    {
      v10 = (ID3D11ShaderResourceView *const *)&a2[4 * v8 + 12];
      do
      {
        if ( *v10 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetShaderResources(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v9,
            1u,
            v10);
        ++v9;
        ++v10;
      }
      while ( v9 < v11 );
    }
  }
  *((_DWORD *)a2 + 2) = 0;
  *((_DWORD *)a2 + 1) = 0;
}


void __usercall vostok::render::buffers_handler<0>::apply(
        vostok::render::buffers_handler<0> *this@<ecx>,
        unsigned __int8 *a2@<esi>)
{
  unsigned __int8 *v2; // edi
  int v3; // edx
  int v4; // ecx
  int *v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  signed int v9; // ebx
  ID3D11ShaderResourceView *const *v10; // edi
  signed int v11; // [esp+8h] [ebp-4h]

  v2 = a2 + 12;
  memset((int)(a2 + 12), 0, 0x200u);
  v3 = *((_DWORD *)a2 + 1);
  if ( *(_DWORD *)a2 )
    v4 = (*(_DWORD *)(*(_DWORD *)a2 + 8) - *(_DWORD *)(*(_DWORD *)a2 + 4)) >> 2;
  else
    v4 = 0;
  while ( v3 < v4 )
  {
    v5 = (int *)(*(_DWORD *)(*(_DWORD *)a2 + 4) + 4 * v3);
    if ( *v5
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v6 = *v5;
      if ( *(_DWORD *)(v6 + 8) )
        v7 = *(_DWORD *)(v6 + 8);
      else
        v7 = 0;
      *(_DWORD *)&v2[4 * v3] = v7;
    }
    else
    {
      *(_DWORD *)&v2[4 * v3] = 0;
    }
    ++v3;
  }
  v8 = *((_DWORD *)a2 + 1);
  if ( v4 > v8 )
  {
    v9 = *((_DWORD *)a2 + 1);
    v11 = v4 - v8;
    if ( v8 < v4 - v8 )
    {
      v10 = (ID3D11ShaderResourceView *const *)&a2[4 * v8 + 12];
      do
      {
        if ( *v10 )
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetShaderResources(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            v9,
            1u,
            v10);
        ++v9;
        ++v10;
      }
      while ( v9 < v11 );
    }
  }
  *((_DWORD *)a2 + 2) = 0;
  *((_DWORD *)a2 + 1) = 0;
}
