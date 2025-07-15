void __userpurge vostok::render::backend::clear_depth_stencil(
        vostok::render::backend *this@<ecx>,
        int a2@<eax>,
        unsigned int flags,
        float z_value,
        unsigned __int8 stencil_value)
{
  int v5; // ecx

  if ( s_debug_enabled_ds_clearing_value )
  {
    v5 = *(_DWORD *)(a2 + 7384);
    if ( v5 )
      ((void (__stdcall *)(ID3D11DeviceContext *, int, unsigned int, _DWORD, _DWORD))vostok::quasi_singleton<vostok::render::device>::pinst->m_context->ClearDepthStencilView)(
        vostok::quasi_singleton<vostok::render::device>::pinst->m_context,
        v5,
        flags,
        1.0,
        0);
  }
}
