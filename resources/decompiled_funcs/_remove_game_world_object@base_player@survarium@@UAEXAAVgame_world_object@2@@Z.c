void __thiscall survarium::base_player::remove_game_world_object(
        survarium::base_player *this,
        survarium::game_world_object *object)
{
  if ( object )
    _InterlockedExchangeAdd(&object->m_reference_count, 1u);
  vostok::intrusive_list<survarium::game_world_object,vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base>,264,vostok::threading::single_threading_policy,vostok::no_size_policy,vostok::no_debug_policy>::erase(
    &this->m_game_world_objects,
    (vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base>)&this->m_game_world_objects);
}
