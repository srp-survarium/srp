void __cdecl Scaleform::GFx::AS2::RectangleProto::Equals(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::RectangleObject *v5; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::RectangleObject *p_pProto; // ecx
  int v8; // edx
  Scaleform::GFx::AS2::Environment *v9; // edx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::Render::Rect<double> v12; // [esp+Ch] [ebp-40h] BYREF
  Scaleform::Render::Rect<double> r; // [esp+2Ch] [ebp-20h] BYREF

  v1 = 0;
  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
    v5 = (Scaleform::GFx::AS2::RectangleObject *)v4;
    if ( v4 )
    {
      if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) == Object_Rectangle )
      {
        if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Rectangle )
        {
          Scaleform::GFx::AS2::Environment::LogScriptError(
            fn->Env,
            "Error: Null or invalid 'this' is used for a method of %s class.\n",
            "Rectangle");
          return;
        }
        ThisPtr = fn->ThisPtr;
        if ( ThisPtr )
          p_pProto = (Scaleform::GFx::AS2::RectangleObject *)&ThisPtr[-2].pProto;
        else
          p_pProto = 0;
        v8 = v5->RefCount + 1;
        r.x1 = 0.0;
        r.y1 = 0.0;
        r.x2 = 0.0;
        r.y2 = 0.0;
        v5->RefCount = v8 & 0x8FFFFFFF;
        v9 = fn->Env;
        v12.x1 = 0.0;
        v12.y1 = 0.0;
        v12.x2 = 0.0;
        v12.y2 = 0.0;
        Scaleform::GFx::AS2::RectangleObject::GetProperties(p_pProto, v9, &r);
        Scaleform::GFx::AS2::RectangleObject::GetProperties(v5, fn->Env, &v12);
        if ( Scaleform::GFx::AS2::IsRectValid(&r) && Scaleform::GFx::AS2::IsRectValid(&v12) )
          v1 = Scaleform::Render::Rect<double>::operator==(&r, &v12);
        RefCount = v5->RefCount;
        if ( (RefCount & 0x3FFFFFF) != 0 )
        {
          v5->RefCount = RefCount - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
        }
      }
    }
  }
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->V.BooleanValue = v1;
  Result->T.Type = 2;
}
