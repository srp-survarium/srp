stlp_std::less<enum vostok::input::enum_keyboard> *__userpurge survarium::swf_input_translator::get_bind@<eax>(
        survarium::swf_input_translator *this@<ecx>,
        stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *a2@<eax>,
        vostok::input::enum_keyboard key)
{
  stlp_std::priv::_Rb_tree_node_base *M_parent; // ecx
  stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *v4; // edx

  M_parent = a2->_M_t._M_header._M_data._M_parent;
  v4 = a2;
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
        v4 = (stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind> > > *)M_parent;
        M_parent = M_parent->_M_left;
      }
    }
    while ( M_parent );
    if ( a2 == v4 )
      return 0;
    if ( key < (signed int)v4->_M_t._M_node_count )
      v4 = a2;
  }
  if ( a2 == v4 )
    return 0;
  return stlp_std::map<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind,stlp_std::less<enum vostok::input::enum_keyboard>,survarium::std_allocator<stlp_std::pair<enum vostok::input::enum_keyboard,survarium::dik_to_swf_bind>>>::operator[]<enum vostok::input::enum_keyboard>(
           a2,
           &key);
}
