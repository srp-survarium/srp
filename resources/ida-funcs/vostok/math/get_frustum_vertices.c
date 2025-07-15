char __cdecl vostok::math::get_frustum_vertices(const vostok::math::frustum *f, vostok::math::float3 (*vertices)[8])
{
  _DWORD *v2; // esi
  vostok::math::aabb_plane *v3; // eax
  vostok::math::aabb_plane *v4; // ecx
  vostok::math::aabb_plane *v5; // edx
  float v6; // xmm1_4
  float z; // xmm0_4
  int v9; // [esp+10h] [ebp-98h]
  _DWORD v10[24]; // [esp+14h] [ebp-94h] BYREF
  vostok::math::float3 v11; // [esp+74h] [ebp-34h] BYREF
  vostok::math::float3 v12; // [esp+80h] [ebp-28h] BYREF
  vostok::math::float3_pod v13; // [esp+8Ch] [ebp-1Ch] BYREF
  vostok::math::float3_pod normal; // [esp+98h] [ebp-10h] BYREF
  unsigned int v15; // [esp+A4h] [ebp-4h]

  v10[1] = 4;
  v10[4] = 4;
  v10[7] = 4;
  v10[10] = 4;
  v10[0] = 0;
  v10[9] = 0;
  v10[12] = 0;
  v10[21] = 0;
  v15 = 0;
  v2 = v10;
  v10[13] = 5;
  v10[16] = 5;
  v10[19] = 5;
  v10[22] = 5;
  v9 = 2;
  v10[2] = 2;
  v10[3] = 1;
  v10[5] = 3;
  v10[6] = 1;
  v10[8] = 3;
  v10[11] = 2;
  v10[14] = 2;
  v10[15] = 1;
  v10[17] = 3;
  v10[18] = 1;
  v10[20] = 3;
  while ( 1 )
  {
    v3 = &f->m_planes[*(v2 - 1)];
    v4 = &f->m_planes[*v2];
    v5 = &f->m_planes[v2[1]];
    LODWORD(v11.x) = LODWORD(v3->plane.d) ^ _mask__NegFloat_;
    LODWORD(v11.y) = LODWORD(v4->plane.d) ^ _mask__NegFloat_;
    LODWORD(v6) = LODWORD(v5->plane.d) ^ _mask__NegFloat_;
    normal = v5->plane.normal;
    v13 = v4->plane.normal;
    *(_QWORD *)&v12.x = *(_QWORD *)&v3->plane.normal.x;
    z = v3->plane.normal.z;
    v11.z = v6;
    v12.z = z;
    if ( !vostok::math::try_solve_linear_equations_system(
            &v12,
            (const vostok::math::float3 *)&v13,
            (const vostok::math::float3 *)&normal,
            &v11,
            (vostok::math::float3 *)((char *)v2 + (char *)vertices - (char *)v10)) )
      break;
    ++v15;
    v2 += 3;
    if ( v15 >= 8 )
      return 1;
  }
  return 0;
}
