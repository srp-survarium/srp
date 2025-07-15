survarium::inventory_item *__thiscall survarium::weapon_ammunition::`scalar deleting destructor'(
        survarium::inventory_item *this,
        char a2)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_action_behaviuor);
  survarium::interactive_object::~interactive_object(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
