BOOL __fastcall survarium::operator==(
        const survarium::movement_animation_controller_parameters *second,
        const survarium::movement_animation_controller_parameters *first)
{
  return first->position.x == second->position.x
      && first->position.y == second->position.y
      && first->position.z == second->position.z
      && first->eyes_direction.x == second->eyes_direction.x
      && first->eyes_direction.y == second->eyes_direction.y
      && first->eyes_direction.z == second->eyes_direction.z
      && first->velocity.x == second->velocity.x
      && first->velocity.y == second->velocity.y
      && first->velocity.z == second->velocity.z
      && first->animation.m_object == second->animation.m_object;
}
