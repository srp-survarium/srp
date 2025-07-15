void __cdecl Scaleform::GFx::AS2::PointProto::Add(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  Scaleform::GFx::AS2::PointObject *v2; // eax
  Scaleform::GFx::AS2::PointObject *v3; // eax
  Scaleform::GFx::AS2::PointObject *v4; // edi
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v6; // ecx
  Scaleform::GFx::AS2::Object *v7; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::PointObject *p_pProto; // ecx
  Scaleform::GFx::AS2::Environment *v11; // ecx
  char v12; // [esp+0h] [ebp-2Ch]
  Scaleform::Render::Point<double> pt1; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::Render::Point<double> pt2; // [esp+1Ch] [ebp-10h] BYREF

  pHeap = fn->Env->StringContext.pContext->pHeap;
  v2 = (Scaleform::GFx::AS2::PointObject *)pHeap->Alloc(pHeap, 52u, 0);
  if ( v2 )
  {
    Scaleform::GFx::AS2::PointObject::PointObject(v2, fn->Env);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  if ( fn->NArgs <= 0 )
    goto LABEL_18;
  Env = fn->Env;
  v6 = 0;
  if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
    v6 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex & 0x1F];
  v7 = Scaleform::GFx::AS2::Value::ToObject(v6, Env);
  if ( v7 )
  {
    if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Point )
    {
      ThisPtr = fn->ThisPtr;
      if ( ThisPtr )
        p_pProto = (Scaleform::GFx::AS2::PointObject *)&ThisPtr[-2].pProto;
      else
        p_pProto = 0;
      Scaleform::GFx::AS2::PointObject::GetProperties(p_pProto, fn->Env, &pt1);
      Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v7, &pt2);
      v11 = fn->Env;
      pt1.x = pt1.x + pt2.x;
      pt1.y = pt2.y + pt1.y;
      Scaleform::GFx::AS2::PointObject::SetProperties(v4, (int)v4, (int)fn, v11, &pt1, v12);
      Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
    }
    else
    {
      Scaleform::GFx::AS2::Environment::LogScriptError(
        fn->Env,
        "Error: Null or invalid 'this' is used for a method of %s class.\n",
        "Point");
    }
  }
  else
  {
LABEL_18:
    Scaleform::GFx::AS2::PointObject::SetProperties(v4, &fn->Env->StringContext, Point_NanParams);
    Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, v4);
  }
  if ( v4 )
  {
    RefCount = v4->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v4->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
    }
  }
}
