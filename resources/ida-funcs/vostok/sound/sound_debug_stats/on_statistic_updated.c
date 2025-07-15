void __thiscall vostok::sound::sound_debug_stats::on_statistic_updated(vostok::sound::sound_debug_stats *this)
{
  vostok::sound::sound_order *v1; // [esp+0h] [ebp-7Ch]
  boost::function0<void> *p_m_next_for_orders; // [esp+10h] [ebp-6Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > f; // [esp+14h] [ebp-68h]
  vostok::memory::base_allocator *allocator; // [esp+44h] [ebp-38h]
  char v6; // [esp+48h] [ebp-34h]
  boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > > result; // [esp+4Ch] [ebp-30h] BYREF
  boost::function0<void> v8; // [esp+54h] [ebp-28h] BYREF
  vostok::sound::sound_order *v9; // [esp+74h] [ebp-8h]
  vostok::sound::sound_order *order; // [esp+78h] [ebp-4h]

  v6 = 0;
  if ( this->m_actual_statistic != -1 )
  {
    allocator = vostok::sound::world_user::get_allocator(this->m_world_user);
    v9 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(allocator, 0x30u);
    if ( v9 )
    {
      f = *boost::bind<void,vostok::sound::sound_debug_stats,vostok::sound::sound_debug_stats *>(
             (boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::ai::working_memory,vostok::ai::game_object const &>,boost::_bi::list2<boost::_bi::value<vostok::ai::working_memory *>,boost::arg<1> > > *)&result,
             vostok::sound::sound_debug_stats::update_statistic,
             this);
      v8.vtable = 0;
      if ( boost::detail::function::basic_vtable0<void>::assign_to<boost::_bi::bind_t<boost::_bi::unspecified,boost::reference_wrapper<boost::function<void __cdecl (vostok::sound::create_sound_propagator_params const &)> const>,boost::_bi::list1<boost::reference_wrapper<vostok::sound::create_sound_propagator_params const>>>>(
             &`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *>>>>'::`2'::stored_vtable,
             (boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *> > >)f,
             &v8.functor) )
      {
        v8.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf0<void,vostok::sound::sound_debug_stats>,boost::_bi::list1<boost::_bi::value<vostok::sound::sound_debug_stats *>>>>'::`2'::stored_vtable.base.manager
                                                           + 1);
      }
      else
      {
        v8.vtable = 0;
      }
      v6 = 1;
      vostok::sound::sound_order::sound_order(v9);
      v9->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
      p_m_next_for_orders = (boost::function0<void> *)&v9[1].m_next_for_orders;
      v9[1].m_next_for_orders = 0;
      boost::function0<void>::assign_to_own(p_m_next_for_orders, &v8);
      v1 = v9;
    }
    else
    {
      v1 = 0;
    }
    order = v1;
    if ( (v6 & 1) != 0 )
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v8);
    vostok::sound::world_user::add_order(this->m_world_user, order);
  }
}
