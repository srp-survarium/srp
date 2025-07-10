BOOL __usercall vostok::render::stage_decals_accumulate::is_effects_ready@<eax>(
        vostok::render::stage_decals_accumulate *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 16) && *(_DWORD *)(a2 + 20);
}
