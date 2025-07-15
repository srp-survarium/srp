void __thiscall vostok::render::stage_visibility::get_results_and_prepare_bounds_particles(
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds,
        unsigned int *out_counter,
        vostok::math::float4x4 *a4)
{
  float w; // eax
  _DWORD *v5; // ebx
  int v6; // esi
  unsigned int *v7; // edi
  float x; // eax
  vostok::math::float4x4 *v9; // eax
  const vostok::math::float4x4 *v10; // eax
  _DWORD *v11; // ecx
  _DWORD *v12; // edi
  vostok::math::float4x4 v13; // [esp+Ch] [ebp-58h] BYREF
  char v14; // [esp+4Ch] [ebp-18h] BYREF
  _DWORD *i; // [esp+5Ch] [ebp-8h]

  w = out_bounds[1][1016].w;
  v5 = *(_DWORD **)(LODWORD(w) + 56568);
  for ( i = *(_DWORD **)(LODWORD(w) + 56572); v5 != i; *out_counter = (unsigned int)(v11 + 4) )
  {
    v6 = *v5;
    v7 = (unsigned int *)(*v5 + 396);
    *(_BYTE *)(v6 + 400) = vostok::render::stage_visibility::occluded(
                             (vostok::render::stage_visibility *)out_bounds,
                             *v7);
    x = a4->i.x;
    *v7 = LODWORD(a4->i.x);
    LODWORD(a4->i.x) = LODWORD(x) + 1;
    v9 = vostok::math::float4x4::identity(a4, &v13);
    v10 = vostok::render::aabb_to_occlusion_bound(
            (const vostok::math::aabb *)(v6 + 160),
            (const vostok::math::float4x4 *)&v14,
            (vostok::math::aabb *)v9);
    v11 = (_DWORD *)*out_counter;
    v12 = (_DWORD *)*out_counter;
    *v12++ = LODWORD(v10->i.x);
    *v12++ = LODWORD(v10->i.y);
    *v12 = LODWORD(v10->i.z);
    ++v5;
    v12[1] = LODWORD(v10->i.w);
  }
}
