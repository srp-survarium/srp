bool __fastcall survarium::operator!=(
        const survarium::movement_animation_controller_parameters *second,
        const survarium::movement_animation_controller_parameters *first)
{
  return !survarium::operator==(second, first);
}
