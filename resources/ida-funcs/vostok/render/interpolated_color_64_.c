vostok::math::color *__usercall vostok::render::interpolated_color_64_@<eax>(
        unsigned int *a1@<edi>,
        int a2@<esi>,
        vostok::math::color *result,
        vostok::math::color (*color_grid)[64][64],
        const vostok::math::float2 uv)
{
  unsigned int v5; // eax
  int v6; // esi
  unsigned int v7; // eax
  double v9; // [esp-4h] [ebp-14h]
  double v10; // [esp+0h] [ebp-10h]
  float v11; // [esp+0h] [ebp-10h]
  float v12; // [esp+8h] [ebp-8h]
  float x; // [esp+Ch] [ebp-4h] BYREF
  float v14; // [esp+20h] [ebp+10h]

  *a1 = -1;
  HIDWORD(v10) = a2;
  LODWORD(v10) = &x;
  x = *(float *)&(*color_grid)[0][0].m_value;
  v12 = modf(*(float *)&(*color_grid)[0][0].m_value, v10);
  LODWORD(v9) = &x;
  x = uv.x;
  v14 = modf(uv.x, v9) * 64.0;
  v11 = 64.0 * v12;
  v5 = vostok::math::floor(v11);
  if ( v5 )
  {
    if ( v5 > 0x3F )
      v6 = 63;
    else
      v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  v7 = vostok::math::floor(v14);
  if ( v7 )
  {
    if ( v7 > 0x3F )
      v7 = 63;
  }
  else
  {
    v7 = 0;
  }
  *a1 = result[64 * v6 + v7].m_value;
  return (vostok::math::color *)a1;
}
