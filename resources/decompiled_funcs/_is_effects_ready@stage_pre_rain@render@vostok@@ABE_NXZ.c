BOOL __usercall vostok::render::stage_pre_rain::is_effects_ready@<eax>(
        vostok::render::stage_pre_rain *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 24) && *(_DWORD *)(a2 + 28);
}
