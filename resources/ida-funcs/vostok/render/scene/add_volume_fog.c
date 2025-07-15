void __fastcall vostok::render::scene::add_volume_fog(
        int a1,
        const vostok::render::volume_fog_parameters *in_parameters,
        vostok::render::scene *this,
        unsigned int id)
{
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v4; // ecx
  stlp_std::priv::_Rb_tree_node_base v5; // [esp-4h] [ebp-17Ch] BYREF
  unsigned int v6; // [esp+10h] [ebp-168h]
  vostok::render::volume_fog_parameters v7; // [esp+14h] [ebp-164h] BYREF
  stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> __val; // [esp+88h] [ebp-F0h] BYREF
  vostok::render::volume_fog_parameters v9; // [esp+100h] [ebp-78h] BYREF

  vostok::render::volume_fog_parameters::volume_fog_parameters(&v9, in_parameters);
  v6 = id;
  vostok::render::volume_fog_parameters::volume_fog_parameters(&v7, &v9);
  __val.first = id;
  vostok::render::volume_fog_parameters::volume_fog_parameters(&__val.second, &v7);
  *(_DWORD *)&v5._M_color = &__val;
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const,vostok::render::volume_fog_parameters>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const,vostok::render::volume_fog_parameters>>,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters>>>::insert_unique(
    v4,
    (int)&v5._M_right,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)((char *)survarium::weapon_user_animations_selector::stand_from_crouch_predicate + (_DWORD)this),
    v5);
}
