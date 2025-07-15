void __thiscall vostok::render::stage_screen_image::clear_surfaces(vostok::render::stage_screen_image *this)
{
  float z; // esi
  unsigned __int8 v2; // al
  vostok::render::backend *v3; // ecx

  if ( vostok::quasi_singleton<vostok::render::options>::pinst->current.m_clear_surfaces )
  {
    z = vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z;
    vostok::render::backend::reset_render_targets(
      (vostok::render::backend *)this,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z));
    *(_BYTE *)(LODWORD(z) + 117) |= *(_DWORD *)(LODWORD(z) + 7384) != 0;
    *(_DWORD *)(LODWORD(z) + 7384) = 0;
    v2 = vostok::math::color_rgba(0.5, COERCE_VOSTOK_MATH_(0.5), 0.5, 0.5);
    vostok::render::backend::clear_render_targets(v3, LODWORD(z), v2);
  }
}
