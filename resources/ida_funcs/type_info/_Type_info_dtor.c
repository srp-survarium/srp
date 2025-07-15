void __cdecl type_info::_Type_info_dtor(type_info *_This)
{
  void *m_data; // ecx
  __type_info_node *next; // eax
  __type_info_node *v3; // edx

  _lock(14);
  m_data = _This->_m_data;
  if ( m_data )
  {
    next = _type_info_root_node.next;
    v3 = &_type_info_root_node;
    while ( _type_info_root_node.next )
    {
      if ( _type_info_root_node.next->memPtr == m_data )
      {
        v3->next = _type_info_root_node.next->next;
        free(next);
        break;
      }
      v3 = _type_info_root_node.next;
    }
    free(_This->_m_data);
    _This->_m_data = 0;
  }
  _unlock(14);
}
