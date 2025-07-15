void __thiscall survarium::bullet::~bullet(survarium::bullet *this)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
}
