survarium::victory_item *__thiscall survarium::victory_item::`vector deleting destructor'(
        survarium::victory_item *this,
        char a2)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_skeleton_model);
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_static_model);
  survarium::victory_item_core::~victory_item_core(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}


survarium::victory_item *__thiscall survarium::victory_item::`vector deleting destructor'(char *this, char a2)
{
  return survarium::victory_item::`vector deleting destructor'((survarium::victory_item *)(this - 20), a2);
}


survarium::victory_item *__thiscall survarium::victory_item::`vector deleting destructor'(char *this, char a2)
{
  return survarium::victory_item::`vector deleting destructor'((survarium::victory_item *)(this - 96), a2);
}
