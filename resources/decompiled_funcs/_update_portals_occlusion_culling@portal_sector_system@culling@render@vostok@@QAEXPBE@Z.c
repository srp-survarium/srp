void __userpurge vostok::render::culling::portal_sector_system::update_portals_occlusion_culling(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        int a2@<eax>,
        unsigned __int8 *occlusion_results)
{
  unsigned int v3; // ecx

  if ( s_portals_occlusion_culling_value )
  {
    v3 = *(_DWORD *)(a2 + 308) - *(_DWORD *)(a2 + 304);
    if ( v3 )
      memmove(*(unsigned __int8 **)(a2 + 304), occlusion_results, v3);
  }
  else
  {
    memset(*(_DWORD *)(a2 + 304), (unsigned __int8 *)0xFF, *(_DWORD *)(a2 + 308) - *(_DWORD *)(a2 + 304));
  }
}
