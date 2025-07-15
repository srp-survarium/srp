void __thiscall survarium::single_position_animation_controller::set_target(
        survarium::single_position_animation_controller *this,
        const survarium::movement_animation_controller_parameters *target)
{
  survarium::movement_animation_controller_parameters::operator=(&this->m_target_parameters, target);
}
