unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_BLEND_DESC *desc@<eax>)
{
  char *p_DestBlend; // esi
  int v4; // [esp+Ch] [ebp-8h]
  unsigned int x; // [esp+10h] [ebp-4h] BYREF

  x = boost::detail::crc_helper<32,1>::reflect(0);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)desc,
    (char *)&desc->IndependentBlendEnable);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->IndependentBlendEnable,
    (char *)desc->RenderTarget);
  p_DestBlend = (char *)&desc->RenderTarget[0].DestBlend;
  v4 = 8;
  do
  {
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend - 8,
      p_DestBlend - 4);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend - 4,
      p_DestBlend);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend,
      p_DestBlend + 4);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend + 4,
      p_DestBlend + 8);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend + 8,
      p_DestBlend + 12);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend + 12,
      p_DestBlend + 16);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend + 16,
      p_DestBlend + 20);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
      (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
      p_DestBlend + 20,
      p_DestBlend + 21);
    p_DestBlend += 32;
    --v4;
  }
  while ( v4 );
  return boost::detail::crc_helper<32,1>::reflect(x);
}


unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_DEPTH_STENCIL_DESC *desc@<esi>)
{
  unsigned int x; // [esp+4h] [ebp-4h] BYREF

  x = boost::detail::crc_helper<32,1>::reflect(0);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)desc,
    (char *)&desc->DepthWriteMask);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->DepthWriteMask,
    (char *)&desc->DepthFunc);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->DepthFunc,
    (char *)&desc->StencilEnable);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->StencilEnable,
    (char *)&desc->StencilReadMask);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->StencilReadMask,
    (char *)&desc->StencilWriteMask);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->StencilWriteMask,
    (char *)&desc->StencilWriteMask + 1);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->FrontFace,
    (char *)&desc->FrontFace.StencilDepthFailOp);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->FrontFace.StencilDepthFailOp,
    (char *)&desc->FrontFace.StencilPassOp);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->FrontFace.StencilPassOp,
    (char *)&desc->FrontFace.StencilFunc);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->FrontFace.StencilFunc,
    (char *)&desc->BackFace);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->BackFace,
    (char *)&desc->BackFace.StencilDepthFailOp);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->BackFace.StencilDepthFailOp,
    (char *)&desc->BackFace.StencilPassOp);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->BackFace.StencilPassOp,
    (char *)&desc->BackFace.StencilFunc);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->BackFace.StencilFunc,
    (char *)&desc[1]);
  return boost::detail::crc_helper<32,1>::reflect(x);
}


unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_RASTERIZER_DESC *desc@<esi>)
{
  unsigned int x; // [esp+4h] [ebp-4h] BYREF

  x = boost::detail::crc_helper<32,1>::reflect(0);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)desc,
    (char *)&desc->CullMode);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->CullMode,
    (char *)&desc->FrontCounterClockwise);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->FrontCounterClockwise,
    (char *)&desc->DepthBias);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->DepthBias,
    (char *)&desc->DepthBiasClamp);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->DepthBiasClamp,
    (char *)&desc->SlopeScaledDepthBias);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->SlopeScaledDepthBias,
    (char *)&desc->DepthClipEnable);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->DepthClipEnable,
    (char *)&desc->ScissorEnable);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->ScissorEnable,
    (char *)&desc->MultisampleEnable);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->MultisampleEnable,
    (char *)&desc->AntialiasedLineEnable);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->AntialiasedLineEnable,
    (char *)&desc[1]);
  return boost::detail::crc_helper<32,1>::reflect(x);
}


unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_SAMPLER_DESC *desc@<esi>)
{
  unsigned int x; // [esp+4h] [ebp-4h] BYREF

  x = boost::detail::crc_helper<32,1>::reflect(0);
  boost::detail::crc_table_t<32,79764919,1>::init_table();
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)desc,
    (char *)&desc->AddressU);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->AddressU,
    (char *)&desc->AddressV);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->AddressV,
    (char *)&desc->AddressW);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->AddressW,
    (char *)&desc->MipLODBias);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->MipLODBias,
    (char *)&desc->MaxAnisotropy);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->ComparisonFunc,
    (char *)desc->BorderColor);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)desc->BorderColor,
    (char *)&desc->BorderColor[1]);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->BorderColor[1],
    (char *)&desc->BorderColor[2]);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->BorderColor[2],
    (char *)&desc->BorderColor[3]);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->BorderColor[3],
    (char *)&desc->MinLOD);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->MinLOD,
    (char *)&desc->MaxLOD);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_block(
    (boost::crc_optimal<32,79764919,4294967295,4294967295,1,1> *)&x,
    (char *)&desc->MaxLOD,
    (char *)&desc[1]);
  return boost::detail::crc_helper<32,1>::reflect(x);
}
