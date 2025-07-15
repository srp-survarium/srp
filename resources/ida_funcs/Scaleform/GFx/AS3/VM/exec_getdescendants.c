void __thiscall Scaleform::GFx::AS3::VM::exec_getdescendants(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  const Scaleform::GFx::AS3::VM::Error *v7; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v9; // [esp+Ch] [ebp-30h] BYREF
  Scaleform::GFx::AS3::ReadMnObjectRef args; // [esp+14h] [ebp-28h] BYREF

  args.VMRef = file->VMRef;
  args.OpStack = &args.VMRef->OpStack;
  Scaleform::GFx::AS3::Multiname::Multiname(&args.ArgMN, file, mn);
  Scaleform::GFx::AS3::StackReader::Read(&args, &args.ArgMN);
  args.ArgObject = args.OpStack->pCurrent;
  Scaleform::GFx::AS3::StackReader::CheckObject(&args, args.ArgObject);
  if ( !this->HandleException
    && !this->XMLSupport_.pObject->GetDescendants(this->XMLSupport_.pObject, &file, args.ArgObject, &args.ArgMN)->Result )
  {
    pCurrent = this->OpStack.pCurrent;
    if ( (pCurrent->Flags & 0x1F) > 9 )
    {
      if ( (pCurrent->Flags & 0x200) != 0 )
      {
        pWeakProxy = pCurrent->Bonus.pWeakProxy;
        if ( pWeakProxy->RefCount-- == 1 )
          Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
        pCurrent->Flags &= 0xFFFFFDE0;
        pCurrent->Bonus.pWeakProxy = 0;
        pCurrent->value.VS._1.VInt = 0;
        pCurrent->value.VS._2.VObj = 0;
      }
      else
      {
        Scaleform::GFx::AS3::Value::ReleaseInternal(this->OpStack.pCurrent);
      }
    }
    --this->OpStack.pCurrent;
    Scaleform::GFx::AS3::VM::Error::Error(&v9, eDescendentsError, this);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v7,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v9.Message.pNode;
    --v9.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
