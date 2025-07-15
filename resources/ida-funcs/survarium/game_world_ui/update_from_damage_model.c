void __thiscall survarium::game_world_ui::update_from_damage_model(
        survarium::game_world_ui *this,
        const survarium::damage_model *d_model,
        int a3)
{
  unsigned int v3; // esi
  survarium::body_part_parameters *body_part; // edi
  survarium::flash_value *v5; // ecx
  survarium::flash_value *v6; // ecx
  int v7; // edx
  unsigned int v8; // ebx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  char **v11; // esi
  int i; // edi
  survarium::flash_value v13; // [esp+14h] [ebp-68h] BYREF
  _BYTE v14[24]; // [esp+2Ch] [ebp-50h] BYREF
  _BYTE v15[24]; // [esp+44h] [ebp-38h] BYREF
  char *part_name[8]; // [esp+5Ch] [ebp-20h] BYREF

  part_name[0] = "left_hand";
  part_name[1] = "right_hand";
  part_name[2] = "left_leg";
  part_name[3] = "right_leg";
  part_name[4] = "head";
  part_name[5] = "body";
  part_name[6] = "pain";
  part_name[7] = "infection";
  v3 = 0;
  do
  {
    body_part = survarium::damage_model::get_body_part((survarium::damage_model *)this, a3, part_name[v3]);
    v5 = &v13;
    do
    {
      survarium::flash_value::flash_value(v5);
      v5 = v6 + 1;
    }
    while ( v7 - 1 >= 0 );
    v8 = v3 + 1;
    survarium::flash_value::SetUInt(v5, (int)&v13, v3 + 1);
    survarium::flash_value::SetNumber(v9, (int)v14, body_part->m_health / body_part->m_max_health);
    survarium::flash_value::SetNumber(v10, (int)v15, body_part->m_regeneration_threshold);
    Scaleform::GFx::Movie::Invoke(
      *(Scaleform::GFx::Movie **)(*(_DWORD *)(d_model->vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags.vostok::resources::unmanaged_resource::vostok::resources::resource_base::vostok::resources::resource_quality::vostok::resources::resource_children::vostok::resources::resource_flags::m_flags
                                            + 264)
                                + 4),
      "root.set_body_part_hp",
      0,
      (const Scaleform::GFx::Value *)&v13,
      3u);
    v11 = part_name;
    for ( i = 2; i >= 0; --i )
    {
      v11 -= 6;
      Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)v11);
    }
    v3 = v8;
  }
  while ( v8 < 6 );
}
