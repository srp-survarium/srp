void __thiscall survarium::weapon_user_animations_selector::remove_animation_callback(
        survarium::weapon_user_animations_selector *this,
        vostok::animation::reserved_channel_ids_enum channel_id,
        const void *callback_uid)
{
  this->m_user->unsubscribe_animation_player(this->m_user, channel_id, callback_uid);
}
