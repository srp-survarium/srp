void __thiscall vostok::network::http_client::on_error(
        vostok::network::http_client *this,
        boost::system::error_code error_code)
{
  vostok::memory::doug_lea_allocator *v2; // eax
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > v4; // [esp+8h] [ebp-8Ch]
  int *_Where; // [esp+4Ch] [ebp-48h]
  char v6; // [esp+58h] [ebp-3Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::_bi::value<boost::system::error_code> > > result; // [esp+5Ch] [ebp-38h] BYREF
  boost::function<void __cdecl(void)> f; // [esp+6Ch] [ebp-28h] BYREF
  vostok::network::response *v9; // [esp+90h] [ebp-4h]

  v6 = 0;
  if ( !vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::operator!((vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&this->m_on_error) )
  {
    survarium::weapon_user_dead_state::finalize((survarium::game_camera *)vostok::network::g_allocator);
    _Where = vostok::memory::doug_lea_allocator::malloc_impl(v2, 0x28u);
    v9 = (vostok::network::response *)operator new(0x28u, _Where);
    if ( v9 )
    {
      v4 = *(boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::weapon_core_cook,vostok::resources::queries_result &>,boost::_bi::list2<boost::_bi::value<survarium::weapon_core_cook *>,boost::arg<1> > > *)boost::bind<void,vostok::network::http_client,boost::system::error_code,vostok::network::http_client *,boost::system::error_code>(&result, vostok::network::http_client::on_error_impl, this, error_code);
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)v4.l_.a1_.t_,
        &f);
      if ( boost::detail::function::basic_vtable2<bool,char const *,enum survarium::hit_affects_type_enum>::assign_to<boost::_bi::bind_t<bool,boost::_mfi::mf2<bool,survarium::artefact_lifebone_core,char const *,enum survarium::hit_affects_type_enum>,boost::_bi::list3<boost::_bi::value<survarium::artefact_lifebone_core *>,boost::arg<1>,boost::arg<2>>>>(
             (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::_bi::value<boost::system::error_code>>>>'::`2'::stored_vtable,
             v4,
             &f.functor) )
      {
        f.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::network::http_client,boost::system::error_code>,boost::_bi::list2<boost::_bi::value<vostok::network::http_client *>,boost::_bi::value<boost::system::error_code>>>>'::`2'::stored_vtable.base.manager
                                                          + 1);
      }
      else
      {
        f.vtable = 0;
      }
      v6 = 1;
      v9->__vftable = (vostok::network::response_vtbl *)&vostok::network::response::`vftable';
      v9->__vftable = (vostok::network::response_vtbl *)&vostok::network::functor_response::`vftable';
      boost::function<void __cdecl (void)>::function<void __cdecl (void)>(
        (boost::function<void __cdecl(void)> *)&v9[1],
        &f);
      vostok::network::network_world::add_response(this->m_world, v9);
    }
    else
    {
      vostok::network::network_world::add_response(this->m_world, 0);
    }
    if ( (v6 & 1) != 0 )
      boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&f);
  }
}
