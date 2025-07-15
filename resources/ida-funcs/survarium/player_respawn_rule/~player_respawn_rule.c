void __thiscall survarium::player_respawn_rule::~player_respawn_rule(survarium::player_respawn_rule *this)
{
  survarium::player_respawn_rule *v1; // edi
  stlp_std::priv::_Rb_tree_node_base *M_left; // eax
  stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260> >,stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *> > > *p_m_respawn_points; // ebx
  stlp_std::priv::_Rb_tree_node_base *M_parent; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  vostok::memory::doug_lea_allocator *v7; // [esp-8h] [ebp-24h]
  const char *v8; // [esp-8h] [ebp-24h]
  const char *v9; // [esp-4h] [ebp-20h]
  const char *v10; // [esp-4h] [ebp-20h]
  survarium::player_respawn_rule *v11; // [esp-4h] [ebp-20h]
  const char *v12; // [esp+0h] [ebp-1Ch]
  unsigned int v13; // [esp+0h] [ebp-1Ch]
  const char *v14; // [esp+0h] [ebp-1Ch]
  unsigned int v15; // [esp+4h] [ebp-18h]
  const char *v16; // [esp+4h] [ebp-18h]
  unsigned int v17; // [esp+8h] [ebp-14h]
  survarium::player_respawn_rule *v18; // [esp+Ch] [ebp-10h]
  vostok::memory::doug_lea_allocator *v19; // [esp+10h] [ebp-Ch]
  char *v20; // [esp+14h] [ebp-8h]
  stlp_std::priv::_Rb_tree_node_base *_M_node; // [esp+18h] [ebp-4h]

  v1 = this;
  M_left = this->m_respawn_points._M_t._M_header._M_data._M_left;
  v18 = this;
  this->survarium::game_match_rule_base::vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::vostok::vfs::vfs_association::__vftable = (survarium::player_respawn_rule_vtbl *)&survarium::player_respawn_rule::`vftable'{for `vostok::resources::unmanaged_resource'};
  this->survarium::game_match_rule_base::survarium::link_resolver::__vftable = (survarium::link_resolver_vtbl *)&survarium::player_respawn_rule::`vftable'{for `survarium::link_resolver'};
  p_m_respawn_points = (stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260> >,stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const ,survarium::base_game_object *> >,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *> > > *)&this->m_respawn_points;
  while ( 1 )
  {
    _M_node = M_left;
    if ( M_left == (stlp_std::priv::_Rb_tree_node_base *)p_m_respawn_points )
      break;
    M_parent = M_left[1]._M_parent;
    v19 = survarium::g_allocator;
    if ( M_parent )
    {
      v5 = __RTCastToVoid((void **)M_parent);
      v7 = survarium::g_allocator;
      v20 = v5;
      *(_DWORD *)&M_parent->_M_color = &survarium::respawn_point_core::`vftable';
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::base_network_client>(
        v7,
        (survarium::game_effect **)&M_parent[2]._M_parent,
        v9,
        v12,
        v15);
      vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,survarium::base_network_client>(
        survarium::g_allocator,
        (survarium::game_effect **)&M_parent[2]._M_left,
        v8,
        v10,
        v13);
      vostok::memory::doug_lea_allocator::free_impl(v6, (int)v19, v20, v14, v16, v17);
      v1 = v18;
    }
    M_left = stlp_std::priv::_Rb_global<bool>::_M_increment(_M_node);
    this = v11;
  }
  if ( p_m_respawn_points->_M_node_count )
  {
    stlp_std::priv::_Rb_tree<vostok::fixed_string<260>,stlp_std::less<vostok::fixed_string<260>>,stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<260> const,survarium::base_game_object *>>,survarium::std_allocator<stlp_std::pair<vostok::fixed_string<260>,survarium::base_game_object *>>>::_M_erase(
      p_m_respawn_points,
      p_m_respawn_points->_M_header._M_data._M_parent);
    p_m_respawn_points->_M_header._M_data._M_left = (stlp_std::priv::_Rb_tree_node_base *)p_m_respawn_points;
    p_m_respawn_points->_M_header._M_data._M_parent = 0;
    p_m_respawn_points->_M_header._M_data._M_right = (stlp_std::priv::_Rb_tree_node_base *)p_m_respawn_points;
    p_m_respawn_points->_M_node_count = 0;
  }
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>::~_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,survarium::respawn_point_core *>>,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *>>>(
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,survarium::respawn_point_core *>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,survarium::respawn_point_core *> >,survarium::std_allocator<stlp_std::pair<unsigned int,survarium::respawn_point_core *> > > *)this,
    p_m_respawn_points);
  survarium::game_match_rule_base::~game_match_rule_base(v1);
}
