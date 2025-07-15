stlp_std::less<unsigned int> *__usercall survarium::items_dictionary::item_by_id@<eax>(
        survarium::items_dictionary *this@<ecx>,
        unsigned int item_dictionary_id@<esi>)
{
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *p_m_items_dict; // ecx
  survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *v4; // edx
  stlp_std::less<unsigned int> *result; // eax

  M_parent = this->m_items_dict._M_t._M_header._M_data._M_parent;
  p_m_items_dict = &this->m_items_dict;
  v4 = p_m_items_dict;
  if ( !M_parent )
    return &v4->_M_t._M_key_compare;
  do
  {
    if ( *(_DWORD *)&M_parent[1]._M_color < item_dictionary_id )
    {
      M_parent = M_parent->_M_right;
    }
    else
    {
      v4 = (survarium::map<unsigned int,survarium::dictionary_item,stlp_std::less<unsigned int> > *)M_parent;
      M_parent = M_parent->_M_left;
    }
  }
  while ( M_parent );
  if ( v4 == p_m_items_dict )
    return &v4->_M_t._M_key_compare;
  result = &p_m_items_dict->_M_t._M_key_compare;
  if ( item_dictionary_id >= v4->_M_t._M_node_count )
    return &v4->_M_t._M_key_compare;
  return result;
}
