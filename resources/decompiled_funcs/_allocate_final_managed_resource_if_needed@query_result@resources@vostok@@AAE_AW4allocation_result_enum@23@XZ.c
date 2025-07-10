int __usercall vostok::resources::query_result::allocate_final_managed_resource_if_needed@<eax>(
        vostok::resources::query_result *this@<ecx>,
        int a2@<edi>)
{
  vostok::resources::cook_base *cook; // eax
  vostok::resources::query_result *m_flags; // ecx
  vostok::resources::cook_base *v4; // ebp
  vostok::const_buffer *v5; // eax
  bool v6; // al
  unsigned int v7; // ebp
  vostok::resources::resources_manager *v8; // ecx
  vostok::resources::managed_resource *managed_resource; // eax
  vostok::resources::managed_resource *m_object; // eax
  boost::function1<void,vostok::collision::object const &> *v11; // ecx
  boost::function<void __cdecl(unsigned int,float,float,char const *)> *v12; // ecx
  const vostok::vfs::vfs_iterator *v14; // eax
  int v15; // ebp
  int v16; // ebp
  vostok::resources::query_result *v17; // ecx
  vostok::resources::resource_base::creation_source_enum v18; // eax
  vostok::const_buffer *v19; // [esp+0h] [ebp-74h]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v20; // [esp+10h] [ebp-64h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v21; // [esp+14h] [ebp-60h] BYREF
  vostok::const_buffer raw_data; // [esp+18h] [ebp-5Ch] BYREF
  _DWORD v23[3]; // [esp+20h] [ebp-54h] BYREF
  _DWORD v24[5]; // [esp+2Ch] [ebp-48h] BYREF
  vostok::vfs::vfs_iterator result; // [esp+40h] [ebp-34h] BYREF
  boost::function<void __cdecl(vostok::resources::query_result *)> callback; // [esp+50h] [ebp-24h] BYREF

  cook = vostok::resources::resources_manager::find_cook(*(vostok::resources::class_id_enum *)(a2 + 132));
  if ( cook )
  {
    m_flags = (vostok::resources::query_result *)cook->m_flags.m_flags;
    if ( ((unsigned __int8)m_flags & 0x20) == 0 || ((unsigned __int8)m_flags & 0x18) != 0 )
      cook = 0;
    v4 = cook;
  }
  else
  {
    v4 = 0;
  }
  if ( *(_DWORD *)(a2 + 164)
    || (m_flags = *(vostok::resources::query_result **)(a2 + 212), *(_DWORD *)(a2 + 208))
    || m_flags
    || (*(_DWORD *)(a2 + 688) & 0x2000) != 0 )
  {
    v5 = vostok::resources::query_result::pin_raw_buffer(m_flags, v19);
  }
  else
  {
    v23[0] = 0;
    v23[1] = 0;
    v5 = (vostok::const_buffer *)v23;
  }
  raw_data = *v5;
  v6 = !*(_DWORD *)(a2 + 164)
    && !*(_DWORD *)(a2 + 208)
    && !*(_DWORD *)(a2 + 212)
    && (*(_DWORD *)(a2 + 688) & 0x2000) == 0;
  v7 = ((int (__thiscall *)(vostok::resources::cook_base *, const char *, unsigned int, bool))v4->__vftable[1].calculate_quality_levels_count)(
         v4,
         raw_data.m_data,
         raw_data.m_size,
         !v6);
  if ( *(_DWORD *)(a2 + 164)
    || (v8 = *(vostok::resources::resources_manager **)(a2 + 212), *(_DWORD *)(a2 + 208))
    || v8
    || (*(_DWORD *)(a2 + 688) & 0x2000) != 0 )
  {
    vostok::resources::query_result::unpin_raw_buffer((vostok::resources::query_result *)&raw_data, &raw_data);
  }
  if ( !v7 )
    return 1;
  managed_resource = vostok::resources::resources_manager::allocate_managed_resource(
                       v8,
                       v7,
                       *(vostok::resources::class_id_enum *)(a2 + 132));
  v20.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v20,
    managed_resource);
  m_object = v20.m_object;
  v20.m_object = *(vostok::resources::managed_resource **)(a2 + 216);
  *(_DWORD *)(a2 + 216) = m_object;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v20);
  if ( *(_DWORD *)(a2 + 216) )
  {
    if ( (*(_DWORD *)(a2 + 688) & 0x800) != 0 )
      v14 = vostok::vfs::vfs_iterator::end(&result);
    else
      v14 = (const vostok::vfs::vfs_iterator *)(a2 + 160);
    v15 = *(_DWORD *)(a2 + 216);
    vostok::vfs::vfs_iterator::vfs_iterator((vostok::vfs::vfs_iterator *)&v24[1], v14);
    v16 = v15 + 160;
    if ( !vostok::vfs::vfs_iterator::operator==(
            (vostok::vfs::vfs_iterator *)&v24[1],
            (const vostok::vfs::vfs_iterator *)v16) )
    {
      *(_QWORD *)v16 = *(_QWORD *)&v24[1];
      *(_QWORD *)(v16 + 8) = *(_QWORD *)&v24[3];
    }
    v21.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v21,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 216));
    v18 = vostok::resources::query_result::creation_source_for_resource(v17, a2);
    v21.m_object->m_creation_source = v18;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&v21);
    return 1;
  }
  *(_DWORD *)(a2 + 308) = &vostok::resources::managed_memory;
  *(_DWORD *)(a2 + 312) = v7;
  *(_DWORD *)(a2 + 304) = 4;
  *(_DWORD *)(a2 + 256) = 7;
  boost::function2<void,unsigned int,unsigned int>::function2<void,unsigned int,unsigned int>(
    (boost::function4<void,unsigned int,float,float,char const *> *)&s_out_of_memory_callback,
    (int)&callback);
  if ( (callback.vtable != 0 ? (unsigned int)survarium::weapon_user_dead_state::finalize : 0) != 0 )
  {
    boost::function1<void,vostok::collision::object const &>::operator()(
      v11,
      &callback,
      (const vostok::collision::object *)a2);
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      v12,
      (int *)&callback);
    return 2;
  }
  else
  {
    boost::function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>::~function<enum vostok::animation::callback_return_type_enum __cdecl (vostok::animation::animation_callback_params &)>(
      (boost::function<void __cdecl(unsigned int,float,float,char const *)> *)v11,
      (int *)&callback);
    return 0;
  }
}
