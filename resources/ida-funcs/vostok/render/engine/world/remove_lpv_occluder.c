void __thiscall vostok::render::engine::world::remove_lpv_occluder(
        vostok::render::engine::world *this,
        const vostok::resources::resource_ptr<vostok::render::base_scene,vostok::resources::unmanaged_intrusive_base> *in_scene,
        stlp_std::priv::_Rb_tree_node_base *id)
{
  stlp_std::priv::_Rb_tree_node_base *v3; // edi
  stlp_std::priv::_Rb_tree_node_base *v4; // eax
  vostok::memory::doug_lea_allocator *v5; // ecx
  const unsigned int *v6; // [esp+0h] [ebp-10h]
  const char *v7; // [esp+0h] [ebp-10h]
  const char *v8; // [esp+4h] [ebp-Ch]
  unsigned int v9; // [esp+8h] [ebp-8h]
  stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::math::float4x4> > > result; // [esp+Ch] [ebp-4h] BYREF

  result._M_node = id;
  v3 = (stlp_std::priv::_Rb_tree_node_base *)((char *)&btDiscreteCollisionDetectorInterface `RTTI Type Descriptor'
                                            + (unsigned int)in_scene->m_object);
  stlp_std::map<unsigned int,vostok::math::float4x4,stlp_std::less<unsigned int>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::math::float4x4>>>::find<unsigned int>(
    (stlp_std::map<unsigned int,vostok::math::float4x4,stlp_std::less<unsigned int>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::math::float4x4> > > *)this,
    (stlp_std::priv::_Rb_tree_iterator<stlp_std::pair<unsigned int const ,vostok::math::float4x4>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::math::float4x4> > > *)&id,
    v3,
    &result,
    v6);
  if ( id != v3 )
  {
    v4 = stlp_std::priv::_Rb_global<bool>::_Rebalance_for_erase(id, &v3->_M_parent, &v3->_M_left, &v3->_M_right);
    vostok::memory::doug_lea_allocator::free_impl(
      v5,
      (int)vostok::render::g_allocator,
      (char *)&v4->_M_color,
      v7,
      v8,
      v9);
    --*(_DWORD *)&v3[1]._M_color;
  }
}
