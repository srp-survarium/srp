void __thiscall survarium::portable_interactive_object_core::set_user(
        survarium::portable_interactive_object_core *this,
        survarium::base_player *user)
{
  const vostok::animation::skeleton *v3; // ebx
  vostok::animation::legs_ik_solver::leg_params *v4; // ecx
  vostok::animation::skeleton *v5; // ecx
  survarium::base_player *m_user; // ebx
  vostok::ai::fsm_state *m_first; // esi

  this->m_user = user;
  v3 = *(const vostok::animation::skeleton **)((char *)&dword_10E28 + (_DWORD)user);
  this->m_legs_ik_solver.m_skeleton = v3;
  vostok::animation::legs_ik_solver::leg_params::set_user(
    (vostok::animation::legs_ik_solver::leg_params *)this,
    (int *)&this->m_legs_ik_solver.m_left_leg_params,
    v3,
    "LeftFoot");
  vostok::animation::legs_ik_solver::leg_params::set_user(
    v4,
    (int *)&this->m_legs_ik_solver.m_right_leg_params,
    v3,
    "RightFoot");
  this->m_legs_ik_solver.m_hip_bone = (const vostok::animation::skeleton_bone *)((char *)&v3[1]
                                                                               + 28
                                                                               * vostok::animation::skeleton::get_bone_index(
                                                                                   v5,
                                                                                   (int)v3,
                                                                                   "Hip"));
  m_user = this->m_user;
  m_first = this->m_user_animations_selector.m_logic.m_states.m_first;
  this->m_user_animations_selector.m_user = m_user;
  while ( m_first )
  {
    ((void (__thiscall *)(vostok::ai::fsm_state *, survarium::base_player *))m_first->__vftable[1].~vostok::ai::fsm_state)(
      m_first,
      m_user);
    m_first = m_first->next;
  }
  this->m_user_hit_animations_selector.m_user = this->m_user;
}
