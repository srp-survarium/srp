unsigned int __cdecl ASN1_tag2bit(unsigned int tag)
{
  if ( tag > 0x1E )
    return 0;
  else
    return tag2bit[tag];
}
