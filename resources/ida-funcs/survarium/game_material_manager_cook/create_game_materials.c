void __thiscall survarium::game_material_manager_cook::create_game_materials(
        survarium::game_material_manager_cook *this,
        survarium::game_material_manager_cook *manager,
        vostok::configs::binary_config_value **materials_root)
{
  vostok::configs::binary_config_value **v3; // eax
  vostok::configs::binary_config_value *v4; // ebx
  vostok::configs::binary_config_value *v5; // ebp
  vostok::memory::doug_lea_allocator *v6; // esi
  char *v7; // eax
  vostok::memory::doug_lea_allocator *v8; // ecx
  int v9; // ecx
  char *v10; // esi
  float v11; // xmm0_4
  vostok::configs::binary_config_value *i; // esi
  const vostok::configs::binary_config_value *v13; // eax
  vostok::configs::binary_config_value *v14; // ecx
  vostok::configs::binary_config_value *v15; // eax
  const char *pointer; // ebx
  unsigned __int16 *v17; // eax
  survarium::game_material_manager *v18; // ecx
  unsigned __int16 v19; // di
  const char **v20; // eax
  const char *v21; // [esp+0h] [ebp-14h]
  const char *v22; // [esp+4h] [ebp-10h]
  unsigned int v23; // [esp+8h] [ebp-Ch]
  const survarium::game_material *material; // [esp+1Ch] [ebp+8h]

  v3 = materials_root;
  v4 = *materials_root;
  v5 = &(*materials_root)[*((unsigned __int16 *)materials_root + 11)];
  if ( *materials_root != v5 )
  {
    do
    {
      if ( !vostok::configs::binary_config_value::value_exists(
              (vostok::configs::binary_config_value *)this,
              (int)v4,
              (unsigned int)"deleted")
        || !vostok::configs::binary_config_value::operator[](v4, "deleted")->data.pointer )
      {
        v6 = survarium::g_allocator;
        v7 = type_info::raw_name(&survarium::game_material `RTTI Type Descriptor');
        v10 = vostok::memory::doug_lea_allocator::malloc_impl(v8, (int)v6, 0x6Cu, v7, v21, v22, v23);
        if ( v10 )
        {
          vostok::fixed_string<64>::fixed_string<64>(
            (vostok::fixed_string<64> *)v9,
            (vostok::buffer_string *)v10,
            "default");
          *((float *)v10 + 19) = retry_to_increase_quality_period_sec;
          v11 = s_bm_current_air_resistance;
          v9 = 0xFFFF;
          *((float *)v10 + 20) = s_bm_current_air_resistance;
          *((float *)v10 + 21) = s_aim_transition_time;
          *((float *)v10 + 22) = v11;
          *((float *)v10 + 23) = v11;
          *((float *)v10 + 24) = v11;
          *((_WORD *)v10 + 50) = -1;
          *((_WORD *)v10 + 51) = -1;
          v10[104] = 0;
          v10[105] = 0;
          v10[106] = 0;
        }
        else
        {
          v10 = 0;
        }
        survarium::game_material::load_from_config((survarium::game_material *)v9, (int)v10, v4);
        this = (survarium::game_material_manager_cook *)*((unsigned __int16 *)v10 + 50);
        *((_DWORD *)&manager[7].m_reuse_type + (_DWORD)this) = v10;
        LOWORD(this) = *((_WORD *)v10 + 50);
        if ( (_WORD)this == *(_WORD *)((char *)&off_1030C + (_DWORD)manager) )
          *(int *)((char *)&dword_10308 + (_DWORD)manager) = (int)v10;
      }
      ++v4;
    }
    while ( v4 != v5 );
    v3 = materials_root;
  }
  for ( i = *v3; i != v5; ++i )
  {
    if ( !vostok::configs::binary_config_value::value_exists(
            (vostok::configs::binary_config_value *)this,
            (int)i,
            (unsigned int)"deleted")
      || !vostok::configs::binary_config_value::operator[](i, "deleted")->data.pointer )
    {
      v13 = vostok::configs::binary_config_value::operator[](i, "physic");
      if ( vostok::configs::binary_config_value::value_exists(v14, (int)v13, (unsigned int)"base_material") )
      {
        v15 = vostok::configs::binary_config_value::operator[](i, "physic");
        pointer = (const char *)vostok::configs::binary_config_value::operator[](v15, "base_material")->data.pointer;
        v17 = (unsigned __int16 *)vostok::configs::binary_config_value::operator[](i, "id");
        material = survarium::game_material_manager::get_material(v18, (int)manager, *v17);
        v19 = 0;
        while ( 1 )
        {
          this = manager;
          v20 = (const char **)*((_DWORD *)&manager[7].m_reuse_type + v19);
          if ( v20 )
          {
            if ( !vostok::strings::compare(*v20, pointer) )
              break;
          }
          if ( ++v19 >= 0x80u )
            goto LABEL_21;
        }
        material->m_base_material_id = v19;
      }
    }
LABEL_21:
    ;
  }
}
