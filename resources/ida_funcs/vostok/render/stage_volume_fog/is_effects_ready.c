BOOL __usercall vostok::render::stage_volume_fog::is_effects_ready@<eax>(
        vostok::render::stage_volume_fog *this@<ecx>,
        int a2@<eax>)
{
  return *(_DWORD *)(a2 + 40) && *(_DWORD *)(a2 + 44);
}
