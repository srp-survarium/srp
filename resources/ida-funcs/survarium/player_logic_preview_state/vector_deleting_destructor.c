survarium::player_logic_preview_state *__thiscall survarium::player_logic_preview_state::`vector deleting destructor'(
        survarium::player_logic_preview_state *this,
        char a2)
{
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_animation_to_wait);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
