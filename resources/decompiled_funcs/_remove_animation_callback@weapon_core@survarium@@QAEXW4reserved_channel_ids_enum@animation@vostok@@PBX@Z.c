void __thiscall survarium::weapon_core::remove_animation_callback(
        survarium::weapon_core *this,
        vostok::animation::reserved_channel_ids_enum channel_id,
        const void *callback_uid)
{
  this->m_user->unsubscribe_animation_player(this->m_user, channel_id, callback_uid);
}
