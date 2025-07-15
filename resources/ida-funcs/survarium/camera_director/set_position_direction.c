void __thiscall survarium::camera_director::set_position_direction(
        const vostok::math::float3 *d,
        survarium::camera_director *this,
        const vostok::math::float3 *p)
{
  vostok::math::float4x4 *v3; // eax
  vostok::math::float4x4 v4; // [esp+4h] [ebp-8Ch] BYREF
  vostok::math::float4x4 v5; // [esp+44h] [ebp-4Ch] BYREF
  vostok::math::float3 v6; // [esp+84h] [ebp-Ch] BYREF

  v6.x = 0.0;
  *(_QWORD *)&v6.elements[1] = LODWORD(s_bm_current_air_resistance);
  v3 = vostok::math::create_camera_direction(d, &v6, &v5, &p->x);
  qmemcpy(&this->m_inverted_view, vostok::math::invert4x3(v3, &v4), sizeof(this->m_inverted_view));
}
