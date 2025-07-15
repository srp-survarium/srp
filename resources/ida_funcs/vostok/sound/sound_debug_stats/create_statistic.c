void __thiscall vostok::sound::sound_debug_stats::create_statistic(vostok::sound::sound_debug_stats *this)
{
  vostok::sound::sound_response *v1; // [esp+0h] [ebp-84h]
  boost::function0<void> *v3; // [esp+10h] [ebp-74h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > f; // [esp+14h] [ebp-70h]
  char v5; // [esp+48h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+4Ch] [ebp-38h] BYREF
  boost::function0<void> v7; // [esp+54h] [ebp-30h] BYREF
  vostok::sound::sound_response *v8; // [esp+78h] [ebp-Ch]
  char v9; // [esp+7Eh] [ebp-6h]
  char v10; // [esp+7Fh] [ebp-5h]
  vostok::sound::sound_response *response; // [esp+80h] [ebp-4h]

  v5 = 0;
  v10 = 0;
  v9 = 0;
  this->m_statistic[0] = vostok::sound::sound_scene::create_statistic(this->m_scene);
  this->m_statistic[1] = vostok::sound::sound_scene::create_statistic(this->m_scene);
  _InterlockedExchange(&this->m_actual_statistic, 0);
  v8 = (vostok::sound::sound_response *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                          0x28u);
  if ( v8 )
  {
    f = *boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
           (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
           vostok::sound::sound_debug_stats::on_statistic_updated,
           this);
    v7.vtable = 0;
    if ( boost::detail::function::basic_vtable0<void>::assign_to<boost::_bi::bind_t<boost::_bi::unspecified,boost::reference_wrapper<boost::function<void __cdecl (vostok::sound::create_sound_propagator_params const &)> const>,boost::_bi::list1<boost::reference_wrapper<vostok::sound::create_sound_propagator_params const>>>>(
           &`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *>>>>'::`2'::stored_vtable,
           (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > >)f,
           &v7.functor) )
    {
      v7.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *>>>>'::`2'::stored_vtable.base.manager
                                                         + 1);
    }
    else
    {
      v7.vtable = 0;
    }
    v5 = 1;
    vostok::sound::sound_response::sound_response(v8);
    v8->__vftable = (vostok::sound::sound_response_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_response>::`vftable';
    v3 = (boost::function0<void> *)&v8[1];
    v8[1].__vftable = 0;
    boost::function0<void>::assign_to_own(v3, &v7);
    v1 = v8;
  }
  else
  {
    v1 = 0;
  }
  response = v1;
  if ( (v5 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v7);
  vostok::sound::world_user::add_response(this->m_world_user, response);
}
