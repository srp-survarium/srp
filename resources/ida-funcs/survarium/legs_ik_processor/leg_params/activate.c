void __thiscall survarium::legs_ik_processor::leg_params::activate(
        survarium::legs_ik_processor::leg_params *this,
        vostok::animation::skeleton *skeleton,
        vostok::animation::skeleton *foot_bone_name)
{
  unsigned int bone_index; // eax
  vostok::animation::skeleton *v4; // ecx
  vostok::animation::skeleton *v5; // ecx
  survarium::legs_ik_processor::leg_params *thisa; // [esp+0h] [ebp-68h]
  int v7; // [esp+Ch] [ebp-5Ch]
  vostok::animation::skeleton *v8; // [esp+10h] [ebp-58h]
  int v9; // [esp+24h] [ebp-44h]
  unsigned int type; // [esp+28h] [ebp-40h]
  vostok::animation::skeleton *v11; // [esp+2Ch] [ebp-3Ch]
  int v12; // [esp+38h] [ebp-30h]
  const vostok::animation::skeleton_bone *m_parent; // [esp+3Ch] [ebp-2Ch]
  vostok::socket_error_types_enum *v14; // [esp+40h] [ebp-28h]
  unsigned int v15; // [esp+4Ch] [ebp-1Ch]
  boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *v16; // [esp+58h] [ebp-10h]
  const vostok::animation::skeleton_bone *foot_bone; // [esp+64h] [ebp-4h]

  bone_index = vostok::animation::skeleton::get_bone_index(foot_bone_name, (const char *)this);
  foot_bone = vostok::animation::skeleton::get_bone(skeleton, bone_index);
  v16 = (boost::_bi::list4<enum vostok::connection_error_types_enum &,enum vostok::handshaking_error_types_enum &,enum vostok::socket_error_types_enum &,enum vostok::lobby_server_message_types_enum &> *)(foot_bone - vostok::animation::skeleton::get_root(v4, (int)skeleton));
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  thisa->foot_bone_index = (unsigned int)v16;
  v14 = boost::_bi::list3<char const * &,enum survarium::hit_affects_type_enum &,enum survarium::affect_event_type_enum &>::operator[](
          v16,
          (int)foot_bone);
  v15 = ((char *)v14 - (char *)vostok::animation::skeleton::get_root(v5, (int)skeleton)) / 20;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  thisa->toe_bone_index = v15;
  m_parent = foot_bone->m_parent;
  v12 = m_parent - vostok::animation::skeleton::get_root((vostok::animation::skeleton *)v15, (int)skeleton);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  thisa->leg_bone_index = v12;
  v11 = (vostok::animation::skeleton *)foot_bone->m_parent;
  type = v11->type;
  v9 = (int)(type - (_DWORD)vostok::animation::skeleton::get_root(v11, (int)skeleton)) / 20;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  thisa->knee_bone_index = v9;
  v8 = (vostok::animation::skeleton *)foot_bone->m_parent->m_parent->m_parent;
  v7 = ((char *)v8 - (char *)vostok::animation::skeleton::get_root(v8, (int)skeleton)) / 20;
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)0x14);
  thisa->up_leg_bone_index = v7;
}
