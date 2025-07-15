void __thiscall survarium::booby_trap_core::hit(
        survarium::booby_trap_core *this,
        const survarium::hit_initiator *const initiator,
        const vostok::collision::bone_collision_data *bone_data,
        const char *damage_type,
        float amount,
        float armor_piercing,
        survarium::bullet *const bullet)
{
  _BYTE *v7; // eax
  _BYTE v8[112]; // [esp-74h] [ebp-98h] BYREF
  const char *v9; // [esp-4h] [ebp-28h]
  double v10; // [esp+0h] [ebp-24h]
  double v11; // [esp+8h] [ebp-1Ch]
  survarium::bullet *v12; // [esp+10h] [ebp-14h]
  survarium::booby_trap_core *thisa; // [esp+1Ch] [ebp-8h]
  char v14; // [esp+23h] [ebp-1h]

  thisa = this;
  v14 = 0;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  if ( *v7 )
  {
    v12 = bullet;
    v11 = armor_piercing;
    v10 = amount;
    v9 = damage_type;
    qmemcpy(v8, bone_data, sizeof(v8));
    survarium::weapon_user_dead_state::finalize(0);
  }
  (*(void (__thiscall **)(vostok::vfs::base_node<1> **))&thisa[-1].m_fat_it.m_link_target->m_name[5])(&thisa[-1].m_fat_it.m_link_target);
}


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
