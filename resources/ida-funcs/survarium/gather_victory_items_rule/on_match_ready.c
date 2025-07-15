void __thiscall survarium::gather_victory_items_rule::on_match_ready(
        survarium::gather_victory_items_rule *this,
        const unsigned int __formal)
{
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_finish; // ebp
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_start; // edi
  int v5; // ebx
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v6; // edi
  vostok::resources::resource_ptr<survarium::victory_items_container_core,vostok::resources::unmanaged_intrusive_base> *v7; // ebx

  M_finish = this->m_victory_items._M_impl._M_finish;
  M_start = this->m_victory_items._M_impl._M_start;
  if ( M_start != M_finish )
  {
    v5 = 0;
    do
    {
      ((void (__stdcall *)(void *, _DWORD))M_start->m_object->insert)(
        this->m_selected_spawners._M_impl._M_start[v5],
        *((float *)this->m_selected_spawners._M_impl._M_start[v5] + 4));
      ++M_start;
      ++v5;
    }
    while ( M_start != M_finish );
  }
  v6 = this->m_containers._M_impl._M_start;
  v7 = this->m_containers._M_impl._M_finish;
  while ( v6 != v7 )
  {
    survarium::usable_object::insert((survarium::usable_object *)this, v6->m_object, v6->m_object->m_physics_world);
    ++v6;
  }
}
