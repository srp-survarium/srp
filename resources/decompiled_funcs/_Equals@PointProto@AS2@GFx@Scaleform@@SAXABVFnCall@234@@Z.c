void __cdecl Scaleform::GFx::AS2::PointProto::Equals(const Scaleform::GFx::AS2::FnCall *fn)
{
  bool v1; // bl
  Scaleform::GFx::AS2::Environment *Env; // edx
  Scaleform::GFx::AS2::Value *v3; // ecx
  Scaleform::GFx::AS2::Object *v4; // eax
  Scaleform::GFx::AS2::Object *v5; // edi
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::GFx::AS2::PointObject *p_pProto; // ecx
  Scaleform::GFx::AS2::Value *Result; // esi
  Scaleform::Render::Point<double> pt2; // [esp+Ch] [ebp-20h] BYREF
  Scaleform::Render::Point<double> pt1; // [esp+1Ch] [ebp-10h] BYREF

  v1 = 0;
  if ( fn->NArgs > 0 )
  {
    Env = fn->Env;
    v3 = 0;
    if ( fn->FirstArgBottomIndex <= 32 * (Env->Stack.Pages.Data.Size - 1) + Env->Stack.pCurrent - Env->Stack.pPageStart )
      v3 = &Env->Stack.Pages.Data.Data[(unsigned int)fn->FirstArgBottomIndex >> 5]->Values[fn->FirstArgBottomIndex
                                                                                         & 0x1F];
    v4 = Scaleform::GFx::AS2::Value::ToObject(v3, Env);
    v5 = v4;
    if ( v4 )
    {
      if ( v4->GetObjectType(&v4->Scaleform::GFx::AS2::ObjectInterface) == Object_Point )
      {
        if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Point )
        {
          Scaleform::GFx::AS2::Environment::LogScriptError(
            fn->Env,
            "Error: Null or invalid 'this' is used for a method of %s class.\n",
            "Point");
          return;
        }
        ThisPtr = fn->ThisPtr;
        if ( ThisPtr )
          p_pProto = (Scaleform::GFx::AS2::PointObject *)&ThisPtr[-2].pProto;
        else
          p_pProto = 0;
        Scaleform::GFx::AS2::PointObject::GetProperties(p_pProto, fn->Env, &pt1);
        Scaleform::GFx::AS2::GFxObject_GetPointProperties(fn->Env, v5, &pt2);
        v1 = Scaleform::Render::Point<double>::operator==(&pt1, &pt2);
      }
    }
  }
  Result = fn->Result;
  Scaleform::GFx::AS2::Value::DropRefs(Result);
  Result->V.BooleanValue = v1;
  Result->T.Type = 2;
}
