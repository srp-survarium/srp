stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *__usercall stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats>>>::operator[]<unsigned int>@<eax>(
        stlp_std::map<unsigned int,survarium::base_point_stats,stlp_std::less<unsigned int>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats> > > *this@<ecx>,
        stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *a2@<eax>)
{
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *M_node; // ecx
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *v4; // edx
  stlp_std::priv::_Rb_tree_node_base *v5; // esi
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::base_point_stats> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats> > > v7; // [esp-8h] [ebp-2Ch] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > result; // [esp+10h] [ebp-14h] BYREF
  __int64 v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-8h]

  *(_DWORD *)&v7._M_key_compare.gap0 = 0;
  M_node = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)a2[1]._M_node;
  v4 = a2;
  while ( M_node )
  {
    if ( M_node[4]._M_node < (stlp_std::priv::_Rb_tree_node_base *)*(_DWORD *)&this->_M_t._M_header._M_data._M_color )
    {
      M_node = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)M_node[3]._M_node;
    }
    else
    {
      v4 = M_node;
      M_node = (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)M_node[2]._M_node;
    }
  }
  if ( v4 != a2
    && (stlp_std::priv::_Rb_tree_node_base *)*(_DWORD *)&this->_M_t._M_header._M_data._M_color >= v4[4]._M_node )
  {
    return v4 + 5;
  }
  v5 = *(stlp_std::priv::_Rb_tree_node_base **)&this->_M_t._M_header._M_data._M_color;
  v10 = 0;
  result._M_node = v5;
  v9 = 0;
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::base_point_stats>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::base_point_stats>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::base_point_stats>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::base_point_stats>>>::insert_unique(
    &v7,
    v4,
    (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > >)&result,
    (const stlp_std::pair<unsigned int const ,survarium::base_point_stats> *)v7._M_header._M_data._M_left);
  return (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::base_point_stats>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::base_point_stats> > > *)(*(_DWORD *)&v7._M_key_compare.gap0 + 20);
}
