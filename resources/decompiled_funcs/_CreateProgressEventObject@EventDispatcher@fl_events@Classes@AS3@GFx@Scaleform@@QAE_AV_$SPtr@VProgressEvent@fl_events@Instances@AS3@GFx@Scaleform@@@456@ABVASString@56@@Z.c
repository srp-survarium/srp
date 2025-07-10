Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateProgressEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        const Scaleform::GFx::ASString *type)
{
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::AS3::Value *v4; // esi
  int i; // ebx
  unsigned int Flags; // eax
  Scaleform::GFx::AS3::Value params[3]; // [esp+Ch] [ebp-30h] BYREF
  _UNKNOWN *retaddr; // [esp+3Ch] [ebp+0h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0;
  Scaleform::GFx::AS3::Value::Value(params, type);
  params[1].Flags = 1;
  params[1].Bonus.pWeakProxy = 0;
  params[1].value.VS._1.VBool = 0;
  params[2].Flags = 1;
  params[2].Bonus.pWeakProxy = 0;
  params[2].value.VS._1.VBool = 0;
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, pVM->ProgressEventClass.pObject, 3u, params);
  v4 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 2; i >= 0; --i )
  {
    Flags = v4[-1].Flags;
    --v4;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v4);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v4);
    }
  }
  return result;
}
