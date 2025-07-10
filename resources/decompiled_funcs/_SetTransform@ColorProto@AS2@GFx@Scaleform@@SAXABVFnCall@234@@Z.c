void __cdecl Scaleform::GFx::AS2::ColorProto::SetTransform(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *p_pProto; // eax
  Scaleform::GFx::Sprite *pObject; // esi
  Scaleform::GFx::AS2::Value *v4; // eax
  Scaleform::GFx::AS2::ObjectInterface *v5; // ebx
  Scaleform::RefCountNTSImpl *v6; // ecx
  Scaleform::GFx::AS2::ASStringContext *p_StringContext; // esi
  Scaleform::GFx::AS2::Environment *c_28; // [esp+4Ch] [ebp-54h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+68h] [ebp-38h] BYREF
  float v10; // [esp+6Ch] [ebp-34h]
  Scaleform::GFx::AS2::Value v11; // [esp+70h] [ebp-30h] BYREF
  Scaleform::Render::Cxform v12; // [esp+80h] [ebp-20h] BYREF

  if ( !fn->ThisPtr || fn->ThisPtr->GetObjectType(fn->ThisPtr) != Object_Color )
  {
    Scaleform::GFx::AS2::Environment::LogScriptError(
      fn->Env,
      "Error: Null or invalid 'this' is used for a method of %s class.\n",
      "Color");
    return;
  }
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
      }
      if ( fn->NArgs < 1 )
      {
        if ( !pObject )
          return;
      }
      else
      {
        if ( !pObject )
          return;
        c_28 = fn->Env;
        v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
        v5 = Scaleform::GFx::AS2::Value::ToObjectInterface(v4, c_28);
        v6 = pObject;
        if ( !v5 )
          goto LABEL_31;
        qmemcpy(&v12, Scaleform::GFx::DisplayObjectBase::GetCxform(pObject), sizeof(v12));
        p_StringContext = &fn->Env->StringContext;
        v11.T.Type = 0;
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "ba", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[0][2] = v10 / 100.0;
        }
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "ga", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[0][1] = v10 / 100.0;
        }
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "ra", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[0][0] = v10 / 100.0;
        }
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "aa", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[0][3] = v10 / 100.0;
        }
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "bb", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[1][2] = v10 / 255.0;
        }
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "gb", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[1][1] = v10 / 255.0;
        }
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "rb", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[1][0] = v10 / 255.0;
        }
        if ( Scaleform::GFx::AS2::ObjectInterface::GetConstMemberRaw(v5, p_StringContext, "ab", &v11) )
        {
          v10 = Scaleform::GFx::AS2::Value::ToNumber(&v11, fn->Env);
          v12.M[1][3] = v10 / 255.0;
        }
        pObject = result.pObject;
        Scaleform::GFx::DisplayObjectBase::SetCxform(result.pObject, &v12);
        pObject->SetAcceptAnimMoves(pObject, 0);
        if ( v11.T.Type >= 5u )
        {
          Scaleform::GFx::AS2::Value::DropRefs(&v11);
          Scaleform::RefCountNTSImpl::Release(pObject);
          return;
        }
      }
      v6 = pObject;
LABEL_31:
      Scaleform::RefCountNTSImpl::Release(v6);
    }
  }
}
