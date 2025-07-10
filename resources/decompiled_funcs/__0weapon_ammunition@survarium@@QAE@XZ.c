void __thiscall survarium::weapon_ammunition::weapon_ammunition(survarium::weapon_ammunition *this)
{
  survarium::inventory_item::inventory_item(this, disabled);
  this->__vftable = (survarium::weapon_ammunition_vtbl *)&survarium::weapon_ammunition::`vftable';
  this->m_source = 0;
}
