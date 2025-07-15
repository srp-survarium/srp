void __thiscall survarium::game_material_manager::add_pair(
        survarium::game_material_manager *this,
        stlp_std::priv::_Rb_tree_node_base *pair)
{
  stlp_std::priv::_Rb_tree_node_base **v2; // eax
  unsigned __int16 first_mtrl_id; // [esp+CCh] [ebp-8h] BYREF
  unsigned __int16 second_mtrl_id; // [esp+D0h] [ebp-4h] BYREF

  first_mtrl_id = (unsigned __int16)pair[2]._M_parent[5]._M_right;
  second_mtrl_id = (unsigned __int16)pair[2]._M_left[5]._M_right;
  v2 = stlp_std::map<unsigned short,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>>>>>::operator[]<unsigned short>(
         &this->m_pairs,
         &first_mtrl_id);
  *stlp_std::map<unsigned short,survarium::game_material const *,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::operator[]<unsigned short>(
     (stlp_std::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::material_pair const *> > > *)v2,
     &second_mtrl_id) = pair;
}
