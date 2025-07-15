survarium::player_logic_dead_state *__thiscall survarium::player_logic_dead_state::`vector deleting destructor'(
        survarium::player_logic_dead_state *this,
        char a2)
{
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *p_m_animation; // esi

  p_m_animation = &this->m_animation;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_animation.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&p_m_animation->first);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
