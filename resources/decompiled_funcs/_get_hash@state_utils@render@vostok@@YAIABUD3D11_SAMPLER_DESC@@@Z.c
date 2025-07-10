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
