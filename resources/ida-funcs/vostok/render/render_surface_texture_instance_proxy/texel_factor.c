double __thiscall vostok::render::render_surface_texture_instance_proxy::texel_factor(
        vostok::render::render_surface_texture_instance_proxy *this)
{
  vostok::render::render_surface_instance *m_surface; // esi
  float y; // xmm1_4
  vostok::math::float3 v4; // [esp+4h] [ebp-10h] BYREF
  float x; // [esp+10h] [ebp-4h]

  m_surface = this->m_surface;
  vostok::math::float4x4::get_scale(m_surface->m_transform, &v4);
  y = v4.y;
  if ( v4.y <= v4.z )
    y = v4.z;
  if ( v4.x <= y )
    x = y;
  else
    x = v4.x;
  return m_surface->m_render_surface->m_streaming_texture_factor * x;
}
