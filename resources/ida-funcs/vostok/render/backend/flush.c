void __thiscall vostok::render::backend::flush(vostok::render::backend *this, unsigned int a2)
{
  unsigned int v2; // ebx
  ID3D11DeviceContext *m_context; // eax
  int v4; // eax
  ID3D11VertexShader *v5; // ecx
  int v6; // esi
  int v7; // eax
  ID3D11GeometryShader *v8; // ecx
  int v9; // eax
  ID3D11PixelShader *v10; // ecx
  bool v11; // zf
  int v12; // eax
  int v13; // edi
  int v14; // eax
  int v15; // eax
  int v16; // edx
  int v17; // eax
  vostok::render::backend *v18; // eax
  int v19; // eax
  int v20; // eax
  ID3D11Buffer *v21; // esi
  unsigned int v22; // eax
  int v23; // eax
  int *v24; // edi
  int v25; // eax
  int *v26; // edi
  int v27; // eax
  int *v28; // edi
  int v29; // eax
  unsigned int v30; // esi
  ID3D11InputLayout *v31; // eax
  _BYTE *v32; // edi
  ID3D11BlendState *v33; // [esp-Ch] [ebp-50h]
  unsigned int v34; // [esp-4h] [ebp-48h]
  _DWORD v35[4]; // [esp+10h] [ebp-34h] BYREF
  _DWORD v36[2]; // [esp+20h] [ebp-24h] BYREF
  _BYTE *v37; // [esp+28h] [ebp-1Ch]
  int *i; // [esp+2Ch] [ebp-18h]
  int v39; // [esp+30h] [ebp-14h] BYREF
  int v40; // [esp+34h] [ebp-10h] BYREF
  int v41; // [esp+38h] [ebp-Ch] BYREF
  vostok::render::backend *v42; // [esp+3Ch] [ebp-8h] BYREF

  v2 = a2;
  if ( *(_BYTE *)(a2 + 94) )
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->RSSetState(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      *(ID3D11RasterizerState **)(a2 + 328));
  if ( *(_BYTE *)(v2 + 95) )
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->OMSetDepthStencilState(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      *(ID3D11DepthStencilState **)(v2 + 332),
      *(_DWORD *)(v2 + 340));
  if ( *(_BYTE *)(v2 + 96) )
  {
    v34 = *(_DWORD *)(v2 + 344);
    m_context = vostok::quasi_singleton<vostok::render::device>::pinst->m_context;
    v33 = *(ID3D11BlendState **)(v2 + 336);
    *(float *)v35 = s_bm_current_air_resistance;
    *(float *)&v35[1] = s_bm_current_air_resistance;
    *(float *)&v35[2] = s_bm_current_air_resistance;
    *(float *)&v35[3] = s_bm_current_air_resistance;
    m_context->OMSetBlendState(m_context, v33, (const float *)v35, v34);
  }
  if ( *(_BYTE *)(v2 + 113)
     | (unsigned __int8)(*(_BYTE *)(v2 + 114) | *(_BYTE *)(v2 + 115) | *(_BYTE *)(v2 + 116) | *(_BYTE *)(v2 + 117)) )
  {
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->OMSetRenderTargets(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      4u,
      (ID3D11RenderTargetView *const *)(v2 + 7368),
      *(ID3D11DepthStencilView **)(v2 + 7384));
  }
  *(_DWORD *)(v2 + 113) = 0;
  *(_BYTE *)(v2 + 117) = 0;
  if ( *(_BYTE *)(v2 + 97) )
  {
    v4 = *(_DWORD *)(v2 + 412);
    if ( v4 )
      v5 = *(ID3D11VertexShader **)(v4 + 8);
    else
      v5 = 0;
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->VSSetShader(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      v5,
      0,
      0);
  }
  v6 = 0;
  if ( *(_BYTE *)(v2 + 102) )
  {
    v7 = *(_DWORD *)(v2 + 420);
    if ( v7 )
      v8 = *(ID3D11GeometryShader **)(v7 + 8);
    else
      v8 = 0;
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->GSSetShader(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      v8,
      0,
      0);
  }
  if ( *(_BYTE *)(v2 + 107) )
  {
    v9 = *(_DWORD *)(v2 + 416);
    if ( v9 )
      v10 = *(ID3D11PixelShader **)(v9 + 8);
    else
      v10 = 0;
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->PSSetShader(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      v10,
      0,
      0);
  }
  v11 = *(_BYTE *)(v2 + 88) == 0;
  a2 = 0;
  v37 = (_BYTE *)(v2 + 88);
  if ( !v11 || *(_BYTE *)(v2 + 89) )
  {
    v12 = *(_DWORD *)(v2 + 396);
    if ( *(_BYTE *)(v2 + 89) )
    {
      if ( v12 )
        v13 = *(_DWORD *)(v12 + 16);
      else
        v13 = 0;
      v14 = *(_DWORD *)(v2 + 400);
      if ( v14 )
        v6 = *(_DWORD *)(v14 + 16);
      v15 = *(_DWORD *)(v2 + 7444);
      this = *(vostok::render::backend **)(v2 + 7452);
      v39 = *(_DWORD *)(v2 + 7448);
      v16 = *(_DWORD *)(v2 + 7456);
      v36[0] = v13;
      v36[1] = v6;
      v41 = v15;
      v42 = this;
      v40 = v16;
      if ( v13 != *(_DWORD *)(v2 + 352)
        || v6 != *(_DWORD *)(v2 + 364)
        || *(_DWORD *)(v2 + 360) != v15
        || *(vostok::render::backend **)(v2 + 372) != this
        || *(_DWORD *)(v2 + 356) != *(_DWORD *)(v2 + 7448)
        || *(_DWORD *)(v2 + 368) != v16 )
      {
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetVertexBuffers(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          0,
          2u,
          (ID3D11Buffer *const *)v36,
          (const unsigned int *)&v41,
          (const unsigned int *)&v39);
        *(_DWORD *)(v2 + 356) = *(_DWORD *)(v2 + 7448);
        *(_DWORD *)(v2 + 360) = *(_DWORD *)(v2 + 7444);
        *(_DWORD *)(v2 + 368) = *(_DWORD *)(v2 + 7456);
        v17 = *(_DWORD *)(v2 + 7452);
        *(_DWORD *)(v2 + 352) = v13;
        *(_DWORD *)(v2 + 364) = v6;
        *(_DWORD *)(v2 + 372) = v17;
      }
    }
    else
    {
      if ( v12 )
        v18 = *(vostok::render::backend **)(v12 + 16);
      else
        v18 = 0;
      v42 = v18;
      if ( v18 != *(vostok::render::backend **)(v2 + 352) || *(_DWORD *)(v2 + 360) != *(_DWORD *)(v2 + 7444) )
      {
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetVertexBuffers(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          0,
          1u,
          (ID3D11Buffer *const *)&v42,
          (const unsigned int *)(v2 + 7444),
          &a2);
        *(_DWORD *)(v2 + 352) = v42;
        *(_DWORD *)(v2 + 356) = a2;
        *(_DWORD *)(v2 + 360) = *(_DWORD *)(v2 + 7444);
      }
      if ( *(_BYTE *)(v2 + 90) )
      {
        v19 = *(_DWORD *)(v2 + 404);
        if ( v19 )
          v19 = *(_DWORD *)(v19 + 16);
        v40 = v19;
        if ( v19 != *(_DWORD *)(v2 + 376) || *(_DWORD *)(v2 + 384) != *(_DWORD *)(v2 + 7460) )
        {
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetVertexBuffers(
            vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
            1u,
            1u,
            (ID3D11Buffer *const *)&v40,
            (const unsigned int *)(v2 + 7460),
            &a2);
          *(_DWORD *)(v2 + 376) = v40;
          *(_DWORD *)(v2 + 380) = a2;
          *(_DWORD *)(v2 + 384) = *(_DWORD *)(v2 + 7460);
        }
      }
    }
  }
  if ( *(_BYTE *)(v2 + 91) )
  {
    v20 = *(_DWORD *)(v2 + 408);
    v21 = v20 ? *(ID3D11Buffer **)(v20 + 16) : 0;
    if ( v21 != *(ID3D11Buffer **)(v2 + 388) )
    {
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetIndexBuffer(
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
        v21,
        DXGI_FORMAT_R16_UINT,
        a2);
      v22 = a2;
      *(_DWORD *)(v2 + 388) = v21;
      *(_DWORD *)(v2 + 392) = v22;
    }
  }
  v23 = *(_DWORD *)(v2 + 432);
  if ( v23 )
  {
    this = (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v24 = *(int **)(v23 + 784);
      for ( i = *(int **)(v23 + 788); v24 != i; ++v24 )
        vostok::render::shader_constant_buffer::update((vostok::render::shader_constant_buffer *)this, *v24);
    }
  }
  v25 = *(_DWORD *)(v2 + 2056);
  if ( v25 )
  {
    this = (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v26 = *(int **)(v25 + 784);
      for ( i = *(int **)(v25 + 788); v26 != i; ++v26 )
        vostok::render::shader_constant_buffer::update((vostok::render::shader_constant_buffer *)this, *v26);
    }
  }
  v27 = *(_DWORD *)(v2 + 3680);
  if ( v27 )
  {
    this = (vostok::render::backend *)vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr;
    if ( vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      v28 = *(int **)(v27 + 784);
      for ( i = *(int **)(v27 + 788); v28 != i; ++v28 )
        vostok::render::shader_constant_buffer::update((vostok::render::shader_constant_buffer *)this, *v28);
    }
  }
  if ( *(_BYTE *)(v2 + 98) )
    vostok::render::constants_handler<0>::apply((vostok::render::constants_handler<0> *)this, v2 + 424);
  if ( *(_BYTE *)(v2 + 99) )
    vostok::render::textures_handler<0>::apply((vostok::render::textures_handler<0> *)this, v2 + 492);
  if ( *(_BYTE *)(v2 + 100) )
    vostok::render::samplers_handler<0>::apply((vostok::render::samplers_handler<0> *)this, v2 + 1296);
  if ( *(_BYTE *)(v2 + 101) )
    vostok::render::buffers_handler<0>::apply(
      (vostok::render::buffers_handler<0> *)this,
      (unsigned __int8 *)(v2 + 1376));
  if ( *(_BYTE *)(v2 + 103) )
    vostok::render::constants_handler<2>::apply((vostok::render::constants_handler<2> *)this, v2 + 2048);
  if ( *(_BYTE *)(v2 + 104) )
    vostok::render::textures_handler<2>::apply((vostok::render::textures_handler<2> *)this, v2 + 2116);
  if ( *(_BYTE *)(v2 + 105) )
    vostok::render::samplers_handler<2>::apply((vostok::render::samplers_handler<2> *)this, v2 + 2920);
  if ( *(_BYTE *)(v2 + 106) )
    vostok::render::buffers_handler<1>::apply(
      (vostok::render::buffers_handler<2> *)this,
      (unsigned __int8 *)(v2 + 3000));
  if ( *(_BYTE *)(v2 + 108) )
    vostok::render::constants_handler<1>::apply((vostok::render::constants_handler<1> *)this, v2 + 3672);
  if ( *(_BYTE *)(v2 + 109) )
    vostok::render::textures_handler<1>::apply((vostok::render::textures_handler<1> *)this, v2 + 3740);
  if ( *(_BYTE *)(v2 + 110) )
    vostok::render::samplers_handler<1>::apply((vostok::render::samplers_handler<1> *)this, v2 + 4544);
  if ( *(_BYTE *)(v2 + 111) )
    vostok::render::buffers_handler<1>::apply(
      (vostok::render::buffers_handler<2> *)this,
      (unsigned __int8 *)(v2 + 4624));
  if ( *(_BYTE *)(v2 + 112) )
    vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetPrimitiveTopology(
      vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
      *(D3D_PRIMITIVE_TOPOLOGY *)(v2 + 7356));
  ++*(_DWORD *)(v2 + 7536);
  if ( *(_BYTE *)(v2 + 93) )
  {
    v29 = *(_DWORD *)(v2 + 412);
    if ( v29 )
    {
      v30 = v2 + 7364;
      if ( !*(_DWORD *)(v2 + 7364) )
        *(_DWORD *)v30 = vostok::render::res_declaration::get(
                           (vostok::render::res_declaration *)this,
                           *(const vostok::render::res_declaration **)(v2 + 7360),
                           *(const vostok::render::res_signature **)(v29 + 23824));
      v31 = *(ID3D11InputLayout **)(*(_DWORD *)v30 + 4);
      if ( *(ID3D11InputLayout **)(v2 + 348) != v31 )
      {
        *(_DWORD *)(v2 + 348) = v31;
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context->IASetInputLayout(
          vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
          v31);
      }
    }
  }
  v32 = v37;
  memset(v37, 0, 0x18u);
  v32[24] = 0;
}
