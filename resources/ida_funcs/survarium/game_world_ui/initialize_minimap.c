void __thiscall survarium::game_world_ui::initialize_minimap(
        survarium::game_world_ui *this,
        survarium::game_world_ui *thisa)
{
  survarium::simple_game_project *m_object; // eax
  vostok::resources::unmanaged_resource *v3; // esi
  const char *pointer; // edi
  survarium::flash_movie_resource *v5; // edx
  survarium::flash_movie_resource *v6; // edx
  survarium::game_world_ui *v7; // ecx
  survarium::game_world_ui *v8; // ecx
  survarium::flash_value minimap_props_value_property; // [esp+18h] [ebp-30h] BYREF
  survarium::flash_value minimap_props_value; // [esp+30h] [ebp-18h] BYREF

  m_object = thisa->m_game_world->m_game_project.m_object;
  v3 = 0;
  if ( m_object )
  {
    v3 = thisa->m_game_world->m_game_project.m_object;
    _InterlockedExchangeAdd(&m_object->m_reference_count, 1u);
  }
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v3[1].m_children_resources.m_first[22].resource,
         "project_name") )
  {
    pointer = (const char *)vostok::configs::binary_config_value::operator[](
                              (vostok::configs::binary_config_value *)v3[1].m_children_resources.m_first[22].resource,
                              "project_name")->data.pointer;
  }
  else
  {
    pointer = (const char *)&buf;
  }
  if ( !_InterlockedExchangeAdd(&v3->m_reference_count, 0xFFFFFFFF) )
    vostok::resources::unmanaged_intrusive_base::destroy(&v3->vostok::resources::unmanaged_intrusive_base, v3);
  v5 = thisa->m_game_hud_ui.m_object;
  *(_DWORD *)minimap_props_value.body = 0;
  *(_DWORD *)&minimap_props_value.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(v5->movie->m_movie, (Scaleform::GFx::Value *)&minimap_props_value, 0, 0, 0);
  v6 = thisa->m_game_hud_ui.m_object;
  *(_DWORD *)minimap_props_value_property.body = 0;
  *(_DWORD *)&minimap_props_value_property.body[4] = 0;
  Scaleform::GFx::Movie::CreateObject(
    v6->movie->m_movie,
    (Scaleform::GFx::Value *)&minimap_props_value_property,
    0,
    0,
    0);
  survarium::flash_value::SetString(&minimap_props_value_property, pointer);
  (*(void (__thiscall **)(_DWORD, _DWORD, const char *, survarium::flash_value *, bool))(**(_DWORD **)minimap_props_value.body
                                                                                       + 20))(
    *(_DWORD *)minimap_props_value.body,
    *(_DWORD *)&minimap_props_value.body[8],
    "map",
    &minimap_props_value_property,
    (minimap_props_value.body[4] & 0x8F) == 10);
  Scaleform::GFx::Movie::Invoke(
    thisa->m_game_hud_ui.m_object->movie->m_movie,
    "root.set_minimap_props",
    0,
    (const Scaleform::GFx::Value *)&minimap_props_value,
    1u);
  survarium::game_world_ui::update_minimap_objects(v7, thisa);
  survarium::game_world_ui::reset_map_rotatable(v8, (int)thisa);
  if ( (minimap_props_value_property.body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)minimap_props_value_property.body + 8))(
      *(_DWORD *)minimap_props_value_property.body,
      &minimap_props_value_property,
      *(_DWORD *)&minimap_props_value_property.body[8]);
    *(_DWORD *)minimap_props_value_property.body = 0;
  }
  *(_DWORD *)&minimap_props_value_property.body[4] = 0;
  if ( (minimap_props_value.body[4] & 0x40) != 0 )
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)minimap_props_value.body + 8))(
      *(_DWORD *)minimap_props_value.body,
      &minimap_props_value,
      *(_DWORD *)&minimap_props_value.body[8]);
}
