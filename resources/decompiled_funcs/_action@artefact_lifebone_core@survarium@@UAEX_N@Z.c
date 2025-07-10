void __thiscall survarium::artefact_lifebone_core::action(survarium::artefact_lifebone_core *this, bool key_down)
{
  unsigned __int16 v2; // ax

  if ( key_down )
  {
    if ( this->m_unlimited || survarium::inventory_item::amount(this, (int)this) )
    {
      survarium::artefact_lifebone_core::activate_impl(this);
      if ( !this->m_unlimited )
      {
        v2 = survarium::inventory_item::amount(this, (int)this);
        survarium::inventory_item::set_amount((survarium::inventory_item *)(v2 - 1), (int)this);
      }
    }
    if ( !this->m_unlimited
      && !survarium::inventory_item::amount((survarium::inventory_item *)this->m_unlimited, (int)this) )
    {
      survarium::artefact_lifebone_core::switch_passive_mode_impl(this, 0);
    }
  }
}
