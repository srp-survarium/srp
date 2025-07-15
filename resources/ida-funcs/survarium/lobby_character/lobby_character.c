void __userpurge survarium::lobby_character::lobby_character(
        const vostok::math::float3 *position@<eax>,
        survarium::lobby_character *this,
        survarium::lobby_menu *lobby_menu,
        vostok::physics::world *physics_world,
        const float orientation)
{
  survarium::lobby_player_profile *m_profiles; // edi
  int i; // [esp+8h] [ebp+8h]

  this->profile_id = 0;
  this->m_position = *position;
  this->m_orientation = pi_23;
  m_profiles = this->m_profiles;
  for ( i = 2; i >= 0; --i )
    survarium::lobby_player_profile::lobby_player_profile(m_profiles++);
  this->m_current_profile_idx = 0;
  this->m_player.m_object = 0;
  this->m_current_query_id = -1;
  this->m_lobby_menu = lobby_menu;
  this->m_physics_world = physics_world;
  this->m_need_to_requery = 0;
  memset((int)this->m_profiles, 0, sizeof(this->m_profiles));
}
