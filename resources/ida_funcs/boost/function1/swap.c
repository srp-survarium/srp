void __thiscall boost::function1<unsigned int,char const *>::swap(
        boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *this,
        boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> *other)
{
  boost::function2<bool,char const *,enum survarium::hit_affects_type_enum> tmp; // [esp+24h] [ebp-20h] BYREF

  if ( other != this )
  {
    boost::function<void __cdecl (void)>::function<void __cdecl (void)>((boost::function1<void,enum vostok::network_core::disconnect_event_types_enum> *)this);
    boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::move_assign(&tmp, this);
    boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::move_assign(this, other);
    boost::function2<bool,char const *,enum survarium::hit_affects_type_enum>::move_assign(other, &tmp);
    boost::function2<bool,vostok::ai::brain_unit const *,vostok::ai::npc const *>::clear((boost::function4<float,char const *,char const *,float,float> *)&tmp);
  }
}


void __userpurge boost::function1<void,vostok::network_core::packet_reader &>::swap(
        boost::function2<void,unsigned int,unsigned int> *other@<esi>,
        boost::function<void __cdecl(unsigned int,float,float,char const *)> *a2@<ecx>,
        boost::function2<void,unsigned int,unsigned int> *this)
{
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v3; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v4; // ecx
  void (__cdecl *v5)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function2<void,unsigned int,unsigned int> tmp; // [esp+8h] [ebp-20h] BYREF

  if ( other != this )
  {
    tmp.vtable = 0;
    boost::function1<void,vostok::resources::query_result *>::move_assign(&tmp, this, a2);
    boost::function1<void,vostok::resources::query_result *>::move_assign(this, other, v3);
    boost::function1<void,vostok::resources::query_result *>::move_assign(other, &tmp, v4);
    if ( tmp.vtable )
    {
      if ( ((int)tmp.vtable & 1) == 0 )
      {
        v5 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)tmp.vtable & 0xFFFFFFFE);
        if ( v5 )
          v5(&tmp.functor, &tmp.functor, 2);
      }
    }
  }
}


void __userpurge boost::function1<void,vostok::resources::queries_result &>::swap(
        boost::function1<void,vostok::resources::queries_result &> *other@<edi>,
        boost::function1<void,vostok::resources::queries_result &> *this)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function1<void,vostok::resources::queries_result &> tmp; // [esp+8h] [ebp-20h] BYREF

  if ( other != this )
  {
    tmp.vtable = 0;
    boost::function1<void,vostok::resources::queries_result &>::move_assign(&tmp, this);
    boost::function1<void,vostok::resources::queries_result &>::move_assign(this, other);
    boost::function1<void,vostok::resources::queries_result &>::move_assign(other, &tmp);
    if ( tmp.vtable )
    {
      if ( ((int)tmp.vtable & 1) == 0 )
      {
        v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)tmp.vtable & 0xFFFFFFFE);
        if ( v2 )
          v2(&tmp.functor, &tmp.functor, 2);
      }
    }
  }
}


void __usercall boost::function1<void,vostok::resources::query_result *>::swap(
        boost::function1<void,vostok::resources::query_result *> *this@<ecx>,
        boost::function2<void,unsigned int,unsigned int> *a2@<esi>)
{
  void (__cdecl *v2)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::function1<void,vostok::resources::query_result *> tmp; // [esp+8h] [ebp-24h] BYREF

  if ( a2 != (boost::function2<void,unsigned int,unsigned int> *)&s_out_of_memory_callback )
  {
    tmp.vtable = 0;
    boost::function1<void,vostok::resources::query_result *>::move_assign(
      (boost::function2<void,unsigned int,unsigned int> *)&tmp,
      a2);
    boost::function1<void,vostok::resources::query_result *>::move_assign(
      a2,
      (boost::function2<void,unsigned int,unsigned int> *)&s_out_of_memory_callback);
    boost::function1<void,vostok::resources::query_result *>::move_assign(
      (boost::function2<void,unsigned int,unsigned int> *)&s_out_of_memory_callback,
      (boost::function2<void,unsigned int,unsigned int> *)&tmp);
    if ( tmp.vtable )
    {
      if ( ((int)tmp.vtable & 1) == 0 )
      {
        v2 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)tmp.vtable & 0xFFFFFFFE);
        if ( v2 )
          v2(&tmp.functor, &tmp.functor, 2);
      }
    }
  }
}
