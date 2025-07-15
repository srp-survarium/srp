void __thiscall survarium::victory_item_core::activate(survarium::victory_item_core *this, const bool real_insert)
{
  this->m_portable_interactive_object->activate(this->m_portable_interactive_object, &this->m_skeleton);
}
