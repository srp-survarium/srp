void __userpurge survarium::console_command_bind::console_command_bind(
        survarium::console_command_bind *this@<ecx>,
        int a2@<eax>,
        survarium::key_binder *binder,
        unsigned int type)
{
  const char *v5; // edx
  void (__cdecl *v6)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int); // eax
  boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::animated_model_instance_cook,vostok::resources::queries_result &,survarium::animated_model_instance *>,boost::_bi::list3<boost::_bi::value<survarium::animated_model_instance_cook *>,boost::arg<1>,boost::_bi::value<survarium::animated_model_instance *> > > v7; // [esp-8h] [ebp-44h]
  void (__thiscall *v8)(survarium::key_binder *, const char *, int); // [esp+Ch] [ebp-30h]
  survarium::key_binder *v9; // [esp+10h] [ebp-2Ch]
  boost::function<void __cdecl(char const *)> functor; // [esp+18h] [ebp-24h] BYREF

  v9 = binder;
  v8 = survarium::key_binder::bind_key;
  *(_QWORD *)&v7.f_.f_ = __PAIR64__(type, (unsigned int)binder);
  functor.vtable = 0;
  if ( boost::detail::function::basic_vtable1<void,bool>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,vostok::resources::device_manager,vostok::resources::query_result *,bool>,boost::_bi::list3<boost::_bi::value<vostok::resources::device_manager *>,boost::_bi::value<vostok::resources::query_result *>,boost::arg<1>>>>(
         &functor.functor,
         (boost::detail::function::basic_vtable1<void,vostok::resources::queries_result &> *)survarium::key_binder::bind_key,
         v7) )
  {
    functor.vtable = (boost::detail::function::vtable_base *)((char *)&`boost::function1<void,char const *>::assign_to<boost::_bi::bind_t<void,boost::_mfi::mf2<void,survarium::key_binder,char const *,int>,boost::_bi::list3<boost::_bi::value<survarium::key_binder *>,boost::arg<1>,boost::_bi::value<int>>>>'::`2'::stored_vtable
                                                            + 1);
  }
  else
  {
    functor.vtable = 0;
  }
  v5 = "bind";
  if ( type )
    v5 = "bind_sec";
  vostok::console_commands::cc_delegate::cc_delegate(
    (vostok::console_commands::cc_delegate *)a2,
    v5,
    &functor,
    1,
    command_type_user_specific);
  if ( functor.vtable )
  {
    if ( ((int)functor.vtable & 1) == 0 )
    {
      v6 = *(void (__cdecl **)(boost::detail::function::function_buffer *, boost::detail::function::function_buffer *, int))((int)functor.vtable & 0xFFFFFFFE);
      if ( v6 )
        v6(&functor.functor, &functor.functor, 2);
    }
  }
  *(_DWORD *)(a2 + 100) = binder;
  *(_DWORD *)(a2 + 96) = type;
  *(_DWORD *)a2 = &survarium::console_command_bind::`vftable';
}
