void __thiscall Scaleform::GFx::AS3::VM::Coerce2ReturnType(
        Scaleform::GFx::AS3::VM *this,
        const Scaleform::GFx::AS3::Value *value,
        Scaleform::GFx::AS3::Value *result)
{
  Scaleform::GFx::AS3::CallFrame **Pages; // edx
  unsigned int v5; // ecx
  int v6; // eax
  Scaleform::GFx::AS3::CallFrame *v7; // ecx
  int Ind; // edx
  Scaleform::GFx::AS3::VMFile *pFile; // ecx
  Scaleform::GFx::AS3::ClassTraits::ClassClass *v10; // eax
  const Scaleform::GFx::AS3::VM::Error *v11; // eax
  Scaleform::GFx::ASStringNode *pNode; // eax
  Scaleform::GFx::AS3::VM::Error v13; // [esp+8h] [ebp-8h] BYREF

  Pages = this->CallStack.Pages;
  v5 = this->CallStack.Size - 1;
  v6 = v5 & 0x3F;
  v7 = Pages[v5 >> 6];
  Ind = v7[v6].MBIIndex.Ind;
  pFile = v7[v6].pFile;
  v10 = Scaleform::GFx::AS3::VM::Resolve2ClassTraits(
          this,
          pFile,
          (Scaleform::GFx::AS3::Abc::Multiname *)pFile[1].__vftable[2].MakeInternedNamespace
        + *(_DWORD *)(*((_DWORD *)pFile[1].__vftable[3].~Scaleform::GFx::AS3::VMFile
                      + *(_DWORD *)(*((_DWORD *)pFile[1].__vftable[4].MakeActivationInstanceTraits + Ind) + 12))
                    + 4));
  if ( v10 )
  {
    if ( v10->Coerce(v10, value, result) )
      return;
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eCheckTypeFailedError, this);
  }
  else
  {
    Scaleform::GFx::AS3::VM::Error::Error(&v13, eClassNotFoundError, this);
  }
  Scaleform::GFx::AS3::VM::ThrowErrorInternal(
    this,
    v11,
    (Scaleform::GFx::ASStringNode *)&Scaleform::GFx::AS3::fl::TypeErrorTI);
  pNode = v13.Message.pNode;
  --v13.Message.pNode->RefCount;
  if ( !pNode->RefCount )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
