void __thiscall vostok::sound::sound_instance_proxy_internal::on_propagators_serialized(
        vostok::sound::sound_instance_proxy_internal *this,
        boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> *fn,
        vostok::memory::writer *sound_thread_writer,
        vostok::memory::writer *w)
{
  vostok::sound::sound_instance_proxy_order *v4; // eax
  vostok::sound::sound_instance_proxy_order *v5; // [esp+0h] [ebp-1A0h]
  vostok::memory::base_allocator *allocator; // [esp+14h] [ebp-18Ch]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > v8; // [esp+18h] [ebp-188h]
  vostok::sound::sound_instance_proxy_order *v9; // [esp+15Ch] [ebp-44h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *> > > result; // [esp+160h] [ebp-40h] BYREF
  void (__thiscall *f)(vostok::sound::sound_world *, vostok::memory::writer *); // [esp+174h] [ebp-2Ch]
  int f_4; // [esp+178h] [ebp-28h]
  vostok::sound::sound_instance_proxy_order *order; // [esp+17Ch] [ebp-24h]
  boost::function<void __cdecl(void)> functor; // [esp+180h] [ebp-20h] BYREF

  boost::function2<void,vostok::memory::writer *,vostok::memory::writer *>::operator()(fn, sound_thread_writer, w);
  f = vostok::sound::sound_world::on_proxy_serialized;
  f_4 = 0;
  v8 = *(boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_environment_cook,vostok::resources::queries_result &,vostok::math::float4x4 *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_environment_cook *>,boost::arg<1>,boost::_bi::value<vostok::math::float4x4 *> > > *)boost::bind<void,vostok::sound::sound_world,vostok::memory::writer *,vostok::sound::sound_world *,vostok::memory::writer *>(&result, (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::memory::writer *))(unsigned int)vostok::sound::sound_world::on_proxy_serialized, this->m_user->m_owner_world, sound_thread_writer);
  functor.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,vostok::sound::create_sound_propagator_params const &>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_scene,vostok::sound::create_sound_propagator_params const &>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_scene *>,boost::arg<1>>>>(
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *>>>>'::`2'::stored_vtable,
         v8,
         &functor.functor) )
  {
    functor.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::memory::writer *>,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::memory::writer *>>>>'::`2'::stored_vtable.base.manager
                                                            + 1);
  }
  else
  {
    functor.vtable = 0;
  }
  allocator = vostok::sound::world_user::get_allocator(this->m_user);
  v9 = (vostok::sound::sound_instance_proxy_order *)vostok::memory::base_allocator::malloc_impl(allocator, 0x38u);
  if ( v9 )
  {
    vostok::sound::sound_instance_proxy_order::sound_instance_proxy_order(v9, this->m_user, this, &functor);
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  order = v5;
  vostok::sound::world_user::add_order(this->m_user, v5);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&functor);
}
