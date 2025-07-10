void __thiscall survarium::game_material_manager::add_game_material(
        survarium::game_material_manager *this,
        stlp_std::priv::_Rb_tree_node_base *mtrl)
{
  unsigned __int16 __k; // [esp+52h] [ebp-2h] BYREF

  __k = (unsigned __int16)mtrl[5]._M_right;
  *stlp_std::map<unsigned short,survarium::game_material const *,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::operator[]<unsigned short>(
     (stlp_std::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::material_pair const *> > > *)&this->m_materials,
     &__k) = mtrl;
}
