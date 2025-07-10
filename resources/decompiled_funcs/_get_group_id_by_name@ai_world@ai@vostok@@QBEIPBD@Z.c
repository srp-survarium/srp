void __thiscall vostok::ai::ai_world::get_group_id_by_name(vostok::ai::ai_world *this, const char *group_name)
{
  vostok::ai::get_id_by_name((survarium::game_camera *)&this->m_npc_groups, group_name);
}
