void __thiscall survarium::game_camera::on_activate(survarium::game_camera *this, survarium::camera_director *cd)
{
  vostok::math::float4x4 *v2; // eax
  int v3; // edx
  vostok::math::float4x4 v4; // [esp+8h] [ebp-40h] BYREF

  qmemcpy(&this->m_inverted_view_matrix, &cd->m_inverted_view, sizeof(this->m_inverted_view_matrix));
  v2 = vostok::math::invert4x3(&this->m_inverted_view_matrix, &v4);
  qmemcpy((void *)(v3 + 4), v2, 0x40u);
}
