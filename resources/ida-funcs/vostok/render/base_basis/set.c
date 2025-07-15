void __userpurge vostok::render::base_basis::set(
        vostok::render::base_basis *this@<ecx>,
        _BYTE *a2@<edi>,
        vostok::math::float3 n)
{
  signed int v3; // eax
  signed int v4; // eax
  signed int v5; // eax
  float y; // [esp+0h] [ebp-8h]
  float z; // [esp+0h] [ebp-8h]

  vostok::math::float3_pod::normalize_safe((vostok::math::float3_pod *)this, &n, &n.x);
  n.x = (float)(n.x + s_bm_current_air_resistance) * 127.5;
  n.y = (float)(n.y + s_bm_current_air_resistance) * 127.5;
  n.z = (float)(n.z + s_bm_current_air_resistance) * 127.5;
  v3 = vostok::math::floor(n.x);
  if ( v3 > 0 )
  {
    if ( v3 > 255 )
      LOBYTE(v3) = -1;
  }
  else
  {
    LOBYTE(v3) = 0;
  }
  y = n.y;
  *a2 = v3;
  v4 = vostok::math::floor(y);
  if ( v4 > 0 )
  {
    if ( v4 > 255 )
      LOBYTE(v4) = -1;
  }
  else
  {
    LOBYTE(v4) = 0;
  }
  z = n.z;
  a2[1] = v4;
  v5 = vostok::math::floor(z);
  if ( v5 > 0 )
  {
    if ( v5 > 255 )
      LOBYTE(v5) = -1;
  }
  else
  {
    LOBYTE(v5) = 0;
  }
  a2[2] = v5;
}
