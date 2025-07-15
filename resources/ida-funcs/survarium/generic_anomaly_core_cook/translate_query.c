void __thiscall survarium::generic_anomaly_core_cook::translate_query(
        survarium::generic_anomaly_core_cook *this,
        const vostok::variant<32> **parent)
{
  const vostok::variant<32> **v2; // ebx
  vostok::variant<32> *v3; // esi
  vostok::resources::query_result_for_cook *v4; // ecx
  survarium::generic_anomaly_core_cook *v5; // ecx
  const char *v6; // [esp+0h] [ebp-18h]
  survarium::anomaly_cook_data game_world; // [esp+Ch] [ebp-Ch] BYREF
  vostok::resources::query_result_for_cook *parenta; // [esp+14h] [ebp-4h]
  int savedregs; // [esp+18h] [ebp+0h] BYREF

  v2 = parent;
  v3 = (vostok::variant<32> *)parent[66];
  parenta = (vostok::resources::query_result_for_cook *)this;
  if ( vostok::variant<32>::try_get<survarium::anomaly_cook_data>(v3, &game_world) )
  {
    if ( vostok::configs::binary_config_value::operator[](game_world.config, "artefacts_enabled")->data.pointer )
      survarium::generic_anomaly_core_cook::query_for_artefacts(
        v5,
        (int)&savedregs,
        "artefacts_enabled",
        v3->m_helper_storage,
        parenta,
        v2,
        game_world.config,
        (int)game_world.game_world);
    else
      survarium::generic_anomaly_core_cook::proceed_to_create_resource(
        v5,
        parenta,
        (const vostok::configs::binary_config_value *)v2,
        (vostok::resources::queries_result *)game_world.config,
        0);
  }
  else
  {
    if ( !debug_macro_helper_ignore_always_46 )
    {
      HIBYTE(parent) = 0;
      vostok::debug::on_error(
        (bool *)&parent + 3,
        process_error_true,
        0,
        "assertion_failed",
        "fatal error",
        ".\\generic_anomaly_core_cook.cpp",
        "survarium::generic_anomaly_core_cook::translate_query",
        (const char *)0x1C,
        "This cook requires generic_anomaly_core_cook_data as user data.",
        v6);
      if ( vostok::debug::is_debugger_present() || HIBYTE(parent) )
        __debugbreak();
    }
    vostok::resources::query_result_for_cook::finish_query_impl(
      v4,
      (vostok::memory::single_size_buffer_allocator<76,vostok::threading::single_threading_policy> *)v2,
      result_success,
      assert_on_fail_true,
      result_out_of_memory|0x8);
  }
}
