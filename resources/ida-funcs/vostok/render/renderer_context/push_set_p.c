void __userpurge vostok::render::renderer_context::push_set_p(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<eax>,
        vostok::render::renderer_context *m)
{
  void *v3; // edi

  v3 = *(void **)(a2 + 14464);
  if ( v3 )
    qmemcpy(v3, (const void *)(a2 + 15940), 0x40u);
  *(_DWORD *)(a2 + 14464) += 64;
  vostok::render::renderer_context::set_p(m, (const vostok::math::float4x4 *)a2);
}
