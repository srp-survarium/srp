void __thiscall vostok::sound::world_user::on_receiver_deleted(
        vostok::sound::world_user *this,
        unsigned __int64 receiver_address)
{
  vostok::sound::functor_command<vostok::sound::sound_response> *v2; // [esp+0h] [ebp-C0h]
  boost::function0<void> *v4; // [esp+10h] [ebp-B0h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > v5; // [esp+14h] [ebp-ACh]
  __int16 m_is_destroying; // [esp+7Bh] [ebp-45h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::world_user,unsigned __int64>,boost::_bi::list2<boost::_bi::value<vostok::sound::world_user *>,boost::_bi::value<unsigned __int64> > > result; // [esp+80h] [ebp-40h] BYREF
  boost::function0<void> f; // [esp+98h] [ebp-28h] BYREF
  vostok::sound::sound_response *v9; // [esp+B8h] [ebp-8h]
  vostok::sound::functor_command<vostok::sound::sound_response> *resp; // [esp+BCh] [ebp-4h]

  m_is_destroying = this->m_owner_world->m_is_destroying;
  if ( !(_BYTE)m_is_destroying )
  {
    v9 = (vostok::sound::sound_response *)vostok::memory::doug_lea_allocator::malloc_impl(
                                            (vostok::memory::doug_lea_allocator *)vostok::sound::g_allocator.m_object,
                                            0x28u);
    if ( v9 )
    {
      v5 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > *)boost::bind<void,vostok::sound::world_user,unsigned __int64,vostok::sound::world_user *,unsigned __int64>(&result, vostok::sound::world_user::unmark_receiver_as_deleted, this, receiver_address);
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
      HIBYTE(m_is_destroying) |= 1u;
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
    if ( (m_is_destroying & 0x100) != 0 )
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
    vostok::sound::world_user::add_response(this, resp);
  }
}
