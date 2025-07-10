void __userpurge vostok::resources::query_result::do_managed_create_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::resources::managed_cook *cook)
{
  int v3; // eax
  vostok::resources::managed_cook *v4; // ebp
  vostok::threading::mutex *v5; // edi
  vostok::resources::query_result *v6; // ecx
  int v7; // ebx
  volatile __int32 *v8; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v9[4]; // [esp-4h] [ebp-24h] BYREF
  vostok::resources::query_result **v10; // [esp+Ch] [ebp-14h]
  vostok::const_buffer raw_data; // [esp+10h] [ebp-10h] BYREF
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>)> delegate; // [esp+18h] [ebp-8h] BYREF

  v3 = *(_DWORD *)(a2 + 216);
  v4 = cook;
  if ( v3 )
  {
    this = *(vostok::resources::query_result **)(v3 + 212);
    if ( !this->m_uid )
    {
      v10 = (vostok::resources::query_result **)(*(_DWORD *)(v3 + 212) + 32);
      this = *v10;
      if ( !*v10 )
      {
        v5 = (vostok::threading::mutex *)(*(_DWORD *)(v3 + 216) + 8368);
        vostok::threading::mutex::lock(v5);
        _InterlockedExchange((volatile __int32 *)v10, 1);
        LeaveCriticalSection((LPCRITICAL_SECTION)v5);
      }
    }
  }
  if ( *(_DWORD *)(a2 + 164)
    || (this = *(vostok::resources::query_result **)(a2 + 212), *(_DWORD *)(a2 + 208))
    || this
    || (this = *(vostok::resources::query_result **)(a2 + 688), ((unsigned __int16)this & 0x2000) != 0) )
  {
    vostok::resources::query_result::pin_raw_file(
      this,
      (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_data,
      (vostok::resources::query_result *)a2);
    v9[0].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      v9,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 216));
    ((void (__thiscall *)(vostok::resources::managed_cook *, int, const char *, unsigned int, vostok::resources::managed_resource *))v4->create_resource)(
      v4,
      a2,
      raw_data.m_data,
      raw_data.m_size,
      v9[0].m_object);
    vostok::resources::query_result::unpin_raw_file(v6, a2, (vostok::vfs::vfs_iterator *)&raw_data);
  }
  else
  {
    v4->get_create_resource_if_no_file_delegate(v4, &delegate);
    cook = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&cook,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 216));
    v9[0].m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      v9,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&cook);
    ((void (__thiscall *)(fastdelegate::detail::GenericClass *, int, vostok::resources::managed_resource *))delegate.m_Closure.m_pFunction)(
      delegate.m_Closure.m_pthis,
      a2,
      v9[0].m_object);
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&cook);
  }
  v7 = *(_DWORD *)(a2 + 216);
  if ( v7 && *(_DWORD *)(*(_DWORD *)(v7 + 212) + 32) )
  {
    v8 = (volatile __int32 *)(*(_DWORD *)(v7 + 212) + 32);
    if ( *v8 )
      _InterlockedExchange(v8, 0);
  }
}
