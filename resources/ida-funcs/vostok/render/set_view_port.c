void __usercall vostok::render::set_view_port(
        unsigned int width@<eax>,
        vostok::render::backend *a2@<ecx>,
        const unsigned int height)
{
  const D3D11_VIEWPORT *v3; // [esp+0h] [ebp-24h]
  D3D11_VIEWPORT v4; // [esp+4h] [ebp-20h] BYREF
  unsigned int v5; // [esp+1Ch] [ebp-8h]

  v5 = width;
  v4.TopLeftX = 0.0;
  v4.TopLeftY = 0.0;
  v4.Width = (float)width;
  v4.Height = (float)height;
  v4.MinDepth = 0.0;
  v4.MaxDepth = s_bm_current_air_resistance;
  vostok::render::backend::set_viewports(
    a2,
    SLODWORD(vostok::quasi_singleton<vostok::render::particle_shader_constants>::pinst.z),
    &v4,
    v3);
}
