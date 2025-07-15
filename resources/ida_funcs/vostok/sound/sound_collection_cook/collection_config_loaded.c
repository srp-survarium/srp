void __thiscall vostok::sound::sound_collection_cook::collection_config_loaded(
        vostok::sound::sound_collection_cook *this,
        vostok::resources::queries_result *data)
{
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> v3; // [esp-Ch] [ebp-78h] BYREF
  const vostok::configs::binary_config_value *v4; // [esp-8h] [ebp-74h]
  vostok::resources::query_result_for_cook *v5; // [esp-4h] [ebp-70h]
  vostok::sound::sound_collection_cook *thisa; // [esp+0h] [ebp-6Ch]
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *v7; // [esp+Ch] [ebp-60h]
  vostok::configs::binary_config_value *m_root; // [esp+20h] [ebp-4Ch]
  vostok::configs::binary_config *v9; // [esp+24h] [ebp-48h]
  char v10; // [esp+2Bh] [ebp-41h]
  vostok::configs::binary_config_value *v11; // [esp+34h] [ebp-38h]
  vostok::configs::binary_config *v12; // [esp+38h] [ebp-34h]
  char v13; // [esp+3Fh] [ebp-2Dh]
  vostok::configs::binary_config *object; // [esp+44h] [ebp-28h]
  vostok::configs::binary_config *m_object; // [esp+48h] [ebp-24h]
  const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *v16; // [esp+4Ch] [ebp-20h]
  bool v17; // [esp+56h] [ebp-16h]
  char v18; // [esp+57h] [ebp-15h]
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v19; // [esp+58h] [ebp-14h] BYREF
  bool do_debug_break; // [esp+5Fh] [ebp-Dh] BYREF
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> config_ptr; // [esp+60h] [ebp-Ch] BYREF
  vostok::resources::query_result_for_cook *parent; // [esp+64h] [ebp-8h]
  const vostok::configs::binary_config_value *collection; // [esp+68h] [ebp-4h]

  thisa = this;
  parent = data->m_parent_query;
  if ( vostok::resources::queries_result::is_successful(data) )
  {
    v16 = (const vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> *)vostok::resources::queries_result::operator[](data, 0);
    v19.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &v19,
      v16 + 55);
    m_object = v19.m_object;
    object = v19.m_object;
    config_ptr.m_object = 0;
    vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
      &config_ptr,
      v19.m_object);
    vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&v19);
    v18 = 1;
    if ( debug_macro_helper_ignore_always_0
      || (v13 = 0,
          v12 = config_ptr.m_object,
          v11 = config_ptr.m_object->m_root,
          v17 = vostok::configs::binary_config_value::value_exists(v11, "collection")) )
    {
      v10 = 0;
      v9 = config_ptr.m_object;
      m_root = config_ptr.m_object->m_root;
      collection = vostok::configs::binary_config_value::operator[](m_root, "collection");
      v5 = parent;
      v4 = collection;
      v3.m_object = (vostok::configs::binary_config *)collection;
      v7 = &v3;
      boost::_bi::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>::value<vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base>>(
        &v3,
        &config_ptr);
      vostok::sound::sound_collection_cook::request_items(thisa, v3, v4, v5);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
    }
    else
    {
      if ( occurances_left_0 == -1 )
        occurances_left_0 = 10;
      if ( occurances_left_0-- )
      {
        if ( !debug_macro_helper_ignore_always_0 )
        {
          do_debug_break = 0;
          vostok::debug::on_error(
            &do_debug_break,
            process_error_false,
            &debug_macro_helper_ignore_always_0,
            assert_untyped,
            "assertion_failed",
            "config_ptr->get_root().value_exists( \"collection\" )",
            ".\\sound_collection_cook.cpp",
            "vostok::sound::sound_collection_cook::collection_config_loaded",
            0x49u);
          if ( vostok::debug::is_debugger_present() || do_debug_break )
            __debugbreak();
        }
      }
      vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
      vostok::intrusive_ptr<survarium::inventory_item,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec((vostok::resources::resource_ptr<survarium::game_world_object,vostok::resources::unmanaged_intrusive_base> *)&config_ptr);
    }
  }
  else
  {
    vostok::resources::query_result_for_cook::finish_query(parent, result_error, assert_on_fail_true);
  }
}
