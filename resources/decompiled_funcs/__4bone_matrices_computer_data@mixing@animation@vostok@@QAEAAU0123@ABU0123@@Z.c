vostok::animation::mixing::bone_matrices_computer_data *__usercall vostok::animation::mixing::bone_matrices_computer_data::operator=@<eax>(
        vostok::animation::mixing::bone_matrices_computer_data *this@<edi>,
        const vostok::animation::mixing::bone_matrices_computer_data *__that@<eax>,
        vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > *a3@<ecx>)
{
  *(_QWORD *)&this->previous_object_movement.rotation.x = *(_QWORD *)&__that->previous_object_movement.rotation.x;
  *(_QWORD *)&this->previous_object_movement.rotation.vector.elements[2] = *(_QWORD *)&__that->previous_object_movement.rotation.vector.elements[2];
  *(_QWORD *)&this->previous_object_movement.translation.x = *(_QWORD *)&__that->previous_object_movement.translation.x;
  *(_QWORD *)&this->previous_object_movement.translation.elements[2] = *(_QWORD *)&__that->previous_object_movement.translation.elements[2];
  *(_QWORD *)&this->previous_object_movement.scale.elements[1] = *(_QWORD *)&__that->previous_object_movement.scale.elements[1];
  this->accumulated_object_movement = __that->accumulated_object_movement;
  vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const>::operator=(
    a3,
    (const vostok::resources::pinned_ptr_base<vostok::animation::cubic_spline_skeleton_animation const > **)&this->pinned_animation,
    &__that->pinned_animation);
  return this;
}
