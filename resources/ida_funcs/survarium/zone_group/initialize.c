void __thiscall survarium::zone_group::initialize(survarium::zone_group *this)
{
  this->charged_count = 0;
  survarium::zone_group::recharge(this);
}
