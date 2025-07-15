void __thiscall Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject::contextMenuSet(
        Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject *this,
        const Scaleform::GFx::AS3::Value *result,
        const Scaleform::GFx::AS3::Value *value)
{
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v5; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v7; // [esp+8h] [ebp-8h] BYREF

  if ( (value->Flags & 0x1F) - 12 > 3
    || (Scaleform::GFx::AS3::VM::GetValueTraits(this->pTraits.pObject->pVM, value)->Flags & 0x20) != 0 )
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v7, eCheckTypeFailedError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v5);
    pNode = v7.Message.pNode;
    --v7.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  else
  {
    Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
      (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pContextMenu,
      (Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *)value->value.VS._1.VInt);
  }
}
