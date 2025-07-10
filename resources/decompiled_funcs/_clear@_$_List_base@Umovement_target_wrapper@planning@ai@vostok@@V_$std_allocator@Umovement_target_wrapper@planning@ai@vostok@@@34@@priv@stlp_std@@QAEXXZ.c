void __thiscall stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper>>::clear(
        stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper> > *this)
{
  stlp_std::priv::_List_node<vostok::ai::planning::movement_target_wrapper> *__tmp; // [esp+8h] [ebp-8h]
  stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper> > *__cur; // [esp+Ch] [ebp-4h]

  __cur = (stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper> > *)this->_M_node._M_data._M_next;
  while ( __cur != this )
  {
    __tmp = (stlp_std::priv::_List_node<vostok::ai::planning::movement_target_wrapper> *)__cur;
    __cur = (stlp_std::priv::_List_base<vostok::ai::planning::movement_target_wrapper,vostok::ai::std_allocator<vostok::ai::planning::movement_target_wrapper> > *)__cur->_M_node._M_data._M_next;
    vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, __tmp);
  }
  this->_M_node._M_data._M_next = (stlp_std::priv::_List_node_base *)this;
  this->_M_node._M_data._M_prev = (stlp_std::priv::_List_node_base *)this;
}
