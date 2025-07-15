void __userpurge vostok::resources::query_result::do_unmanaged_create_resource(
        vostok::resources::query_result *this@<ecx>,
        _DWORD *a2@<eax>,
        vostok::resources::unmanaged_cook *cook)
{
  vostok::resources::unmanaged_cook *v3; // ebx
  vostok::resources::query_result *v5; // ecx
  vostok::mutable_buffer *v6; // eax
  void (__thiscall *create_resource)(vostok::resources::unmanaged_cook *, vostok::resources::query_result_for_cook *, vostok::const_buffer, vostok::mutable_buffer); // edx
  vostok::resources::query_result *v8; // ecx
  int v9; // eax
  unsigned int v10; // eax
  vostok::const_buffer raw_data; // [esp+14h] [ebp-18h] BYREF
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)> delegate; // [esp+1Ch] [ebp-10h] BYREF
  vostok::mutable_buffer v13; // [esp+24h] [ebp-8h] BYREF

  v3 = cook;
  vostok::const_buffer::const_buffer((vostok::mutable_buffer *)&raw_data);
  if ( a2[41] || (v5 = (vostok::resources::query_result *)a2[53], a2[52]) || v5 || (a2[172] & 0x2000) != 0 )
  {
    v6 = vostok::resources::query_result::pin_raw_buffer(v5, (int)a2, &v13);
    raw_data.m_data = v6->m_data;
    create_resource = v3->create_resource;
    raw_data.m_size = v6->m_size;
    ((void (__thiscall *)(vostok::resources::unmanaged_cook *, _DWORD *, char *, unsigned int, _DWORD, _DWORD))create_resource)(
      v3,
      a2,
      v6->m_data,
      v6->m_size,
      a2[161],
      a2[162]);
    vostok::resources::query_result::unpin_raw_buffer(
      v8,
      (int)a2,
      (vostok::intrusive_ptr<vostok::sound::encoded_sound_interface,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)&raw_data);
  }
  else
  {
    v3->get_create_resource_if_no_file_delegate(v3, &delegate);
    ((void (__thiscall *)(fastdelegate::detail::GenericClass *, _DWORD *, _DWORD, _DWORD))delegate.m_Closure.m_pFunction)(
      delegate.m_Closure.m_pthis,
      a2,
      a2[161],
      a2[162]);
  }
  v9 = a2[65];
  if ( v9 != 2 && v9 != 4 && v9 != 5 && v9 != 1 && (a2[172] & 0x8000) == 0 )
  {
    if ( debug_macro_helper_ignore_always_18 || a2[55] )
    {
      vostok::resources::query_result::set_deleter_object_if_needed(0, (int)a2);
    }
    else
    {
      v10 = occurances_left_18;
      if ( occurances_left_18 == -1 )
        v10 = 10;
      occurances_left_18 = v10 - 1;
      if ( v10 )
      {
        LOBYTE(cook) = 0;
        vostok::debug::on_error(
          (unsigned int)v3,
          (bool *)&cook,
          process_error_false,
          &debug_macro_helper_ignore_always_18,
          assert_untyped,
          "assertion_failed",
          "m_unmanaged_resource",
          ".\\resources_query_result_cook.cpp",
          "vostok::resources::query_result::do_unmanaged_create_resource",
          0x7Eu,
          "cook::create_resource should have called query.set_unmanaged_resource");
        if ( vostok::debug::is_debugger_present() || (_BYTE)cook )
          __debugbreak();
      }
    }
  }
}
