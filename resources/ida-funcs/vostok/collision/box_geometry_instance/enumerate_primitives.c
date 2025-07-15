void __thiscall vostok::collision::box_geometry_instance::enumerate_primitives(
        vostok::collision::box_geometry_instance *this,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::enumerate_primitives_callback_vtbl *v2; // edi
  vostok::math::float4x4 *v3; // eax
  vostok::math::float4x4 v4; // [esp+0h] [ebp-5Ch] BYREF
  _DWORD v5[7]; // [esp+40h] [ebp-1Ch] BYREF

  *(float *)&v5[4] = s_bm_current_air_resistance;
  *(float *)&v5[5] = s_bm_current_air_resistance;
  *(float *)&v5[6] = s_bm_current_air_resistance;
  v5[0] = 1;
  *(float *)&v5[1] = s_bm_current_air_resistance;
  *(float *)&v5[2] = s_bm_current_air_resistance;
  *(float *)&v5[3] = s_bm_current_air_resistance;
  v2 = cb->__vftable;
  v3 = vostok::math::float4x4::identity((vostok::math::float4x4 *)this, &v4);
  v2->enumerate(cb, v3, (const vostok::collision::primitive *)v5);
}


void __thiscall vostok::collision::box_geometry_instance::enumerate_primitives(
        vostok::collision::box_geometry_instance *this,
        const vostok::math::float4x4 *transform,
        vostok::collision::enumerate_primitives_callback *cb)
{
  vostok::collision::box_geometry_instance_vtbl *v3; // eax
  const vostok::math::float4x4 *v4; // eax
  vostok::math::float4x4 v5; // [esp+0h] [ebp-5Ch] BYREF
  _DWORD v6[7]; // [esp+40h] [ebp-1Ch] BYREF

  v3 = this->__vftable;
  *(float *)&v6[4] = s_bm_current_air_resistance;
  *(float *)&v6[5] = s_bm_current_air_resistance;
  *(float *)&v6[6] = s_bm_current_air_resistance;
  v6[0] = 1;
  *(float *)&v6[1] = s_bm_current_air_resistance;
  *(float *)&v6[2] = s_bm_current_air_resistance;
  *(float *)&v6[3] = s_bm_current_air_resistance;
  v4 = v3->get_matrix(&this->vostok::collision::geometry_instance);
  vostok::math::mul4x3(transform, v4, &v5);
  cb->enumerate(cb, &v5, (const vostok::collision::primitive *)v6);
}
