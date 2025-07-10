void __fastcall vostok::animation::animation_player::unsubscribe(
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *callback_uid,
        vostok::animation::animation_player *this,
        vostok::animation::reserved_channel_ids_enum channel_id)
{
  BYTE1(channel_id) = 0;
  vostok::animation::animation_player::unsubscribe(
    (vostok::animation::animation_player *)&channel_id,
    this,
    callback_uid);
}
