void __usercall vostok::render::binary_shader_source::binary_shader_source(
        vostok::render::binary_shader_source *this@<ecx>,
        int a2@<esi>)
{
  vostok::resources::unmanaged_resource::unmanaged_resource((vostok::resources::unmanaged_resource *)a2, 1u);
  *(_DWORD *)a2 = &stru_984D24.m_available_macros.m_buffer[4];
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 272) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_BYTE *)(a2 + 296) = 4;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 300) = 0;
  *(_DWORD *)(a2 + 304) = a2 + 316;
  *(_DWORD *)(a2 + 308) = a2 + 316;
  *(_BYTE *)(a2 + 316) = 0;
  *(_DWORD *)(a2 + 312) = a2 + 576;
  *(_BYTE *)(a2 + 576) = 47;
}
