void __thiscall survarium::booby_trap_core::hit(
        survarium::booby_trap_core *this,
        survarium::game_camera *initiator,
        unsigned int bone_index,
        const char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet)
{
  _BYTE *v7; // eax

  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v7 )
    survarium::weapon_user_dead_state::finalize(initiator);
  (*(void (__thiscall **)(vostok::vfs::base_node<1> **))&this[-1].m_fat_it.m_link_target->m_name[5])(&this[-1].m_fat_it.m_link_target);
}
