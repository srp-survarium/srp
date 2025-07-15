void __usercall vostok::render::binary_shader_source::binary_shader_source(
        vostok::render::binary_shader_source *this@<ecx>,
        int a2@<esi>)
{
  char v2; // dl

  vostok::resources::unmanaged_resource::unmanaged_resource(this, (_DWORD *)a2, fs_iterator_class);
  *(_DWORD *)a2 = &vostok::render::binary_shader_source::`vftable';
  *(_DWORD *)(a2 + 272) = 0;
  v2 = *(_BYTE *)(a2 + 274);
  *(_DWORD *)(a2 + 264) = 0;
  *(_DWORD *)(a2 + 268) = 0;
  *(_DWORD *)(a2 + 276) = 0;
  *(_BYTE *)(a2 + 274) = v2 & 0xF1 | 8;
  *(_DWORD *)(a2 + 280) = 0;
  *(_DWORD *)(a2 + 284) = 0;
  *(_DWORD *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 292) = 0;
  *(_DWORD *)(a2 + 296) = 0;
  *(_DWORD *)(a2 + 300) = 0;
}
