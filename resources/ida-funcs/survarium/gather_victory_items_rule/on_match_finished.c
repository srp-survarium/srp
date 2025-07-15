void __thiscall survarium::gather_victory_items_rule::on_match_finished(survarium::gather_victory_items_rule *this)
{
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_finish; // ebx
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *i; // edi
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *M_start; // ebx
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v5; // esi

  M_finish = this->m_victory_items._M_impl._M_finish;
  for ( i = this->m_victory_items._M_impl._M_start; i != M_finish; ++i )
    i->m_object->remove(i->m_object);
  M_start = this->m_containers._M_impl._M_start;
  v5 = this->m_containers._M_impl._M_finish;
  while ( M_start != v5 )
  {
    survarium::usable_object::remove((survarium::usable_object *)this, M_start->m_object);
    ++M_start;
  }
}
