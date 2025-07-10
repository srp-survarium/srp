survarium::victory_items_container *__thiscall survarium::victory_items_container::`vector deleting destructor'(
        survarium::victory_items_container *this,
        char a2)
{
  void **M_start; // eax

  M_start = this->m_victory_items._M_impl._M_start;
  if ( M_start )
    this->m_victory_items._M_impl._M_end_of_storage.m_allocator->call_free(
      this->m_victory_items._M_impl._M_end_of_storage.m_allocator,
      M_start);
  survarium::usable_object::~usable_object(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
