void __userpurge survarium::weapon_user_animations_selector::remove_animation_callback(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>,
        const char *channel_id,
        const void *callback_uid)
{
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    *(_DWORD *)(a2 + 60),
    "jump",
    (int)channel_id);
}


void __userpurge survarium::weapon_user_animations_selector::remove_animation_callback(
        survarium::weapon_user_animations_selector *this@<ecx>,
        int a2@<eax>,
        vostok::animation::reserved_channel_ids_enum channel_id,
        int callback_uid)
{
  survarium::base_player::unsubscribe_animation_player(
    (survarium::base_player *)this,
    *(vostok::animation::reserved_channel_ids_enum *)(a2 + 60),
    (const void *)channel_id,
    callback_uid);
}
