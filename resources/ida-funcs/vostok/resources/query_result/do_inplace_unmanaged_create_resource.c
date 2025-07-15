void __userpurge vostok::resources::query_result::do_inplace_unmanaged_create_resource(
        vostok::resources::inplace_unmanaged_cook *cook@<eax>,
        vostok::resources::query_result *a2@<ecx>,
        vostok::resources::query_result *this)
{
  vostok::resources::query_result *v3; // ebx
  vostok::resources::query_result *v4; // esi
  vostok::resources::query_result *v6; // ecx
  bool v7; // zf
  vostok::resources::inplace_unmanaged_cook_vtbl *v8; // eax
  int v9; // eax
  vostok::resources::query_result *v10; // ecx
  vostok::resources::inplace_unmanaged_cook_vtbl *v11; // eax
  vostok::resources::cook_base::result_enum m_create_resource_result; // eax
  unsigned int v13; // eax
  vostok::resources::unmanaged_resource *m_object; // eax
  vostok::vfs::vfs_iterator *v15; // esi
  survarium::pure_game_effect_emitter_base *v16; // ecx
  vostok::resources::query_result *v17; // ecx
  vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> v18[5]; // [esp-4h] [ebp-48h] BYREF
  vostok::vfs::vfs_iterator v19; // [esp+10h] [ebp-34h] BYREF
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)> v20; // [esp+24h] [ebp-20h] BYREF
  fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)> v21; // [esp+2Ch] [ebp-18h] BYREF
  _DWORD v22[2]; // [esp+34h] [ebp-10h] BYREF
  bool resource_inplace_in_creation_or_inline_data; // [esp+3Fh] [ebp-5h]

  v3 = this;
  v4 = this;
  resource_inplace_in_creation_or_inline_data = vostok::resources::query_result::need_create_resource_inplace_in_creation_or_inline_data(
                                                  a2,
                                                  (int)this);
  if ( resource_inplace_in_creation_or_inline_data )
  {
    v7 = !vostok::resources::query_result::has_uncompressed_inline_data(v6, (vostok::vfs::vfs_iterator *)v3);
    v8 = cook->__vftable;
    if ( v7 )
      v9 = (int)v8->get_create_resource_inplace_in_creation_data_delegate(cook, &v20);
    else
      v9 = (int)v8->get_create_resource_inplace_in_inline_fat_delegate(cook, &v21);
    (*(void (__thiscall **)(_DWORD, vostok::resources::query_result *, char *, unsigned int))(v9 + 4))(
      *(_DWORD *)v9,
      v3,
      v3->m_raw_unmanaged_buffer.m_data,
      v3->m_raw_unmanaged_buffer.m_size);
  }
  else
  {
    v7 = !vostok::resources::query_result::need_create_resource_if_no_file(v6, v3);
    v11 = cook->__vftable;
    if ( v7 )
    {
      ((void (__thiscall *)(vostok::resources::inplace_unmanaged_cook *, vostok::resources::query_result *, char *, unsigned int))v11->create_resource)(
        cook,
        v3,
        v3->m_raw_unmanaged_buffer.m_data,
        v3->m_raw_unmanaged_buffer.m_size);
    }
    else
    {
      v11->get_create_resource_if_no_file_delegate(
        cook,
        (fastdelegate::FastDelegate<void __cdecl(vostok::resources::query_result_for_cook &,vostok::mutable_buffer)> *)v22);
      ((void (__thiscall *)(_DWORD, vostok::resources::query_result *, char *, unsigned int))v22[1])(
        v22[0],
        v3,
        v3->m_raw_unmanaged_buffer.m_data,
        v3->m_raw_unmanaged_buffer.m_size);
    }
  }
  m_create_resource_result = v3->m_create_resource_result;
  if ( m_create_resource_result != result_need_async
    && m_create_resource_result != result_cannot_lock
    && (v3->m_flags & 0x8000) == 0 )
  {
    if ( debug_macro_helper_ignore_always_30 || v3->m_unmanaged_resource.m_object )
    {
      if ( resource_inplace_in_creation_or_inline_data
        && vostok::resources::query_result::has_uncompressed_inline_data(v10, (vostok::vfs::vfs_iterator *)v3) )
      {
        m_object = v3->m_unmanaged_resource.m_object;
        m_object->m_inlined_in_fat = 1;
        _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
      }
      else if ( !v3->m_unmanaged_resource.m_object->m_deleter )
      {
        vostok::resources::query_result::set_deleter_object(v10, (int)v4, v3->m_unmanaged_resource.m_object);
      }
      v15 = (vostok::vfs::vfs_iterator *)v3->m_unmanaged_resource.m_object;
      if ( !v15[12].m_hashset )
      {
        v15[10] = *vostok::resources::query_result::get_fat_it_zero_if_physical_path_it(v3, &v19);
        v18[0].m_object = v16;
        vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>(
          v18,
          (const vostok::resources::resource_ptr<survarium::pure_game_effect_emitter_base,vostok::resources::unmanaged_intrusive_base> *)&v3->m_unmanaged_resource);
        vostok::resources::query_result::set_creation_source_for_resource(
          v17,
          (int)v3,
          (vostok::intrusive_ptr<vostok::particle::particle_system_instance_impl,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>)v18[0].m_object);
      }
    }
    else
    {
      v13 = occurances_left_19;
      if ( occurances_left_19 == -1 )
        v13 = 10;
      occurances_left_19 = v13 - 1;
      if ( v13 )
      {
        HIBYTE(this) = 0;
        vostok::debug::on_error(
          (bool *)&this + 3,
          process_error_false,
          0,
          "assertion_failed",
          "m_unmanaged_resource",
          ".\\resources_query_result_cook.cpp",
          "vostok::resources::query_result::do_inplace_unmanaged_create_resource",
          (const char *)0xA2,
          "cook::create_resource should have called query.set_unmanaged_resource or query.set_zero_unmanaged_resource",
          (const char *)v18[1].m_object);
        if ( vostok::debug::is_debugger_present() || HIBYTE(this) )
          __debugbreak();
      }
    }
  }
}
