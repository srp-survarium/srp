void __thiscall survarium::victory_item_core::take(survarium::victory_item_core *this)
{
  survarium::usable_object::remove(this);
  this->m_is_inserted = 0;
}
