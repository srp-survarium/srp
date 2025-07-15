void __thiscall survarium::weapon::instant_aim_start(survarium::weapon *this)
{
  survarium::rifle_scope *m_object; // eax
  float m_fov_factor; // xmm0_4
  survarium::base_player *m_user; // eax
  int v5; // edx
  survarium::rifle_scope *v6; // eax
  float m_near_plane_factor; // xmm0_4
  int v8; // eax

  survarium::weapon_core::instant_aim_start(this);
  if ( this->m_game_ui )
  {
    m_object = this->m_rifle_scope.m_object;
    if ( m_object
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_fov_factor = m_object->m_fov_factor;
    }
    else
    {
      m_fov_factor = this->m_aim_fov_factor;
    }
    m_user = this->m_user;
    v5 = *(int *)((char *)&dword_10F0C + (_DWORD)m_user);
    m_user[244].m_character_head_transform.k.y = m_user[244].m_character_head_transform.k.z;
    *(float *)((char *)&dword_10F24 + (_DWORD)m_user) = s_aim_transition_time;
    *(int *)((char *)&dword_10F28 + (_DWORD)m_user) = v5;
    *(float *)((char *)&dword_10F18 + (_DWORD)m_user) = m_fov_factor;
    v6 = this->m_rifle_scope.m_object;
    if ( v6
      && vostok::intrusive_ptr<vostok::animation::mixing::binary_tree_weight_node,vostok::animation::mixing::binary_tree_base_node,vostok::threading::single_threading_policy>::c_ptr )
    {
      m_near_plane_factor = v6->m_near_plane_factor;
    }
    else
    {
      m_near_plane_factor = this->m_aim_near_plane_factor;
    }
    v8 = *(int *)((char *)&dword_10EF4 + (unsigned int)this->m_user);
    if ( v8 )
      *(float *)(v8 + 76) = m_near_plane_factor * 0.050000001;
    *(_DWORD *)(*(int *)((char *)&dword_10EF4 + (unsigned int)this->m_user) + 416) = 4;
  }
}
