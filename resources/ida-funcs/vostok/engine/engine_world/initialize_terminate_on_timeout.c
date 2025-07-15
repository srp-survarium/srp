void __thiscall vostok::engine::engine_world::initialize_terminate_on_timeout(
        vostok::engine::engine_world *this,
        boost::function<void __cdecl(void)> *a2)
{
  void *v2; // ecx
  unsigned int v3; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v4; // ecx
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::engine::engine_world,float>,boost::_bi::list2<boost::_bi::value<vostok::engine::engine_world *>,boost::_bi::value<float> > > v5; // [esp-14h] [ebp-48h]
  boost::function<void __cdecl(void)> f; // [esp+8h] [ebp-2Ch] BYREF
  unsigned int out_value; // [esp+2Ch] [ebp-8h] BYREF

  if ( vostok::command_line::key::is_set_as_number(
         (vostok::command_line::key *)this,
         (int)&s_terminate_on_timeout_key,
         (float *)&out_value) )
  {
    f.functor.vostok_pointer_size_alignment[2] = vostok::engine::engine_world::terminate_on_timeout;
    *((_QWORD *)&f.functor.data + 2) = __PAIR64__(out_value, (unsigned int)a2);
    f.functor.vostok_pointer_size_alignment[3] = 0;
    HIDWORD(v5.f_.f_) = vostok::engine::engine_world::terminate_on_timeout;
    v5.l_.a1_.t_ = 0;
    LODWORD(v5.l_.a2_.t_) = a2;
    LODWORD(v5.f_.f_) = &f;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(a2, v5, out_value);
    v3 = vostok::threading::core_count(v2);
    vostok::threading::spawn(&f, (const char *)&stru_7F9A50, "process termination", 8 % v3, 0);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v4,
      (int *)&f);
  }
}
