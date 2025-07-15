void __usercall vostok::math::half_pod::operator float(vostok::math::half_pod *this@<ecx>, unsigned __int16 *a2@<eax>)
{
  unsigned int v2; // eax
  int v3; // ecx
  int v4; // eax

  v2 = *a2;
  v3 = (v2 >> 10) & 0x1F;
  v4 = v2 & 0x3FF;
  if ( !v3 && v4 )
  {
    while ( (v4 & 0x400) == 0 )
    {
      LOWORD(v4) = 2 * v4;
      --v3;
    }
  }
}
