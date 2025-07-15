void __thiscall vostok::render::stage_visibility::get_results_and_prepare_bounds_models(
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds,
        unsigned int *out_counter,
        int *a4)
{
  float w; // eax
  int *v5; // ebx
  int v6; // esi
  int v7; // eax
  const vostok::math::float4x4 *v8; // eax
  _DWORD *v9; // ecx
  _DWORD *v10; // edi
  char v11; // [esp+Ch] [ebp-18h] BYREF
  int *i; // [esp+1Ch] [ebp-8h]

  w = out_bounds[1][1016].w;
  v5 = *(int **)(LODWORD(w) + 9368);
  for ( i = *(int **)(LODWORD(w) + 9372); v5 != i; *out_counter = (unsigned int)(v9 + 4) )
  {
    v6 = *v5;
    *(_BYTE *)(v6 + 53) = vostok::render::stage_visibility::occluded(
                            (vostok::render::stage_visibility *)out_bounds,
                            *(_DWORD *)(*v5 + 24));
    v7 = *a4;
    *(_DWORD *)(v6 + 24) = *a4;
    *a4 = v7 + 1;
    v8 = vostok::render::aabb_to_occlusion_bound(
           (const vostok::math::aabb *)(*(_DWORD *)(v6 + 16) + 108),
           (const vostok::math::float4x4 *)&v11,
           *(vostok::math::aabb **)(v6 + 36));
    v9 = (_DWORD *)*out_counter;
    v10 = (_DWORD *)*out_counter;
    *v10++ = LODWORD(v8->i.x);
    *v10++ = LODWORD(v8->i.y);
    *v10 = LODWORD(v8->i.z);
    ++v5;
    v10[1] = LODWORD(v8->i.w);
  }
}
