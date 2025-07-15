void __thiscall vostok::sound::world_user::set_time_scale_factor(vostok::sound::world_user *this, float factor)
{
  vostok::sound::sound_order *v2; // [esp+4h] [ebp-ACh]
  boost::function0<void> *p_m_next_for_orders; // [esp+14h] [ebp-9Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > v5; // [esp+18h] [ebp-98h]
  char v6; // [esp+64h] [ebp-4Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,float>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<float> > > result; // [esp+68h] [ebp-48h] BYREF
  void (__thiscall *f)(vostok::sound::sound_world *, float); // [esp+78h] [ebp-38h]
  int f_4; // [esp+7Ch] [ebp-34h]
  boost::function0<void> v10; // [esp+80h] [ebp-30h] BYREF
  vostok::sound::sound_order *v11; // [esp+A4h] [ebp-Ch]
  char v12; // [esp+ABh] [ebp-5h]
  vostok::sound::sound_order *order; // [esp+ACh] [ebp-4h]

  v6 = 0;
  v12 = 0;
  v11 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(this->m_allocator, 0x30u);
  if ( v11 )
  {
    f = vostok::sound::sound_world::set_time_scale_factor;
    f_4 = 0;
    v5 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)boost::bind<void,vostok::sound::sound_world,float,vostok::sound::sound_world *,float>(&result, (void (__thiscall *__ptr64)(vostok::sound::sound_world *, float))(unsigned int)vostok::sound::sound_world::set_time_scale_factor, this->m_owner_world, factor);
    v10.vtable = 0;
    if ( boost::detail::function::basic_vtable1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
           (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,float>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<float>>>>'::`2'::stored_vtable,
           v5,
           &v10.functor) )
    {
      v10.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,float>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<float>>>>'::`2'::stored_vtable.base.manager
                                                          + 1);
    }
    else
    {
      v10.vtable = 0;
    }
    v6 = 1;
    vostok::sound::sound_order::sound_order(v11);
    v11->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
    p_m_next_for_orders = (boost::function0<void> *)&v11[1].m_next_for_orders;
    v11[1].m_next_for_orders = 0;
    boost::function0<void>::assign_to_own(p_m_next_for_orders, &v10);
    v2 = v11;
  }
  else
  {
    v2 = 0;
  }
  order = v2;
  if ( (v6 & 1) != 0 )
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v10);
  vostok::sound::world_user::add_order(this, order);
}
