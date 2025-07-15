vostok::math::float4x4 *__userpurge vostok::physics::bt_animated_rigid_body::get_surface_point_transform@<eax>(
        vostok::physics::bt_animated_rigid_body *this@<ecx>,
        const unsigned int surface_id@<eax>,
        vostok::math::float4x4 *a3)
{
  long double v3; // rdi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  vostok::math::float4x4 *v7; // esi
  float v8; // xmm0_4
  vostok::math::float4x4 *v9; // eax
  vostok::math::float4x4 *v11; // [esp-4h] [ebp-168h]
  char v12; // [esp+10h] [ebp-154h] BYREF
  char v13; // [esp+50h] [ebp-114h] BYREF
  char v14; // [esp+90h] [ebp-D4h] BYREF
  char v15; // [esp+D0h] [ebp-94h] BYREF
  vostok::math::float4x4 right; // [esp+110h] [ebp-54h] BYREF
  vostok::math::float3 v17; // [esp+154h] [ebp-10h] BYREF

  HIDWORD(v3) = this->m_shape->m_children.m_data[surface_id].m_childShape[2].__vftable;
  LODWORD(v3) = *(_DWORD *)(HIDWORD(v3) + 64);
  vostok::physics::from_bullet(v3, (int)&right);
  v4 = *(_DWORD *)(LODWORD(v3) + 4);
  if ( !v4 )
  {
    v7 = (vostok::math::float4x4 *)&v12;
    goto LABEL_10;
  }
  v5 = v4 - 8;
  if ( !v5 )
  {
    v8 = *(float *)(LODWORD(v3) + 32) * *(float *)(LODWORD(v3) + 16);
    v17.x = v8;
    v17.y = v8;
    v7 = (vostok::math::float4x4 *)&v14;
LABEL_11:
    v17.z = v8;
    v9 = vostok::math::create_scale(&v17, v7);
    vostok::math::mul4x3(&right, v9, a3);
    return a3;
  }
  v6 = v5 - 2;
  if ( !v6 )
  {
    v7 = (vostok::math::float4x4 *)&v13;
    goto LABEL_10;
  }
  if ( v6 == 3 )
  {
    v7 = (vostok::math::float4x4 *)&v15;
LABEL_10:
    *(_QWORD *)&v17.x = *(_QWORD *)(LODWORD(v3) + 32);
    v8 = *(float *)(LODWORD(v3) + 40);
    goto LABEL_11;
  }
  qmemcpy(a3, vostok::math::float4x4::identity(v11, &right), sizeof(vostok::math::float4x4));
  return a3;
}
