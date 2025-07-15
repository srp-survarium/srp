void __userpurge vostok::render::sky_ambient_occlusion::sky_ambient_occlusion(
        vostok::render::sky_ambient_occlusion *this@<ecx>,
        int a2@<esi>,
        const vostok::render::sky_ambient_occlusion_properties *properties,
        unsigned int id)
{
  const vostok::math::float4x4 *v4; // xmm0_4
  __int64 v5; // [esp+4h] [ebp-10h]

  *(_DWORD *)a2 = 0;
  *(_DWORD *)(a2 + 4) = a2 + 16;
  *(_DWORD *)(a2 + 8) = a2 + 16;
  *(_BYTE *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 12) = a2 + 276;
  *(_QWORD *)(a2 + 304) = 0xBF800000BF800000uLL;
  v4 = clear_value;
  *(_DWORD *)(a2 + 312) = -1082130432;
  LODWORD(v5) = v4;
  HIDWORD(v5) = v4;
  *(_QWORD *)(a2 + 316) = v5;
  *(_DWORD *)(a2 + 324) = v4;
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 332) = id;
  *(_DWORD *)(a2 + 336) = -1;
  *(_BYTE *)(a2 + 340) = 0;
  vostok::render::sky_ambient_occlusion::set_properties(properties, (vostok::render::sky_ambient_occlusion *)a2);
}
