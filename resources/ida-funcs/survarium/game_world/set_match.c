void __usercall survarium::game_world::set_match(
        survarium::game_world *this@<ecx>,
        vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *a2@<eax>)
{
  boost::function<void __cdecl(unsigned int)> v3; // [esp-24h] [ebp-54h] BYREF
  int v4; // [esp-4h] [ebp-34h]
  boost::detail::function::vtable_base **v5; // [esp+Ch] [ebp-24h]
  void (__thiscall *v6)(survarium::game_world *, unsigned int); // [esp+10h] [ebp-20h]
  int v7; // [esp+14h] [ebp-1Ch]
  vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *v8; // [esp+18h] [ebp-18h]
  unsigned int v9; // [esp+1Ch] [ebp-14h]
  __int64 v10; // [esp+20h] [ebp-10h] BYREF
  unsigned __int64 v11; // [esp+28h] [ebp-8h]

  v5 = (boost::detail::function::vtable_base **)&a2[3401];
  vostok::resources::resource_ptr<vostok::physics::bt_collision_shape,vostok::resources::unmanaged_intrusive_base>::operator=(
    (const vostok::resources::resource_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base> *)this,
    a2 + 3401);
  v8 = a2;
  v7 = 0;
  v6 = survarium::game_world::on_resync;
  LODWORD(v10) = survarium::game_world::on_resync;
  HIDWORD(v10) = 0;
  v11 = __PAIR64__(v9, (unsigned int)a2);
  v3.vtable = (boost::detail::function::vtable_base *)&v10;
  (&v3.vtable)[1] = 0;
  if ( Scaleform::Render::RenderEvent::GetListenerStatus(0) )
  {
    (&v3.vtable)[1] = 0;
  }
  else
  {
    if ( &(&v3.vtable)[1] != (boost::detail::function::vtable_base **)-8 )
    {
      *(_QWORD *)((char *)&v3.functor.bound_memfunc_ptr.memfunc_ptr + 4) = v10;
      *(_QWORD *)(&v3.functor.data + 12) = v11;
    }
    (&v3.vtable)[1] = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,unsigned int>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf1<void,survarium::game_world,unsigned int>,boost::_bi::list2<boost::_bi::value<survarium::game_world *>,boost::arg<1>>>>'::`2'::stored_vtable
                                                             + 1);
  }
  v3.vtable = *v5;
  survarium::pvp_match_core::set_on_resync_callback((survarium::pvp_match_core *)&v10, v3, v4);
}
