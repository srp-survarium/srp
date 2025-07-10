void __thiscall vostok::sound::world_user::remove_sound_scene(
        vostok::sound::world_user *this,
        vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *scene)
{
  vostok::resources::unmanaged_resource *v2; // ecx
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> v3; // [esp-18h] [ebp-9Ch] BYREF
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > > v4; // [esp-14h] [ebp-98h] BYREF
  int v5; // [esp-4h] [ebp-88h]
  vostok::sound::functor_command<vostok::sound::sound_order> *v6; // [esp+0h] [ebp-84h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > > *v7; // [esp+4h] [ebp-80h]
  boost::_bi::bind_t<void,boost::_mfi::mf1<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> >,boost::_bi::list2<boost::_bi::value<vostok::sound::sound_world *>,boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> > > > *result; // [esp+8h] [ebp-7Ch]
  vostok::sound::world_user *thisa; // [esp+Ch] [ebp-78h]
  boost::function0<void> *p_m_next_for_orders; // [esp+18h] [ebp-6Ch]
  vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base> *v11; // [esp+30h] [ebp-54h]
  vostok::sound::sound_order *v12; // [esp+40h] [ebp-44h]
  vostok::memory::base_allocator *m_allocator; // [esp+44h] [ebp-40h]
  int v14; // [esp+48h] [ebp-3Ch]
  void (__thiscall *__ptr64 f)(vostok::sound::sound_world *, vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>); // [esp+4Ch] [ebp-38h]
  boost::function<void __cdecl(void)> v16; // [esp+5Ch] [ebp-28h] BYREF
  vostok::sound::sound_order *v17; // [esp+7Ch] [ebp-8h]
  vostok::sound::functor_command<vostok::sound::sound_order> *order; // [esp+80h] [ebp-4h]

  thisa = this;
  v14 = 0;
  m_allocator = this->m_allocator;
  v12 = (vostok::sound::sound_order *)vostok::memory::base_allocator::malloc_impl(m_allocator, 0x30u);
  v17 = v12;
  if ( v12 )
  {
    LODWORD(f) = vostok::sound::sound_world::remove_sound_scene_impl;
    HIDWORD(f) = 0;
    v5 = 0;
    result = &v4;
    v3.m_object = v2;
    v11 = &v3;
    boost::_bi::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
      &v3,
      scene);
    v7 = boost::bind<void,vostok::sound::sound_world,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>,vostok::sound::sound_world *,vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>>(
           result,
           f,
           thisa->m_owner_world,
           v3);
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>(&v16, v4, v5);
    v14 |= 1u;
    vostok::sound::sound_order::sound_order(v17);
    v17->__vftable = (vostok::sound::sound_order_vtbl *)&vostok::sound::functor_command<vostok::sound::sound_order>::`vftable';
    p_m_next_for_orders = (boost::function0<void> *)&v17[1].m_next_for_orders;
    v17[1].m_next_for_orders = 0;
    boost::function0<void>::assign_to_own(p_m_next_for_orders, &v16);
    v6 = (vostok::sound::functor_command<vostok::sound::sound_order> *)v17;
  }
  else
  {
    v6 = 0;
  }
  order = v6;
  if ( (v14 & 1) != 0 )
  {
    v14 &= ~1u;
    boost::function<void __cdecl (void)>::~function<void __cdecl (void)>((boost::function9<void,void *,char const *,unsigned int,char const *,char const *,enum vostok::logging::verbosity,char const *,unsigned int,enum vostok::logging::callback_flag> *)&v16);
  }
  vostok::sound::world_user::add_order(thisa, order);
}
