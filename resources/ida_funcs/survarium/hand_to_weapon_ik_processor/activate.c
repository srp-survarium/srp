void __thiscall survarium::hand_to_weapon_ik_processor::activate(
        survarium::hand_to_weapon_ik_processor *this,
        const vostok::animation::skeleton *user_skeleton,
        const vostok::animation::skeleton *weapon_skeleton)
{
  unsigned int bone_index; // esi
  vostok::animation::skeleton *v4; // ecx
  vostok::animation::skeleton *v5; // ecx
  unsigned int v6; // esi
  vostok::animation::skeleton *v7; // ecx
  const char *v8; // [esp+0h] [ebp-48h]
  const char *v9; // [esp+0h] [ebp-48h]
  const char *v10; // [esp+0h] [ebp-48h]
  const char *v11; // [esp+0h] [ebp-48h]
  const char *v12; // [esp+0h] [ebp-48h]

  this->m_skeleton = user_skeleton;
  this->m_weapon_bone_index = vostok::animation::skeleton::get_bone_index(
                                (vostok::animation::skeleton *)&stru_971D84.m_data.m_size,
                                v8);
  this->m_hands[0].is_active = 0;
  this->m_hands[0].hand_bone_index = vostok::animation::skeleton::get_bone_index(
                                       (vostok::animation::skeleton *)(&stru_973958.m_memory_type_data + 1),
                                       v9);
  this->m_hands[0].hand_matrix_index = this->m_hands[0].hand_bone_index
                                     - vostok::animation::skeleton::get_root_bones_count(
                                         (vostok::animation::skeleton *)this,
                                         (int)user_skeleton);
  bone_index = vostok::animation::skeleton::get_bone_index((vostok::animation::skeleton *)&stru_977EF0, v10);
  this->m_hands[0].locator_matrix_index = bone_index
                                        - vostok::animation::skeleton::get_root_bones_count(v4, (int)weapon_skeleton);
  this->m_hands[1].is_active = 0;
  this->m_hands[1].hand_bone_index = vostok::animation::skeleton::get_bone_index(
                                       (vostok::animation::skeleton *)&stru_973958,
                                       v11);
  this->m_hands[1].hand_matrix_index = this->m_hands[1].hand_bone_index
                                     - vostok::animation::skeleton::get_root_bones_count(v5, (int)user_skeleton);
  v6 = vostok::animation::skeleton::get_bone_index(
         (vostok::animation::skeleton *)&stru_977EF0.vostok::resources::resource_reconstruction_info,
         v12);
  this->m_hands[1].locator_matrix_index = v6
                                        - vostok::animation::skeleton::get_root_bones_count(v7, (int)weapon_skeleton);
}
