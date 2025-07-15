vostok::animation::mixing::bone_matrices_computer_data *__userpurge vostok::animation::mixing::bone_matrices_computer_data::operator=@<eax>(
        const vostok::animation::mixing::bone_matrices_computer_data *__that@<eax>,
        vostok::animation::mixing::bone_matrices_computer_data *this)
{
  qmemcpy(this, __that, 0x28u);
  qmemcpy(
    &this->accumulated_object_movement,
    &__that->accumulated_object_movement,
    sizeof(this->accumulated_object_movement));
  vostok::resources::pinned_ptr_const<vostok::animation::cubic_spline_skeleton_animation>::operator=(
    &this->pinned_animation,
    &__that->pinned_animation);
  return this;
}
