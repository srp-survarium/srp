void __thiscall survarium::body_part_parameters::add_damage_protector(
        survarium::body_part_parameters *this,
        survarium::damage_protector *protector)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  vostok::intrusive_list<survarium::damage_protector,survarium::damage_protector *,72,vostok::threading::single_threading_policy,vostok::size_policy,vostok::no_debug_policy>::push_back(
    &this->m_damage_protectors,
    (survarium::game_camera *)protector,
    0);
}
