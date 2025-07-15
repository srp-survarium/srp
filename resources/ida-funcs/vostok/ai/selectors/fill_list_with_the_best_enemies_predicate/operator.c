void __thiscall vostok::ai::selectors::fill_list_with_the_best_enemies_predicate::operator()(
        vostok::ai::selectors::fill_list_with_the_best_enemies_predicate *this,
        vostok::ai::percept_memory_object *memory_object)
{
  survarium::game_camera *v2; // ecx
  vostok::fixed_vector<stlp_std::pair<vostok::ai::npc const *,float>,16> *v4; // [esp+20h] [ebp-5Ch]
  stlp_std::pair<vostok::ai::npc const *,float> *v5; // [esp+24h] [ebp-58h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *v6; // [esp+28h] [ebp-54h]
  vostok::fixed_vector<stlp_std::pair<vostok::ai::npc const *,float>,16> *v7; // [esp+2Ch] [ebp-50h]
  stlp_std::pair<vostok::ai::npc const *,float> *v8; // [esp+30h] [ebp-4Ch]
  vostok::fixed_vector<stlp_std::pair<vostok::ai::npc const *,float>,16> *v9; // [esp+34h] [ebp-48h]
  signed int v10; // [esp+38h] [ebp-44h]
  survarium::game_camera *v11; // [esp+3Ch] [ebp-40h]
  vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float> > *v12; // [esp+40h] [ebp-3Ch]
  stlp_std::pair<vostok::ai::npc const *,float> *end; // [esp+44h] [ebp-38h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *m_end; // [esp+48h] [ebp-34h]
  stlp_std::pair<vostok::ai::npc const *,float> *m_begin; // [esp+4Ch] [ebp-30h]
  vostok::fixed_vector<stlp_std::pair<vostok::ai::npc const *,float>,16> *enemies_list; // [esp+50h] [ebp-2Ch]
  stlp_std::pair<vostok::ai::npc const *,float> value; // [esp+54h] [ebp-28h] BYREF
  char v18; // [esp+5Eh] [ebp-1Eh]
  char v19; // [esp+5Fh] [ebp-1Dh]
  stlp_std::pair<vostok::ai::npc const *,float> *i; // [esp+60h] [ebp-1Ch]
  stlp_std::pair<vostok::ai::npc const *,float> *min_confidence_item; // [esp+64h] [ebp-18h] BYREF
  stlp_std::pair<vostok::ai::npc const *,float> *it; // [esp+68h] [ebp-14h] BYREF
  const void *target_npc; // [esp+6Ch] [ebp-10h]
  const vostok::ai::game_object *object; // [esp+70h] [ebp-Ch]
  float confidence; // [esp+74h] [ebp-8h]
  const vostok::ai::npc *target; // [esp+78h] [ebp-4h]

  object = memory_object->object;
  confidence = vostok::ai::selectors::get_recalculated_confidence(this->world, memory_object);
  target = object->cast_npc(object);
  v19 = 0;
  survarium::weapon_user_dead_state::finalize(v2);
  enemies_list = this->enemies_list;
  m_begin = enemies_list->m_begin;
  for ( it = m_begin; ; ++it )
  {
    m_end = this->enemies_list->m_end;
    if ( it == m_end )
      break;
    if ( it->first == target )
    {
      if ( confidence <= it->second )
        return;
      v12 = this->enemies_list;
      end = it + 1;
      vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float>>::erase(v12, &it, &end);
      break;
    }
  }
  v11 = (survarium::game_camera *)this->enemies_list;
  v10 = (signed int)(LODWORD(v11->m_inverted_view_matrix.i.x) - (unsigned int)v11->__vftable) >> 3;
  if ( v10 == 16 )
  {
    v18 = 0;
    survarium::weapon_user_dead_state::finalize(v11);
    v9 = this->enemies_list;
    v8 = v9->m_begin;
    min_confidence_item = v8;
    v7 = this->enemies_list;
    for ( i = v7->m_begin; ; ++i )
    {
      v6 = this->enemies_list->m_end;
      if ( i == v6 )
        break;
      if ( min_confidence_item->second > i->second )
        min_confidence_item = i;
    }
    if ( confidence > min_confidence_item->second )
    {
      v4 = this->enemies_list;
      v5 = min_confidence_item + 1;
      vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float>>::erase(v4, &min_confidence_item, &v5);
    }
  }
  target_npc = target;
  if ( (unsigned int)(this->enemies_list->m_end - this->enemies_list->m_begin) < 0x10 )
  {
    value.first = target;
    value.second = confidence;
    vostok::buffer_vector<stlp_std::pair<vostok::ai::npc const *,float>>::push_back(this->enemies_list, &value);
  }
}
