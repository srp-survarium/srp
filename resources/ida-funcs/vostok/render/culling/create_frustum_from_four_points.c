vostok::math::frustum *__cdecl vostok::render::culling::create_frustum_from_four_points(
        vostok::math::frustum *result,
        const vostok::math::float3 *view_pos,
        const vostok::math::float3 (*points)[4],
        const vostok::math::plane *far_plane)
{
  vostok::math::frustum *v4; // eax
  vostok::math::plane v5; // [esp+10h] [ebp-F8h] BYREF
  vostok::math::float3 *second; // [esp+20h] [ebp-E8h]
  _BYTE v7[12]; // [esp+24h] [ebp-E4h]
  vostok::math::plane frustrum_planes[6]; // [esp+30h] [ebp-D8h] BYREF
  vostok::math::frustum resulta; // [esp+90h] [ebp-78h] BYREF

  vostok::math::create_plane((const vostok::math::float3 *)points, &(*points)[1], &(*points)[2], (int)&v5);
  if ( (float)((float)((float)((float)(view_pos->y * v5.normal.y) + (float)(view_pos->z * v5.normal.z))
                     + (float)(view_pos->x * v5.normal.x))
             + v5.d) <= 0.0 )
  {
    vostok::math::create_plane(view_pos, (const vostok::math::float3 *)points, &(*points)[1], (int)frustrum_planes);
    second = (vostok::math::float3 *)&(*points)[3];
    vostok::math::create_plane(view_pos, &(*points)[2], &(*points)[3], (int)&frustrum_planes[1]);
    vostok::math::create_plane(view_pos, &(*points)[1], &(*points)[2], (int)&frustrum_planes[2]);
    vostok::math::create_plane(view_pos, second, (const vostok::math::float3 *)points, (int)&frustrum_planes[3]);
    frustrum_planes[4] = *far_plane;
    frustrum_planes[5] = v5;
  }
  else
  {
    vostok::math::create_plane(view_pos, &(*points)[1], (const vostok::math::float3 *)points, (int)frustrum_planes);
    vostok::math::create_plane(view_pos, &(*points)[3], &(*points)[2], (int)&frustrum_planes[1]);
    vostok::math::create_plane(view_pos, &(*points)[2], &(*points)[1], (int)&frustrum_planes[2]);
    vostok::math::create_plane(view_pos, (const vostok::math::float3 *)points, &(*points)[3], (int)&frustrum_planes[3]);
    frustrum_planes[4] = *far_plane;
    *(float *)v7 = -v5.normal.x;
    *(_QWORD *)&v7[4] = *(_QWORD *)&v5.vector.elements[1] ^ 0x8000000080000000uLL;
    *(_QWORD *)&frustrum_planes[5].normal.x = *(_QWORD *)v7;
    LODWORD(frustrum_planes[5].normal.z) = LODWORD(v5.normal.z) ^ 0x80000000;
    frustrum_planes[5].d = -v5.d;
  }
  vostok::math::cuboid::cuboid(&resulta, (const vostok::math::plane (*)[6])frustrum_planes);
  v4 = result;
  qmemcpy(result, &resulta, sizeof(vostok::math::frustum));
  return v4;
}
