void __thiscall vostok::render::stage_visibility::get_results_and_prepare_bounds_env_probes(
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds,
        unsigned int *out_counter,
        int *a4)
{
  float w; // eax
  int *v5; // ebx
  int v6; // esi
  int v7; // eax
  vostok::math::float4x4 *v8; // eax
  const vostok::math::float4x4 *v9; // eax
  _DWORD *v10; // ecx
  _DWORD *v11; // edi
  vostok::math::float4x4 v12; // [esp+Ch] [ebp-70h] BYREF
  vostok::math::aabb v13; // [esp+4Ch] [ebp-30h] BYREF
  char v14; // [esp+64h] [ebp-18h] BYREF
  int *i; // [esp+74h] [ebp-8h]

  w = out_bounds[1][1016].w;
  v5 = *(int **)(LODWORD(w) + 52460);
  for ( i = *(int **)(LODWORD(w) + 52464); v5 != i; *out_counter = (unsigned int)(v10 + 4) )
  {
    v6 = *v5;
    *(_BYTE *)(v6 + 616) = vostok::render::stage_visibility::occluded(
                             (vostok::render::stage_visibility *)out_bounds,
                             *(_DWORD *)(*v5 + 608));
    v7 = *a4;
    *(_DWORD *)(*v5 + 608) = *a4;
    *a4 = v7 + 1;
    qmemcpy(&v13, (const void *)(*v5 + 552), sizeof(v13));
    v8 = vostok::math::float4x4::identity(0, &v12);
    v9 = vostok::render::aabb_to_occlusion_bound(&v13, (const vostok::math::float4x4 *)&v14, (vostok::math::aabb *)v8);
    v10 = (_DWORD *)*out_counter;
    v11 = (_DWORD *)*out_counter;
    *v11++ = LODWORD(v9->i.x);
    *v11++ = LODWORD(v9->i.y);
    *v11 = LODWORD(v9->i.z);
    ++v5;
    v11[1] = LODWORD(v9->i.w);
  }
}
