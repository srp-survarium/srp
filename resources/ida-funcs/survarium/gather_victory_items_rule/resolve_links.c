void __thiscall survarium::gather_victory_items_rule::resolve_links(
        survarium::gather_victory_items_rule *this,
        survarium::base_project *project,
        vostok::configs::binary_config_value config)
{
  vostok::configs::binary_config_value *v3; // eax
  vostok::configs::binary_config_value *v4; // eax
  const vostok::configs::binary_config_value *v5; // eax
  vostok::configs::binary_config_value *v6; // ebx
  vostok::configs::binary_config_value *v7; // esi
  const vostok::configs::binary_config_value *v8; // eax
  int v9; // eax
  survarium::base_project::resolve_link_object *v10; // eax
  vostok::configs::binary_config_value v11; // [esp-18h] [ebp-30h] BYREF
  vostok::configs::binary_config_value *pointer; // [esp+10h] [ebp-8h]
  survarium::gather_victory_items_rule *v13; // [esp+14h] [ebp-4h]

  v13 = this;
  v3 = vostok::configs::binary_config_value::operator[](&config, "server_objects");
  pointer = (vostok::configs::binary_config_value *)vostok::configs::binary_config_value::operator[](
                                                      v3,
                                                      "victory_items_containers")->data.pointer;
  v4 = vostok::configs::binary_config_value::operator[](&config, "server_objects");
  v5 = vostok::configs::binary_config_value::operator[](v4, "victory_items_containers");
  v6 = (vostok::configs::binary_config_value *)((char *)v5->data.pointer + 24 * v5->count);
  while ( pointer != v6 )
  {
    v7 = pointer;
    v8 = vostok::configs::binary_config_value::operator[](pointer, "id");
    v9 = *((_DWORD *)&v13->m_children_resources.m_last->resource + LOWORD(v8->data.max_storage));
    if ( v9 )
      v10 = (survarium::base_project::resolve_link_object *)(v9 + 4);
    else
      v10 = 0;
    qmemcpy((void *)&v11, v7, sizeof(v11));
    survarium::base_project::register_object_to_resolve(v10, project, v11);
    ++pointer;
  }
}
