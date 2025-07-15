vostok::animation::callback_return_type_enum __thiscall survarium::weapon_core_shotgun_reload_one_round_substate::on_animation_end(
        survarium::weapon_core_shotgun_reload_one_round_substate *this,
        survarium::game_camera *params)
{
  BYTE2(params->m_inverted_view_matrix.lines[1].elements[0]) = 0;
  if ( params->__vftable == (survarium::game_camera_vtbl *)this->m_weapon )
  {
    survarium::weapon_user_dead_state::finalize(params);
    if ( vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::operator==(
           (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)LODWORD(params->m_inverted_view_matrix.i.x),
           &this->m_animation_to_wait_for) )
    {
      survarium::weapon_core::reload_one_round(this->m_weapon);
      BYTE2(params->m_inverted_view_matrix.lines[1].elements[0]) = 1;
    }
  }
  return 0;
}
