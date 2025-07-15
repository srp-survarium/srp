void __userpurge vostok::render::sky_ambient_occlusion::sky_ambient_occlusion(
        vostok::render::sky_ambient_occlusion *this@<ecx>,
        int a2@<esi>,
        const vostok::render::sky_ambient_occlusion_properties *properties,
        const unsigned int id)
{
  vostok::render::sky_ambient_occlusion *v4; // ecx

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = a2 + 16;
  *(_DWORD *)(a2 + 8) = a2 + 16;
  *(_BYTE *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 12) = a2 + 276;
  vostok::math::create_identity_aabb((vostok::math::aabb *)(a2 + 304));
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 336) = -1;
  *(_DWORD *)(a2 + 332) = id;
  *(_BYTE *)(a2 + 340) = 0;
  vostok::render::sky_ambient_occlusion::set_properties(
    v4,
    (const vostok::render::sky_ambient_occlusion_properties *)a2,
    &properties->texture_name);
}
