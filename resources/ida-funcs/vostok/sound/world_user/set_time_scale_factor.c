void __thiscall vostok::sound::world_user::set_time_scale_factor(
        vostok::sound::world_user *this,
        float factor,
        boost::function<void __cdecl(void)> *a3)
{
  __int32 v3; // edi
  int v4; // esi
  char *v5; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v6; // ecx
  __int32 v7; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,float>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<float> > > v8; // [esp-10h] [ebp-5Ch]
  char v9; // [esp+14h] [ebp-38h]
  vostok::sound::functor_command<vostok::sound::sound_order> *v10; // [esp+18h] [ebp-34h]
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> f; // [esp+2Ch] [ebp-20h] BYREF

  v3 = 0;
  v9 = 0;
  v4 = *(_DWORD *)(LODWORD(factor) + 284);
  v5 = type_info::raw_name(&vostok::sound::functor_command<vostok::sound::sound_order> `RTTI Type Descriptor');
  v10 = (vostok::sound::functor_command<vostok::sound::sound_order> *)(*(int (__thiscall **)(int, int, char *, const char *, const char *, int))(*(_DWORD *)v4 + 16))(
                                                                        v4,
                                                                        48,
                                                                        v5,
                                                                        "vostok::sound::world_user::set_time_scale_factor",
                                                                        ".\\world_user.cpp",
                                                                        318);
  if ( v10 )
  {
    HIDWORD(v8.f_.f_) = vostok::sound::sound_world::set_time_scale_factor;
    v8.l_.a1_.t_ = 0;
    v8.l_.a2_.t_ = *(float *)(LODWORD(factor) + 280);
    LODWORD(v8.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(a3, v8, (int)a3);
    v9 = 1;
    vostok::sound::functor_command<vostok::sound::sound_order>::functor_command<vostok::sound::sound_order>(
      v10,
      *(vostok::memory::base_allocator **)(LODWORD(factor) + 284),
      &f);
    v3 = v7;
  }
  if ( (v9 & 1) != 0 )
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v6,
      (int *)&f);
  *(_DWORD *)(v3 + 8) = 0;
  _InterlockedExchange((volatile __int32 *)(*(_DWORD *)(LODWORD(factor) + 136) + 8), v3);
  *(_DWORD *)(LODWORD(factor) + 136) = v3;
}
