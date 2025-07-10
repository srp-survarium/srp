BOOL __thiscall survarium::weapon_core::target_predicate(
        survarium::weapon_core *this,
        survarium::weapon_targets target)
{
  return this->m_target == target;
}
