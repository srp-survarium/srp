void __thiscall vostok::render::stage_decals_accumulate::debug_render(vostok::render::stage_decals_accumulate *this)
{
  vostok::resources::resource_base::creation_source_enum *p_m_creation_source; // eax
  const vostok::math::float3_pod **v2; // esi
  const vostok::math::float3_pod *v3; // ebx
  vostok::math::float4x4 *v4; // ecx
  vostok::math::float4x4 *v5; // ebx
  vostok::math::float4x4 *scale; // eax
  vostok::math::float4x4 *v7; // eax
  vostok::render::system_renderer *v8; // ecx
  const vostok::math::float3_pod **v9; // [esp+1Ch] [ebp-188h]
  vostok::resources::resource_base::creation_source_enum *v10; // [esp+20h] [ebp-184h]
  int v11; // [esp+24h] [ebp-180h] BYREF
  vostok::math::float3 v12; // [esp+28h] [ebp-17Ch] BYREF
  vostok::math::float3 v13; // [esp+34h] [ebp-170h] BYREF
  vostok::math::float3 v14; // [esp+40h] [ebp-164h] BYREF
  vostok::math::float3_pod v15; // [esp+4Ch] [ebp-158h] BYREF
  vostok::math::float3 v16; // [esp+58h] [ebp-14Ch] BYREF
  vostok::math::float4x4 v17; // [esp+64h] [ebp-140h] BYREF
  vostok::math::float4x4 v18; // [esp+A4h] [ebp-100h] BYREF
  char v19[64]; // [esp+E4h] [ebp-C0h] BYREF
  char v20[64]; // [esp+124h] [ebp-80h] BYREF
  vostok::math::float4x4 v21; // [esp+164h] [ebp-40h] BYREF

  if ( s_render_debug )
  {
    p_m_creation_source = &this->m_context->m_scene_view.m_object[172].m_creation_source;
    v2 = (const vostok::math::float3_pod **)*p_m_creation_source;
    v10 = p_m_creation_source;
    v9 = (const vostok::math::float3_pod **)*p_m_creation_source;
    if ( *p_m_creation_source != *((_DWORD *)p_m_creation_source + 1) )
    {
      *(_QWORD *)&v12.x = 0;
      v12.z = s_bm_current_air_resistance;
      v11 = vostok::math::color_rgba(0.0, COERCE_VOSTOK_MATH_(1.0), 0.0, 1.0);
      while ( 1 )
      {
        v3 = *v2;
        v15 = (*v2)[6];
        vostok::math::normalize_safe(v3 + 3, &v12, &v13);
        v14.x = (float)(v15.z * (float)(v13.x * 0.0)) + v3[4].y;
        v14.y = v3[4].z + (float)(v15.z * (float)(v13.y * 0.0));
        v14.z = v3[5].x + (float)(v15.z * (float)(v13.z * 0.0));
        vostok::math::float4x4::get_angles_xyz(v4, (int)&v16, (int)&v3->y);
        v5 = vostok::math::create_rotation(&v16, (int)&v16, (int)v19);
        scale = vostok::math::create_scale((const vostok::math::float3 *)&v15, (vostok::math::float4x4 *)v20);
        vostok::math::mul4x3(v5, scale, &v18);
        v7 = vostok::math::create_translation(&v14, &v21);
        vostok::math::mul4x3(v7, &v18, &v17);
        vostok::render::system_renderer::draw_obb(
          v8,
          vostok::quasi_singleton<vostok::render::system_renderer>::pinst,
          (const vostok::math::color *)&v17,
          &v11);
        if ( ++v9 == *((const vostok::math::float3_pod ***)v10 + 1) )
          break;
        v2 = v9;
      }
    }
  }
}
