bool __usercall vostok::render::stage_visibility::query_data@<al>(
        vostok::render::stage_visibility *this@<ecx>,
        int a2@<eax>)
{
  return vostok::render::hw_hiz_occlusion_manager::quary_and_get_results_if_ready(
           *(vostok::render::hw_hiz_occlusion_manager **)(a2 + 32),
           *(unsigned __int8 **)(a2 + 28),
           *(_DWORD *)(a2 + 32));
}
