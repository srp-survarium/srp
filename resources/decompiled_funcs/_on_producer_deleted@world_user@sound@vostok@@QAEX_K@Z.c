void __thiscall vostok::sound::world_user::on_producer_deleted(
        vostok::sound::world_user *this,
        unsigned __int64 address)
{
  vostok::sound::functor_command<vostok::sound::sound_response> *v2; // [esp+0h] [ebp-BCh]
  boost::function0<void> *v4; // [esp+10h] [ebp-ACh]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > v5; // [esp+14h] [ebp-A8h]
  char v6; // [esp+78h] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64> > > result; // [esp+7Ch] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+94h] [ebp-28h] BYREF
  vostok::sound::sound_response *v9; // [esp+B4h] [ebp-8h]
  vostok::sound::functor_command<vostok::sound::sound_response> *resp; // [esp+B8h] [ebp-4h]

  v6 = 0;
  v9 = (vostok::sound::sound_response *)vostok::memory::doug_lea_allocator::malloc_impl(
                                          (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                          0x28u);
  if ( v9 )
  {
    v5 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > *)boost::bind<void,vostok::sound::world_user,unsigned __int64,vostok::sound::world_user *,unsigned __int64>(&result, vostok::sound::world_user::unmark_producer_as_deleted, this, address);
    f.vtable = 0;
    if ( boost::detail::function::basic_vtable0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64>>>>(
           &`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64>>>>'::`2'::stored_vtable,
           v5,
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
    vostok::sound::sound_response::sound_response(v9);
    v9->__vftable = (vostok::sound::sound_response_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_response>::`vftable';
    v4 = (boost::function0<void> *)&v9[1];
    v9[1].__vftable = 0;
    boost::function0<void>::assign_to_own(v4, &f);
    v2 = (vostok::sound::functor_command<vostok::sound::sound_response> *)v9;
  }
  else
  {
    v2 = 0;
  }
  resp = v2;
  if ( (v6 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
  vostok::sound::world_user::add_response(this, resp);
}
