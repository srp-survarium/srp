survarium::fwd_animation_interval_end_time_calculator *__thiscall survarium::fwd_animation_interval_end_time_calculator::`scalar deleting destructor'(
        survarium::fwd_animation_interval_end_time_calculator *this,
        char a2)
{
  `vector destructor iterator'(
    (char *)this->m_animations,
    4u,
    30,
    (void (__thiscall *)(void *))vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>::~resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>);
  this->__vftable = (survarium::fwd_animation_interval_end_time_calculator_vtbl *)&vostok::animation::animation_states_dumper::`vftable';
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
