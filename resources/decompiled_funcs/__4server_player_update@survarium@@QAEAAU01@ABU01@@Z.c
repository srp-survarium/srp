survarium::server_player_update *__userpurge survarium::server_player_update::operator=@<eax>(
        const survarium::server_player_update *__that@<eax>,
        survarium::server_player_update *this)
{
  this->input.angular_velocity = __that->input.angular_velocity;
  this->input.angular_acceleration = __that->input.angular_acceleration;
  this->input.actions_mask = __that->input.actions_mask;
  qmemcpy(&this->state, &__that->state, sizeof(this->state));
  survarium::weapon_state::operator=(&this->weapon_state, &__that->weapon_state);
  return this;
}
