int __cdecl ASN1_put_eoc(unsigned __int8 **pp)
{
  _BYTE *v1; // eax

  v1 = *pp;
  *v1++ = 0;
  *v1 = 0;
  *pp = v1 + 1;
  return 2;
}
