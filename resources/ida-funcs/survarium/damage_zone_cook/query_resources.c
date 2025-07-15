void __thiscall survarium::damage_zone_cook::query_resources(
        survarium::damage_zone_cook *this,
        vostok::buffer_vector<vostok::resources::request> *requests,
        const vostok::configs::binary_config_value *cfg_val)
{
  vostok::configs::binary_config_value *v3; // ecx
  int v4; // ecx
  const vostok::configs::binary_config_value *v5; // eax
  int v6; // esi
  int v7; // ecx
  const vostok::configs::binary_config_value *v8; // eax
  vostok::configs::binary_config_value *v9; // ecx
  const void *v10; // eax
  vostok::configs::binary_config_value *v11; // ecx
  const void *v12; // eax
  vostok::configs::binary_config_value *v13; // ecx
  const void *v14; // eax
  const void *v15; // eax
  vostok::configs::binary_config_value *v16; // ecx
  const char *v17; // eax
  vostok::configs::binary_config_value *v18; // ecx
  const char *v19; // eax
  vostok::configs::binary_config_value *v20; // ecx
  const char *v21; // eax
  int v22; // ebx
  const char *v23; // eax
  int v24; // [esp+Ch] [ebp-14h]
  int v25; // [esp+10h] [ebp-10h]
  const char *pointer; // [esp+14h] [ebp-Ch]
  int v27; // [esp+14h] [ebp-Ch]
  const char *v28; // [esp+14h] [ebp-Ch]
  int v29; // [esp+14h] [ebp-Ch]
  const char *v30; // [esp+14h] [ebp-Ch]
  int v31; // [esp+14h] [ebp-Ch]
  const char *v32; // [esp+14h] [ebp-Ch]
  int v33; // [esp+14h] [ebp-Ch]
  int v34; // [esp+14h] [ebp-Ch]
  int v35; // [esp+14h] [ebp-Ch]
  int v36; // [esp+14h] [ebp-Ch]
  vostok::resources::request v37; // [esp+18h] [ebp-8h] BYREF

  survarium::damage_zone_core_cook::query_resources(this, requests, cfg_val);
  if ( vostok::configs::binary_config_value::value_exists(v3, (int)cfg_val, (unsigned int)"sound_zones") )
  {
    v5 = vostok::configs::binary_config_value::operator[](cfg_val, "sound_zones");
    v4 = 24;
    v6 = 24 * v5->count / 24;
    v25 = v6;
  }
  else
  {
    v25 = 0;
    v6 = 0;
  }
  if ( vostok::configs::binary_config_value::value_exists(
         (vostok::configs::binary_config_value *)v4,
         (int)cfg_val,
         (unsigned int)"effect_zones") )
  {
    v8 = vostok::configs::binary_config_value::operator[](cfg_val, "effect_zones");
    v7 = 24;
    v24 = 24 * v8->count / 24;
  }
  else
  {
    v24 = 0;
  }
  if ( v6 )
  {
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)v7,
           (int)cfg_val,
           (unsigned int)"activated_sound") )
    {
      pointer = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "activated_sound")->data.pointer;
      v10 = vostok::configs::binary_config_value::operator[](cfg_val, "activated_sound_resource_id")->data.pointer;
      v37.path = pointer;
      v37.id = (vostok::resources::class_id_enum)v10;
      v27 = v6;
      do
      {
        vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
        --v27;
      }
      while ( v27 );
      v6 = v25;
    }
    if ( vostok::configs::binary_config_value::value_exists(v9, (int)cfg_val, (unsigned int)"idle_sound") )
    {
      v28 = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "idle_sound")->data.pointer;
      v12 = vostok::configs::binary_config_value::operator[](cfg_val, "idle_sound_resource_id")->data.pointer;
      if ( v6 )
      {
        v37.path = v28;
        v37.id = (vostok::resources::class_id_enum)v12;
        v29 = v6;
        do
        {
          vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
          --v29;
        }
        while ( v29 );
        v6 = v25;
      }
    }
    if ( vostok::configs::binary_config_value::value_exists(v11, (int)cfg_val, (unsigned int)"deactivated_sound") )
    {
      v30 = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "deactivated_sound")->data.pointer;
      v14 = vostok::configs::binary_config_value::operator[](cfg_val, "deactivated_sound_resource_id")->data.pointer;
      if ( v6 )
      {
        v37.path = v30;
        v37.id = (vostok::resources::class_id_enum)v14;
        v31 = v6;
        do
        {
          vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
          --v31;
        }
        while ( v31 );
        v6 = v25;
      }
    }
    if ( vostok::configs::binary_config_value::value_exists(v13, (int)cfg_val, (unsigned int)"hit_sound") )
    {
      v32 = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "hit_sound")->data.pointer;
      v15 = vostok::configs::binary_config_value::operator[](cfg_val, "hit_sound_resource_id")->data.pointer;
      if ( v6 )
      {
        v37.path = v32;
        v37.id = (vostok::resources::class_id_enum)v15;
        v33 = v6;
        do
        {
          vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
          --v33;
        }
        while ( v33 );
      }
    }
  }
  if ( v24 )
  {
    if ( vostok::configs::binary_config_value::value_exists(
           (vostok::configs::binary_config_value *)v7,
           (int)cfg_val,
           (unsigned int)"activated_particle") )
    {
      v17 = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "activated_particle")->data.pointer;
      v37.path = v17;
      v37.id = particle_system_instance_class;
      v34 = v24;
      do
      {
        vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
        --v34;
      }
      while ( v34 );
    }
    if ( vostok::configs::binary_config_value::value_exists(v16, (int)cfg_val, (unsigned int)"idle_particle") )
    {
      v19 = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "idle_particle")->data.pointer;
      v37.path = v19;
      v37.id = particle_system_instance_class;
      v35 = v24;
      do
      {
        vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
        --v35;
      }
      while ( v35 );
    }
    if ( vostok::configs::binary_config_value::value_exists(v18, (int)cfg_val, (unsigned int)"deactivated_particle") )
    {
      v21 = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "deactivated_particle")->data.pointer;
      v37.path = v21;
      v37.id = particle_system_instance_class;
      v36 = v24;
      do
      {
        vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
        --v36;
      }
      while ( v36 );
    }
    if ( vostok::configs::binary_config_value::value_exists(v20, (int)cfg_val, (unsigned int)"hit_particle") )
    {
      v22 = v24;
      v23 = (const char *)vostok::configs::binary_config_value::operator[](cfg_val, "hit_particle")->data.pointer;
      v37.path = v23;
      v37.id = particle_system_instance_class;
      do
      {
        vostok::buffer_vector<vostok::resources::request>::push_back(requests, &v37);
        --v22;
      }
      while ( v22 );
    }
  }
}
