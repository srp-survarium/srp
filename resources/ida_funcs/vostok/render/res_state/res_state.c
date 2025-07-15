void __userpurge vostok::render::res_state::res_state(
        vostok::render::res_state *this@<ecx>,
        int a2@<eax>,
        ID3D11DepthStencilState *rasterizer_state,
        ID3D11BlendState *depth_stencil_state,
        ID3D11BlendState *blend_state,
        unsigned int stencil_ref)
{
  *(_DWORD *)(a2 + 4) = this;
  *(_DWORD *)(a2 + 8) = rasterizer_state;
  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 12) = depth_stencil_state;
  *(_DWORD *)(a2 + 16) = blend_state;
  *(_BYTE *)(a2 + 20) = 0;
}
