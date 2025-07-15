void __thiscall vostok::network::http_client::create_client_impl(vostok::network::http_client *this)
{
  vostok::memory::doug_lea_allocator *v1; // esi
  char *v3; // eax
  vostok::memory::doug_lea_allocator *v4; // ecx
  char *v5; // eax
  vostok::particle::particle_action *v6; // ecx
  int v7; // eax
  int v8; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v9; // ecx
  const char *v10; // [esp+0h] [ebp-38h]
  const char *v11; // [esp+4h] [ebp-34h]
  unsigned int v12; // [esp+8h] [ebp-30h]
  boost::function<void __cdecl(vostok::network_core::buffer_reader &)> v13; // [esp+18h] [ebp-20h] BYREF

  v1 = vostok::network::g_allocator;
  v3 = type_info::raw_name(&vostok::network_core::http_client `RTTI Type Descriptor');
  v5 = vostok::memory::doug_lea_allocator::malloc_impl(v4, (int)v1, 0x108u, v3, v10, v11, v12);
  if ( v5 )
  {
    vostok::network_core::http_client::http_client(
      (vostok::network_core::http_client *)this->m_world,
      (int)v5,
      this->m_world->m_io_service);
    v8 = v7;
  }
  else
  {
    v8 = 0;
  }
  this->m_client = (vostok::network_core::http_client *)v8;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(v6) )
  {
    v13.vtable = 0;
  }
  else
  {
    v13.functor.obj_ptr = vostok::network::http_client::on_error;
    v13.functor.vostok_pointer_size_alignment[1] = this;
    v13.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,boost::system::error_code>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                        + 1);
  }
  boost::function<void __cdecl (boost::system::error_code)>::operator=(
    &v13,
    (boost::function1<void,vostok::physics::contact_point const &> *)(v8 + 232));
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v9,
    (int *)&v13);
  this->m_busy = 0;
}
