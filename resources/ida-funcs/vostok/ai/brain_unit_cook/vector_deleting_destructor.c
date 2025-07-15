vostok::ai::brain_unit_cook *__thiscall vostok::ai::brain_unit_cook::`vector deleting destructor'(
        vostok::ai::brain_unit_cook *this,
        char a2)
{
  vostok::resources::unmanaged_cook *v2; // ecx

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_ai_world);
  vostok::resources::unmanaged_cook::~unmanaged_cook(v2, this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
