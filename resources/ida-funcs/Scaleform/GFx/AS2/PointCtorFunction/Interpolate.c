void __usercall Scaleform::GFx::AS2::PointCtorFunction::Interpolate(char a1@<bl>, int fn)
{
  int v2; // ecx
  Scaleform::GFx::AS2::PointObject *v3; // eax
  Scaleform::GFx::AS2::PointObject *v4; // eax
  Scaleform::GFx::AS2::PointObject *v5; // edi
  Scaleform::GFx::AS2::Environment *v6; // edx
  Scaleform::GFx::AS2::Value *v7; // ecx
  Scaleform::GFx::AS2::Object *v8; // eax
  Scaleform::GFx::AS2::Environment *v9; // edx
  unsigned int v10; // eax
  Scaleform::GFx::AS2::Value *v11; // ecx
  Scaleform::GFx::AS2::Object *v12; // eax
  _DWORD *v13; // ecx
  int v14; // ebx
  int v15; // ebp
  _DWORD *v16; // ecx
  Scaleform::GFx::AS2::Object *v17; // edi
  unsigned int v18; // eax
  const Scaleform::GFx::AS2::Value *v19; // edx
  long double v20; // st7
  char v21; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v23; // [esp-Ch] [ebp-5Ch]
  Scaleform::GFx::AS2::PointObject *obj; // [esp+8h] [ebp-48h]
  Scaleform::GFx::AS2::Object *pobj; // [esp+Ch] [ebp-44h]
  Scaleform::GFx::AS2::Value v27; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Point<double> pt; // [esp+20h] [ebp-30h] BYREF
  Scaleform::Render::Point<double> v29; // [esp+30h] [ebp-20h] BYREF
  Scaleform::Render::Point<double> v30; // [esp+40h] [ebp-10h] BYREF

  v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 116) + 24);
  v3 = (Scaleform::GFx::AS2::PointObject *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v2 + 40))(v2, 52, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v3, *(Scaleform::GFx::AS2::Environment **)(fn + 24));
    v5 = v4;
    obj = v4;
  }
  else
  {
    v5 = 0;
    obj = 0;
  }
  if ( *(int *)(fn + 28) <= 2 )
    goto LABEL_18;
  v6 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  v7 = 0;
  if ( *(_DWORD *)(fn + 32) <= 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart )
    v7 = &v6->Stack.Pages.Data.Data[*(_DWORD *)(fn + 32) >> 5]->Values[*(_DWORD *)(fn + 32) & 0x1F];
  v8 = Scaleform::GFx::AS2::Value::ToObject(v7, v6);
  v9 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  pobj = v8;
  v10 = *(_DWORD *)(fn + 32) - 1;
  v11 = 0;
  if ( v10 <= 32 * (v9->Stack.Pages.Data.Size - 1) + v9->Stack.pCurrent - v9->Stack.pPageStart )
    v11 = &v9->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
  v12 = Scaleform::GFx::AS2::Value::ToObject(v11, v9);
  v13 = *(_DWORD **)(fn + 24);
  v14 = v13[1] - v13[2];
  v15 = v13[6];
  v16 = v13 + 1;
  v17 = v12;
  v18 = *(_DWORD *)(fn + 32) - 2;
  v19 = 0;
  if ( v18 <= 32 * (v15 - 1) + (v14 >> 4) )
    v19 = (const Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v16[4] + 4 * (v18 >> 5)) + 16 * (v18 & 0x1F));
  Scaleform::GFx::AS2::Value::Value(&v27, v19);
  if ( pobj && v17 )
  {
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(*(Scaleform::GFx::AS2::Environment **)(fn + 24), pobj, &pt);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(*(Scaleform::GFx::AS2::Environment **)(fn + 24), v17, &v29);
    v20 = Scaleform::GFx::AS2::Value::ToNumber(&v27, (Scaleform::GFx::AS2::Environment *)*(_DWORD *)(fn + 24));
    v5 = obj;
    v23 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
    v30.x = v29.x + (pt.x - v29.x) * v20;
    v30.y = v20 * (pt.y - v29.y) + v29.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(obj, (int)obj, fn, v23, &v30, a1);
    v21 = 1;
  }
  else
  {
    v21 = 0;
    v5 = obj;
  }
  if ( v27.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v27);
  if ( !v21 )
LABEL_18:
    Scaleform::GFx::AS2::PointObject::SetProperties(
      v5,
      (Scaleform::GFx::AS2::ASStringContext *)(*(_DWORD *)(fn + 24) + 116),
      Point_NanParams);
  Scaleform::GFx::AS2::Value::SetAsObject(*(Scaleform::GFx::AS2::Value **)(fn + 4), v5);
  if ( v5 )
  {
    RefCount = v5->RefCount;
    if ( (RefCount & 0x3FFFFFF) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}
