long double __cdecl Scaleform::GFx::AS2::MouseCtorFunction::GetPosition(int fn)
{
  Scaleform::GFx::AS2::Value *v1; // edi
  Scaleform::GFx::AS2::Environment *v2; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned int v4; // edi
  Scaleform::GFx::AS2::Value *v5; // ecx
  long double result; // st7
  int v7; // eax
  int v8; // ecx
  Scaleform::GFx::AS2::PointObject *v9; // eax
  Scaleform::GFx::AS2::PointObject *v10; // eax
  Scaleform::GFx::AS2::PointObject *v11; // edi
  Scaleform::GFx::AS2::Environment *v12; // eax
  unsigned int RefCount; // eax
  char v14; // [esp+10h] [ebp-24h]
  float v15; // [esp+1Ch] [ebp-18h]
  float v16; // [esp+20h] [ebp-14h]
  Scaleform::Render::Point<double> v17; // [esp+24h] [ebp-10h] BYREF

  v1 = *(Scaleform::GFx::AS2::Value **)(fn + 4);
  Scaleform::GFx::AS2::Value::DropRefs(v1);
  v1->T.Type = 0;
  v2 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  pMovieImpl = v2->Target->pASRoot->pMovieImpl;
  v4 = 0;
  if ( *(int *)(fn + 28) > 0 )
  {
    v5 = 0;
    if ( *(_DWORD *)(fn + 32) <= 32 * (v2->Stack.Pages.Data.Size - 1) + v2->Stack.pCurrent - v2->Stack.pPageStart )
      v5 = &v2->Stack.Pages.Data.Data[*(_DWORD *)(fn + 32) >> 5]->Values[*(_DWORD *)(fn + 32) & 0x1F];
    result = Scaleform::GFx::AS2::Value::ToNumber(v5, v2);
    v4 = (__int64)result;
  }
  if ( v4 < pMovieImpl->GetMouseCursorCount(pMovieImpl) )
  {
    if ( v4 < 6 )
      v7 = (int)&pMovieImpl->mMouseState[v4];
    else
      v7 = 0;
    v15 = *(float *)(v7 + 32);
    v8 = *(_DWORD *)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 116) + 24);
    v16 = *(float *)(v7 + 36);
    v9 = (Scaleform::GFx::AS2::PointObject *)(*(int (__thiscall **)(int, int, _DWORD))(*(_DWORD *)v8 + 40))(v8, 52, 0);
    if ( v9 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v9, *(Scaleform::GFx::AS2::Environment **)(fn + 24));
      v11 = v10;
    }
    else
    {
      v11 = 0;
    }
    v17.x = floor(v15 + 0.5) * 0.05;
    result = floor(v16 + 0.5) * 0.05;
    v12 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
    v17.y = result;
    Scaleform::GFx::AS2::PointObject::SetProperties(v11, (int)v11, fn, v12, &v17, v14);
    Scaleform::GFx::AS2::Value::SetAsObject(*(Scaleform::GFx::AS2::Value **)(fn + 4), v11);
    if ( v11 )
    {
      RefCount = v11->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        v11->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v11);
      }
    }
  }
  return result;
}
