vostok::math::color *__cdecl vostok::render::interpolated_color_64_(
        vostok::math::color *result,
        vostok::math::color (*color_grid)[64][64],
        vostok::math::float2 uv)
{
  signed int v4; // edi
  signed int v5; // eax
  unsigned int v6; // eax
  int v7; // esi
  unsigned int v8; // eax
  float y; // [esp+18h] [ebp+4h]

  result->m_value = -1;
  v4 = vostok::math::floor(uv.x);
  v5 = vostok::math::floor(uv.y);
  y = (float)(COERCE_FLOAT(LODWORD(uv.y) & 0x7FFFFFFF) - (float)((v5 >> 31) ^ ((v5 >> 31) + v5))) * 64.0;
  v6 = vostok::math::floor((float)(COERCE_FLOAT(LODWORD(uv.x) & 0x7FFFFFFF) - (float)((v4 >> 31) ^ ((v4 >> 31) + v4))) * 64.0);
  if ( v6 )
  {
    v7 = v6;
    if ( v6 > 0x3F )
      v7 = 63;
  }
  else
  {
    v7 = 0;
  }
  v8 = vostok::math::floor(y);
  if ( v8 )
  {
    if ( v8 > 0x3F )
      v8 = 63;
    *result = (*color_grid)[v7][v8];
    return result;
  }
  else
  {
    *result = (*color_grid)[v7][0];
    return result;
  }
}
