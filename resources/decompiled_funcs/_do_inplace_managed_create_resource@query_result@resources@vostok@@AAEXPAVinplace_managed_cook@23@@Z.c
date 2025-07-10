void __userpurge vostok::resources::query_result::do_inplace_managed_create_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::resources::inplace_managed_cook *cook)
{
  int v3; // eax
  vostok::resources::inplace_managed_cook *v4; // ebp
  vostok::threading::mutex *v5; // ebx
  vostok::resources::managed_resource *file_size; // eax
  int v7; // edx
  vostok::resources::inplace_managed_cook *v8; // eax
  int v9; // edi
  volatile __int32 *v10; // eax
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v11; // [esp-Ch] [ebp-34h] BYREF
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> v12; // [esp-8h] [ebp-30h] BYREF
  int v13; // [esp-4h] [ebp-2Ch]
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> object; // [esp+10h] [ebp-18h] BYREF
  volatile __int32 *v15; // [esp+14h] [ebp-14h]
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::resources::resource_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base>,unsigned int &)> delegate; // [esp+18h] [ebp-10h] BYREF
  _DWORD v17[2]; // [esp+20h] [ebp-8h] BYREF

  v3 = *(_DWORD *)(a2 + 632);
  v4 = cook;
  if ( v3 )
  {
    if ( !*(_DWORD *)(*(_DWORD *)(v3 + 212) + 32) )
    {
      v15 = (volatile __int32 *)(*(_DWORD *)(v3 + 212) + 32);
      if ( !*v15 )
      {
        v5 = (vostok::threading::mutex *)(*(_DWORD *)(v3 + 216) + 8368);
        vostok::threading::mutex::lock(v5);
        _InterlockedExchange(v15, 1);
        LeaveCriticalSection((LPCRITICAL_SECTION)v5);
      }
    }
  }
  if ( *(_DWORD *)(a2 + 164) )
    goto LABEL_11;
  if ( *(_DWORD *)(a2 + 208) || *(_DWORD *)(a2 + 212) || (*(_DWORD *)(a2 + 688) & 0x2000) != 0 )
  {
    if ( !*(_DWORD *)(a2 + 164) )
    {
      v7 = *(_DWORD *)(a2 + 212);
      v17[0] = *(_DWORD *)(a2 + 208);
      v17[1] = v7;
      file_size = (vostok::resources::managed_resource *)vostok::mutable_buffer::size((vostok::vfs::vfs_iterator *)v17);
      goto LABEL_13;
    }
LABEL_11:
    file_size = (vostok::resources::managed_resource *)vostok::vfs::vfs_iterator::get_file_size((vostok::vfs::vfs_iterator *)(a2 + 160));
LABEL_13:
    v13 = a2 + 696;
    v12.m_object = file_size;
    v11.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
      &v11,
      (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 632));
    ((void (__thiscall *)(vostok::resources::inplace_managed_cook *, int, vostok::resources::managed_resource *, vostok::resources::managed_resource *, int))v4->create_resource)(
      v4,
      a2,
      v11.m_object,
      v12.m_object,
      v13);
    goto LABEL_14;
  }
  v4->get_create_resource_if_no_file_delegate(v4, &delegate);
  object.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &object,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 632));
  v13 = a2 + 696;
  v12.m_object = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    &v12,
    &object);
  ((void (__thiscall *)(fastdelegate::detail::GenericClass *, int, vostok::resources::managed_resource *, int))delegate.m_Closure.m_pFunction)(
    delegate.m_Closure.m_pthis,
    a2,
    v12.m_object,
    v13);
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>(&object);
LABEL_14:
  cook = 0;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::set(
    (vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&cook,
    (const vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)(a2 + 632));
  v8 = cook;
  cook = *(vostok::resources::inplace_managed_cook **)(a2 + 216);
  *(_DWORD *)(a2 + 216) = v8;
  vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>::~intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock>((vostok::intrusive_ptr<vostok::resources::managed_resource,vostok::resources::managed_intrusive_base,vostok::threading::simple_lock> *)&cook);
  v9 = *(_DWORD *)(a2 + 632);
  if ( v9 && *(_DWORD *)(*(_DWORD *)(v9 + 212) + 32) )
  {
    v10 = (volatile __int32 *)(*(_DWORD *)(v9 + 212) + 32);
    if ( *v10 )
      _InterlockedExchange(v10, 0);
  }
}
