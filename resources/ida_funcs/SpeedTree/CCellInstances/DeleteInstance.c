char __thiscall SpeedTree::CCellInstances::DeleteInstance(
        SpeedTree::CCellInstances *this,
        const struct SpeedTree::CCore *a2,
        const struct SpeedTree::CInstance *a3)
{
  int v4; // [esp-8h] [ebp-94h] BYREF
  int v5; // [esp+0h] [ebp-8Ch]
  int v6; // [esp+4h] [ebp-88h]
  SpeedTree::CCellInstances *v7; // [esp+8h] [ebp-84h]
  int *v8; // [esp+Ch] [ebp-80h]
  int v9; // [esp+10h] [ebp-7Ch]
  int v10; // [esp+14h] [ebp-78h]
  _BYTE v11[12]; // [esp+64h] [ebp-28h] BYREF
  int v12; // [esp+70h] [ebp-1Ch]
  int v13; // [esp+74h] [ebp-18h]
  int v14; // [esp+78h] [ebp-14h]
  unsigned __int8 *src; // [esp+7Ch] [ebp-10h]
  int v16; // [esp+80h] [ebp-Ch] BYREF
  int v17; // [esp+84h] [ebp-8h]
  char v18; // [esp+8Bh] [ebp-1h]

  v7 = this;
  v18 = 0;
  SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::find(&v16, &a2);
  v12 = 0;
  v13 = 0;
  if ( v16 )
  {
    if ( v17 )
    {
      v6 = v16 + *(_DWORD *)(v17 + 4);
      v5 = v6;
    }
    else
    {
      v5 = 0;
    }
    v14 = v5 + 4;
    src = (unsigned __int8 *)SpeedTree::CArray<SpeedTree::CInstance,1>::lower(a3);
    if ( src == (unsigned __int8 *)(*(_DWORD *)(v5 + 8) + 36 * *(_DWORD *)(v5 + 12))
      || !(unsigned __int8)SpeedTree::CInstance::operator==(a3) )
    {
      SpeedTree::CCore::SetError("CCellInstances::DeleteInstance, failed to find requested instance\n");
    }
    else
    {
      SpeedTree::CArray<SpeedTree::CInstance,1>::erase(src);
      if ( !*(_DWORD *)(v14 + 8) )
      {
        v8 = &v4;
        v9 = v17;
        v10 = v16;
        SpeedTree::CMap<SpeedTree::CCore const *,SpeedTree::CArray<SpeedTree::CInstance,1>,1>::erase(v11, v16, v17);
      }
      return 1;
    }
  }
  else
  {
    SpeedTree::CCore::SetError("CCellInstances::DeleteInstance, internal error 1\n");
  }
  return v18;
}
