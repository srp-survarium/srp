void __usercall Scaleform::GFx::AS2::PointCtorFunction::Interpolate(char a1@<bl>, int fn)
{
  Scaleform::MemoryHeap *v2; // ecx
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
  Scaleform::GFx::AS2::Environment *v13; // ecx
  int v14; // ebx
  unsigned int Size; // ebp
  Scaleform::GFx::AS2::PagedStack<Scaleform::GFx::AS2::Value,32> *p_Stack; // ecx
  Scaleform::GFx::AS2::Object *v17; // edi
  unsigned int v18; // eax
  const Scaleform::GFx::AS2::Value *v19; // edx
  long double v20; // st7
  char v21; // bl
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Environment *v23; // [esp-Ch] [ebp-5Ch]
  Scaleform::GFx::AS2::PointObject *v25; // [esp+8h] [ebp-48h]
  Scaleform::GFx::AS2::Object *p1; // [esp+Ch] [ebp-44h]
  Scaleform::GFx::AS2::Value f; // [esp+10h] [ebp-40h] BYREF
  Scaleform::Render::Point<double> pt1; // [esp+20h] [ebp-30h] BYREF
  Scaleform::Render::Point<double> pt2; // [esp+30h] [ebp-20h] BYREF
  Scaleform::Render::Point<double> pt; // [esp+40h] [ebp-10h] BYREF

  v2 = *(Scaleform::MemoryHeap **)(*(_DWORD *)(*(_DWORD *)(fn + 24) + 116) + 24);
  v3 = (Scaleform::GFx::AS2::PointObject *)v2->Alloc(v2, 52u, 0);
  if ( v3 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v3, *(Scaleform::GFx::AS2::Environment **)(fn + 24));
    v5 = v4;
    v25 = v4;
  }
  else
  {
    v5 = 0;
    v25 = 0;
  }
  if ( *(int *)(fn + 28) <= 2 )
    goto LABEL_18;
  v6 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  v7 = 0;
  if ( *(_DWORD *)(fn + 32) <= 32 * (v6->Stack.Pages.Data.Size - 1) + v6->Stack.pCurrent - v6->Stack.pPageStart )
    v7 = &v6->Stack.Pages.Data.Data[*(_DWORD *)(fn + 32) >> 5]->Values[*(_DWORD *)(fn + 32) & 0x1F];
  v8 = Scaleform::GFx::AS2::Value::ToObject(v7, v6);
  v9 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  p1 = v8;
  v10 = *(_DWORD *)(fn + 32) - 1;
  v11 = 0;
  if ( v10 <= 32 * (v9->Stack.Pages.Data.Size - 1) + v9->Stack.pCurrent - v9->Stack.pPageStart )
    v11 = &v9->Stack.Pages.Data.Data[v10 >> 5]->Values[v10 & 0x1F];
  v12 = Scaleform::GFx::AS2::Value::ToObject(v11, v9);
  v13 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
  v14 = (char *)v13->Stack.pCurrent - (char *)v13->Stack.pPageStart;
  Size = v13->Stack.Pages.Data.Size;
  p_Stack = &v13->Stack;
  v17 = v12;
  v18 = *(_DWORD *)(fn + 32) - 2;
  v19 = 0;
  if ( v18 <= 32 * (Size - 1) + (v14 >> 4) )
    v19 = &p_Stack->Pages.Data.Data[v18 >> 5]->Values[v18 & 0x1F];
  Scaleform::GFx::AS2::Value::Value(&f, v19);
  if ( p1 && v17 )
  {
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(*(Scaleform::GFx::AS2::Environment **)(fn + 24), p1, &pt1);
    Scaleform::GFx::AS2::GFxObject_GetPointProperties(*(Scaleform::GFx::AS2::Environment **)(fn + 24), v17, &pt2);
    v20 = Scaleform::GFx::AS2::Value::ToNumber(&f, (Scaleform::GFx::AS2::Environment *)*(_DWORD *)(fn + 24));
    v5 = v25;
    v23 = *(Scaleform::GFx::AS2::Environment **)(fn + 24);
    pt.x = pt2.x + (pt1.x - pt2.x) * v20;
    pt.y = v20 * (pt1.y - pt2.y) + pt2.y;
    Scaleform::GFx::AS2::PointObject::SetProperties(v25, (int)v25, fn, v23, &pt, a1);
    v21 = 1;
  }
  else
  {
    v21 = 0;
    v5 = v25;
  }
  if ( f.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&f);
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
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v5->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
    }
  }
}
