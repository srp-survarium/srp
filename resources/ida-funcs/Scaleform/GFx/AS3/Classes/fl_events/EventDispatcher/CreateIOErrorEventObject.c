Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *__thiscall Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher::CreateIOErrorEventObject(
        Scaleform::GFx::AS3::Classes::fl_events::EventDispatcher *this,
        Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Object> *result,
        __m128i *errText)
{
  Scaleform::GFx::AS3::ASVM *pVM; // esi
  Scaleform::GFx::ASStringNode *pStr; // eax
  Scaleform::GFx::ASStringNode *v6; // eax
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::Class *Class; // eax
  Scaleform::GFx::AS3::Value *v9; // esi
  int i; // ebx
  unsigned int Flags; // eax
  Scaleform::StringDataPtr v; // [esp+10h] [ebp-48h] BYREF
  Scaleform::GFx::AS3::Value params[4]; // [esp+18h] [ebp-40h] BYREF
  _UNKNOWN *retaddr; // [esp+58h] [ebp+0h] BYREF

  pVM = (Scaleform::GFx::AS3::ASVM *)this->pTraits.pObject->pVM;
  result->pObject = 0;
  v.pStr = (const char *)Scaleform::GFx::ASStringManager::CreateConstStringNode(
                           pVM->StringManagerRef->pStringManager,
                           "ioError",
                           7u,
                           0);
  ++*((_DWORD *)v.pStr + 3);
  Scaleform::GFx::AS3::Value::Value(params, (const Scaleform::GFx::ASString *)&v);
  pStr = (Scaleform::GFx::ASStringNode *)v.pStr;
  --*((_DWORD *)v.pStr + 3);
  if ( !pStr->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pStr);
  params[1].Flags = 1;
  params[1].Bonus.pWeakProxy = 0;
  params[1].value.VS._1.VBool = 0;
  params[2].Flags = 1;
  params[2].Bonus.pWeakProxy = 0;
  params[2].value.VS._1.VBool = 0;
  errText = (__m128i *)Scaleform::GFx::ASStringManager::CreateStringNode(pVM->StringManagerRef->pStringManager, errText);
  ++errText->m128i_i32[3];
  Scaleform::GFx::AS3::Value::Value(&params[3], (const Scaleform::GFx::ASString *)&errText);
  v6 = (Scaleform::GFx::ASStringNode *)errText;
  --errText->m128i_i32[3];
  if ( !v6->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v6);
  pObject = this->pTraits.pObject;
  v.pStr = "flash.events.IOErrorEvent";
  v.Size = 25;
  Class = Scaleform::GFx::AS3::VM::GetClass(pObject->pVM, &v, pObject->pVM->CurrentDomain);
  Scaleform::GFx::AS3::ASVM::_constructInstance(pVM, result, Class, 4u, params);
  v9 = (Scaleform::GFx::AS3::Value *)&retaddr;
  for ( i = 3; i >= 0; --i )
  {
    Flags = v9[-1].Flags;
    --v9;
    if ( (Flags & 0x1F) > 9 )
    {
      if ( (Flags & 0x200) != 0 )
        Scaleform::GFx::AS3::Value::ReleaseWeakRef(v9);
      else
        Scaleform::GFx::AS3::Value::ReleaseInternal(v9);
    }
  }
  return result;
}
