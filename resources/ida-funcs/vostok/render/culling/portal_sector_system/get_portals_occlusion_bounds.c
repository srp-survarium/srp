void __userpurge vostok::render::culling::portal_sector_system::get_portals_occlusion_bounds(
        vostok::render::culling::portal_sector_system *this@<ecx>,
        int a2@<eax>,
        vostok::math::float4 *bounds)
{
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax

  v3 = *(unsigned __int8 **)(a2 + 292);
  v4 = *(_DWORD *)(a2 + 296) - (_DWORD)v3;
  if ( v4 )
    memmove((unsigned __int8 *)bounds, v3, v4);
}
