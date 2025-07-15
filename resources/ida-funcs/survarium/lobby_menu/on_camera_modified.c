void __thiscall survarium::lobby_menu::on_camera_modified(
        survarium::lobby_menu *this,
        survarium::base_game_scene *dist_to_player,
        float a3)
{
  float *v3; // eax
  float *v4; // eax
  int v5; // edi
  survarium::flash_value *v6; // ecx
  survarium::flash_value *v7; // ecx
  int v8; // edx
  survarium::flash_value *v9; // ecx
  survarium::flash_value *v10; // ecx
  survarium::flash_value *v11; // ecx
  vostok::math::float3 *v12; // esi
  survarium::flash_value v13; // [esp+4h] [ebp-80h] BYREF
  _BYTE v14[24]; // [esp+1Ch] [ebp-68h] BYREF
  _BYTE v15[24]; // [esp+34h] [ebp-50h] BYREF
  _BYTE v16[24]; // [esp+4Ch] [ebp-38h] BYREF
  vostok::math::float3 v17; // [esp+64h] [ebp-20h] BYREF
  vostok::math::float2 result; // [esp+70h] [ebp-14h] BYREF
  vostok::math::float3 p; // [esp+78h] [ebp-Ch] BYREF

  v3 = (float *)&(&dist_to_player[6].m_scheduler.m_inactive_objects._M_impl._M_start->m_id)[1];
  result.x = SNaN;
  result.y = SNaN;
  p.x = *v3;
  p.y = v3[1] - 0.1;
  p.z = v3[2];
  survarium::base_game_scene::point_to_screen(&result, dist_to_player, &p);
  v4 = (float *)&(&dist_to_player[6].m_scheduler.m_inactive_objects._M_impl._M_start->m_id)[1];
  p.y = SNaN;
  p.z = SNaN;
  v17.x = *v4;
  v17.y = v4[1] + 2.0;
  v17.z = v4[2];
  survarium::base_game_scene::point_to_screen((vostok::math::float2 *)&p.elements[1], dist_to_player, &v17);
  v5 = 3;
  v6 = &v13;
  do
  {
    survarium::flash_value::flash_value(v6);
    v6 = v7 + 1;
  }
  while ( v8 - 1 >= 0 );
  survarium::flash_value::SetUInt(v6, (int)&v13, (unsigned __int16)(int)(float)(p.y - (float)(200.0 / a3)));
  survarium::flash_value::SetUInt(v9, (int)v14, (unsigned __int16)(int)p.z);
  survarium::flash_value::SetUInt(v10, (int)v15, (unsigned __int16)(int)(float)(p.y + (float)(200.0 / a3)));
  survarium::flash_value::SetUInt(v11, (int)v16, (unsigned __int16)(int)result.y);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(LODWORD(dist_to_player[6].m_game->m_game_world.m_inverted_view_matrix.c.w) + 4),
    "root.set_player_region",
    0,
    (const Scaleform::GFx::Value *)&v13,
    4u);
  v12 = &v17;
  do
  {
    v12 -= 2;
    Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)v12);
    --v5;
  }
  while ( v5 >= 0 );
}
