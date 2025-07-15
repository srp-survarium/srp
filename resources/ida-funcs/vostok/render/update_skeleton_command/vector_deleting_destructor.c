vostok::render::update_skeleton_command *__thiscall vostok::render::update_skeleton_command::`vector deleting destructor'(
        vostok::render::update_skeleton_command *this,
        char a2)
{
  vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_model_instance);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
