void __usercall vostok::render::state_utils::crc::process(
        boost::crc_optimal<32,79764919,0,0,1,0> *proc@<esi>,
        unsigned int value)
{
  unsigned int v2; // ebx

  v2 = value;
  boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(proc, (char *)&value, 1u);
  LOBYTE(value) = BYTE1(v2);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(proc, (char *)&value, 1u);
  LOBYTE(value) = BYTE2(v2);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(proc, (char *)&value, 1u);
  LOBYTE(value) = HIBYTE(v2);
  boost::crc_optimal<32,79764919,0,0,1,0>::process_bytes(proc, (char *)&value, 1u);
}
