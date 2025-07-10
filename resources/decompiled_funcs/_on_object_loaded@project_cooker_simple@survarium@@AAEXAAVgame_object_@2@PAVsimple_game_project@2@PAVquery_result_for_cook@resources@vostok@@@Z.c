void __thiscall survarium::project_cooker_simple::on_object_loaded(
        survarium::project_cooker_simple *this,
        survarium::game_object_ *__formal,
        vostok::configs::binary_config *project,
        vostok::resources::query_result_for_cook *parent_query)
{
  bool v4; // zf
  unsigned int m_link_target; // eax
  vostok::resources::query_result_for_cook *v6; // ecx
  vostok::intrusive_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> v7; // [esp-Ch] [ebp-1Ch] BYREF
  const vostok::resources::memory_type *v8; // [esp-8h] [ebp-18h]
  unsigned int v9; // [esp-4h] [ebp-14h]
  int v10; // [esp+Ch] [ebp-4h]

  ++project[1].m_fat_it.m_link_target;
  v4 = BYTE1(project[1].m_fat_it.m_type) == 0;
  m_link_target = (unsigned int)project[1].m_fat_it.m_link_target;
  v10 = 0;
  if ( !v4
    && BYTE2(project[1].m_fat_it.m_type)
    && m_link_target == ((int)project[1].m_children_resources.m_first - *(_DWORD *)&project[1].m_children_resources.gapC) >> 2 )
  {
    if ( LOBYTE(project[1].m_fat_it.m_type) )
    {
      ((void (__thiscall *)(vostok::configs::binary_config_value **))project->m_root->id.pointer)(&project->m_root);
      v9 = 448;
      v8 = &vostok::resources::nocache_memory;
      v7.m_object = 0;
      vostok::intrusive_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::set(
        &v7,
        project);
      vostok::resources::query_result_for_cook::set_unmanaged_resource(
        parent_query,
        (vostok::resources::resource_ptr<vostok::resources::unmanaged_resource,vostok::resources::unmanaged_intrusive_base>)v7.m_object,
        v8,
        v9);
      vostok::resources::query_result_for_cook::finish_query_impl(
        v6,
        result_success,
        assert_on_fail_true,
        error_type_unset);
    }
  }
}
