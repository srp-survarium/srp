int __cdecl crc32(unsigned int crc, const unsigned __int8 *buf, unsigned int len)
{
  if ( buf )
    return crc32_little(crc, buf, len);
  else
    return 0;
}
