void __thiscall vostok::render::stage_visibility::get_results_and_prepare_bounds_grass(
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds,
        unsigned int *out_counter,
        vostok::math::float4x4 *a4)
{
  _DWORD *v4; // eax
  int **v5; // eax
  int *v6; // ebx
  int v7; // esi
  float x; // eax
  int v9; // esi
  vostok::math::float4x4 *v10; // eax
  const vostok::math::float4x4 *v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // edi
  vostok::math::float4x4 v14; // [esp+Ch] [ebp-58h] BYREF
  char v15; // [esp+4Ch] [ebp-18h] BYREF
  int *i; // [esp+5Ch] [ebp-8h]

  v4 = (int *)((char *)&dword_8B9668 + LODWORD(out_bounds[1][1016].z));
  if ( *v4 )
  {
    v5 = (int **)(*v4 + 340);
    v6 = *v5;
    for ( i = v5[1]; v6 != i; *out_counter = (unsigned int)(v12 + 4) )
    {
      v7 = *v6;
      *(_BYTE *)(v7 + 16565) = vostok::render::stage_visibility::occluded(
                                 (vostok::render::stage_visibility *)out_bounds,
                                 *(_DWORD *)(*v6 + 16528));
      x = a4->i.x;
      *(float *)(*v6 + 16528) = a4->i.x;
      v9 = *v6;
      LODWORD(a4->i.x) = LODWORD(x) + 1;
      v10 = vostok::math::float4x4::identity(a4, &v14);
      v11 = vostok::render::aabb_to_occlusion_bound(
              (const vostok::math::aabb *)(v9 + 92),
              (const vostok::math::float4x4 *)&v15,
              (vostok::math::aabb *)v10);
      v12 = (_DWORD *)*out_counter;
      v13 = (_DWORD *)*out_counter;
      *v13++ = LODWORD(v11->i.x);
      *v13++ = LODWORD(v11->i.y);
      *v13 = LODWORD(v11->i.z);
      ++v6;
      v13[1] = LODWORD(v11->i.w);
    }
  }
}
