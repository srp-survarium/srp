stlp_std::priv::_Rb_tree_node_base *__userpurge vostok::render::effect_manager::get_effect_descriptor_by_name@<eax>(
        vostok::render::effect_manager *this@<ecx>,
        int a2@<eax>,
        const char *name)
{
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *v3; // esi
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *v4; // eax

  v3 = (stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *)(a2 + 108);
  v4 = stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::_M_find<char const *>(
         (char **)&name,
         (stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *)(a2 + 108));
  if ( v4 == v3 )
    return 0;
  else
    return v4[6]._M_header._M_data._M_right;
}
