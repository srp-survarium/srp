void __thiscall vostok::ai::ai_world::get_heavy_weapon_id_by_name(vostok::ai::ai_world *this, const char *weapon_name)
{
  vostok::ai::get_id_by_name((survarium::game_camera *)&this->m_heavy_weapons, weapon_name);
}
