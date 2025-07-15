void __usercall vostok::render::texture_storage::~texture_storage(
        vostok::render::texture_storage *this@<ecx>,
        int a2@<eax>)
{
  stlp_std::priv::_Rb_tree_node_base *v2; // ebx
  bool v3; // zf
  stlp_std::priv::_Rb_tree_node_base *M_left; // edi
  stlp_std::priv::_Rb_tree_node_base *M_parent; // esi
  vostok::render::texture_storage *v6; // [esp-4h] [ebp-1Ch]
  const char *v7; // [esp+0h] [ebp-18h]
  const char *v8; // [esp+4h] [ebp-14h]
  unsigned int v9; // [esp+8h] [ebp-10h]
  vostok::memory::doug_lea_allocator *v10; // [esp+Ch] [ebp-Ch]
  stlp_std::priv::_Rb_tree_node_base *i; // [esp+10h] [ebp-8h]
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v12; // [esp+14h] [ebp-4h]

  v2 = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 12);
  v12 = (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)(a2 + 4);
  v3 = v2 == (stlp_std::priv::_Rb_tree_node_base *)(a2 + 4);
  while ( !v3 )
  {
    M_left = v2[2]._M_left;
    v10 = vostok::render::g_allocator;
    if ( M_left )
    {
      M_parent = M_left[6]._M_parent;
      for ( i = M_left[6]._M_left; M_parent != i; M_parent = (stlp_std::priv::_Rb_tree_node_base *)((char *)M_parent + 12) )
      {
        if ( *(_DWORD *)&M_parent->_M_color )
          (*(void (__stdcall **)(_DWORD))(**(_DWORD **)&M_parent->_M_color + 8))(*(_DWORD *)&M_parent->_M_color);
      }
      M_left[6]._M_left = M_left[6]._M_parent;
      vostok::memory::doug_lea_allocator::free_impl(
        (vostok::memory::doug_lea_allocator *)this,
        (int)v10,
        (char *)&M_left->_M_color,
        v7,
        v8,
        v9);
      v2[2]._M_left = 0;
    }
    v2 = stlp_std::priv::_Rb_global<bool>::_M_increment(v2);
    v3 = v2 == (stlp_std::priv::_Rb_tree_node_base *)v12;
    this = v6;
  }
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)this,
    v12);
}
