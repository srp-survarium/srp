void __thiscall survarium::player::unsubscribe_animation_player(
        survarium::player *this,
        vostok::animation::animation_player *channel_id,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *callback_uid)
{
  vostok::animation::animation_player::unsubscribe(channel_id, &this->m_current.animation_player, callback_uid);
  vostok::animation::animation_player::unsubscribe(channel_id, &this->m_target.animation_player, callback_uid);
}
