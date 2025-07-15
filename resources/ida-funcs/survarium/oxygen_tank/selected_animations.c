void __thiscall survarium::oxygen_tank::selected_animations(
        survarium::weapon_ammunition *this,
        vostok::animation::mixing::expression *result,
        vostok::mutable_buffer *buffer,
        bool is_third_view)
{
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)this);
  survarium::weapon_user_dead_state::finalize((survarium::game_camera *)buffer->m_data);
}
