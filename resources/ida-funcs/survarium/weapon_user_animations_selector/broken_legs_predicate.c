bool __thiscall survarium::weapon_user_animations_selector::broken_legs_predicate(
        survarium::weapon_user_animations_selector *this)
{
  return this->m_user->damage_model(&this->m_user->survarium::inventory_holder)->m_object->m_broken_legs_count == 2;
}
