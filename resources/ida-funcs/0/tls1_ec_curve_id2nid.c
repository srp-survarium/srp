int __cdecl tls1_ec_curve_id2nid(unsigned int curve_id)
{
  if ( (int)curve_id < 1 || curve_id > 0x19 )
    return 0;
  else
    return dword_873524[curve_id];
}
