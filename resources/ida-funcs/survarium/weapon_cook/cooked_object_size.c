int __thiscall survarium::weapon_cook::cooked_object_size(
        survarium::weapon_cook *this,
        survarium::weapon_core *object_to_cook)
{
  return 4 * LODWORD(object_to_cook[1].m_transform.i.z) + 9472;
}
