void __thiscall vostok::ai::blackboard::dump_state(vostok::ai::blackboard *this, vostok::ai::npc_statistics *stats)
{
  char *v2; // eax
  vostok::fixed_string<64> value; // [esp+58h] [ebp-9Ch] BYREF
  vostok::fixed_string<64> new_item_content; // [esp+A4h] [ebp-50h] BYREF

  vostok::fixed_string<16>::operator=(&stru_97F818, &stats->blackboard_state.caption);
  if ( this->m_current_goal )
  {
    vostok::fixed_string<64>::fixed_string<64>(&new_item_content, &stru_97F818.m_buffer[8]);
    v2 = (char *)stlp_std::priv::_Impl_vector<unsigned char,stlp_std::allocator<unsigned char>>::begin(
                   (stlp_std::vector<vostok::variant<32> const *,survarium::std_allocator<vostok::variant<32> const *> > *)this,
                   (int)&this->m_current_goal->m_caption);
    vostok::buffer_string::append(&new_item_content, v2);
    vostok::buffer_vector<vostok::fixed_string<64>>::push_back(&new_item_content, &stats->blackboard_state.content);
    vostok::fs_new::path_string_impl::clear(&new_item_content);
    vostok::buffer_string::appendf(
      &new_item_content,
      (vostok::buffer_string *)&stru_97F83C,
      (const char *)this->m_current_goal->m_priority);
    vostok::buffer_vector<vostok::fixed_string<64>>::push_back(&new_item_content, &stats->blackboard_state.content);
  }
  if ( stats->blackboard_state.content.m_begin == stats->blackboard_state.content.m_end )
  {
    vostok::fixed_string<64>::fixed_string<64>(&value, "no entries");
    vostok::buffer_vector<vostok::fixed_string<64>>::push_back(&value, &stats->blackboard_state.content);
  }
}
