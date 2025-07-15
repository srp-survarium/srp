int __thiscall survarium::victory_item_core::player_stance(survarium::victory_item_core *this)
{
  return survarium::portable_interactive_object_core::player_stance(
           (survarium::portable_interactive_object_core *)this,
           (int)this->m_portable_interactive_object);
}
