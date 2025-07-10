void __thiscall survarium::ladder::deactivate(survarium::ladder *this)
{
  survarium::usable_object::remove(&this->survarium::usable_object);
}
