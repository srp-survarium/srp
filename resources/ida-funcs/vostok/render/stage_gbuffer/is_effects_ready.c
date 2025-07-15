BOOL __usercall vostok::render::stage_gbuffer::is_effects_ready@<eax>(
        vostok::render::stage_gbuffer *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 112) && *(_DWORD *)(a2 + 116);
}
