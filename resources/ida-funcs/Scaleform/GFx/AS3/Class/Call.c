void __thiscall Scaleform::GFx::AS3::Class::Call(
        Scaleform::GFx::AS3::Class *this,
        const Scaleform::GFx::AS3::Value *__formal,
        Scaleform::GFx::AS3::Value *result,
        Scaleform::GFx::ASStringNode *argc,
        Scaleform::GFx::AS3::Value *argv)
{
  Scaleform::GFx::AS3::Traits *pObject; // ecx
  Scaleform::GFx::AS3::Value *v7; // edi
  const char *pData; // eax
  unsigned int v9; // eax
  const Scaleform::GFx::AS3::VM::Error *v10; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v12; // eax
  Scaleform::GFx::AS3::VM *pVM; // esi
  const Scaleform::GFx::AS3::VM::Error *v14; // eax
  Scaleform::StringDataPtr v15; // [esp-8h] [ebp-1Ch]
  Scaleform::GFx::AS3::VM::Error v16; // [esp+Ch] [ebp-8h] BYREF

  pObject = this->pTraits.pObject;
  if ( argc == (Scaleform::GFx::ASStringNode *)1 )
  {
    v7 = argv;
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::GFx::AS3::Traits *, const Scaleform::GFx::AS3::Value *const, Scaleform::GFx::AS3::Value *))pObject->__vftable[1].ForEachChild_GC)(
           pObject,
           argv,
           result) )
    {
      return;
    }
    pData = this->pTraits.pObject->GetName(this->pTraits.pObject, &argc)->pNode->pData;
    v15.pStr = pData;
    if ( pData )
      v9 = strlen(pData);
    else
      v9 = 0;
    v15.Size = v9;
    Scaleform::GFx::AS3::VM::Error::Error(
      &v16,
      (Scaleform::GFx::AS3::VM_vtbl *)0x40A,
      (Scaleform::GFx::ASStringNode *)this->pTraits.pObject->pVM,
      v7,
      v15);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this->pTraits.pObject->pVM,
      v10,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v16.Message.pNode;
    --v16.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v12 = argc;
  }
  else
  {
    pVM = pObject->pVM;
    Scaleform::GFx::AS3::VM::Error::Error(&v16, eCoerceArgumentCountError, (Scaleform::String)pVM, (int)argc);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      pVM,
      v14,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::RangeErrorTI);
    v12 = v16.Message.pNode;
  }
  if ( !--v12->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(v12);
}
