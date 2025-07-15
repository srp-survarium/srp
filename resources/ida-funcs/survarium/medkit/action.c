void __thiscall survarium::medkit::action(survarium::medkit *this, bool key_down)
{
  survarium::inventory_item *v2; // ecx
  unsigned __int16 v3; // ax

  if ( key_down && !this->m_active )
  {
    if ( survarium::inventory_item::amount(this, (int)this) )
    {
      survarium::medkit::set_active(this, 1);
      v3 = survarium::inventory_item::amount(v2, (int)this);
      survarium::inventory_item::set_amount((survarium::inventory_item *)(v3 - 1), (int)this);
    }
  }
}
