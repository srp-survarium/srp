void __thiscall Scaleform::GFx::AS3::Instances::fl_vec::Vector_object::AS3sort(
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *this,
        Scaleform::GFx::AS3::Value *result,
        unsigned int argc,
        Scaleform::GFx::AS3::Value *argv)
{
  unsigned int v4; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v8; // [esp+8h] [ebp-8h] BYREF

  if ( argc
    && (v4 = argv->Flags & 0x1F) != 0
    && (v4 - 12 > 3 || argv->value.VS._1.VInt)
    && ((argv->Flags & 0x1F) > 0xF || v4 == 14 || v4 == 5 || v4 == 15 || v4 == 6 || v4 == 7 || v4 == 12 || v4 == 13) )
  {
    Scaleform::GFx::AS3::VectorBase<Scaleform::GFx::AS3::Value>::Sort<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object>(
      &this->V,
      result,
      argc,
      argv,
      this);
  }
  else
  {
    pVM = this->pTraits.pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v8, eCheckTypeFailedError, pVM);
    Scaleform::GFx::AS3::VM::ThrowTypeError(pVM, v6);
    pNode = v8.Message.pNode;
    --v8.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
}
