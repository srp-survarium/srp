int __usercall vostok::math::color_rgba@<eax>(float a1@<xmm0>, vostok::math *this, float g, float a)
{
  int v4; // edi
  unsigned int v5; // edi
  int v6; // edi

  v4 = (unsigned __int8)vostok::math::floor(a1 * 255.0);
  v5 = ((vostok::math::floor(a * 255.0) << 8) | v4) << 8;
  v6 = ((unsigned __int8)vostok::math::floor(g * 255.0) | v5) << 8;
  return v6 | (unsigned __int8)vostok::math::floor(*(float *)&this * 255.0);
}
