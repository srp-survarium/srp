int __cdecl tls1_ec_curve_id2nid(int curve_id)
{
  if ( curve_id < 1 || (unsigned int)curve_id > 0x19 )
    return 0;
  else
    return dword_9B2744[curve_id];
}
