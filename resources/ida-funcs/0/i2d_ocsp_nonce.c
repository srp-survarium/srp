unsigned __int8 *__cdecl i2d_ocsp_nonce(unsigned __int8 **a, unsigned __int8 **pp)
{
  if ( pp )
  {
    memcpy((int)*pp, (const __m128i *)a[2], (unsigned int)*a);
    *pp = &(*pp)[(_DWORD)*a];
  }
  return *a;
}
