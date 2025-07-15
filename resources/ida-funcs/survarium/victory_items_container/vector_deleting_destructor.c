survarium::victory_items_container *__thiscall survarium::victory_items_container::`vector deleting destructor'(
        survarium::victory_items_container *this,
        char a2)
{
  vostok::fixed_vector<survarium::victory_items_container::victory_item_transform,10> *p_m_victory_item_transforms; // eax
  survarium::victory_items_container_core *m_begin; // ecx

  p_m_victory_item_transforms = &this->m_victory_item_transforms;
  m_begin = (survarium::victory_items_container_core *)this->m_victory_item_transforms.m_begin;
  p_m_victory_item_transforms->m_end = (survarium::victory_items_container::victory_item_transform *)m_begin;
  survarium::victory_items_container_core::~victory_items_container_core(m_begin, (int)this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::victory_items_container *__thiscall survarium::victory_items_container::`vector deleting destructor'(
        char *this,
        char a2)
{
  return survarium::victory_items_container::`vector deleting destructor'(
           (survarium::victory_items_container *)(this - 72),
           a2);
}
