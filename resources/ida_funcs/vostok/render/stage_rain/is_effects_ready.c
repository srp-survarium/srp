BOOL __usercall vostok::render::stage_rain::is_effects_ready@<eax>(
        vostok::render::stage_rain *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 20) && *(_DWORD *)(a2 + 24);
}
