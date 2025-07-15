ID3D11BlendState *__thiscall vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::get_state(
        vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32> *this,
        const vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::state_record *desc,
        const D3D11_BLEND_DESC *desca)
{
  unsigned int hash; // eax
  int AlphaToCoverageEnable; // edi
  int v6; // esi
  int v7; // esi
  vostok::buffer_vector<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::state_record> *v8; // ecx
  _BYTE v10[268]; // [esp-10Ch] [ebp-234h] BYREF
  _BYTE v11[264]; // [esp+10h] [ebp-118h] BYREF
  _DWORD v12[2]; // [esp+118h] [ebp-10h] BYREF
  unsigned int v13; // [esp+120h] [ebp-8h]
  unsigned int v14; // [esp+124h] [ebp-4h]
  const D3D11_BLEND_DESC *desc1; // [esp+130h] [ebp+8h]

  hash = vostok::render::state_utils::get_hash(desca);
  AlphaToCoverageEnable = desc->desc.AlphaToCoverageEnable;
  v14 = hash;
  v6 = 0;
  v13 = (desc->desc.IndependentBlendEnable - AlphaToCoverageEnable) / 272;
  if ( !v13 )
    goto LABEL_6;
  desc1 = (const D3D11_BLEND_DESC *)AlphaToCoverageEnable;
  while ( desc1[1].IndependentBlendEnable != v14 || !vostok::render::state_utils::operator==(desc1, desca) )
  {
    desc1 = (const D3D11_BLEND_DESC *)((char *)desc1 + 272);
    if ( ++v6 >= v13 )
      goto LABEL_6;
  }
  if ( v6 == -1 )
LABEL_6:
    v7 = 0;
  else
    v7 = *(_DWORD *)(272 * v6 + AlphaToCoverageEnable + 264);
  if ( !v7 )
  {
    v12[1] = v14;
    qmemcpy(v11, desca, sizeof(v11));
    *(_DWORD *)v10 = v12;
    qmemcpy(&v10[4], desca, 0x108u);
    vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::create_state(
      0,
      *(D3D11_BLEND_DESC *)v10,
      *(ID3D11BlendState ***)&v10[264]);
    v7 = v12[0];
    vostok::buffer_vector<vostok::render::state_cache<ID3D11BlendState,D3D11_BLEND_DESC,32>::state_record>::push_back(
      v8,
      desc,
      v11);
  }
  return (ID3D11BlendState *)v7;
}


ID3D11DepthStencilState *__thiscall vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::get_state(
        vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32> *this,
        const vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::state_record *desc,
        const D3D11_DEPTH_STENCIL_DESC *desca)
{
  unsigned int hash; // eax
  int DepthEnable; // edi
  int v6; // esi
  ID3D11DepthStencilState *v7; // esi
  vostok::buffer_vector<vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::state_record> *v8; // ecx
  D3D11_DEPTH_STENCIL_DESC v10; // [esp-38h] [ebp-88h] BYREF
  _BYTE v11[52]; // [esp+Ch] [ebp-44h] BYREF
  ID3D11DepthStencilState *ppIState[2]; // [esp+40h] [ebp-10h] BYREF
  unsigned __int32 v13; // [esp+48h] [ebp-8h]
  ID3D11DepthStencilState *v14; // [esp+4Ch] [ebp-4h]
  const D3D11_DEPTH_STENCIL_DESC *desc1; // [esp+58h] [ebp+8h]

  hash = vostok::render::state_utils::get_hash(desca);
  DepthEnable = desc->desc.DepthEnable;
  v14 = (ID3D11DepthStencilState *)hash;
  v6 = 0;
  v13 = (desc->desc.DepthWriteMask - DepthEnable) / 60;
  if ( !v13 )
    goto LABEL_6;
  desc1 = (const D3D11_DEPTH_STENCIL_DESC *)DepthEnable;
  while ( (ID3D11DepthStencilState *)desc1[1].DepthWriteMask != v14
       || !vostok::render::state_utils::operator==(desc1, desca) )
  {
    desc1 = (const D3D11_DEPTH_STENCIL_DESC *)((char *)desc1 + 60);
    if ( ++v6 >= v13 )
      goto LABEL_6;
  }
  if ( v6 == -1 )
LABEL_6:
    v7 = 0;
  else
    v7 = *(ID3D11DepthStencilState **)(60 * v6 + DepthEnable + 52);
  if ( !v7 )
  {
    ppIState[1] = v14;
    qmemcpy(v11, desca, sizeof(v11));
    qmemcpy((void *)&v10, desca, sizeof(v10));
    vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::create_state(0, v10, ppIState);
    v7 = ppIState[0];
    vostok::buffer_vector<vostok::render::state_cache<ID3D11DepthStencilState,D3D11_DEPTH_STENCIL_DESC,32>::state_record>::push_back(
      v8,
      desc,
      v11);
  }
  return v7;
}
