void __thiscall survarium::weapon_core::set_magazine_capacity(
        survarium::weapon_core *this,
        unsigned __int16 magazine_capacity)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  this->m_magazine_capacity = magazine_capacity;
}
