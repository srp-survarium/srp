void __thiscall survarium::lobby_menu::update_level_loading_progress(survarium::lobby_menu *this, int a2)
{
  int v2; // eax
  unsigned int v3; // edx
  int v4; // eax
  const char *v5; // ecx
  survarium::flash_value *v6; // ecx
  float v7; // xmm1_4
  char string[512]; // [esp+10h] [ebp-234h] BYREF
  Scaleform::GFx::Value pargs; // [esp+210h] [ebp-34h] BYREF
  survarium::flash_value v10; // [esp+228h] [ebp-1Ch] BYREF

  if ( *(_DWORD *)(a2 + 1652) > (unsigned int)vostok::resources::pending_queries_count() )
  {
    v2 = vostok::resources::pending_queries_count();
    *(float *)(a2 + 1648) = *(float *)(a2 + 1648) + (double)(v3 - v2) / (double)v3 * (1.0 - *(float *)(a2 + 1648));
  }
  *(_DWORD *)(a2 + 1652) = vostok::resources::pending_queries_count();
  v4 = vostok::resources::pending_queries_count();
  sprintf_s(string, 0x200u, "%s - %d", v5, v4);
  *(_DWORD *)v10.body = 0;
  *(_DWORD *)&v10.body[4] = 0;
  survarium::flash_value::SetString(&v10, string);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_mm_status",
    0,
    (const Scaleform::GFx::Value *)&v10,
    1u);
  v7 = *(float *)(a2 + 1648);
  pargs.pObjectInterface = 0;
  pargs.Type = VT_Undefined;
  if ( (float)(s_bm_current_air_resistance - v7) < 0.001 )
    v7 = s_bm_current_air_resistance;
  *(float *)(a2 + 1648) = v7;
  survarium::flash_value::SetUInt(v6, (int)&pargs, (unsigned __int64)(v7 * s_spot_max_distance));
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 1600) + 264) + 4),
    "root.set_mm_percent",
    0,
    &pargs,
    1u);
  Scaleform::GFx::Value::~Value(&pargs);
  Scaleform::GFx::Value::~Value((Scaleform::GFx::Value *)&v10);
}
