void __thiscall survarium::ladder::activate(survarium::ladder *this, vostok::physics::world *world)
{
  survarium::usable_object::insert((survarium::usable_object *)this, &this->survarium::usable_object, world);
}
