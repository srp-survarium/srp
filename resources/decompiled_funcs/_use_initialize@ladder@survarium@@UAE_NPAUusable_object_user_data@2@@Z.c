char __thiscall survarium::ladder::use_initialize(survarium::ladder *this, survarium::usable_object_user_data *user)
{
  user->owner->use_ladder(user->owner, (survarium::ladder *)&this[-1].m_parent_resources.gapC);
  return 1;
}
