vostok::mutable_buffer *__userpurge survarium::weapon_core_idle_state::get_user_hands_lexeme@<eax>(
        survarium::weapon_core_idle_state *this@<ecx>,
        vostok::animation::mixing::animation_lexeme *a2@<eax>,
        vostok::mutable_buffer *result,
        vostok::mutable_buffer *buffer,
        const survarium::weapon_user_state_enum user_state_id)
{
  survarium::weapon_core_base_state *v6; // [esp-4h] [ebp-18h]

  v6 = (survarium::weapon_core_base_state *)&(&(&a2[2].m_time_scale_interpolator)[4
                                                                                * (*((_BYTE *)a2[2].m_time_calculator.m_Closure.m_pFunction
                                                                                   + 1108) != 0)])[2
                                                                                                 * (user_state_id == type_crouch)];
  survarium::weapon_core_base_state::get_user_hands_lexeme_impl(
    v6,
    a2,
    (vostok::animation::mixing::animation_lexeme *)result,
    buffer,
    (vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base> (*)[2])v6,
    0.30000001,
    0,
    play_cyclically,
    1.0);
  return result;
}
