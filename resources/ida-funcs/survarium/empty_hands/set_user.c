void __thiscall survarium::empty_hands::set_user(survarium::empty_hands *this, survarium::base_player *user)
{
  this->m_user = user;
  qmemcpy(&this->m_transform, user->transform(&user->survarium::collision_user), sizeof(this->m_transform));
}
