vostok::ai::behaviour_cook *__thiscall vostok::ai::behaviour_cook::`vector deleting destructor'(
        vostok::ai::behaviour_cook *this,
        char a2)
{
  vostok::resources::unmanaged_cook *v2; // ecx

  vostok::resources::resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>::~resource_ptr<survarium::booby_trap_core,vostok::resources::unmanaged_intrusive_base>((vostok::resources::resource_ptr<survarium::inventory,vostok::resources::unmanaged_intrusive_base> *)&this->m_loaded_binary_config);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_ai_world);
  vostok::resources::unmanaged_cook::~unmanaged_cook(v2, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
