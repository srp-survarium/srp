void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::contextMenuSet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        const Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::AS3::Value *value)
{
  const Scaleform::GFx::AS3::Value *v3; // edi
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // eax
  unsigned int v7; // eax
  const Scaleform::GFx::AS3::VM::Error *v8; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v10; // eax
  Scaleform::StringDataPtr v11; // [esp-10h] [ebp-20h]
  Scaleform::StringDataPtr v12; // [esp-8h] [ebp-18h]
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  v3 = value;
  if ( (value->Flags & 0x1F) - 12 > 3
    || (Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, value)->Flags & 0x20) != 0 )
  {
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, v3);
    v12.pStr = "flash.ui.ContextMenu";
    v12.Size = 20;
    pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&value)->pNode->pData;
    v11.pStr = pData;
    if ( pData )
      v7 = strlen(pData);
    else
      v7 = 0;
    v11.Size = v7;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eCheckTypeFailedError, this->pTraits.pObject->pVM, v11, v12);
    Scaleform::GFx::AS3::VM::ThrowTypeError(this->pTraits.pObject->pVM, v8);
    pNode = v13.Message.pNode;
    --v13.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v10 = (Scaleform::GFx::ASStringNode *)value;
    --value->value.VS._2.VObj;
    if ( !v10->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v10);
  }
  else
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pContextMenu,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)v3->value.VS._1.VInt);
  }
}
