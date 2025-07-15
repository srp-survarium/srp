void __userpurge survarium::damage_model::cancel_affect(
        survarium::damage_model *this@<ecx>,
        int a2@<eax>,
        unsigned int current_time_in_ms,
        char *part_name,
        const survarium::hit_affects_type_enum affect)
{
  survarium::body_part_parameters *body_part; // ebx
  vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> > *p_m_affects; // edi
  int v7; // esi
  survarium::hit_affects_type_enum first; // ecx
  const char *m_begin; // [esp-8h] [ebp-18h]
  stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int> *where; // [esp+Ch] [ebp-4h] BYREF

  body_part = survarium::damage_model::get_body_part(this, a2, part_name);
  p_m_affects = &body_part->m_affects;
  v7 = body_part->m_affects.m_end - body_part->m_affects.m_begin;
  while ( --v7 >= 0 )
  {
    first = p_m_affects->m_begin[v7].first;
    if ( first == affect )
    {
      m_begin = body_part->m_name.m_begin;
      where = &p_m_affects->m_begin[v7];
      survarium::damage_model::notify_on_affect_event(
        current_time_in_ms,
        first,
        (vostok::intrusive_list<survarium::affect_subscriber,survarium::affect_subscriber *,32,vostok::threading::mutex,vostok::size_policy,vostok::no_debug_policy> *)body_part->m_damage_model,
        m_begin,
        affect_canceling);
      vostok::buffer_vector<stlp_std::pair<enum survarium::hit_affects_type_enum,unsigned int>>::erase(
        p_m_affects,
        &where);
    }
  }
}
