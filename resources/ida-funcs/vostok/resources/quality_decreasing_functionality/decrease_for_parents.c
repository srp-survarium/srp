void __thiscall vostok::resources::quality_decreasing_functionality::decrease_for_parents(
        vostok::resources::quality_decreasing_functionality *this,
        vostok::resources::resource_base *top_resource,
        vostok::resources::resource_link *do_debug_break)
{
  vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *v3; // ebx
  const vostok::threading::simple_lock *p_next_link; // eax
  vostok::resources::resource_link *v5; // edx
  vostok::resources::resource_base **v6; // edx
  vostok::resources::resource_base *v7; // eax
  vostok::resources::resource_base *v8; // edi
  vostok::resources::quality_increase_functionality *v9; // ecx
  unsigned int v10; // eax
  unsigned int v11; // eax
  bool *v12; // [esp-18h] [ebp-38h]
  const char *v13; // [esp-14h] [ebp-34h]
  const char *v14; // [esp-10h] [ebp-30h]
  const char *v15; // [esp-Ch] [ebp-2Ch]
  vostok::threading::simple_lock::mutex_raii v16; // [esp+10h] [ebp-10h] BYREF
  unsigned int m_size; // [esp+18h] [ebp-8h]
  vostok::resources::quality_increase_functionality v18; // [esp+1Ch] [ebp-4h] BYREF

  v3 = (vostok::intrusive_list<vostok::resources::resource_link,vostok::resources::resource_link *,4,vostok::threading::simple_lock,vostok::size_policy,vostok::no_debug_policy> *)&do_debug_break[5];
  if ( do_debug_break == (vostok::resources::resource_link *)-60 )
    p_next_link = 0;
  else
    p_next_link = (const vostok::threading::simple_lock *)&do_debug_break[5].next_link;
  v16.lock = p_next_link;
  vostok::threading::simple_lock::lock((vostok::threading::simple_lock *)this, (int)p_next_link);
  v16.locked = 1;
  v5 = vostok::resources::resource_link_list_front_no_dying(v3);
  if ( !v5 )
    goto LABEL_23;
  while ( 1 )
  {
    m_size = v3->m_size;
    do_debug_break = vostok::resources::resource_link_list_next_no_dying(v5);
    v7 = v6[2];
    if ( v7 == (vostok::resources::resource_base *)-1 )
      goto LABEL_10;
    if ( !debug_macro_helper_ignore_always_36
      && v7 == (vostok::resources::resource_base *)((*v6)->m_quality_levels_count - 1) )
    {
      break;
    }
    v8 = *v6;
    (*v6)->decrease_quality(*v6, (unsigned int)&v7->__vftable + 1);
    vostok::resources::quality_increase_functionality::quality_increase_functionality(
      &v18,
      (vostok::resources::game_resources_manager_data *)top_resource->log_string);
    vostok::resources::quality_increase_functionality::update_current_satisfaction_for_resource(
      &v18,
      v8,
      v9,
      (vostok::resources::compare_by_target_satisfaction *)v3);
    if ( !debug_macro_helper_ignore_always_37 && v3->m_size >= m_size )
    {
      v11 = occurances_left_22;
      if ( occurances_left_22 == -1 )
        v11 = 10;
      occurances_left_22 = v11 - 1;
      if ( v11 )
      {
        v15 = (const char *)101;
        v14 = "vostok::resources::quality_decreasing_functionality::decrease_for_parents";
        v13 = ".\\game_resman_quality_decrease.cpp";
        v12 = (bool *)"(current_parents_count) < (previous_parents_count)";
        goto LABEL_20;
      }
      goto LABEL_23;
    }
LABEL_10:
    v5 = do_debug_break;
    if ( !do_debug_break )
      goto LABEL_23;
  }
  v10 = occurances_left_21;
  if ( occurances_left_21 == -1 )
    v10 = 10;
  occurances_left_21 = v10 - 1;
  if ( v10 )
  {
    v15 = "vostok::resources::quality_decreasing_functionality::decrease_for_parents";
    v14 = ".\\game_resman_quality_decrease.cpp";
    v13 = "(it_link->quality_value) != (worst_quality_level)";
LABEL_20:
    HIBYTE(do_debug_break) = 0;
    vostok::debug::on_error((bool *)&do_debug_break + 3, process_error_false, v12, v13, v14, v15);
    if ( vostok::debug::is_debugger_present() || HIBYTE(do_debug_break) )
      __debugbreak();
  }
LABEL_23:
  vostok::threading::simple_lock::mutex_raii::~mutex_raii(&v16);
}
