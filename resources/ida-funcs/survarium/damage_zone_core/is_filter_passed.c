BOOL __thiscall survarium::damage_zone_core::is_filter_passed(
        survarium::damage_zone_core *this,
        vostok::physics::base_physics_object *object)
{
  return (((int (__thiscall *)(vostok::physics::base_physics_object *, survarium::damage_zone_core *))object->get_collision_group)(
            object,
            this)
        & 0x40) != 0;
}
