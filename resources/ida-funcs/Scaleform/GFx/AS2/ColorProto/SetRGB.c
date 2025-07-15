void __cdecl Scaleform::GFx::AS2::ColorProto::SetRGB(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *p_pProto; // eax
  Scaleform::GFx::Sprite *pObject; // ebx
  Scaleform::GFx::AS2::Value *v4; // eax
  const Scaleform::Render::Cxform *Cxform; // esi
  __int16 v6; // ax
  Scaleform::GFx::AS2::Environment *Env; // [esp-4h] [ebp-44h]
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+14h] [ebp-2Ch] BYREF
  __int64 v9; // [esp+18h] [ebp-28h]
  Scaleform::Render::Cxform v10; // [esp+20h] [ebp-20h] BYREF

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
          &result);
        pObject = result.pObject;
        if ( result.pObject )
        {
          ++result.pObject->RefCount;
          Scaleform::RefCountNTSImpl::Release(pObject);
        }
        if ( fn->NArgs < 1 )
        {
          if ( pObject )
            Scaleform::RefCountNTSImpl::Release(pObject);
        }
        else if ( pObject )
        {
          Env = fn->Env;
          v4 = Scaleform::GFx::AS2::FnCall::Arg(fn, 0);
          v9 = (__int64)Scaleform::GFx::AS2::Value::ToNumber(v4, Env);
          Cxform = Scaleform::GFx::DisplayObjectBase::GetCxform(pObject);
          v6 = v9;
          qmemcpy(&v10, Cxform, sizeof(v10));
          v10.M[0][2] = 0.0;
          v10.M[0][1] = 0.0;
          v10.M[0][0] = 0.0;
          v10.M[1][0] = (float)BYTE2(v9);
          LODWORD(v9) = (unsigned __int8)v9;
          v10.M[1][1] = (float)HIBYTE(v6);
          v10.M[1][2] = (float)(unsigned __int8)v6;
          Scaleform::Render::Cxform::Normalize(&v10);
          Scaleform::GFx::DisplayObjectBase::SetCxform(pObject, &v10);
          pObject->SetAcceptAnimMoves(pObject, 0);
          Scaleform::RefCountNTSImpl::Release(pObject);
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
