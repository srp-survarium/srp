void __thiscall vostok::render::engine::world::remove_volume_fog(
        vostok::render::engine::world *this,
        stlp_std::priv::_Rb_tree_node_base *in_scene,
        stlp_std::map<unsigned int,vostok::math::float4x4,stlp_std::less<unsigned int>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::math::float4x4> > > *id)
{
  stlp_std::priv::_Rb_tree_node_base *v3; // edi
  stlp_std::priv::_Rb_tree_node_base *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  const unsigned int *v6; // [esp+0h] [ebp-8h]
  const char *v7; // [esp+0h] [ebp-8h]
  const char *v8; // [esp+4h] [ebp-4h]
  unsigned int savedregs; // [esp+8h] [ebp+0h]

  v3 = (stlp_std::priv::_Rb_tree_node_base *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate
                                            + *(_DWORD *)&in_scene->_M_color);
  stlp_std::map<unsigned int,vostok::math::float4x4,stlp_std::less<unsigned int>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::math::float4x4>>>::find<unsigned int>(
    id,
    (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::math::float4x4> > > *)&in_scene,
    v3,
    (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::math::float4x4> > > *)&id,
    v6);
  if ( in_scene != v3 )
  {
    v4 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(in_scene, &v3->_M_parent, &v3->_M_left, &v3->_M_right);
    vostok::memory::doug_lea_allocator::free_impl(
      v5,
      (int)vostok::render::g_allocator,
      (char *)&v4->_M_color,
      v7,
      v8,
      savedregs);
    --*(_DWORD *)&v3[1]._M_color;
  }
}
