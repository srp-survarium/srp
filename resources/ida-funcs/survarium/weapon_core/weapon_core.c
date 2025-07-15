void __thiscall survarium::weapon_core::weapon_core(survarium::weapon_core *this, int a2)
{
  float v2; // xmm1_4
  survarium::breath_vibration_calculator *v3; // ecx
  vostok::memory::doug_lea_allocator *v4; // esi
  char *v5; // eax
  vostok::memory::doug_lea_allocator *v6; // ecx
  char *v7; // eax
  float v8; // xmm1_4
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  float v10; // xmm1_4
  const char *v11; // [esp+0h] [ebp-40h]
  const char *v12; // [esp+4h] [ebp-3Ch]
  unsigned int v13; // [esp+8h] [ebp-38h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v14; // [esp+10h] [ebp-30h] BYREF
  __int64 v15; // [esp+30h] [ebp-10h]
  __int64 v16; // [esp+38h] [ebp-8h]

  *(_DWORD *)a2 = &survarium::interactive_object::`vftable';
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_BYTE *)(a2 + 12) = -1;
  *(_BYTE *)(a2 + 13) = 1;
  *(_BYTE *)(a2 + 14) = 1;
  survarium::inventory_item::inventory_item((survarium::inventory_item *)this, a2 + 16, inventory_active_item, 1);
  v2 = s_bm_current_air_resistance;
  *(_DWORD *)a2 = &survarium::weapon_core::`vftable'{for `survarium::interactive_object'};
  *(_DWORD *)(a2 + 16) = &survarium::weapon_core::`vftable'{for `survarium::inventory_item'};
  *(_DWORD *)(a2 + 312) = 0;
  *(_DWORD *)(a2 + 320) = 0;
  *(_DWORD *)(a2 + 324) = 0;
  *(_DWORD *)(a2 + 328) = 0;
  *(_DWORD *)(a2 + 336) = 0;
  *(float *)(a2 + 376) = FLOAT_0_25;
  *(_DWORD *)(a2 + 372) = 0;
  *(_DWORD *)(a2 + 368) = a2;
  *(_DWORD *)(a2 + 380) = 0;
  *(_DWORD *)(a2 + 384) = 0;
  *(_DWORD *)(a2 + 388) = 0;
  *(float *)(a2 + 392) = v2;
  *(float *)(a2 + 396) = v2;
  *(_DWORD *)(a2 + 400) = 0;
  survarium::breath_vibration_calculator::initialize_logic(v3, (survarium::breath_vibration_calculator *)(a2 + 312));
  v4 = survarium::g_allocator;
  v5 = type_info::raw_name(&vostok::ai::fsm `RTTI Type Descriptor');
  v7 = vostok::memory::doug_lea_allocator::malloc_impl(v6, (int)v4, 0x38u, v5, v11, v12, v13);
  if ( v7 )
  {
    *(_DWORD *)v7 = 0;
    *((_DWORD *)v7 + 2) = 0;
    *((_DWORD *)v7 + 3) = 0;
    *((_DWORD *)v7 + 4) = 0;
    *((_DWORD *)v7 + 6) = 0;
  }
  else
  {
    v7 = 0;
  }
  *(_DWORD *)(a2 + 408) = v7;
  v8 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 412) = a2 + 424;
  *(_DWORD *)(a2 + 416) = a2 + 424;
  *(_DWORD *)(a2 + 420) = a2 + 460;
  *(_DWORD *)(a2 + 588) = 0;
  *(_DWORD *)(a2 + 592) = 0;
  *(_DWORD *)(a2 + 596) = 0;
  *(float *)(a2 + 600) = v8;
  *(_DWORD *)(a2 + 604) = 0;
  *(_DWORD *)(a2 + 608) = 0;
  *(_DWORD *)(a2 + 612) = 0;
  *(_DWORD *)(a2 + 616) = 0;
  *(_DWORD *)(a2 + 620) = 0;
  *(_DWORD *)(a2 + 624) = -1;
  *(_DWORD *)(a2 + 628) = -1;
  *(_DWORD *)(a2 + 632) = -1;
  *(_DWORD *)(a2 + 636) = 0;
  *(float *)(a2 + 640) = v8;
  *(float *)(a2 + 644) = v8;
  *(float *)(a2 + 648) = v8;
  *(float *)(a2 + 652) = v8;
  *(_DWORD *)(a2 + 656) = -1;
  *(_DWORD *)(a2 + 660) = 0;
  *(_DWORD *)(a2 + 664) = a2;
  *(_DWORD *)(a2 + 668) = 0;
  *(_DWORD *)(a2 + 672) = 0;
  *(_DWORD *)(a2 + 676) = 0;
  *(_DWORD *)(a2 + 680) = 0;
  *(_DWORD *)(a2 + 684) = 0;
  *(_DWORD *)(a2 + 688) = 0;
  *(_DWORD *)(a2 + 692) = -1;
  *(_DWORD *)(a2 + 696) = 0;
  *(_DWORD *)(a2 + 700) = 0;
  *(_DWORD *)(a2 + 704) = 0;
  *(_DWORD *)(a2 + 708) = 0;
  *(_DWORD *)(a2 + 712) = -1;
  *(float *)(a2 + 716) = v8;
  *(_DWORD *)(a2 + 720) = 0;
  *(_DWORD *)(a2 + 724) = 0;
  *(_DWORD *)(a2 + 728) = 0;
  *(_DWORD *)(a2 + 732) = 0;
  *(_DWORD *)(a2 + 736) = 0;
  *(_DWORD *)(a2 + 740) = 0;
  *(_DWORD *)(a2 + 744) = 0;
  *(_DWORD *)(a2 + 748) = 0;
  *(_DWORD *)(a2 + 752) = 0;
  *(_DWORD *)(a2 + 756) = 0;
  *(_DWORD *)(a2 + 760) = 0;
  *(_DWORD *)(a2 + 764) = 0;
  *(_DWORD *)(a2 + 768) = 0;
  *(_DWORD *)(a2 + 772) = 0;
  *(_DWORD *)(a2 + 776) = 0;
  *(_DWORD *)(a2 + 780) = 0;
  *(_DWORD *)(a2 + 784) = 0;
  *(_DWORD *)(a2 + 788) = 0;
  *(_DWORD *)(a2 + 792) = 0;
  *(_DWORD *)(a2 + 796) = 0;
  *(_DWORD *)(a2 + 800) = 0;
  *(_DWORD *)(a2 + 804) = 0;
  *(_DWORD *)(a2 + 808) = 0;
  *(_DWORD *)(a2 + 812) = 0;
  *(_DWORD *)(a2 + 816) = 0;
  *(_DWORD *)(a2 + 820) = 0;
  *(_DWORD *)(a2 + 824) = 0;
  *(_DWORD *)(a2 + 828) = 0;
  *(float *)(a2 + 832) = v8;
  *(float *)(a2 + 836) = v8;
  *(float *)(a2 + 840) = v8;
  *(float *)(a2 + 844) = v8;
  *(float *)(a2 + 848) = v8;
  *(float *)(a2 + 852) = v8;
  *(float *)(a2 + 856) = retry_to_increase_quality_period_sec;
  *(float *)(a2 + 860) = FLOAT_0_02;
  *(float *)(a2 + 864) = FLOAT_0_0099999998;
  *(float *)(a2 + 868) = FLOAT_10_0;
  memset((void *)(a2 + 872), 0, 0x60u);
  *(_DWORD *)(a2 + 968) = 0;
  *(_DWORD *)(a2 + 972) = 0;
  *(_DWORD *)(a2 + 976) = 0;
  *(_DWORD *)(a2 + 980) = 0;
  *(_DWORD *)(a2 + 984) = 0;
  vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base>(
    (vostok::resources::resource_ptr<survarium::weapon_core_base_state,vostok::resources::unmanaged_intrusive_base> *)(a2 + 988),
    0);
  (&v14.vtable)[1] = 0;
  v14.vtable = (boost::detail::function::vtable_base *) __thiscall survarium::weapon_core::`vcall'{160,{flat}};
  v14.functor.obj_ptr = (void *)a2;
  LODWORD(v15) =  __thiscall survarium::weapon_core::`vcall'{160,{flat}};
  HIDWORD(v15) = 0;
  LODWORD(v16) = a2;
  *(_DWORD *)(a2 + 992) = 0;
  HIDWORD(v16) = v14.functor.vostok_pointer_size_alignment[1];
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    v14.vtable = 0;
  }
  else
  {
    *(_QWORD *)&v14.functor.obj_ptr = v15;
    *((_QWORD *)&v14.functor.data + 1) = v16;
    v14.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,survarium::weapon_core>,boost::_bi::list1<boost::_bi::value<survarium::weapon_core *>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    &v14,
    (const boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)(a2 + 1000));
  *(_DWORD *)(a2 + 1032) = 0;
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&v14);
  *(_DWORD *)(a2 + 1040) = -1;
  *(_DWORD *)(a2 + 1044) = 0;
  *(_BYTE *)(a2 + 1048) = 0;
  *(_BYTE *)(a2 + 1049) = 0;
  *(_DWORD *)(a2 + 1060) = 1;
  *(float *)(a2 + 1068) = pi_x2_13;
  *(_DWORD *)(a2 + 1064) = 0;
  v10 = s_bm_current_air_resistance;
  *(_DWORD *)(a2 + 1072) = 0;
  *(float *)(a2 + 1076) = v10;
  *(_DWORD *)(a2 + 1080) = 0;
  *(_DWORD *)(a2 + 1084) = 0;
  *(_DWORD *)(a2 + 1088) = 0;
  *(_BYTE *)(a2 + 1092) = 0;
  *(_WORD *)(a2 + 1100) = 0;
  *(_WORD *)(a2 + 1102) = 0;
  *(_WORD *)(a2 + 1104) = 0;
  *(_BYTE *)(a2 + 1106) = 0;
  *(_BYTE *)(a2 + 1107) = 0;
  *(_BYTE *)(a2 + 1108) = 0;
  *(_BYTE *)(a2 + 1110) = 0;
  *(_BYTE *)(a2 + 1111) = 0;
  *(_BYTE *)(a2 + 1112) = 0;
  *(_BYTE *)(a2 + 1113) = 0;
  *(_BYTE *)(a2 + 1114) = 0;
  *(_BYTE *)(a2 + 1115) = 0;
  *(_BYTE *)(a2 + 1116) = 0;
  *(_DWORD *)(a2 + 1096) = 0;
  *(_BYTE *)(a2 + 1109) = 1;
  *(_DWORD *)(a2 + 1140) = -1;
  *(_DWORD *)(a2 + 1124) = 0;
  *(_DWORD *)(a2 + 1128) = 0;
  *(_DWORD *)(a2 + 1132) = 0;
  *(_DWORD *)(a2 + 1136) = 0;
  *(_DWORD *)(a2 + 1148) = 0;
  *(_DWORD *)(a2 + 1144) = 0;
}
