void __thiscall vostok::ai::ai_world::get_class_id_by_name(vostok::ai::ai_world *this, const char *class_name)
{
  vostok::ai::get_id_by_name((survarium::game_camera *)&this->m_npc_classes, class_name);
}
