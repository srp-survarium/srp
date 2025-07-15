void __thiscall vostok::sound::sound_producer::~sound_producer(vostok::sound::sound_producer *this)
{
  vostok::sound::functor_command<vostok::sound::sound_order> *v1; // [esp+0h] [ebp-C4h]
  boost::function0<void> *p_m_next_for_orders; // [esp+10h] [ebp-B4h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > v4; // [esp+14h] [ebp-B0h]
  vostok::memory::base_allocator *allocator; // [esp+74h] [ebp-50h]
  char v6; // [esp+80h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64> > > result; // [esp+84h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+9Ch] [ebp-28h] BYREF
  vostok::sound::sound_order *v9; // [esp+BCh] [ebp-8h]
  vostok::sound::functor_command<vostok::sound::sound_order> *order; // [esp+C0h] [ebp-4h]

  v6 = 0;
  this->__vftable = (vostok::sound::sound_producer_vtbl *)&vostok::sound::sound_producer::`vftable';
  if ( this->m_world_user && !this->m_world_user->m_owner_world->m_is_destroying )
  {
    vostok::sound::world_user::mark_producer_as_deleted(this->m_world_user, (int)this);
    allocator = vostok::sound::world_user::get_allocator(this->m_world_user);
    v9 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(allocator, 0x30u);
    if ( v9 )
    {
      v4 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > *)boost::bind<void,vostok::sound::world_user,unsigned __int64,vostok::sound::world_user *,unsigned __int64>(&result, vostok::sound::world_user::on_producer_deleted, this->m_world_user, (int)this);
      f.vtable = 0;
      if ( boost::detail::function::basic_vtable0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64>>>>(
             &`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64>>>>'::`2'::stored_vtable,
             v4,
             &f.functor) )
      {
        f.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64>>>>'::`2'::stored_vtable.base.manager
                                                          + 1);
      }
      else
      {
        f.vtable = 0;
      }
      v6 = 1;
      vostok::sound::sound_order::sound_order(v9);
      v9->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
      p_m_next_for_orders = (boost::function0<void> *)&v9[1].m_next_for_orders;
      v9[1].m_next_for_orders = 0;
      boost::function0<void>::assign_to_own(p_m_next_for_orders, &f);
      v1 = (vostok::sound::functor_command<vostok::sound::sound_order> *)v9;
    }
    else
    {
      v1 = 0;
    }
    order = v1;
    if ( (v6 & 1) != 0 )
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
    vostok::sound::world_user::add_order(this->m_world_user, order);
  }
}
