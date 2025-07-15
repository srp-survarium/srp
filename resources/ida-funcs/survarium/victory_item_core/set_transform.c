void __thiscall survarium::victory_item_core::set_transform(
        survarium::victory_item_core *this,
        const vostok::math::float3 *position,
        float orientation)
{
  float v3; // xmm0_4
  vostok::math::float4x4 *v5; // esi
  vostok::math::float4x4 *v6; // eax
  vostok::math::float4x4 *v7; // eax
  vostok::math::float3 v8; // [esp+4h] [ebp-158h] BYREF
  vostok::math::float3 v9; // [esp+10h] [ebp-14Ch] BYREF
  vostok::math::float4x4 v10; // [esp+1Ch] [ebp-140h] BYREF
  vostok::math::float4x4 v11; // [esp+5Ch] [ebp-100h] BYREF
  vostok::math::float4x4 v12; // [esp+9Ch] [ebp-C0h] BYREF
  _BYTE v13[64]; // [esp+DCh] [ebp-80h] BYREF
  vostok::math::float4x4 v14; // [esp+11Ch] [ebp-40h] BYREF

  v3 = s_bm_current_air_resistance;
  this->m_position = *position;
  v8.x = v3;
  v8.y = v3;
  v8.z = v3;
  this->m_orientation = orientation;
  v9.x = 0.0;
  *(_QWORD *)&v9.elements[1] = LODWORD(orientation);
  v5 = vostok::math::create_scale(&v8, &v12);
  v6 = vostok::math::create_rotation(&v9, (int)&v8, (int)v13);
  vostok::math::mul4x3(v5, v6, &v11);
  v7 = vostok::math::create_translation(&this->m_position, &v14);
  vostok::math::mul4x3(v7, &v11, &v10);
  (*(void (__thiscall **)(survarium::collision_geometry *, vostok::math::float4x4 *))(**(_DWORD **)this->m_collision_geometries
                                                                                    + 20))(
    *this->m_collision_geometries,
    &v10);
}
