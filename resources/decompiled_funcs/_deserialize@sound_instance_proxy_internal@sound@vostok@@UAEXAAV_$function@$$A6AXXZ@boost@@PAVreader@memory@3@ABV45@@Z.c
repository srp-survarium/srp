void __thiscall vostok::sound::sound_instance_proxy_internal::deserialize(
        vostok::sound::sound_instance_proxy_internal *this,
        boost::function<void __cdecl(void)> *fn,
        vostok::memory::reader *r,
        const boost::function<void __cdecl(void)> *callback)
{
  boost::function0<void> *v4; // eax
  vostok::sound::sound_instance_proxy_order *v5; // eax
  vostok::sound::sound_instance_proxy_order *v6; // [esp+0h] [ebp-C4h]
  vostok::memory::base_allocator *allocator; // [esp+14h] [ebp-B0h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > v9; // [esp+18h] [ebp-ACh]
  unsigned int v10; // [esp+40h] [ebp-84h] BYREF
  _DWORD destination[2]; // [esp+44h] [ebp-80h] BYREF
  boost::function<void __cdecl(void)> v12; // [esp+4Ch] [ebp-78h] BYREF
  char v13; // [esp+6Dh] [ebp-57h]
  char v14; // [esp+6Eh] [ebp-56h]
  char v15; // [esp+6Fh] [ebp-55h]
  vostok::sound::sound_instance_proxy_order *v16; // [esp+70h] [ebp-54h]
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *> > > result; // [esp+74h] [ebp-50h] BYREF
  void (__thiscall *f)(vostok::sound::sound_world *, vostok::sound::sound_instance_proxy_internal *, vostok::memory::reader *); // [esp+8Ch] [ebp-38h]
  int f_4; // [esp+90h] [ebp-34h]
  vostok::sound::sound_instance_proxy_order *order; // [esp+94h] [ebp-30h]
  unsigned int is_playing_once; // [esp+98h] [ebp-2Ch]
  boost::function<void __cdecl(void)> functor; // [esp+9Ch] [ebp-28h] BYREF
  unsigned int is_callback_pending; // [esp+BCh] [ebp-8h]
  bool is_callback_was_set; // [esp+C3h] [ebp-1h] BYREF

  is_callback_was_set = 0;
  v15 = 0;
  v14 = 0;
  v13 = 0;
  vostok::memory::copy(&is_callback_was_set, 1u, r->m_pointer, 1u);
  ++r->m_pointer;
  if ( is_callback_was_set )
  {
    destination[1] = &this->m_callback;
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&v12, callback);
    boost::function0<void>::swap(v4, &this->m_callback);
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v12);
  }
  vostok::memory::reader::r(r, (unsigned __int8 *)destination, 4u, 4u);
  is_callback_pending = destination[0];
  vostok::memory::reader::r(r, (unsigned __int8 *)&v10, 4u, 4u);
  is_playing_once = v10;
  vostok::memory::copy(&this->m_is_playing, 1u, r->m_pointer, 1u);
  vostok::memory::copy(&this->m_is_producing_paused, 1u, ++r->m_pointer, 1u);
  vostok::memory::copy(&this->m_is_propagating_paused, 1u, ++r->m_pointer, 1u);
  ++r->m_pointer;
  _InterlockedExchange(&this->m_callback_pending, is_callback_pending);
  _InterlockedExchange(&this->m_is_playing_once, is_playing_once);
  f = vostok::sound::sound_world::deserialize_proxy;
  f_4 = 0;
  v9 = *boost::bind<void,vostok::sound::sound_scene,vostok::sound::sound_receiver *,vostok::sound::atomic_half3 *,vostok::sound::sound_scene *,vostok::sound::sound_receiver *,vostok::sound::atomic_half3 *>(
          &result,
          (void (__thiscall *__ptr64)(vostok::sound::sound_world *, vostok::sound::sound_instance_proxy_internal *, vostok::memory::reader *))(unsigned int)vostok::sound::sound_world::deserialize_proxy,
          this->m_user->m_owner_world,
          this,
          r);
  functor.vtable = 0;
  boost::function0<void>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::sound::sound_world,vostok::sound::sound_instance_proxy_internal *,vostok::memory::reader *>,boost::_bi::list3<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::sound::sound_instance_proxy_internal *>,boost::_bi::value<vostok::memory::reader *>>>>(
    &functor,
    v9);
  allocator = vostok::sound::world_user::get_allocator(this->m_user);
  v16 = (vostok::sound::sound_instance_proxy_order *)vostok::memory::base_allocator::malloc_impl(allocator, 0x38u);
  if ( v16 )
  {
    vostok::sound::sound_instance_proxy_order::sound_instance_proxy_order(v16, this->m_user, this, &functor);
    v6 = v5;
  }
  else
  {
    v6 = 0;
  }
  order = v6;
  vostok::sound::world_user::add_order(this->m_user, v6);
  boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&functor);
}
