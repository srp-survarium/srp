void __thiscall Scaleform::GFx::AS3::VM::exec_dxnslate(Scaleform::GFx::AS3::VM *this)
{
  Scaleform::GFx::AS3::Value *pCurrent; // ecx
  Scaleform::GFx::ASStringNode *VStr; // ebx
  unsigned int HashFlags; // eax
  Scaleform::GFx::AS3::InstanceTraits::Traits *pObject; // esi
  Scaleform::GFx::AS3::Instances::fl::Namespace *v6; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *v7; // eax
  Scaleform::GFx::AS3::Instances::fl_text::TextFormat *v8; // ebx
  unsigned int RefCount; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::Value *v11; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::CheckResult result; // [esp+13h] [ebp-9h] BYREF
  Scaleform::GFx::ASString uri; // [esp+14h] [ebp-8h] BYREF
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> other; // [esp+18h] [ebp-4h] BYREF

  other.pObject = 0;
  pCurrent = this->OpStack.pCurrent;
  if ( (pCurrent->Flags & 0x1F) == 0xB )
  {
    VStr = pCurrent->value.VS._1.VStr;
    uri.pNode = VStr;
    if ( VStr )
      VStr->HashFlags = (VStr->HashFlags + 1) & 0x8FBFFFFF;
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->DefXMLNamespace,
      (const Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&uri);
    if ( VStr )
    {
      if ( ((unsigned __int8)VStr & 1) == 0 )
      {
        HashFlags = VStr->HashFlags;
        if ( ((unsigned int)&byte_3FFFFF & HashFlags) != 0 )
        {
          VStr->HashFlags = HashFlags - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal((Scaleform::GFx::AS3::RefCountBaseGC<328> *)VStr);
        }
      }
    }
  }
  else
  {
    uri.pNode = &this->StringManagerRef->pStringManager->EmptyStringNode;
    ++uri.pNode->RefCount;
    if ( Scaleform::GFx::AS3::Value::Convert2String(pCurrent, &result, &uri)->Result && uri.pNode->Size )
    {
      if ( (_S10_0 & 1) == 0 )
      {
        _S10_0 |= 1u;
        v.Flags = 0;
        v.Bonus.pWeakProxy = 0;
        atexit(Scaleform::GFx::AS3::Value::GetUndefined_::_2_::_dynamic_atexit_destructor_for__v__);
      }
      pObject = this->TraitsNamespace.pObject->ITraits.pObject;
      other.pObject = (Scaleform::GFx::AS3::Instances::fl_text::TextFormat *)328;
      v6 = (Scaleform::GFx::AS3::Instances::fl::Namespace *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                              Scaleform::Memory::pGlobalHeap,
                                                              pObject,
                                                              56,
                                                              &other);
      if ( v6 )
      {
        Scaleform::GFx::AS3::Instances::fl::Namespace::Namespace(
          v6,
          pObject->pVM,
          (Scaleform::GFx::Resource *)pObject[1].RefCount,
          NS_Public,
          &uri,
          &v);
        v8 = v7;
      }
      else
      {
        v8 = 0;
      }
      other.pObject = v8;
      Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_events::Event>::Set(
        (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_text::TextFormat> *)&this->DefXMLNamespace,
        &other);
      if ( v8 )
      {
        if ( ((unsigned __int8)v8 & 1) == 0 )
        {
          RefCount = v8->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
          {
            v8->RefCount = RefCount - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v8);
          }
        }
      }
    }
    pNode = uri.pNode;
    --uri.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  v11 = this->OpStack.pCurrent;
  if ( (v11->Flags & 0x1F) <= 9 )
    goto LABEL_27;
  if ( (v11->Flags & 0x200) == 0 )
  {
    Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
LABEL_27:
    --this->OpStack.pCurrent;
    return;
  }
  pWeakProxy = v11->Bonus.pWeakProxy;
  if ( pWeakProxy->RefCount-- == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
  v11->Flags &= 0xFFFFFDE0;
  v11->Bonus.pWeakProxy = 0;
  v11->value.VS._1.VInt = 0;
  v11->value.VS._2.VObj = 0;
  --this->OpStack.pCurrent;
}
