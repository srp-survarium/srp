void __thiscall survarium::player_respawn_rule::resolve_links(
        survarium::player_respawn_rule *this,
        survarium::base_project *project,
        vostok::configs::binary_config_value config)
{
  vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ebx
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *p_m_flags; // esi
  const void *v8; // edx
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *M_parent; // eax
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *v10; // ecx
  stlp_std::priv::_Rb_tree_node_base *M_node; // eax
  survarium::base_project::resolve_link_object *v12; // eax
  vostok::configs::binary_config_value v13; // [esp-18h] [ebp-48h] BYREF
  char v14; // [esp+Fh] [ebp-21h]
  vostok::configs::binary_config_value *pointer; // [esp+10h] [ebp-20h]
  int v16; // [esp+14h] [ebp-1Ch]
  survarium::player_respawn_rule *i; // [esp+18h] [ebp-18h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> > > __position; // [esp+1Ch] [ebp-14h] BYREF
  const void *v19; // [esp+20h] [ebp-10h]
  int v20; // [esp+24h] [ebp-Ch]
  stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> __val; // [esp+28h] [ebp-8h] BYREF

  v16 = 0;
  i = this;
  v3 = vostok::configs::binary_config_value::operator[](&config, "server_objects");
  pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v3,
                                                      "respawn_points")->data.pointer;
  v4 = vostok::configs::binary_config_value::operator[](&config, "server_objects");
  v5 = vostok::configs::binary_config_value::operator[](v4, "respawn_points");
  v6 = (vostok::configs::binary_config_value *)((char *)v5->data.pointer + 24 * v5->count);
  if ( pointer != v6 )
  {
    p_m_flags = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)&i->survarium::game_match_rule_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags;
    for ( i = (survarium::player_respawn_rule *)((char *)i + 8);
          ;
          p_m_flags = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)i )
    {
      v8 = vostok::configs::binary_config_value::operator[](pointer, "point_id")->data.pointer;
      M_parent = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)p_m_flags->_M_header._M_data._M_parent;
      v20 = 0;
      v19 = v8;
      v10 = p_m_flags;
      while ( M_parent )
      {
        if ( M_parent->_M_node_count < (unsigned __int16)v8 )
        {
          M_parent = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)M_parent->_M_header._M_data._M_right;
        }
        else
        {
          v10 = M_parent;
          M_parent = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)M_parent->_M_header._M_data._M_left;
        }
      }
      M_node = (stlp_std::priv::_Rb_tree_node_base *)v10;
      if ( v10 == p_m_flags || (v16 |= 1u, v14 = 0, (unsigned __int16)v8 < v10->_M_node_count) )
        v14 = 1;
      if ( (v16 & 1) != 0 )
        v16 &= ~1u;
      if ( v14 )
      {
        __val.second = 0;
        __val.first = (unsigned __int16)v19;
        stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::insert_unique(
          p_m_flags,
          &__val,
          (stlp_std::priv::_Rb_tree_node_base *)&__position,
          v10);
        M_node = __position._M_node;
      }
      v12 = (survarium::base_project::resolve_link_object *)M_node[1]._M_parent;
      qmemcpy((void *)&v13, pointer, sizeof(v13));
      survarium::base_project::register_object_to_resolve(v12, project, v13);
      if ( ++pointer == v6 )
        break;
    }
  }
}
