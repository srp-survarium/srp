survarium::human_npc::npc_game_attributes *__userpurge survarium::human_npc::npc_game_attributes::operator=@<eax>(
        survarium::human_npc::npc_game_attributes *this@<ecx>,
        survarium::human_npc::npc_game_attributes *result@<eax>,
        survarium::human_npc::npc_game_attributes *other)
{
  survarium::human_npc::npc_game_attributes *v3; // edi
  vostok::fixed_string<32> *p_name; // eax
  char *m_begin; // ecx
  unsigned int v6; // ebp
  vostok::fixed_string<32> *p_description; // ecx
  char *v8; // eax
  unsigned int v9; // ebp

  v3 = result;
  if ( result != other )
  {
    result->initial_position = other->initial_position;
    result->initial_scale = other->initial_scale;
    result->initial_rotation = other->initial_rotation;
    result->debug_draw_color.m_value = other->debug_draw_color.m_value;
    p_name = &other->name;
    if ( &v3->name != &other->name )
    {
      m_begin = v3->name.m_begin;
      v3->name.m_end = m_begin;
      *m_begin = 0;
      v6 = other->name.m_end - p_name->m_begin;
      memcpy((unsigned __int8 *)v3->name.m_end, (unsigned __int8 *)p_name->m_begin, v6);
      v3->name.m_end += v6;
      *v3->name.m_end = 0;
    }
    p_description = &other->description;
    if ( &v3->description != &other->description )
    {
      v8 = v3->description.m_begin;
      v3->description.m_end = v8;
      *v8 = 0;
      v9 = other->description.m_end - p_description->m_begin;
      memcpy((unsigned __int8 *)v3->description.m_end, (unsigned __int8 *)p_description->m_begin, v9);
      v3->description.m_end += v9;
      *v3->description.m_end = 0;
    }
    v3->initial_velocity = other->initial_velocity;
    v3->initial_luminosity = other->initial_luminosity;
    v3->id = other->id;
    v3->group_id = other->group_id;
    v3->class_id = other->class_id;
    v3->outfit_id = other->outfit_id;
    vostok::intrusive_list<survarium::object_weapon,survarium::object_weapon *,12,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy>::swap(
      &v3->weapons,
      &other->weapons);
    return v3;
  }
  return result;
}
