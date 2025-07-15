unsigned __int8 __userpurge survarium::player_shootmarks_storage::add_shootmark@<al>(
        unsigned int bullet_id@<eax>,
        survarium::player_shootmarks_storage *this,
        survarium::player_shootmarks_storage::sm *bullet_change_trajectory_count,
        const unsigned __int8 player_id)
{
  vostok::buffer_vector<survarium::player_shootmarks_storage::sm> *v4; // esi
  survarium::player_shootmarks_storage::sm *m_begin; // ebx
  survarium::player_shootmarks_storage::sm *m_end; // edi
  survarium::player_shootmarks_storage::sm *v7; // eax
  survarium::player_shootmarks_storage::sm __val; // [esp+10h] [ebp-Ch] BYREF

  v4 = &this->m_shootmarks[player_id];
  __val.bullet_id = bullet_id;
  m_begin = v4->m_begin;
  m_end = v4->m_end;
  __val.bullet_change_trajectory_count = (unsigned __int8)bullet_change_trajectory_count;
  __val.shootmark_count = 0;
  v7 = stlp_std::priv::__find<survarium::player_shootmarks_storage::sm *,survarium::player_shootmarks_storage::sm>(
         m_begin,
         &__val,
         m_end);
  if ( v7 == m_end )
  {
    __val.shootmark_count = 1;
    if ( (((char *)m_end - (char *)m_begin) & 0xFFFFFFF8) == 0x100 )
    {
      bullet_change_trajectory_count = m_begin;
      vostok::buffer_vector<survarium::player_shootmarks_storage::sm>::erase(v4, &bullet_change_trajectory_count);
    }
    vostok::buffer_vector<survarium::player_shootmarks_storage::sm>::push_back(v4, &__val);
    return 1;
  }
  else
  {
    return ++v7->shootmark_count;
  }
}
