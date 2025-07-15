void __fastcall survarium::messaging_client::assign_match_channel_order(
        survarium::messaging_client *this,
        unsigned int match_id,
        survarium::game_team_id team_id)
{
  if ( this->m_match_channel_id_ != match_id && match_id != -1 )
  {
    this->m_match_channel_id_ = match_id;
    this->m_game_team_id = team_id;
    survarium::messaging_client::update_channel_subscriptions(this, this);
  }
}
