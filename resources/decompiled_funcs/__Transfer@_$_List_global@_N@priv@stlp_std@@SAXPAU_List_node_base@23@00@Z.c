void __cdecl stlp_std::priv::_List_global<bool>::_Transfer(
        stlp_std::priv::_List_node_base *__position,
        stlp_std::priv::_List_node_base *__first,
        stlp_std::priv::_List_node_base *__last)
{
  stlp_std::priv::_List_node_base *M_prev; // esi

  if ( __position != __last )
  {
    __last->_M_prev->_M_next = __position;
    __first->_M_prev->_M_next = __last;
    __position->_M_prev->_M_next = __first;
    M_prev = __position->_M_prev;
    __position->_M_prev = __last->_M_prev;
    __last->_M_prev = __first->_M_prev;
    __first->_M_prev = M_prev;
  }
}
