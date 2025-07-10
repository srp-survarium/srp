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
