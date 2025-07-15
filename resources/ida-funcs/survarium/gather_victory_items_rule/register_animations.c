void __thiscall survarium::gather_victory_items_rule::register_animations(
        survarium::gather_victory_items_rule *this,
        survarium::animations_registry *animations_registry)
{
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_start; // esi
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_finish; // edi

  M_start = this->m_victory_items._M_impl._M_start;
  M_finish = this->m_victory_items._M_impl._M_finish;
  while ( M_start != M_finish )
  {
    M_start->m_object->register_animations(&M_start->m_object->survarium::interactive_object, animations_registry);
    ++M_start;
  }
}
