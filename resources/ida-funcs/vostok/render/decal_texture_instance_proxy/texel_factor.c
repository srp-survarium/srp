double __thiscall vostok::render::decal_texture_instance_proxy::texel_factor(
        vostok::render::decal_texture_instance_proxy *this)
{
  float v2[6]; // [esp+0h] [ebp-1Ch] BYREF
  float v3; // [esp+18h] [ebp-4h]

  qmemcpy(v2, &this->m_decal->m_aabb, sizeof(v2));
  if ( (float)((float)(v2[3] - v2[0]) * 0.5) <= (float)((float)(v2[5] - v2[2]) * 0.5) )
    v3 = (float)(v2[5] - v2[2]) * 0.5;
  else
    v3 = (float)(v2[3] - v2[0]) * 0.5;
  return v3 * 0.5;
}
