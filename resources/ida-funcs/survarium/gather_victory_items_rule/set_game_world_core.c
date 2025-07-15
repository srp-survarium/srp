void __thiscall survarium::gather_victory_items_rule::set_game_world_core(
        survarium::gather_victory_items_rule *this,
        survarium::game_world_core *game_world_core)
{
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_start; // ebx
  vostok::resources::resource_ptr<survarium::victory_item_core,vostok::resources::unmanaged_intrusive_base> *M_finish; // ebp
  survarium::interactive_object *v4; // edi
  unsigned __int8 v5; // al

  M_start = this->m_victory_items._M_impl._M_start;
  M_finish = this->m_victory_items._M_impl._M_finish;
  for ( this->m_game_world_core = game_world_core; M_start != M_finish; v4->m_game_world_core = game_world_core )
  {
    v4 = &M_start->m_object->survarium::interactive_object;
    v5 = survarium::game_world_core::register_interactive_object(
           (survarium::game_world_core *)this,
           game_world_core,
           &M_start->m_object->survarium::interactive_object);
    ++M_start;
    v4->m_id = v5;
  }
}
