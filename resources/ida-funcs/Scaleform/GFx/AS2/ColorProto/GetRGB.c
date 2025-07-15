void __cdecl Scaleform::GFx::AS2::ColorProto::GetRGB(const Scaleform::GFx::AS2::FnCall *fn)
{
  Scaleform::GFx::AS2::ObjectInterface *ThisPtr; // eax
  Scaleform::WeakPtr<Scaleform::GFx::Sprite> *p_pProto; // eax
  Scaleform::GFx::Sprite *pObject; // ebx
  Scaleform::GFx::AS2::Value *v4; // edi
  int v5; // esi
  Scaleform::Ptr<Scaleform::GFx::Sprite> result; // [esp+14h] [ebp-2Ch] BYREF
  __int64 v7; // [esp+18h] [ebp-28h]
  float v8[8]; // [esp+20h] [ebp-20h] BYREF

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
          qmemcpy(v8, Scaleform::GFx::DisplayObjectBase::GetCxform(pObject), sizeof(v8));
          v7 = (__int64)v8[4];
          LODWORD(v7) = LOWORD(result.pObject) | 0xC00;
          v4 = fn->Result;
          v7 = (__int64)v8[5];
          v5 = (unsigned __int16)(-256 * v7) | (unsigned __int8)-(__int64)v8[6] | (-65536 * (__int64)v8[4]) & 0xFF0000;
          if ( v4->T.Type >= 5u )
            Scaleform::GFx::AS2::Value::DropRefs(v4);
          v4->T.Type = 4;
          v4->NV.Int32Value = v5;
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
