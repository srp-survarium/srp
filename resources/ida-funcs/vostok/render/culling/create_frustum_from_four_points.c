vostok::math::frustum *__usercall vostok::render::culling::create_frustum_from_four_points@<eax>(
        const vostok::math::float3 *view_pos@<ecx>,
        vostok::math::float3 (*points)[4]@<eax>,
        vostok::math::frustum *far_plane,
        int a4)
{
  int v6; // ecx
  vostok::math::frustum *result; // eax
  vostok::math::frustum v8; // [esp+10h] [ebp-F8h] BYREF
  vostok::math::plane v9[6]; // [esp+88h] [ebp-80h] BYREF
  int v10; // [esp+E8h] [ebp-20h]
  int v11; // [esp+ECh] [ebp-1Ch]
  int v12; // [esp+F0h] [ebp-18h]
  const vostok::math::float3 *v13; // [esp+F4h] [ebp-14h]
  vostok::math::plane v14; // [esp+F8h] [ebp-10h] BYREF

  vostok::math::create_plane((const vostok::math::float3 *)points, &(*points)[2], &v14, &(*points)[1].x);
  if ( (float)((float)((float)((float)(view_pos->y * v14.normal.y) + (float)(view_pos->z * v14.normal.z))
                     + (float)(view_pos->x * v14.normal.x))
             + v14.d) <= 0.0 )
  {
    vostok::math::create_plane(view_pos, &(*points)[1], v9, (float *)points);
    vostok::math::create_plane(view_pos, &(*points)[3], &v9[1], &(*points)[2].x);
    vostok::math::create_plane(view_pos, &(*points)[2], &v9[2], &(*points)[1].x);
    vostok::math::create_plane(view_pos, (const vostok::math::float3 *)points, &v9[3], &(*points)[3].x);
    *(_QWORD *)&v9[4].normal.x = *(_QWORD *)a4;
    *(_QWORD *)&v9[4].vector.elements[2] = *(_QWORD *)(a4 + 8);
    v9[5] = v14;
  }
  else
  {
    vostok::math::create_plane(view_pos, (const vostok::math::float3 *)points, v9, &(*points)[1].x);
    v13 = &(*points)[3];
    vostok::math::create_plane(view_pos, &(*points)[2], &v9[1], &(*points)[3].x);
    vostok::math::create_plane(view_pos, &(*points)[1], &v9[2], &(*points)[2].x);
    vostok::math::create_plane(view_pos, v13, &v9[3], (float *)points);
    *(_QWORD *)&v9[4].normal.x = *(_QWORD *)a4;
    v9[4].normal.z = *(float *)(a4 + 8);
    v10 = LODWORD(v14.normal.x) ^ _mask__NegFloat_;
    v11 = LODWORD(v14.normal.y) ^ _mask__NegFloat_;
    v9[4].d = *(float *)(a4 + 12);
    v12 = LODWORD(v14.normal.z) ^ _mask__NegFloat_;
    LODWORD(v9[5].normal.x) = LODWORD(v14.normal.x) ^ _mask__NegFloat_;
    LODWORD(v9[5].normal.y) = LODWORD(v14.normal.y) ^ _mask__NegFloat_;
    LODWORD(v9[5].normal.z) = LODWORD(v14.normal.z) ^ _mask__NegFloat_;
    LODWORD(v9[5].d) = LODWORD(v14.d) ^ _mask__NegFloat_;
  }
  vostok::math::frustum::frustum(v6, (const vostok::math::plane (*)[6])v9, &v8);
  result = far_plane;
  qmemcpy(far_plane, &v8, sizeof(vostok::math::frustum));
  return result;
}
