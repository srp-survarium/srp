void __thiscall survarium::game_world_ui::on_player_score_changed(
        survarium::game_world_ui *this,
        unsigned __int8 player_id,
        __int16 score)
{
  this->m_hud_state.player_kd_stats[player_id].score = score;
}
