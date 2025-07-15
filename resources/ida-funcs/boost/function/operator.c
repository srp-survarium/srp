boost::function<void __cdecl(unsigned int,unsigned int)> *__usercall boost::function<void __cdecl (unsigned char,vostok::network_core::packet_reader &)>::operator=@<eax>(
        boost::function<void __cdecl(unsigned int,unsigned int)> *this@<ecx>,
        boost::function2<void,unsigned int,unsigned int> *a2@<edi>)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  const boost::function4<void,unsigned int,float,float,char const *> *v4; // [esp+0h] [ebp-28h]
  boost::function2<void,unsigned int,unsigned int> v5; // [esp+8h] [ebp-20h] BYREF

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)this,
    v4);
  boost::function1<void,vostok::network_core::packet_reader &>::swap(&v5, a2);
  if ( v5.vtable )
  {
    if ( ((int)v5.vtable & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v5.vtable & 0xFFFFFFFE);
      if ( v2 )
        v2(&v5.functor, &v5.functor, 2);
    }
  }
  return (boost::function<void __cdecl(unsigned int,unsigned int)> *)a2;
}


boost::function<void __cdecl(vostok::resources::query_result *)> *__thiscall boost::function<void __cdecl (vostok::resources::query_result *)>::operator=(
        boost::function<void __cdecl(vostok::resources::query_result *)> *this)
{
  boost::function1<void,vostok::resources::query_result *> *v1; // ecx
  void (__cdecl *v2)(_BYTE *, _BYTE *, int); // eax
  const boost::function4<void,unsigned int,float,float,char const *> *v4; // [esp+0h] [ebp-28h]
  boost::function1<void,vostok::resources::query_result *> *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+8h] [ebp-20h]
  _BYTE v7[24]; // [esp+10h] [ebp-18h] BYREF

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)this,
    v4);
  boost::function1<void,vostok::resources::query_result *>::swap(v1, v5);
  if ( v6 )
  {
    if ( (v6 & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v6 & 0xFFFFFFFE);
      if ( v2 )
        v2(v7, v7, 2);
    }
  }
  return &s_out_of_memory_callback;
}


boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> *__thiscall boost::function<void __cdecl (vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)>::operator=(
        boost::function<void __cdecl(vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum)> *this)
{
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *v1; // ecx
  void (__cdecl *v2)(_BYTE *, _BYTE *, int); // eax
  const boost::function4<void,unsigned int,float,float,char const *> *v4; // [esp+0h] [ebp-28h]
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum> *v5; // [esp+0h] [ebp-28h]
  int v6; // [esp+8h] [ebp-20h]
  _BYTE v7[24]; // [esp+10h] [ebp-18h] BYREF

  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)this,
    v4);
  boost::function3<void,vostok::resources::query_result *,vostok::resources::memory_usage_type const &,enum vostok::resources::class_id_enum>::swap(
    v1,
    v5);
  if ( v6 )
  {
    if ( (v6 & 1) == 0 )
    {
      v2 = *(void (__cdecl **)(_BYTE *, _BYTE *, int))(v6 & 0xFFFFFFFE);
      if ( v2 )
        v2(v7, v7, 2);
    }
  }
  return &s_resource_freed_callback;
}


boost::function<void __cdecl(boost::system::error_code)> *__thiscall boost::function<void __cdecl (boost::system::error_code)>::operator=(
        boost::function<void __cdecl(boost::system::error_code)> *this,
        const boost::function<void __cdecl(boost::system::error_code)> *f)
{
  boost::function1<void,enum vostok::handshaking_error_types_enum> v4; // [esp+2Ch] [ebp-20h] BYREF

  boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
  boost::function3<void,vostok::ai::brain_unit const *,vostok::ai::npc const *,vostok::ai::weapon const *>::assign_to_own(
    &v4,
    (const boost::function1<void,enum vostok::handshaking_error_types_enum> *)f);
  boost::function1<unsigned int,char const *>::swap(
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)&v4,
    (boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *)this);
  boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&v4);
  return this;
}


boost::function<void __cdecl(void)> *__thiscall boost::function<void __cdecl (void)>::operator=(
        boost::function<void __cdecl(void)> *this,
        const boost::function<void __cdecl(void)> *f)
{
  void (__cdecl *v3)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function0<void> v5; // [esp+8h] [ebp-20h] BYREF

  v5.vtable = 0;
  boost::function0<void>::assign_to_own(&v5, f);
  boost::function0<void>::swap(&v5, this);
  if ( v5.vtable )
  {
    if ( ((int)v5.vtable & 1) == 0 )
    {
      v3 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)v5.vtable & 0xFFFFFFFE);
      if ( v3 )
        v3(&v5.functor, &v5.functor, 2);
    }
  }
  return this;
}
