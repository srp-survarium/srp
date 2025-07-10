void __thiscall stlp_std::priv::_List_base<unsigned int,vostok::ai::std_allocator<unsigned int>>::clear(
        stlp_std::priv::_List_base<unsigned int,vostok::ai::std_allocator<unsigned int> > *this)
{
  survarium::game_camera *v1; // ecx
  stlp_std::priv::_List_node<unsigned int> *__tmp; // [esp+8h] [ebp-8h]
  stlp_std::priv::_List_base<unsigned int,vostok::ai::std_allocator<unsigned int> > *__cur; // [esp+Ch] [ebp-4h]

  __cur = (stlp_std::priv::_List_base<unsigned int,vostok::ai::std_allocator<unsigned int> > *)this->_M_node._M_data._M_next;
  while ( __cur != this )
  {
    __tmp = (stlp_std::priv::_List_node<unsigned int> *)__cur;
    v1 = (survarium::game_camera *)__cur;
    __cur = (stlp_std::priv::_List_base<unsigned int,vostok::ai::std_allocator<unsigned int> > *)__cur->_M_node._M_data._M_next;
    survarium::weapon_user_dead_state::finalize(v1);
    vostok::memory::doug_lea_allocator::free_impl(vostok::ai::g_allocator, __tmp);
  }
  this->_M_node._M_data._M_next = (stlp_std::priv::_List_node_base *)this;
  this->_M_node._M_data._M_prev = (stlp_std::priv::_List_node_base *)this;
}
