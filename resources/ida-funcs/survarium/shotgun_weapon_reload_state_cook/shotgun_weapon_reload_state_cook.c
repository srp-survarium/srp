void __thiscall survarium::shotgun_weapon_reload_state_cook::shotgun_weapon_reload_state_cook(
        survarium::shotgun_weapon_reload_state_cook *this)
{
  LODWORD(_S3_4.m_inverted_view_matrix.j.x) = &vostok::resources::cook_base::`vftable';
  *(_QWORD *)&_S3_4.m_inverted_view_matrix.lines[1].elements[1] = 0x13600000000LL;
  _S3_4.m_inverted_view_matrix.j.w = 0.0;
  LODWORD(_S3_4.m_inverted_view_matrix.k.x) = GetCurrentThreadId();
  *(_QWORD *)&_S3_4.m_inverted_view_matrix.lines[2].elements[1] = GetCurrentThreadId();
  _S3_4.m_inverted_view_matrix.k.w = 0.0;
  LODWORD(_S3_4.m_inverted_view_matrix.j.x) = &survarium::shotgun_weapon_reload_state_cook::`vftable';
  vostok::resources::resources_manager::register_cook((vostok::resources::cook_base *)&_S3_4.m_inverted_view_matrix.lines[1]);
}
