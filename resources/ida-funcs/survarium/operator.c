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


BOOL __usercall survarium::operator==@<eax>(
        const survarium::simple_animation_controller_parameters *first@<eax>,
        const survarium::simple_animation_controller_parameters *second@<edx>)
{
  return first->emitter.m_object == second->emitter.m_object;
}


BOOL __fastcall survarium::operator!=(
        const survarium::animation_space_vertex_id *right,
        const survarium::animation_space_vertex_id *left)
{
  return left->rotation.x != right->rotation.x
      || left->rotation.y != right->rotation.y
      || left->rotation.z != right->rotation.z
      || left->rotation.w != right->rotation.w
      || !vostok::math::float3_pod::is_similar(&left->translation, &right->translation, 0.30000001);
}


bool __fastcall survarium::operator!=(
        const survarium::movement_animation_controller_parameters *second,
        const survarium::movement_animation_controller_parameters *first)
{
  return !survarium::operator==(second, first);
}


BOOL __usercall survarium::operator!=@<eax>(
        const survarium::simple_animation_controller_parameters *first@<eax>,
        const survarium::simple_animation_controller_parameters *second@<edx>)
{
  return first->emitter.m_object != second->emitter.m_object;
}
