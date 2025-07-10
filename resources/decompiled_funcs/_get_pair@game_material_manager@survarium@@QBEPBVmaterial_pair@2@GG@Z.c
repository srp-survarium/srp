stlp_std::priv::_Rb_tree_node_base *__thiscall survarium::game_material_manager::get_pair(
        survarium::game_material_manager *this,
        unsigned __int16 first_mtrl_id,
        unsigned __int16 second_mtrl_id)
{
  survarium::game_camera *M_node; // ecx
  survarium::game_camera *v4; // ecx
  unsigned __int16 v6; // [esp+0h] [ebp-60h]
  unsigned __int16 m_default_material_id; // [esp+2h] [ebp-5Eh]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v9; // [esp+8h] [ebp-58h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v10; // [esp+2Ch] [ebp-34h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v11; // [esp+30h] [ebp-30h]
  boost::_bi::list1<vostok::network_core::packet_reader &> *v12; // [esp+34h] [ebp-2Ch]
  survarium::game_camera *v13; // [esp+3Ch] [ebp-24h] BYREF
  stlp_std::priv::_Rb_tree_node_base *v14; // [esp+40h] [ebp-20h] BYREF
  char v15; // [esp+47h] [ebp-19h]
  survarium::game_camera *v16; // [esp+48h] [ebp-18h] BYREF
  boost::_bi::list1<vostok::network_core::packet_reader &> *v17; // [esp+4Ch] [ebp-14h] BYREF
  unsigned __int16 second_material; // [esp+50h] [ebp-10h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::material_pair const *>,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned short const ,survarium::material_pair const *> > > second_it; // [esp+54h] [ebp-Ch] BYREF
  unsigned __int16 first_material; // [esp+58h] [ebp-8h] BYREF
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned short const ,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short> > >,stlp_std::priv::_ConstMapTraitsT<stlp_std::pair<unsigned short const ,survarium::map<unsigned short,survarium::material_pair const *,stlp_std::less<unsigned short> > > > > first_it; // [esp+5Ch] [ebp-4h] BYREF

  if ( survarium::game_material_manager::material_exist(this, first_mtrl_id) )
    m_default_material_id = first_mtrl_id;
  else
    m_default_material_id = this->m_default_material_id;
  first_material = m_default_material_id;
  if ( survarium::game_material_manager::material_exist(this, second_mtrl_id) )
    v6 = second_mtrl_id;
  else
    v6 = this->m_default_material_id;
  second_material = v6;
  v12 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::game_material const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::game_material const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::_M_find<unsigned short>(
                                                                      (stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *> > > *)&this->m_pairs,
                                                                      &first_material);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v12,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&first_it);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&this->m_pairs,
    &v17);
  M_node = (survarium::game_camera *)first_it._M_node;
  if ( (boost::_bi::list1<vostok::network_core::packet_reader &> *)first_it._M_node == v17 )
  {
    first_material = this->m_default_material_id;
    v11 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::game_material const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::game_material const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::_M_find<unsigned short>(
                                                                        (stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *> > > *)&this->m_pairs,
                                                                        &first_material);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v11,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v16);
    M_node = v16;
    first_it._M_node = (stlp_std::priv::_Rb_tree_node_base *)v16;
  }
  v15 = 0;
  survarium::weapon_user_dead_state::finalize(M_node);
  v10 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::game_material const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::game_material const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::_M_find<unsigned short>(
                                                                      (stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *> > > *)&first_it._M_node[1]._M_parent,
                                                                      &second_material);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    v10,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&second_it);
  stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
    (boost::_bi::list1<vostok::network_core::packet_reader &> *)&first_it._M_node[1]._M_parent,
    (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v14);
  v4 = (survarium::game_camera *)(second_it._M_node == v14);
  if ( second_it._M_node == v14 )
  {
    second_material = this->m_default_material_id;
    v9 = (boost::_bi::list1<vostok::network_core::packet_reader &> *)stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const,survarium::game_material const *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const,survarium::game_material const *>>,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *>>>::_M_find<unsigned short>(
                                                                       (stlp_std::priv::_Rb_tree<unsigned short,stlp_std::less<unsigned short>,stlp_std::pair<unsigned short const ,survarium::game_material const *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned short const ,survarium::game_material const *> >,survarium::std_allocator<stlp_std::pair<unsigned short,survarium::game_material const *> > > *)&first_it._M_node[1]._M_parent,
                                                                       &second_material);
    stlp_std::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>::reverse_iterator<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *>(
      v9,
      (boost::_bi::list1<vostok::network_core::packet_reader &> **)&v13);
    v4 = v13;
    second_it._M_node = (stlp_std::priv::_Rb_tree_node_base *)v13;
  }
  survarium::weapon_user_dead_state::finalize(v4);
  return second_it._M_node[1]._M_parent;
}
