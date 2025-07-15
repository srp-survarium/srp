char __usercall vostok::math::get_frustum_vertices@<al>(
        const vostok::math::frustum *f@<edi>,
        vostok::math::float3 (*vertices)[8])
{
  vostok::math::get_frustum_vertices::__l2::frustum_plane_id *v2; // esi
  unsigned int v3; // ebx
  vostok::math::aabb_plane *v4; // eax
  vostok::math::float3 *v5; // ecx
  int v6; // edx
  vostok::math::float3 *v7; // edx
  float v8; // xmm1_4
  float z; // xmm0_4
  vostok::math::float3 second; // [esp+10h] [ebp-90h] BYREF
  vostok::math::float3 b; // [esp+1Ch] [ebp-84h] BYREF
  vostok::math::float3 first; // [esp+28h] [ebp-78h] BYREF
  vostok::math::float3 third; // [esp+34h] [ebp-6Ch] BYREF
  vostok::math::get_frustum_vertices::__l2::frustum_plane_id plane_itersections[24]; // [esp+40h] [ebp-60h] BYREF

  plane_itersections[2] = 4;
  plane_itersections[5] = 4;
  plane_itersections[8] = 4;
  plane_itersections[11] = 4;
  plane_itersections[0] = hands_count;
  plane_itersections[3] = hands_count;
  plane_itersections[12] = hands_count;
  plane_itersections[15] = hands_count;
  v2 = &plane_itersections[1];
  plane_itersections[14] = 5;
  plane_itersections[17] = 5;
  plane_itersections[20] = 5;
  plane_itersections[23] = 5;
  plane_itersections[4] = right;
  plane_itersections[7] = right;
  plane_itersections[16] = right;
  plane_itersections[19] = right;
  v3 = 0;
  plane_itersections[1] = left;
  plane_itersections[6] = hands_count|right;
  plane_itersections[9] = hands_count|right;
  plane_itersections[10] = left;
  plane_itersections[13] = left;
  plane_itersections[18] = hands_count|right;
  plane_itersections[21] = hands_count|right;
  plane_itersections[22] = left;
  while ( 1 )
  {
    v4 = &f->m_planes[*((_DWORD *)v2 - 1)];
    v5 = (vostok::math::float3 *)&f->m_planes[*v2];
    v6 = *((_DWORD *)v2 + 1);
    b.x = -v4->plane.d;
    v7 = (vostok::math::float3 *)&f->m_planes[v6];
    b.y = -v5[1].x;
    v8 = -v7[1].x;
    third = *v7;
    second = *v5;
    *(_QWORD *)&first.x = *(_QWORD *)&v4->plane.normal.x;
    z = v4->plane.normal.z;
    b.z = v8;
    first.z = z;
    if ( !vostok::math::try_solve_linear_equations_system(
            &first,
            &second,
            &third,
            &b,
            (vostok::math::float3 *)((char *)v2 + (char *)vertices - (char *)&plane_itersections[1])) )
      break;
    ++v3;
    v2 += 3;
    if ( v3 >= 8 )
      return 1;
  }
  return 0;
}
