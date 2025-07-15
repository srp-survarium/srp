void __thiscall survarium::game_camera::set_position_direction(
        const vostok::math::float3 *d,
        survarium::game_camera *this,
        const vostok::math::float3 *p)
{
  vostok::math::float4x4 v3; // [esp+0h] [ebp-4Ch] BYREF
  vostok::math::float3 v4; // [esp+40h] [ebp-Ch] BYREF

  v4.x = 0.0;
  *(_QWORD *)&v4.elements[1] = LODWORD(s_bm_current_air_resistance);
  qmemcpy(&this->m_view_matrix, vostok::math::create_camera_direction(d, &v4, &v3, &p->x), sizeof(this->m_view_matrix));
  qmemcpy(
    &this->m_inverted_view_matrix,
    vostok::math::invert4x3(&this->m_view_matrix, &v3),
    sizeof(this->m_inverted_view_matrix));
}
