void __thiscall survarium::medkit::~medkit(survarium::medkit *this)
{
  vostok::memory::doug_lea_allocator *v1; // eax
  vostok::memory::doug_lea_allocator *v2; // eax
  vostok::memory::doug_lea_allocator *v3; // eax
  char **p_m_damage_protect; // [esp+4h] [ebp-24h]
  char **p_m_affects; // [esp+10h] [ebp-18h]
  char **p_m_influences; // [esp+1Ch] [ebp-Ch]

  this->__vftable = (survarium::medkit_vtbl *)&survarium::medkit::`vftable';
  p_m_influences = (char **)&this->m_influences;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_influences);
  if ( *p_m_influences )
  {
    vostok::memory::doug_lea_allocator::free_impl(v1, *p_m_influences);
    *p_m_influences = 0;
  }
  p_m_affects = (char **)&this->m_affects;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_affects);
  if ( this->m_affects )
  {
    vostok::memory::doug_lea_allocator::free_impl(v2, *p_m_affects);
    *p_m_affects = 0;
  }
  p_m_damage_protect = (char **)&this->m_damage_protect;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_damage_protect);
  if ( this->m_damage_protect )
  {
    vostok::memory::doug_lea_allocator::free_impl(v3, *p_m_damage_protect);
    *p_m_damage_protect = 0;
  }
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)&this->m_action_behaviuor);
  survarium::interactive_object::~interactive_object(this);
}
