void __thiscall Scaleform::GFx::AS3::Class::Construct(
        Scaleform::GFx::AS3::Class *this,
        Scaleform::GFx::AS3::Value *_this,
        unsigned int argc,
        const Scaleform::GFx::AS3::Value *argv,
        int extCall)
{
  Scaleform::GFx::AS3::Value *v5; // esi
  Scaleform::GFx::AS3::Traits *pObject; // eax
  Scaleform::GFx::AS3::VM *pVM; // ebx
  const Scaleform::GFx::AS3::VM::Error *v9; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v11; // [esp+Ch] [ebp-8h] BYREF

  v5 = _this;
  pObject = this->pTraits.pObject;
  pVM = pObject->pVM;
  (*((void (__stdcall **)(Scaleform::GFx::AS3::Value *, Scaleform::GFx::AS3::Traits_vtbl *))pObject[1].ForEachChild_GC
   + 15))(
    _this,
    pObject[1].__vftable);
  if ( (v5->Flags & 0x1F) - 12 <= 3 && !v5->value.VS._1.VInt )
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v11, eOutOfMemoryError, pVM);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      pVM,
      v9,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl_errors::MemoryErrorTI);
    pNode = v11.Message.pNode;
    --v11.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  if ( this->PreInit(this, &_this, v5)->Result )
  {
    (*(void (__thiscall **)(Scaleform::GFx::AS3::Value::V1U, int))(*(_DWORD *)v5->value.VS._1.VInt + 52))(
      v5->value.VS._1,
      extCall);
    this->PostInit(this, v5, argc, argv);
  }
}
