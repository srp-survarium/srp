survarium::game_team_id __usercall survarium::shared_statistics::team@<eax>(
        survarium::shared_statistics *this@<ecx>,
        const survarium::player_shared_statistics *player_stats@<eax>)
{
  return this->m_match_options->player_profiles.elems[(unsigned __int8)(((char *)player_stats - (char *)this) / 212)].team;
}
