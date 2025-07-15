void __thiscall survarium::ladder::deactivate(survarium::ladder *this)
{
  survarium::usable_object::remove((survarium::usable_object *)this, &this->survarium::usable_object);
}
