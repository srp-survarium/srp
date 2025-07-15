void __cdecl Scaleform::GFx::AS2::PointProto::Subtract(int fn)
{
  int v1; // ecx
  Scaleform::GFx::AS2::PointObject *v2; // eax
  Scaleform::GFx::AS2::PointObject *v3; // eax
  Scaleform::GFx::AS2::PointObject *v4; // edi
  Scaleform::GFx::AS2::Environment *v5; // edx
  Scaleform::GFx::AS2::Value *v6; // ecx
  Scaleform::GFx::AS2::Object *v7; // ebx
  unsigned int RefCount; // eax
  int v9; // eax
  Scaleform::GFx::AS2::PointObject *v10; // ecx
  Scaleform::GFx::AS2::Environment *v11; // ecx
  char v12; // [esp+0h] [ebp-2Ch]
  Scaleform::Render::Point<double> pt; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::Render::Point<double> v14; // [esp+1Ch] [ebp-10h] BYREF

  v1 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 116) + 24);
  v2 = (Scaleform::GFx::AS2::PointObject *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v1 + 40))(v1, 52, 0);
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, *(Scaleform::GFx::AS2::Environment **)(fn + 24));
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  if ( *(int *)(fn + 28) <= 0 )
    goto LABEL_18;
  v5 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  v6 = 0;
  if ( *(_DWORD *)(fn + 32) <= 32 * (v5->Stack.Pages.Data.Size - 1) + v5->Stack.pCurrent - v5->Stack.pPageStart )
    v6 = &v5->Stack.Pages.Data.Data[*(_DWORD *)(fn + 32) >> 5]->Values[*(_DWORD *)(fn + 32) & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToObject(v6, v5);
  if ( v7 )
  {
    if ( *(_DWORD *)(fn + 8) && (*(int (__thiscall **)(_DWORD))(**(_DWORD **)(fn + 8) + 8))(*(_DWORD *)(fn + 8)) == 16 )
    {
      v9 = *(_DWORD *)(fn + 8);
      if ( v9 )
        v10 = (Scaleform::GFx::AS2::PointObject *)(v9 - 16);
      else
        v10 = 0;
      Scaleform::GFx::AS2::PointObject::GetProperties(v10, *(Scaleform::GFx::AS2::Environment **)(fn + 24), &pt);
      Scaleform::GFx::AS2::GFxObject_GetPointProperties(*(Scaleform::GFx::AS2::Environment **)(fn + 24), v7, &v14);
      v11 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
      pt.x = pt.x - v14.x;
      pt.y = pt.y - v14.y;
      Scaleform::GFx::AS2::PointObject::SetProperties(v4, (int)v4, fn, v11, &pt, v12);
      Scaleform::GFx::AS2::Value::SetAsObject(*(Scaleform::GFx::AS2::Value **)(fn + 4), v4);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        *(Scaleform::GFx::AS2::Environment **)(fn + 24),
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Point");
    }
  }
  else
  {
LABEL_18:
    Scaleform::GFx::AS2::PointObject::SetProperties(
      v4,
      (Scaleform::GFx::AS2::ASStringContext *)(*(_DWORD *)(fn + 24) + 116),
      Point_NanParams);
    Scaleform::GFx::AS2::Value::SetAsObject(*(Scaleform::GFx::AS2::Value **)(fn + 4), v4);
  }
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
}
