Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        const Scaleform::GFx::ASString *type,
        bool bubbles,
        bool cancelable)
{
  Scaleform::GFx::AS3::Traits *pObject; // esi
  Scaleform::GFx::AS3::Value *v7; // esi
  int i; // edi
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value params[3]; // [esp+Ch] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+3Ch] [ebp+0h] BYREF

  result->pObject = 0;
  Scaleform::GFx::AS3::Value::Value(params, type);
  pObject = this->pTraits.pObject;
  params[2].value.VS._1.VBool = cancelable;
  params[1].Flags = 1;
  params[1].Bonus.pWeakProxy = 0;
  params[1].value.VS._1.VBool = bubbles;
  params[2].Flags = 1;
  params[2].Bonus.pWeakProxy = 0;
  Scaleform::GFx::AS3::ASVM::_constructInstance(
    (Scaleform::GFx::AS3::ASVM *)pObject->pVM,
    result,
    (Scaleform::GFx::AS3::Object *)pObject->pVM[1].InInitializer,
    3u,
    params);
  v7 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 2; i >= 0; --i )
  {
    Flags = v7[-1].Flags;
    --v7;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v7);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v7);
    }
  }
  return result;
}
