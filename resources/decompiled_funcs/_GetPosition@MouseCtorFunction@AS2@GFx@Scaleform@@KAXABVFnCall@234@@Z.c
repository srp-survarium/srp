void __cdecl Scaleform::GFx::AS2::MouseCtorFunction::GetPosition(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::Value *Result; // edi
  Scaleform::GFx::AS2::Environment *Env; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // ebx
  unsigned int v4; // edi
  Scaleform::GFx::AS2::Value *v5; // ecx
  int v6; // eax
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::PointObject *v8; // eax
  Scaleform::GFx::AS2::PointObject *v9; // eax
  Scaleform::GFx::AS2::PointObject *v10; // edi
  double v11; // st7
  Scaleform::GFx::AS2::Environment *v12; // eax
  unsigned int RefCount; // eax
  char v14; // [esp+10h] [ebp-24h]
  float v15; // [esp+1Ch] [ebp-18h]
  float v16; // [esp+20h] [ebp-14h]
  Scaleform::Render::Point<double> pt; // [esp+24h] [ebp-10h] BYREF

  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->T.Type = 0;
  Env = fn->Env;
  pMovieImpl = Env->Target->pASRoot->pMovieImpl;
  v4 = 0;
  if ( fn->NArgs > 0 )
  {
    v5 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v5 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v4 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v5, Env);
  }
  if ( v4 < pMovieImpl->GetMouseCursorCount(pMovieImpl) )
  {
    if ( v4 < 6 )
      v6 = (int)&pMovieImpl->mMouseState[v4];
    else
      v6 = 0;
    v15 = *(float *)(v6 + 32);
    pHeap = fn->Env->StringContext.pContext->pHeap;
    v16 = *(float *)(v6 + 36);
    v8 = (Scaleform::GFx::AS2::PointObject *)pHeap->Alloc(pHeap, 52u, 0);
    if ( v8 )
    {
      Scaleform::GFx::AS2::PointObject::PointObject(v8, fn->Env);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    pt.x = floor(v15 + 0.5) * 0.05;
    v11 = floor(v16 + 0.5);
    v12 = fn->Env;
    pt.y = v11 * 0.05;
    Scaleform::GFx::AS2::PointObject::SetProperties(v10, (int)v10, (int)fn, v12, &pt, v14);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v10);
    if ( v10 )
    {
      RefCount = v10->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        v10->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
  }
}
