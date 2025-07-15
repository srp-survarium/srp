boost::function1<void,vostok::physics::contact_point const &> *__thiscall boost::function<unsigned char __cdecl (void const *)>::operator=(
        boost::function<void __cdecl(float)> *this,
        boost::function1<void,vostok::physics::contact_point const &> *f)
{
  boost::detail::function::vtable_base *vtable; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v5; // [esp+8h] [ebp-44h] BYREF
  boost::function1<void,vostok::physics::contact_point const &> v6; // [esp+28h] [ebp-24h] BYREF

  vtable = this->vtable;
  v6.vtable = 0;
  if ( vtable )
  {
    v6.vtable = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
    {
      qmemcpy((void *)&v6.functor, &this->functor, sizeof(v6.functor));
      this = 0;
    }
    else
    {
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &this->functor,
        &v6.functor,
        0);
    }
  }
  if ( f != &v6 )
  {
    v5.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v5,
      &v6);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v6,
      f);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      f,
      &v5);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&v5);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&v6);
  return f;
}


boost::function1<void,vostok::physics::contact_point const &> *__usercall boost::function<void __cdecl (unsigned int,unsigned int)>::operator=@<eax>(
        boost::function<void __cdecl(unsigned int,unsigned int)> *this@<ecx>,
        boost::function1<void,vostok::physics::contact_point const &> *a2@<edi>)
{
  boost::function1<void,vostok::physics::contact_point const &> *v2; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::physics::contact_point const &> *v4; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v7; // [esp+8h] [ebp-40h] BYREF
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v8; // [esp+28h] [ebp-20h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)this,
    &v8);
  v4 = v2;
  if ( a2 != v2 )
  {
    v7.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v7,
      v2);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v4,
      a2);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      a2,
      &v7);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&v7);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v8);
  return a2;
}


boost::function1<void,vostok::physics::contact_point const &> *__thiscall boost::function<void __cdecl (char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int)>::operator=(
        boost::function<void __cdecl(char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int)> *this,
        boost::function1<void,vostok::physics::contact_point const &> *f)
{
  boost::detail::function::vtable_base *vtable; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> v5; // [esp+8h] [ebp-24h] BYREF

  vtable = this->vtable;
  v5.vtable = 0;
  if ( vtable )
  {
    v5.vtable = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
      qmemcpy((void *)&v5.functor, &this->functor, sizeof(v5.functor));
    else
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &this->functor,
        &v5.functor,
        0);
  }
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(f, &v5);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v5);
  return f;
}


boost::function1<void,vostok::physics::contact_point const &> *__thiscall boost::function<void __cdecl (vostok::vfs::mount_result)>::operator=(
        boost::function<void __cdecl(vostok::vfs::mount_result)> *this,
        boost::function1<void,vostok::physics::contact_point const &> *f)
{
  boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> *v2; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v5; // [esp+8h] [ebp-24h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)this,
    &v5);
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(f, v2);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v5);
  return f;
}


boost::function1<void,vostok::physics::contact_point const &> *__thiscall boost::function<void __cdecl (boost::system::error_code)>::operator=(
        boost::function<void __cdecl(vostok::network_core::buffer_reader &)> *this,
        boost::function1<void,vostok::physics::contact_point const &> *f)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v4; // [esp+8h] [ebp-24h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)this,
    &v4);
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    f,
    (boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> *)&v4);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v4);
  return f;
}


boost::function1<void,vostok::physics::contact_point const &> *__thiscall boost::function<void __cdecl (enum vostok::network_core::disconnect_event_types_enum)>::operator=(
        boost::function<void __cdecl(unsigned char,short)> *this,
        boost::function1<void,vostok::physics::contact_point const &> *f)
{
  boost::detail::function::vtable_base *vtable; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::physics::contact_point const &> v5; // [esp+8h] [ebp-40h] BYREF
  boost::function1<void,vostok::physics::contact_point const &> v6; // [esp+28h] [ebp-20h] BYREF

  vtable = this->vtable;
  v5.vtable = 0;
  if ( vtable )
  {
    v5.vtable = vtable;
    if ( ((unsigned __int8)vtable & 1) != 0 )
    {
      qmemcpy((void *)&v5.functor, &this->functor, sizeof(v5.functor));
      this = 0;
    }
    else
    {
      (*(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, _DWORD))((unsigned int)vtable & 0xFFFFFFFE))(
        &this->functor,
        &v5.functor,
        0);
    }
  }
  if ( f != &v5 )
  {
    v6.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v6,
      &v5);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v5,
      f);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      f,
      &v6);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v3,
      (int *)&v6);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    (boost::function1<void,vostok::sound::create_sound_propagator_params const &> *)this,
    (int *)&v5);
  return f;
}


boost::function1<void,vostok::physics::contact_point const &> *__thiscall boost::function<void __cdecl (void)>::operator=(
        boost::function<void __cdecl(void)> *this,
        boost::function1<void,vostok::physics::contact_point const &> *f)
{
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v2; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v4; // [esp+8h] [ebp-20h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)this,
    &v4);
  boost::function4<void,char const *,enum survarium::hit_type_enum,float &,float &>::swap(
    f,
    (boost::function4<void,char const *,enum survarium::hit_affects_type_enum,enum survarium::affect_event_type_enum,unsigned int> *)&v4);
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v2,
    (int *)&v4);
  return f;
}


boost::function1<void,vostok::physics::contact_point const &> *__usercall boost::function<bool __cdecl (void)>::operator=@<eax>(
        boost::function<bool __cdecl(void)> *this@<ecx>,
        boost::function1<void,vostok::physics::contact_point const &> *a2@<edi>)
{
  boost::function1<void,vostok::physics::contact_point const &> *v2; // eax
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v3; // ecx
  boost::function1<void,vostok::physics::contact_point const &> *v4; // esi
  boost::function1<void,vostok::sound::create_sound_propagator_params const &> *v5; // ecx
  boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> v7; // [esp+8h] [ebp-40h] BYREF
  boost::function1<void,vostok::physics::contact_point const &> v8; // [esp+28h] [ebp-20h] BYREF

  boost::function1<void,boost::system::error_code>::function1<void,boost::system::error_code>(
    (boost::function<void __cdecl(vostok::sound::create_sound_propagator_params const &)> *)this,
    &v7);
  v4 = v2;
  if ( a2 != v2 )
  {
    v8.vtable = 0;
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      &v8,
      v2);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      v4,
      a2);
    boost::function1<fastdelegate::FastDelegate<float __cdecl (float,float,unsigned int,unsigned int,unsigned int,float)>,unsigned char>::move_assign(
      a2,
      &v8);
    boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
      v5,
      (int *)&v8);
  }
  boost::function3<void,unsigned char,enum survarium::match_stats_events_dict_enum,unsigned short>::clear(
    v3,
    (int *)&v7);
  return a2;
}
