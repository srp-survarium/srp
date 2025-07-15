void __userpurge vostok::resources::query_result::do_unmanaged_create_resource(
        vostok::resources::query_result *this@<ecx>,
        int a2@<esi>,
        vostok::resources::unmanaged_cook *cook)
{
  vostok::resources::unmanaged_cook *v3; // ebx
  vostok::const_buffer *v4; // eax
  vostok::resources::unmanaged_cook_vtbl *v5; // edx
  vostok::resources::query_result *v6; // ecx
  int v7; // eax
  unsigned int v8; // eax
  const char *m_data; // [esp-10h] [ebp-34h]
  int v10; // [esp-8h] [ebp-2Ch]
  int v11; // [esp-4h] [ebp-28h]
  const char *v12; // [esp+0h] [ebp-24h]
  const char *v13; // [esp+8h] [ebp-1Ch] BYREF
  vostok::const_buffer pinned_raw_buffer; // [esp+10h] [ebp-14h] BYREF
  _DWORD v15[3]; // [esp+18h] [ebp-Ch] BYREF

  v3 = cook;
  if ( vostok::resources::query_result::need_create_resource_if_no_file(this, (_DWORD *)a2) )
  {
    v3->get_create_resource_if_no_file_delegate(
      v3,
      (fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)> *)v15);
    ((void (__thiscall *)(_DWORD, int, _DWORD, _DWORD))v15[1])(v15[0], a2, *(_DWORD *)(a2 + 660), *(_DWORD *)(a2 + 664));
  }
  else
  {
    v4 = vostok::resources::query_result::pin_raw_buffer((vostok::resources::query_result *)a2, &v13);
    v11 = *(_DWORD *)(a2 + 664);
    v10 = *(_DWORD *)(a2 + 660);
    v5 = v3->__vftable;
    pinned_raw_buffer.m_data = v4->m_data;
    m_data = v4->m_data;
    pinned_raw_buffer.m_size = v4->m_size;
    ((void (__thiscall *)(vostok::resources::unmanaged_cook *, int, const char *, unsigned int, int, int))v5->create_resource)(
      v3,
      a2,
      m_data,
      pinned_raw_buffer.m_size,
      v10,
      v11);
    vostok::resources::query_result::unpin_raw_buffer(v6, &pinned_raw_buffer);
  }
  v7 = *(_DWORD *)(a2 + 260);
  if ( v7 != 2 && v7 != 4 && v7 != 5 && v7 != 1 && (*(_DWORD *)(a2 + 704) & 0x8000) == 0 )
  {
    if ( debug_macro_helper_ignore_always_29 || *(_DWORD *)(a2 + 220) )
    {
      vostok::resources::query_result::set_deleter_object_if_needed(0, (vostok::resources::query_result *)a2);
    }
    else
    {
      v8 = occurances_left_18;
      if ( occurances_left_18 == -1 )
        v8 = 10;
      occurances_left_18 = v8 - 1;
      if ( v8 )
      {
        HIBYTE(cook) = 0;
        vostok::debug::on_error(
          (bool *)&cook + 3,
          process_error_false,
          0,
          "assertion_failed",
          "m_unmanaged_resource",
          ".\\resources_query_result_cook.cpp",
          "vostok::resources::query_result::do_unmanaged_create_resource",
          (const char *)0x7E,
          "cook::create_resource should have called query.set_unmanaged_resource",
          v12);
        if ( vostok::debug::is_debugger_present() || HIBYTE(cook) )
          __debugbreak();
      }
    }
  }
}
