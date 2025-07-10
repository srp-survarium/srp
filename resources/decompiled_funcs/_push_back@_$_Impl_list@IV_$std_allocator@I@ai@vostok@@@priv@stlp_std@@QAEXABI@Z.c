void __thiscall stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int>>::push_back(
        stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int> > *this,
        const unsigned int *__x)
{
  stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int> > *v2; // [esp+4h] [ebp-30h] BYREF
  stlp_std::priv::_List_node_base *node; // [esp+1Ch] [ebp-18h]
  stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int> > *v4; // [esp+20h] [ebp-14h]
  stlp_std::priv::_List_node_base *M_prev; // [esp+24h] [ebp-10h]
  stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int> > **v6; // [esp+28h] [ebp-Ch]

  v6 = &v2;
  v2 = this;
  node = stlp_std::priv::_Impl_list<unsigned int,vostok::ai::std_allocator<unsigned int>>::_M_create_node(this, __x);
  v4 = v2;
  M_prev = v2->_M_node._M_data._M_prev;
  node->_M_next = (stlp_std::priv::_List_node_base *)v2;
  node->_M_prev = M_prev;
  M_prev->_M_next = node;
  v4->_M_node._M_data._M_prev = node;
}
