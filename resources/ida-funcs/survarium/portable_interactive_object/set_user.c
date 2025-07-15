void __thiscall survarium::portable_interactive_object::set_user(
        survarium::portable_interactive_object *this,
        survarium::base_player *user)
{
  const vostok::animation::skeleton *v3; // eax
  vostok::animation::skeleton *v4; // ecx
  survarium::player *m_user; // edi
  int v6; // eax
  vostok::animation::skeleton *v7; // ecx
  vostok::animation::skeleton *v8; // ecx
  int v9; // eax
  int v10; // edi
  int bone_index; // ecx
  int v12; // eax

  survarium::portable_interactive_object_core::set_user(this, user);
  v3 = *(const vostok::animation::skeleton **)((char *)&dword_10E28 + (unsigned int)this->m_user);
  this->m_hand_ik_solver.m_user_skeleton = v3;
  this->m_hand_ik_solver.m_weapon_bone_index = vostok::animation::skeleton::get_bone_index(v4, (int)v3, "Weapon");
  m_user = (survarium::player *)this->m_user;
  this->m_player_equipment_sound_effect.m_player = m_user;
  v6 = *(int *)((char *)&dword_10E28 + (_DWORD)m_user);
  v8 = (vostok::animation::skeleton *)(vostok::animation::skeleton::get_bone_index(v7, v6, "LeftFoot")
                                     - (*(_DWORD *)(v6 + 280) - (v6 + 272)) / 28);
  this->m_player_equipment_sound_effect.m_left_toe_bone_index = (unsigned int)v8;
  v9 = *(int *)((char *)&dword_10E28 + (_DWORD)m_user);
  v10 = v9 + 272;
  bone_index = vostok::animation::skeleton::get_bone_index(v8, v9, "RightFoot");
  v12 = *(_DWORD *)(v10 + 8) - v10;
  this->m_player_equipment_sound_effect.m_toe_transforms_are_actual = 0;
  this->m_player_equipment_sound_effect.m_right_toe_bone_index = bone_index - v12 / 28;
}
