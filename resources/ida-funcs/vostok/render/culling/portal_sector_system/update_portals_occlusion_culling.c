void __userpurge vostok::render::culling::portal_sector_system::update_portals_occlusion_culling(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        int a2@<eax>,
        unsigned __int8 *occlusion_results)
{
  if ( s_portals_occlusion_culling_value )
    stlp_std::priv::__copy_trivial(
      occlusion_results,
      &occlusion_results[*(_DWORD *)(a2 + 49464) - *(_DWORD *)(a2 + 49460)],
      *(unsigned __int8 **)(a2 + 49460));
  else
    memset(*(_DWORD *)(a2 + 49460), 255, *(_DWORD *)(a2 + 49464) - *(_DWORD *)(a2 + 49460));
}
