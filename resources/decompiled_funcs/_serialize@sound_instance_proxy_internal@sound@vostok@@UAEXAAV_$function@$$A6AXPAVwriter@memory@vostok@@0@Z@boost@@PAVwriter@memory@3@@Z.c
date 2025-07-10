void __thiscall vostok::sound::sound_instance_proxy_internal::serialize(
        vostok::sound::sound_instance_proxy_internal *this,
        boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> *fn,
        vostok::memory::writer *writer)
{
  vostok::sound::sound_order *v3; // eax
  boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> v4; // [esp-60h] [ebp-ECh] BYREF
  vostok::memory::writer *v5; // [esp-40h] [ebp-CCh]
  boost::_bi::bind_t<void,boost::_mfi::cmf3<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> >,boost::_bi::value<vostok::memory::writer *> > > v6; // [esp-3Ch] [ebp-C8h] BYREF
  int v7; // [esp-4h] [ebp-90h]
  vostok::sound::sound_instance_proxy_order *v8; // [esp+0h] [ebp-8Ch]
  boost::_bi::bind_t<void,boost::_mfi::cmf3<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> >,boost::_bi::value<vostok::memory::writer *> > > *v9; // [esp+4h] [ebp-88h]
  boost::_bi::bind_t<void,boost::_mfi::cmf3<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *>,boost::_bi::list4<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> >,boost::_bi::value<vostok::memory::writer *> > > *result; // [esp+8h] [ebp-84h]
  vostok::sound::sound_instance_proxy_internal *thisa; // [esp+Ch] [ebp-80h]
  vostok::sound::sound_instance_proxy_order *v12; // [esp+18h] [ebp-74h]
  vostok::memory::base_allocator *allocator; // [esp+1Ch] [ebp-70h]
  vostok::sound::sound_world *a1; // [esp+2Ch] [ebp-60h]
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v15; // [esp+30h] [ebp-5Ch]
  unsigned int v16; // [esp+34h] [ebp-58h] BYREF
  unsigned int v17; // [esp+38h] [ebp-54h] BYREF
  __int64 m_propagator_emitter; // [esp+3Ch] [ebp-50h] BYREF
  vostok::sound::sound_instance_proxy_order *v19; // [esp+44h] [ebp-48h]
  void (__thiscall *__ptr64 f)(vostok::sound::sound_world *, vostok::sound::sound_instance_proxy_internal *, boost::function<void __cdecl(vostok::memory::writer *,vostok::memory::writer *)> *, vostok::memory::writer *); // [esp+48h] [ebp-44h]
  vostok::sound::sound_instance_proxy_order *order; // [esp+58h] [ebp-34h]
  bool is_callback_empty; // [esp+5Fh] [ebp-2Dh] BYREF
  unsigned int is_playing_once; // [esp+60h] [ebp-2Ch]
  boost::function<void __cdecl(void)> functor; // [esp+64h] [ebp-28h] BYREF
  unsigned int is_callback_pending; // [esp+88h] [ebp-4h]

  thisa = this;
  m_propagator_emitter = (int)this->m_propagator_emitter;
  writer->write(writer, &m_propagator_emitter, 8u);
  is_callback_empty = thisa->m_callback.vtable == 0;
  writer->write(writer, &is_callback_empty, 1u);
  is_callback_pending = thisa->m_callback_pending;
  v17 = is_callback_pending;
  writer->write(writer, &v17, 4u);
  is_playing_once = thisa->m_is_playing_once;
  v16 = is_playing_once;
  writer->write(writer, &v16, 4u);
  writer->write(writer, &thisa->m_is_playing, 1u);
  writer->write(writer, &thisa->m_is_producing_paused, 1u);
  writer->write(writer, &thisa->m_is_propagating_paused, 1u);
  LODWORD(f) = vostok::sound::sound_world::serialize_proxy;
  HIDWORD(f) = 0;
  v7 = 0;
  result = &v6;
  v5 = writer;
  v15 = (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&v4;
  v4.vtable = 0;
  boost::function1<void,vostok::sound::create_sound_propagator_params const &>::assign_to_own(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)&v4,
    (const boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)fn);
  a1 = thisa->m_user->m_owner_world;
  v9 = boost::bind<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,boost::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)> &,vostok::memory::writer *,vostok::sound::sound_world *,vostok::sound::sound_instance_proxy_internal *,boost::function<void __cdecl (vostok::memory::writer *,vostok::memory::writer *)>,vostok::memory::writer *>(
         result,
         f,
         a1,
         thisa,
         v4,
         v5);
  boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&functor, v6, v7);
  allocator = vostok::sound::world_user::get_allocator(thisa->m_user);
  v12 = (vostok::sound::sound_instance_proxy_order *)vostok::memory::base_allocator::malloc_impl(allocator, 0x38u);
  v19 = v12;
  if ( v12 )
  {
    vostok::sound::sound_instance_proxy_order::sound_instance_proxy_order(v19, thisa->m_user, thisa, &functor);
    v8 = (vostok::sound::sound_instance_proxy_order *)v3;
  }
  else
  {
    v8 = 0;
  }
  order = v8;
  vostok::sound::world_user::add_order(thisa->m_user, v8);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&functor);
}
