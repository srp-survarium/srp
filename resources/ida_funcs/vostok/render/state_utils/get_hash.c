unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_BLEND_DESC *desc@<eax>)
{
  D3D11_BLEND *p_SrcBlend; // esi
  int v3; // edi
  int v4; // ebx
  D3D11_BLEND v5; // ebx
  int v6; // ebx
  int v7; // ebx
  int v8; // ebx
  int v9; // ebx
  int v10; // ebx
  char buffer[4]; // [esp+Ch] [ebp-8h] BYREF
  boost::crc_optimal<32,79764919,0,0,1,0> crc_hash; // [esp+10h] [ebp-4h] BYREF

  boost::crc_optimal<32,79764919,0,0,1,0>::crc_optimal<32,79764919,0,0,1,0>(&crc_hash, 0);
  vostok::render::state_utils::crc::process(&crc_hash, desc->AlphaToCoverageEnable);
  vostok::render::state_utils::crc::process(&crc_hash, desc->IndependentBlendEnable);
  p_SrcBlend = &desc->RenderTarget[0].SrcBlend;
  v3 = 8;
  do
  {
    v4 = *((_DWORD *)p_SrcBlend - 1);
    buffer[0] = v4;
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE1(v4);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE2(v4);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = HIBYTE(v4);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    v5 = *p_SrcBlend;
    buffer[0] = *p_SrcBlend;
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE1(v5);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE2(v5);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = HIBYTE(v5);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    v6 = *((_DWORD *)p_SrcBlend + 1);
    buffer[0] = v6;
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE1(v6);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE2(v6);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = HIBYTE(v6);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    v7 = *((_DWORD *)p_SrcBlend + 2);
    buffer[0] = v7;
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE1(v7);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE2(v7);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = HIBYTE(v7);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    v8 = *((_DWORD *)p_SrcBlend + 3);
    buffer[0] = v8;
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE1(v8);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE2(v8);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = HIBYTE(v8);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    v9 = *((_DWORD *)p_SrcBlend + 4);
    buffer[0] = v9;
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE1(v9);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE2(v9);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = HIBYTE(v9);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    v10 = *((_DWORD *)p_SrcBlend + 5);
    buffer[0] = v10;
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE1(v10);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = BYTE2(v10);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = HIBYTE(v10);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    buffer[0] = *((_BYTE *)p_SrcBlend + 24);
    boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
    p_SrcBlend += 8;
    --v3;
  }
  while ( v3 );
  return boost::crc_optimal<32,79764919,0,0,1,0>::checksum(&crc_hash);
}


unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_DEPTH_STENCIL_DESC *desc@<edi>)
{
  char buffer[4]; // [esp+4h] [ebp-8h] BYREF
  boost::crc_optimal<32,79764919,0,0,1,0> crc_hash; // [esp+8h] [ebp-4h] BYREF

  boost::crc_optimal<32,79764919,0,0,1,0>::crc_optimal<32,79764919,0,0,1,0>(&crc_hash, 0);
  vostok::render::state_utils::crc::process(&crc_hash, desc->DepthEnable);
  vostok::render::state_utils::crc::process(&crc_hash, desc->DepthWriteMask);
  vostok::render::state_utils::crc::process(&crc_hash, desc->DepthFunc);
  vostok::render::state_utils::crc::process(&crc_hash, desc->StencilEnable);
  buffer[0] = desc->StencilReadMask;
  boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
  buffer[0] = desc->StencilWriteMask;
  boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(&crc_hash, buffer, 1u);
  vostok::render::state_utils::crc::process(&crc_hash, desc->FrontFace.StencilFailOp);
  vostok::render::state_utils::crc::process(&crc_hash, desc->FrontFace.StencilDepthFailOp);
  vostok::render::state_utils::crc::process(&crc_hash, desc->FrontFace.StencilPassOp);
  vostok::render::state_utils::crc::process(&crc_hash, desc->FrontFace.StencilFunc);
  vostok::render::state_utils::crc::process(&crc_hash, desc->BackFace.StencilFailOp);
  vostok::render::state_utils::crc::process(&crc_hash, desc->BackFace.StencilDepthFailOp);
  vostok::render::state_utils::crc::process(&crc_hash, desc->BackFace.StencilPassOp);
  vostok::render::state_utils::crc::process(&crc_hash, desc->BackFace.StencilFunc);
  return boost::crc_optimal<32,79764919,0,0,1,0>::checksum(&crc_hash);
}


unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_RASTERIZER_DESC *desc@<edi>)
{
  boost::crc_optimal<32,79764919,0,0,1,0> crc_hash; // [esp+4h] [ebp-8h] BYREF
  unsigned int value; // [esp+8h] [ebp-4h]

  boost::crc_optimal<32,79764919,0,0,1,0>::crc_optimal<32,79764919,0,0,1,0>(&crc_hash, 0);
  vostok::render::state_utils::crc::process(&crc_hash, desc->FillMode);
  vostok::render::state_utils::crc::process(&crc_hash, desc->CullMode);
  vostok::render::state_utils::crc::process(&crc_hash, desc->FrontCounterClockwise);
  vostok::render::state_utils::crc::process(&crc_hash, desc->DepthBias);
  value = LODWORD(desc->DepthBiasClamp);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  value = LODWORD(desc->SlopeScaledDepthBias);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  vostok::render::state_utils::crc::process(&crc_hash, desc->DepthClipEnable);
  vostok::render::state_utils::crc::process(&crc_hash, desc->ScissorEnable);
  vostok::render::state_utils::crc::process(&crc_hash, desc->MultisampleEnable);
  vostok::render::state_utils::crc::process(&crc_hash, desc->AntialiasedLineEnable);
  return boost::crc_optimal<32,79764919,0,0,1,0>::checksum(&crc_hash);
}


unsigned int __usercall vostok::render::state_utils::get_hash@<eax>(const D3D11_SAMPLER_DESC *desc@<edi>)
{
  boost::crc_optimal<32,79764919,0,0,1,0> crc_hash; // [esp+4h] [ebp-8h] BYREF
  unsigned int value; // [esp+8h] [ebp-4h]

  boost::crc_optimal<32,79764919,0,0,1,0>::crc_optimal<32,79764919,0,0,1,0>(&crc_hash, 0);
  vostok::render::state_utils::crc::process(&crc_hash, desc->Filter);
  vostok::render::state_utils::crc::process(&crc_hash, desc->AddressU);
  vostok::render::state_utils::crc::process(&crc_hash, desc->AddressV);
  vostok::render::state_utils::crc::process(&crc_hash, desc->AddressW);
  value = LODWORD(desc->MipLODBias);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  vostok::render::state_utils::crc::process(&crc_hash, desc->ComparisonFunc);
  value = LODWORD(desc->BorderColor[0]);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  value = LODWORD(desc->BorderColor[1]);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  value = LODWORD(desc->BorderColor[2]);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  value = LODWORD(desc->BorderColor[3]);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  value = LODWORD(desc->MinLOD);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  value = LODWORD(desc->MaxLOD);
  vostok::render::state_utils::crc::process(&crc_hash, value);
  return boost::crc_optimal<32,79764919,0,0,1,0>::checksum(&crc_hash);
}
