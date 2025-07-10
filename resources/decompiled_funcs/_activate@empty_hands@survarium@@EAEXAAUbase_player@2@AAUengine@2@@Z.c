void __thiscall survarium::empty_hands::activate(
        survarium::empty_hands *this,
        survarium::base_player *user,
        survarium::engine *engine)
{
  this->m_user = user;
  qmemcpy((void *)&this->m_transform, user->get_transform(&user->survarium::collision_user), sizeof(this->m_transform));
}
