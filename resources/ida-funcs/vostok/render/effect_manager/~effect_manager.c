void __thiscall vostok::render::effect_manager::~effect_manager(vostok::render::effect_manager *this, int a2)
{
  stlp_std::priv::_Rb_tree_node_base *i; // esi
  stlp_std::priv::_Rb_tree_node_base *j; // esi
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v4; // ecx
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v5; // ecx
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v6; // ecx
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v7; // edi
  vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **v8; // esi
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v9; // ecx
  stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *v10; // ecx
  int v11; // eax
  const char *v12; // [esp+0h] [ebp-10h]
  const char *v13; // [esp+4h] [ebp-Ch]
  unsigned int v14; // [esp+8h] [ebp-8h]

  for ( i = *(stlp_std::priv::_Rb_tree_node_base **)((char *)&loc_44770 + a2);
        i != (stlp_std::priv::_Rb_tree_node_base *)((char *)&loc_44768 + a2);
        i = stlp_std::priv::_Rb_global<bool>::_M_increment(i) )
  {
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
      vostok::render::g_allocator,
      (vostok::ai::fsm_state **)&i[9]._M_right,
      v12,
      v13,
      v14);
  }
  for ( j = *(stlp_std::priv::_Rb_tree_node_base **)(a2 + 280456);
        j != (stlp_std::priv::_Rb_tree_node_base *)(a2 + 280448);
        j = stlp_std::priv::_Rb_global<bool>::_M_increment(j) )
  {
    vostok::memory::delete_helper<vostok::memory::doug_lea_allocator,vostok::render::scene_view>(
      vostok::render::g_allocator,
      (vostok::ai::fsm_state **)&j[9]._M_right,
      v12,
      v13,
      v14);
  }
  v4 = *(stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > **)((char *)&loc_4479C + a2);
  *(_DWORD *)((char *)&loc_4479C + a2 + 4) = v4;
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    v4,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)(a2 + 280448));
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    v5,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)((char *)&loc_44768 + a2));
  v7 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 18268);
  v8 = (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 18272);
  while ( v7 != *v8 )
  {
    vostok::intrusive_ptr<survarium::weapon_user_animations_container,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(v7 + 1);
    v7 += 8;
  }
  *v8 = *(vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> **)(a2 + 18268);
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    v6,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)(a2 + 18244));
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    v9,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)(a2 + 18220));
  stlp_std::priv::_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>::~_Rb_tree<vostok::fixed_string<128>,stlp_std::less<vostok::fixed_string<128>>,stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>,stlp_std::priv::_Select1st<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,stlp_std::priv::_MapTraitsT<stlp_std::pair<vostok::fixed_string<128> const,vostok::render::effect_descriptor *>>,vostok::render::std_allocator<stlp_std::pair<vostok::fixed_string<128>,vostok::render::effect_descriptor *>>>(
    v10,
    (stlp_std::priv::_Rb_tree<unsigned int,stlp_std::less<unsigned int>,stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters>,stlp_std::priv::_Select1st<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,stlp_std::priv::_MapTraitsT<stlp_std::pair<unsigned int const ,vostok::render::volume_fog_parameters> >,vostok::render::std_allocator<stlp_std::pair<unsigned int,vostok::render::volume_fog_parameters> > > *)(a2 + 18196));
  v11 = *(_DWORD *)(a2 + 4);
  vostok::quasi_singleton<vostok::render::effect_manager>::pinst = 0;
  *(_DWORD *)(a2 + 8) = v11;
}
