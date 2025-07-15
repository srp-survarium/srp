void __thiscall survarium::victory_item_core::put_to_container(
        survarium::victory_item_core *this,
        const bool real_remove)
{
  this->m_container->put_item(this->m_container, this);
}
