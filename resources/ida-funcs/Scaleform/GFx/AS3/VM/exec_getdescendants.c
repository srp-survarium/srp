void __thiscall Scaleform::GFx::AS3::VM::exec_getdescendants(
        Scaleform::GFx::AS3::VM *this,
        Scaleform::GFx::AS3::VMFile *file,
        Scaleform::GFx::AS3::Abc::Multiname *mn)
{
  Scaleform::GFx::AS3::Value *pCurrent; // edi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  Scaleform::GFx::AS3::Value *ArgObject; // ecx
  Scaleform::GFx::AS3::Traits *ValueTraits; // eax
  const char *pData; // eax
  unsigned int v10; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::ASStringNode *v13; // eax
  Scaleform::StringDataPtr v14; // [esp+0h] [ebp-40h]
  Scaleform::GFx::AS3::VM::Error v15; // [esp+10h] [ebp-30h] BYREF
  Scaleform::GFx::AS3::ReadMnObjectRef args; // [esp+18h] [ebp-28h] BYREF

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
    ArgObject = args.ArgObject;
    --this->OpStack.pCurrent;
    ValueTraits = Scaleform::GFx::AS3::VM::GetValueTraits(this, ArgObject);
    pData = ValueTraits->GetName(ValueTraits, (Scaleform::GFx::ASString *)&file)->pNode->pData;
    v14.pStr = pData;
    if ( pData )
      v10 = strlen(pData);
    else
      v10 = 0;
    v14.Size = v10;
    Scaleform::GFx::AS3::VM::Error::Error(&v15, eDescendentsError, (Scaleform::String)this, v14);
    Scaleform::GFx::AS3::VM::ThrowErrorInternal(
      this,
      v11,
      (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
    pNode = v15.Message.pNode;
    --v15.Message.pNode->RefCount;
    if ( !pNode->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
    v13 = (Scaleform::GFx::ASStringNode *)file;
    --file->pPrev;
    if ( !v13->RefCount )
      Scaleform::GFx::ASStringNode::ReleaseNode(v13);
  }
  Scaleform::GFx::AS3::Multiname::~Multiname(&args.ArgMN);
}
