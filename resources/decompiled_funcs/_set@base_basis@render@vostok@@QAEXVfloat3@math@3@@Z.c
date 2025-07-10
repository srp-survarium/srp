void __userpurge vostok::render::base_basis::set(
        vostok::render::base_basis *this@<ecx>,
        _BYTE *a2@<esi>,
        vostok::math::float3 n)
{
  signed int v3; // eax
  signed int v4; // eax
  signed int v5; // eax
  float value; // [esp+0h] [ebp-4h]
  float valuea; // [esp+0h] [ebp-4h]

  vostok::math::float3_pod::normalize_safe(&n, &n);
  n.x = (float)(n.x + *(float *)&clear_value) * 127.5;
  n.y = (float)(n.y + *(float *)&clear_value) * 127.5;
  n.z = (float)(n.z + *(float *)&clear_value) * 127.5;
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
  value = n.y;
  *a2 = v3;
  v4 = vostok::math::floor(value);
  if ( v4 > 0 )
  {
    if ( v4 > 255 )
      LOBYTE(v4) = -1;
  }
  else
  {
    LOBYTE(v4) = 0;
  }
  valuea = n.z;
  a2[1] = v4;
  v5 = vostok::math::floor(valuea);
  if ( v5 > 0 )
  {
    if ( v5 > 255 )
      LOBYTE(v5) = -1;
    a2[2] = v5;
  }
  else
  {
    a2[2] = 0;
  }
}
