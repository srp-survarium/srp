void __thiscall survarium::lobby_player_profile::lobby_player_profile(survarium::lobby_player_profile *this)
{
  survarium::player_profile::player_profile(this);
  this->current_exp = 0;
  this->next_level_exp = 0;
  this->prev_level_exp = 0;
  this->autobuy_items = 0;
  this->skill_points_total = 0;
  this->last_match_exp = 0;
}
