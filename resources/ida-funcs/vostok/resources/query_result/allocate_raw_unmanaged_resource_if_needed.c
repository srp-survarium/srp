int __usercall vostok::resources::query_result::allocate_raw_unmanaged_resource_if_needed@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<eax>)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::cook_base *v4; // ebx
  unsigned int m_flags; // eax
  vostok::resources::query_result *v6; // ecx
  vostok::resources::query_result *v7; // ecx
  vostok::resources::query_result *v8; // ecx
  vostok::resources::query_result_for_cook *v9; // ecx
  _DWORD *v10; // eax
  unsigned int raw_file_size; // eax
  boost::function1<void,vostok::collision::object const &> *v12; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v13; // ecx
  DWORD v15[2]; // [esp+10h] [ebp-30h] BYREF
  _BYTE v16[8]; // [esp+18h] [ebp-28h] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *)> callback; // [esp+20h] [ebp-20h] BYREF

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  v4 = cook;
  if ( !cook )
    return 0;
  m_flags = cook->m_flags.m_flags;
  if ( (m_flags & 0x20) != 0 )
    return 0;
  if ( (m_flags & 0x10) == 0 )
    return 0;
  if ( (m_flags & 8) != 0 )
    return 0;
  v15[0] = GetCurrentThreadId();
  if ( vostok::resources::query_result::allocate_thread_id(v6, a2) != v15[0]
    || vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(v7, a2) )
  {
    return 0;
  }
  vostok::threading::interlocked_and((volatile int *)(a2 + 688), 0xFFFEFFFF);
  if ( vostok::resources::query_result::need_create_resource_if_no_file(v8) )
  {
    v10 = (_DWORD *)((int (__thiscall *)(vostok::resources::cook_base *, DWORD *, int, _DWORD, int, _DWORD))v4->__vftable[1].cache_by_game_resources_manager)(
                      v4,
                      v15,
                      a2,
                      0,
                      a2 + 672,
                      0);
  }
  else
  {
    raw_file_size = vostok::resources::query_result_for_cook::get_raw_file_size(v9);
    *(_DWORD *)(a2 + 672) = 0;
    v10 = (_DWORD *)((int (__thiscall *)(vostok::resources::cook_base *, _BYTE *, int, unsigned int, int, int))v4->__vftable[1].cache_by_game_resources_manager)(
                      v4,
                      v16,
                      a2,
                      raw_file_size,
                      a2 + 672,
                      1);
  }
  *(_DWORD *)(a2 + 636) = *v10;
  *(_DWORD *)(a2 + 640) = v10[1];
  if ( !vostok::mutable_buffer::operator bool((vostok::mutable_buffer *)(a2 + 636))
    && ((unsigned int)&_sbh_sizeHeaderList & *(_DWORD *)(a2 + 688)) == 0 )
  {
    *(_DWORD *)(a2 + 304) = 3;
    *(_DWORD *)(a2 + 256) = 7;
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
      (boost::function4<void,unsigned int,float,float,char const *> *)&s_out_of_memory_callback,
      (int)&callback);
    if ( (callback.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
    {
      boost::function1<void,vostok::collision::object const &>::operator()(
        v12,
        &callback,
        (const vostok::collision::object *)a2);
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v13,
        (int *)&callback);
      return 2;
    }
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v12,
      (int *)&callback);
    return 0;
  }
  return 1;
}
