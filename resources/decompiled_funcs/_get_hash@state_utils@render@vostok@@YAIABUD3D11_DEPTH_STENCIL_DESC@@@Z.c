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
