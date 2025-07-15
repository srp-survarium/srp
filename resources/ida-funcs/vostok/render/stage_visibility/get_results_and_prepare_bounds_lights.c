void __thiscall vostok::render::stage_visibility::get_results_and_prepare_bounds_lights(
        vostok::render::stage_visibility *this,
        vostok::math::float4 **out_bounds,
        unsigned int *out_counter,
        int *a4)
{
  float w; // eax
  int *v5; // ebx
  int v6; // esi
  int v7; // eax
  int v8; // eax
  float v9; // xmm0_4
  int v10; // eax
  __int64 v11; // [esp+10h] [ebp-24h]
  float v12; // [esp+18h] [ebp-1Ch]
  vostok::math::sphere v13; // [esp+1Ch] [ebp-18h] BYREF
  int *i; // [esp+2Ch] [ebp-8h]

  w = out_bounds[1][1016].w;
  v5 = *(int **)(LODWORD(w) + 44244);
  for ( i = *(int **)(LODWORD(w) + 44248); v5 != i; *out_counter = v10 + 16 )
  {
    v6 = *v5;
    *(_BYTE *)(v6 + 624) = vostok::render::stage_visibility::occluded(
                             (vostok::render::stage_visibility *)out_bounds,
                             *(_DWORD *)(*v5 + 684));
    v7 = *a4;
    *(_DWORD *)(*v5 + 684) = *a4;
    *a4 = v7 + 1;
    v8 = *v5;
    if ( (*(_DWORD *)(*v5 + 860) & 0xF) == 0 || (*(_DWORD *)(*v5 + 860) & 0xF) == 5 )
    {
      v9 = *(float *)(v8 + 608);
      *(_QWORD *)&v13.vector.x = *(_QWORD *)(v8 + 532);
      v13.vector.z = *(float *)(v8 + 540);
      v13.vector.w = v9;
    }
    else
    {
      vostok::math::aabb::sphere((vostok::math::aabb *)(v8 + 872), &v13);
    }
    v10 = *out_counter;
    v11 = *(_QWORD *)&v13.center.elements[1];
    v12 = v13.vector.w;
    *(float *)v10 = v13.vector.x;
    *(_QWORD *)(v10 + 4) = v11;
    ++v5;
    *(float *)(v10 + 12) = v12;
  }
}
