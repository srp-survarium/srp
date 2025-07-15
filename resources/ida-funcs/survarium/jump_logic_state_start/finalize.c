void __thiscall survarium::jump_logic_state_start::finalize(survarium::jump_logic_state_start *this)
{
  survarium::weapon_user_animations_selector *v2; // ecx
  const void *v3; // [esp+0h] [ebp-4h]

  survarium::weapon_user_animations_selector::remove_animation_callback(
    (survarium::weapon_user_animations_selector *)this,
    (int)this->m_jump_logic->m_owner,
    (const char *)this,
    v3);
  survarium::weapon_user_animations_selector::remove_animation_callback(
    v2,
    (int)this->m_jump_logic->m_owner,
    channel_id_on_animation_interval_end,
    (int)this);
}
