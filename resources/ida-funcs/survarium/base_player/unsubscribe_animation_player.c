void __userpurge survarium::base_player::unsubscribe_animation_player(
        survarium::base_player *this@<ecx>,
        int a2@<eax>,
        char *channel_id,
        int callback_uid)
{
  vostok::animation::animation_player::unsubscribe(
    (vostok::animation::animation_player *)this,
    (const char *)(a2 + 848),
    channel_id,
    callback_uid);
}


void __thiscall survarium::base_player::unsubscribe_animation_player(
        survarium::base_player *this,
        vostok::animation::reserved_channel_ids_enum channel_id,
        const void *callback_uid,
        int a4)
{
  BYTE1(callback_uid) = 0;
  vostok::animation::animation_player::unsubscribe(
    (vostok::animation::animation_player *)this,
    (const char *)(channel_id + 848),
    (char *)&callback_uid,
    a4);
}
