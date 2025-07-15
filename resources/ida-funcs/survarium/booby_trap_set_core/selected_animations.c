void __thiscall survarium::booby_trap_set_core::selected_animations(
        survarium::booby_trap_set_core *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer->m_size);
  JUMPOUT(0x96A49);
}
