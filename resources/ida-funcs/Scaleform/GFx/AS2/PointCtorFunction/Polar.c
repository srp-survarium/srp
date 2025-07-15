void __usercall Scaleform::GFx::AS2::PointCtorFunction::Polar(char a1@<bpl>, int fn)
{
  int v2; // ecx
  Scaleform::GFx::AS2::PointObject *v3; // eax
  Scaleform::GFx::AS2::PointObject *v4; // eax
  Scaleform::GFx::AS2::PointObject *v5; // edi
  int v6; // eax
  int v7; // ebx
  int v8; // eax
  const Scaleform::GFx::AS2::Value *v9; // edx
  _DWORD *v10; // ecx
  int v11; // ebx
  int v12; // ebp
  _DWORD *v13; // ecx
  unsigned int v14; // eax
  const Scaleform::GFx::AS2::Value *v15; // edx
  Scaleform::GFx::AS2::Environment *v16; // edx
  unsigned int RefCount; // eax
  long double v19; // [esp+8h] [ebp-40h]
  long double v20; // [esp+10h] [ebp-38h]
  Scaleform::GFx::AS2::Value v21; // [esp+18h] [ebp-30h] BYREF
  Scaleform::GFx::AS2::Value v22; // [esp+28h] [ebp-20h] BYREF
  Scaleform::Render::Point<double> v23; // [esp+38h] [ebp-10h] BYREF

  v2 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 116) + 24);
  v3 = (Scaleform::GFx::AS2::PointObject *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v2 + 40))(v2, 52, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v3, *(Scaleform::GFx::AS2::Environment **)(fn + 24));
    v5 = v4;
  }
  else
  {
    v5 = 0;
  }
  v6 = *(_DWORD *)(fn + 24);
  if ( *(int *)(fn + 28) <= 1 )
  {
    Scaleform::GFx::AS2::PointObject::SetProperties(
      v5,
      (Scaleform::GFx::AS2::ASStringContext *)(v6 + 116),
      Point_NanParams);
  }
  else
  {
    v7 = *(_DWORD *)(v6 + 4) - *(_DWORD *)(v6 + 8);
    v8 = v6 + 4;
    v9 = 0;
    if ( *(_DWORD *)(fn + 32) <= (unsigned int)(32 * (*(_DWORD *)(v8 + 20) - 1) + (v7 >> 4)) )
      v9 = (const Scaleform::GFx::AS2::Value *)(*(_DWORD *)(*(_DWORD *)(v8 + 16) + 4 * (*(_DWORD *)(fn + 32) >> 5))
                                              + 16 * (*(_DWORD *)(fn + 32) & 0x1F));
    Scaleform::GFx::AS2::Value::Value(&v22, v9);
    v10 = *(_DWORD **)(fn + 24);
    v11 = v10[1] - v10[2];
    v12 = v10[6];
    v13 = v10 + 1;
    v14 = *(_DWORD *)(fn + 32) - 1;
    v15 = 0;
    if ( v14 <= 32 * (v12 - 1) + (v11 >> 4) )
      v15 = (const Scaleform::GFx::AS2::Value *)(*(_DWORD *)(v13[4] + 4 * (v14 >> 5)) + 16 * (v14 & 0x1F));
    Scaleform::GFx::AS2::Value::Value(&v21, v15);
    v19 = Scaleform::GFx::AS2::Value::ToNumber(&v22, (Scaleform::GFx::AS2::Environment *)*(_DWORD *)(fn + 24));
    v20 = Scaleform::GFx::AS2::Value::ToNumber(&v21, (Scaleform::GFx::AS2::Environment *)*(_DWORD *)(fn + 24));
    v23.x = cos(v20) * v19;
    v16 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
    v23.y = sin(v20) * v19;
    Scaleform::GFx::AS2::PointObject::SetProperties(v5, (int)v5, fn, v16, &v23, a1);
    if ( v21.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v21);
    if ( v22.T.Type >= 5u )
      Scaleform::GFx::AS2::Value::DropRefs(&v22);
  }
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
