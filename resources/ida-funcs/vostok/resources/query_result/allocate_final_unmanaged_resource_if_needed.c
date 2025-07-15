int __usercall vostok::resources::query_result::allocate_final_unmanaged_resource_if_needed@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::query_result *v3; // ecx
  vostok::resources::cook_base *v4; // ebp
  vostok::const_buffer *v5; // eax
  _DWORD *v6; // esi
  bool v7; // al
  _DWORD *v8; // eax
  boost::function1<void,vostok::collision::object const &> *v9; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v10; // ecx
  vostok::const_buffer *v12; // [esp+Ch] [ebp-4Ch]
  vostok::const_buffer raw_data; // [esp+14h] [ebp-44h] BYREF
  _DWORD v14[2]; // [esp+1Ch] [ebp-3Ch] BYREF
  _BYTE v15[8]; // [esp+2Ch] [ebp-2Ch] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *)> callback; // [esp+34h] [ebp-24h] BYREF

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  v4 = cook;
  if ( !cook || (cook->m_flags.m_flags & 0x38) != 0 )
    return 0;
  if ( *(_DWORD *)(a2 + 164)
    || (v3 = *(vostok::resources::query_result **)(a2 + 212), *(_DWORD *)(a2 + 208))
    || v3
    || (*(_DWORD *)(a2 + 688) & 0x2000) != 0 )
  {
    v5 = vostok::resources::query_result::pin_raw_buffer(v3, v12);
  }
  else
  {
    v14[0] = *(_DWORD *)(a2 + 212);
    v14[1] = 0;
    v5 = (vostok::const_buffer *)v14;
  }
  raw_data = *v5;
  v6 = (_DWORD *)(a2 + 688);
  vostok::threading::interlocked_and((volatile int *)(a2 + 688), 0xFFFEFFFF);
  v7 = !*(_DWORD *)(a2 + 164) && !*(_DWORD *)(a2 + 208) && !*(_DWORD *)(a2 + 212) && (*v6 & 0x2000) == 0;
  v8 = (_DWORD *)((int (__thiscall *)(vostok::resources::cook_base *, _BYTE *, int, const char *, unsigned int, bool))v4->__vftable[1].calculate_quality_levels_count)(
                   v4,
                   v15,
                   a2,
                   raw_data.m_data,
                   raw_data.m_size,
                   !v7);
  *(_DWORD *)(a2 + 644) = *v8;
  *(_DWORD *)(a2 + 648) = v8[1];
  if ( !vostok::mutable_buffer::operator bool((vostok::mutable_buffer *)(a2 + 644))
    && ((unsigned int)&_sbh_sizeHeaderList & *v6) == 0 )
  {
    *(_DWORD *)(a2 + 304) = 4;
    *(_DWORD *)(a2 + 256) = 7;
    boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
      (boost::function4<void,unsigned int,float,float,char const *> *)&s_out_of_memory_callback,
      (int)&callback);
    if ( (callback.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
    {
      boost::function1<void,vostok::collision::object const &>::operator()(
        v9,
        &callback,
        (const vostok::collision::object *)a2);
      boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
        v10,
        (int *)&callback);
      return 2;
    }
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v9,
      (int *)&callback);
    return 0;
  }
  if ( *(_DWORD *)(a2 + 164) || *(_DWORD *)(a2 + 208) || *(_DWORD *)(a2 + 212) || (*v6 & 0x2000) != 0 )
    vostok::resources::query_result::unpin_raw_buffer((vostok::resources::query_result *)&raw_data, &raw_data);
  return 1;
}
