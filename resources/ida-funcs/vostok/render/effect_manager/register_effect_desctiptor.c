void __thiscall vostok::render::effect_manager::register_effect_desctiptor(
        vostok::render::effect_manager *this,
        const char *name,
        vostok::render::effect_descriptor *dectriptor,
        int a4)
{
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128> >,stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const ,vostok::render::effect_descriptor *> >,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *> > > *v4; // ecx
  stlp_std::priv::_Rb_tree_node_base v5[9]; // [esp-4h] [ebp-A8h] BYREF
  int v6; // [esp+94h] [ebp-10h]
  _BYTE v7[12]; // [esp+98h] [ebp-Ch] BYREF

  vostok::fixed_string<128>::fixed_string<128>(
    (vostok::fixed_string<128> *)this,
    (vostok::buffer_string *)&v5[0]._M_right,
    (char *)dectriptor);
  v6 = a4;
  *(_DWORD *)&v5[0]._M_color = &v5[0]._M_right;
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::insert_unique(
    v4,
    (stlp_std::priv::_Rb_tree_node_base *)((char *)&loc_44768 + (_DWORD)name),
    (int)v7,
    v5[0]);
}
