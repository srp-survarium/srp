vostok::math::float4 *__thiscall vostok::render::stage_postprocess::compute_luminance_parameters(
        vostok::render::stage_postprocess *this,
        vostok::render::stage_postprocess *result,
        unsigned int frame_delta)
{
  float v3; // eax
  int v4; // edi
  vostok::render::res_texture *v5; // eax
  int v6; // edi
  vostok::render::res_texture *v7; // esi
  vostok::render::res_texture *v8; // ecx

  v3 = *(float *)&result->m_context;
  v4 = *(_DWORD *)(LODWORD(v3) + 12392);
  v5 = *(vostok::render::res_texture **)(*(_DWORD *)LODWORD(v3) + 7676);
  v6 = v4 + 280;
  v7 = 0;
  if ( v5 )
  {
    v7 = v5;
    ++v5->m_reference_count;
  }
  vostok::render::stage_postprocess::measure_per_pixel_luminance(this, result, v7);
  if ( v7 )
  {
    if ( v7->m_reference_count-- == 1 )
      vostok::render::res_texture::destroy_impl(v8, v7);
  }
  if ( COERCE_FLOAT(*(_DWORD *)(v6 + 344) & 0x7FFFFFFF) >= 0.050000001 )
    vostok::render::stage_postprocess::compute_per_pixel_eye_adaptated_luminance(
      (vostok::render::stage_postprocess *)v8,
      result);
  return (vostok::math::float4 *)frame_delta;
}
