char *__thiscall survarium::game_world_core::profile_name(
        survarium::game_world_core *this,
        const unsigned __int8 client_id)
{
  char *result; // eax

  if ( client_id < 0x14u )
    return this->m_match_options->player_profiles.elems[client_id].profile_name;
  result = "<server>";
  if ( client_id != 20 )
    return "<invalid>";
  return result;
}
