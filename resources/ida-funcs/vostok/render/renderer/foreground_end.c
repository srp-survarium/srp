void __usercall vostok::render::renderer::foreground_end(vostok::render::renderer *this@<ecx>, int a2@<edi>)
{
  vostok::render::renderer_context *v2; // ecx
  vostok::render::backend *v3; // ecx
  const D3D11_VIEWPORT *v4; // [esp+0h] [ebp-4h]

  if ( s_foreground_pass )
  {
    D3DPERF_EndEvent();
    vostok::render::renderer_context::pop_p(v2, *(vostok::render::renderer_context **)(a2 + 480));
    vostok::render::backend::set_viewports(
      v3,
      SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
      (const D3D11_VIEWPORT *)a2,
      v4);
  }
}
