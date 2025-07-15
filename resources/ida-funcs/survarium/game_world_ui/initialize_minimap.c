void __thiscall survarium::game_world_ui::initialize_minimap(
        survarium::game_world_ui *this,
        vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock> a2)
{
  survarium::simple_game_project *m_object; // ebx
  vostok::resources::resource_ptr<vostok::configs::binary_config,vostok::resources::unmanaged_intrusive_base> *p_m_config; // esi
  vostok::configs::binary_config_value *v4; // ecx
  const char *pointer; // edi
  stlp_std::priv::_Rb_tree_node_base *M_parent; // eax
  survarium::flash_movie *v7; // ecx
  stlp_std::priv::_Rb_tree_node_base *v8; // eax
  survarium::flash_movie *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::game_world_ui *v11; // ecx
  Scaleform::GFx::Value pargs; // [esp+10h] [ebp-34h] BYREF
  survarium::flash_value value; // [esp+28h] [ebp-1Ch] BYREF

  m_object = a2.m_object;
  p_m_config = &survarium::game_world::get_project(
                  (survarium::game_world *)a2.m_object->m_objects_registry._M_t._M_node_count,
                  &a2)->m_object->m_config;
  if ( vostok::configs::binary_config_value::value_exists(
         v4,
         (int)p_m_config->m_object->m_root,
         (unsigned int)"project_name") )
  {
    pointer = (const char *)vostok::configs::binary_config_value::operator[](
                              p_m_config->m_object->m_root,
                              "project_name")->data.pointer;
  }
  else
  {
    pointer = uri;
  }
  vostok::intrusive_ptr<survarium::simple_game_project,vostok::resources::unmanaged_intrusive_base,vostok::threading::simple_lock>::dec(&a2);
  M_parent = m_object->m_objects_registry._M_t._M_header._M_data._M_parent;
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  survarium::flash_movie::CreateObject(v7, (survarium::flash_value *)M_parent[16]._M_left, &pargs);
  v8 = m_object->m_objects_registry._M_t._M_header._M_data._M_parent;
  *(_DWORD *)value.body = 0;
  *(_DWORD *)&value.body[4] = 0;
  survarium::flash_movie::CreateObject(v9, (survarium::flash_value *)v8[16]._M_left, (Scaleform::GFx::Value *)&value);
  survarium::flash_value::SetString(&value, pointer);
  survarium::flash_value::SetMember(v10, &pargs, "map", &value);
  Scaleform::GFx::Movie::Invoke(
    (Scaleform::GFx::Movie *)m_object->m_objects_registry._M_t._M_header._M_data._M_parent[16]._M_left->_M_parent,
    "root.set_minimap_props",
    0,
    &pargs,
    1u);
  survarium::game_world_ui::reset_map_rotatable(v11, (int)m_object);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&value);
  Scaleform::GFx::Value::~Value(&pargs);
}
