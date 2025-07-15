void __thiscall survarium::jump_logic_base_state::~jump_logic_base_state(survarium::jump_logic_base_state *this)
{
  stlp_std::pair<vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> > *p_m_animation; // esi

  p_m_animation = &this->m_animation;
  this->__vftable = (survarium::jump_logic_base_state_vtbl *)&survarium::jump_logic_base_state::`vftable';
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&this->m_animation.second);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::dec(&p_m_animation->first);
}
