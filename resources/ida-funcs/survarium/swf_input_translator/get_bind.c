stlp_std::priv::_Rb_tree_node_base **__thiscall survarium::swf_input_translator::get_bind(
        survarium::swf_input_translator *this,
        vostok::input::enum_keyboard key)
{
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  survarium::swf_input_translator *v3; // edx

  M_parent = this->char_map._M_t._M_header._M_data._M_parent;
  v3 = this;
  if ( M_parent )
  {
    do
    {
      if ( *(_DWORD *)&M_parent[1]._M_color < key )
      {
        M_parent = M_parent->_M_right;
      }
      else
      {
        v3 = (survarium::swf_input_translator *)M_parent;
        M_parent = M_parent->_M_left;
      }
    }
    while ( M_parent );
    if ( this == v3 )
      return 0;
    if ( key < (signed int)v3->char_map._M_t._M_node_count )
      v3 = this;
  }
  if ( this == v3 )
    return 0;
  return stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
           &this->char_map,
           &key);
}
