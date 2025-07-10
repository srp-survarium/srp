void __cdecl Scaleform::GFx::AS2::ColorProto::GetTransform(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *p_pProto; // eax
  Scaleform::GFx::Sprite *pObject; // esi
  const Scaleform::Render::Cxform *Cxform; // esi
  Scaleform::GFx::AS2::GlobalContext *pContext; // eax
  Scaleform::GFx::AS2::Object *v6; // eax
  Scaleform::GFx::AS2::Object *v7; // eax
  Scaleform::GFx::AS2::Environment *Env; // esi
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::ObjectInterface *v10; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::Object *obj; // [esp+34h] [ebp-3Ch]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+38h] [ebp-38h] BYREF
  Scaleform::GFx::AS2::Value val; // [esp+3Ch] [ebp-34h] BYREF
  float v15[8]; // [esp+50h] [ebp-20h] BYREF

  if ( fn->ThisPtr && fn->ThisPtr->GetObjectType(fn->ThisPtr) == Object_Color )
  {
    ThisPtr = fn->ThisPtr;
    if ( ThisPtr )
    {
      p_pProto = (Scaleform::WeakPtr<Scaleform::GFx::Sprite> *)&ThisPtr[-2].pProto;
      if ( p_pProto )
      {
        Scaleform::WeakPtr<Scaleform::GFx::InteractiveObject>::operator Scaleform::Ptr<Scaleform::GFx::InteractiveObject>(
          p_pProto + 13,
          (Scaleform::Ptr<Scaleform::GFx::InteractiveObject> *)&result);
        pObject = result.pObject;
        if ( result.pObject )
        {
          ++result.pObject->RefCount;
          Scaleform::RefCountNTSImpl::Release(pObject);
          Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(pObject);
          pContext = fn->Env->StringContext.pContext;
          qmemcpy(v15, Cxform, sizeof(v15));
          v6 = (Scaleform::GFx::AS2::Object *)pContext->pHeap->Alloc(pContext->pHeap, 52u, 0);
          if ( v6 )
          {
            Scaleform::GFx::AS2::Object::Object(v6, fn->Env);
            obj = v7;
          }
          else
          {
            obj = 0;
          }
          Env = fn->Env;
          *(float *)&val.T.Type = v15[2] * 100.0;
          p_StringContext = &Env->StringContext;
          v10 = &obj->Scaleform::GFx::AS2::ObjectInterface;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          val.V.BooleanValue = 3;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            &obj->Scaleform::GFx::AS2::ObjectInterface,
            p_StringContext,
            "ba",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          *(float *)&val.T.Type = v15[1] * 100.0;
          val.V.BooleanValue = 3;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v10,
            p_StringContext,
            "ga",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          *(float *)&val.T.Type = v15[0] * 100.0;
          val.V.BooleanValue = 3;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v10,
            p_StringContext,
            "ra",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          *(float *)&val.T.Type = v15[3] * 100.0;
          val.V.BooleanValue = 3;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v10,
            p_StringContext,
            "aa",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          *(float *)&val.T.Type = v15[6] * 255.0;
          val.V.BooleanValue = 3;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v10,
            p_StringContext,
            "bb",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          *(float *)&val.T.Type = v15[5] * 255.0;
          val.V.BooleanValue = 3;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v10,
            p_StringContext,
            "gb",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          *(float *)&val.T.Type = v15[4] * 255.0;
          val.V.BooleanValue = 3;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v10,
            p_StringContext,
            "rb",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          *(float *)&val.T.Type = v15[7] * 255.0;
          val.V.BooleanValue = 3;
          *(double *)((char *)&val.NV.NumberValue + 4) = *(float *)&val.T.Type;
          Scaleform::GFx::AS2::ObjectInterface::SetConstMemberRaw(
            v10,
            p_StringContext,
            "ab",
            (const Scaleform::GFx::AS2::Value *)&val.NV.4);
          if ( val.V.BooleanValue >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs((Scaleform::GFx::AS2::Value *)&val.NV.4);
          Scaleform::GFx::AS2::Value::SetAsObject(fn->Result, obj);
          if ( obj )
          {
            RefCount = obj->RefCount;
            if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
            {
              obj->RefCount = RefCount - 1;
              Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(obj);
            }
          }
          Scaleform::RefCountNTSImpl::Release(result.pObject);
        }
      }
    }
  }
  else
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Color");
  }
}
