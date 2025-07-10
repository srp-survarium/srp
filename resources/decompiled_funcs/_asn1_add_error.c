void __cdecl asn1_add_error(const unsigned __int8 *address, int offset)
{
  char v2[16]; // [esp+0h] [ebp-24h] BYREF
  char buf[16]; // [esp+10h] [ebp-14h] BYREF

  BIO_snprintf(buf, 0xDu, "%lu", address);
  BIO_snprintf(v2, 0xDu, "%d", offset);
  ERR_add_error_data(4, "address=", buf, " offset=", v2);
}
