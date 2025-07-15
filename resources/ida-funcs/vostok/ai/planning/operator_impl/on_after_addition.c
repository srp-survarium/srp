void __thiscall vostok::ai::planning::operator_impl::on_after_addition(
        vostok::ai::planning::operator_impl *this,
        vostok::ai::planning::propositional_planner *object)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_object = object;
}
