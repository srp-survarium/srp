void __usercall vostok::render::renderer_context::set_current_time(
        vostok::render::renderer_context *this@<ecx>,
        int a2@<eax>,
        int a3@<xmm0>)
{
  *(_DWORD *)(a2 + 11244) = a3;
}
