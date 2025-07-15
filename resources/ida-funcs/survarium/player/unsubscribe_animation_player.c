void __thiscall survarium::player::unsubscribe_animation_player(
        survarium::player *this,
        vostok::animation::animation_player *channel_id,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *callback_uid)
{
  vostok::animation::animation_player::unsubscribe(channel_id, &this->m_current.animation_player, callback_uid);
  vostok::animation::animation_player::unsubscribe(channel_id, &this->m_target.animation_player, callback_uid);
}


void __thiscall survarium::player::unsubscribe_animation_player(
        survarium::player *this,
        vostok::animation::reserved_channel_ids_enum channel_id,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *callback_uid)
{
  unsigned __int8 v3; // bl
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // edi

  v3 = channel_id;
  v4 = callback_uid;
  BYTE1(channel_id) = 0;
  vostok::animation::animation_player::unsubscribe(
    (vostok::animation::animation_player *)&channel_id,
    &this->m_current.animation_player,
    callback_uid);
  LOWORD(channel_id) = v3;
  vostok::animation::animation_player::unsubscribe(
    (vostok::animation::animation_player *)&channel_id,
    &this->m_target.animation_player,
    v4);
}
