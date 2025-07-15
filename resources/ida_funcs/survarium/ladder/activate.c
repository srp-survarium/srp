void __thiscall survarium::ladder::activate(survarium::ladder *this, vostok::physics::world *world)
{
  survarium::usable_object::insert(&this->survarium::usable_object, world);
}
