void __usercall survarium::game_options::refill_item_data(survarium::game_options *this@<ecx>, int a2@<eax>)
{
  survarium::flash_value *v3; // eax
  int i; // ecx
  int v5; // ecx
  int v6; // ecx
  char *v7; // esi
  int j; // edi
  int v9; // eax
  survarium::flash_value options_item_data[3]; // [esp+14h] [ebp-4Ch] BYREF
  char v11; // [esp+5Ch] [ebp-4h] BYREF

  v3 = options_item_data;
  for ( i = 2; i >= 0; --i )
  {
    if ( v3 )
    {
      *(_DWORD *)v3->body = 0;
      *(_DWORD *)&v3->body[4] = 0;
    }
    ++v3;
  }
  if ( (options_item_data[0].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_item_data[0].body + 8))(
      *(_DWORD *)options_item_data[0].body,
      options_item_data,
      *(_DWORD *)&options_item_data[0].body[8]);
    *(_DWORD *)options_item_data[0].body = 0;
  }
  *(_DWORD *)&options_item_data[0].body[4] = 4;
  *(_DWORD *)&options_item_data[0].body[8] = 2;
  if ( (options_item_data[1].body[4] & 0x40) != 0 )
  {
    (*(void (__thiscall **)(_DWORD, survarium::flash_value *, _DWORD))(**(_DWORD **)options_item_data[1].body + 8))(
      *(_DWORD *)options_item_data[1].body,
      &options_item_data[1],
      *(_DWORD *)&options_item_data[1].body[8]);
    *(_DWORD *)options_item_data[1].body = 0;
  }
  v5 = *(_DWORD *)(a2 + 16);
  *(_DWORD *)&options_item_data[1].body[4] = 4;
  *(_DWORD *)&options_item_data[1].body[8] = 1;
  Scaleform::GFx::Movie::CreateArray(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(v5 + 264) + 4),
    (Scaleform::GFx::Value *)&options_item_data[2]);
  v6 = *(_DWORD *)(**(_DWORD **)(a2 + 32) + 4);
  (*(void (__thiscall **)(int, survarium::flash_value *))(*(_DWORD *)v6 + 8))(v6, &options_item_data[2]);
  Scaleform::GFx::Movie::Invoke(
    *(Scaleform::GFx::Movie **)(*(_DWORD *)(*(_DWORD *)(a2 + 16) + 264) + 4),
    "root.set_data_provider",
    0,
    (const Scaleform::GFx::Value *)options_item_data,
    3u);
  v7 = &v11;
  for ( j = 2; j >= 0; --j )
  {
    v9 = *((_DWORD *)v7 - 5);
    v7 -= 24;
    if ( (v9 & 0x40) != 0 )
    {
      (*(void (__stdcall **)(char *, _DWORD))(**(_DWORD **)v7 + 8))(v7, *((_DWORD *)v7 + 2));
      *(_DWORD *)v7 = 0;
    }
    *((_DWORD *)v7 + 1) = 0;
  }
}
