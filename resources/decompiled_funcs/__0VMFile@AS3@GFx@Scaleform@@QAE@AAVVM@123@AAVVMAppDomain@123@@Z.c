void __thiscall Scaleform::GFx::AS3::VMFile::VMFile(
        Scaleform::GFx::AS3::VMFile *this,
        Scaleform::GFx::AS3::VM *vm,
        Scaleform::GFx::AS3::VMAppDomain *appDomain)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340,Scaleform::ArrayDefaultPolicy> *p_IntStrings; // edi
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // ebx
  unsigned int Size; // edx

  this->pRCCRaw = (unsigned int)vm->GC.GC;
  this->__vftable = (Scaleform::GFx::AS3::VMFile_vtbl *)&Scaleform::GFx::AS3::VMFile::`vftable';
  this->VMRef = vm;
  this->AppDomain = appDomain;
  this->RefCount = 1;
  this->IntNamespaces.Entries.mHash.pTable = 0;
  this->IntNamespaceSets.Data.Data = 0;
  this->IntNamespaceSets.Data.Size = 0;
  this->IntNamespaceSets.Data.Policy.Capacity = 0;
  p_IntStrings = &this->IntStrings;
  this->IntStrings.Data.Data = 0;
  this->IntStrings.Data.Size = 0;
  this->IntStrings.Data.Policy.Capacity = 0;
  this->ActivationTraitsCache.mHash.pTable = 0;
  p_EmptyStringNode = &vm->StringManagerRef->pStringManager->EmptyStringNode;
  if ( vm->StringManagerRef->pStringManager != (Scaleform::GFx::ASStringManager *)-32 )
    ++p_EmptyStringNode->RefCount;
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode>,340>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
    &this->IntStrings.Data,
    &this->IntStrings,
    this->IntStrings.Data.Size + 1);
  Size = this->IntStrings.Data.Size;
  if ( &p_IntStrings->Data.Data[Size] != (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::ASStringNode> *)4 )
  {
    p_IntStrings->Data.Data[Size - 1].pObject = p_EmptyStringNode;
    if ( !p_EmptyStringNode )
      return;
    ++p_EmptyStringNode->RefCount;
  }
  if ( p_EmptyStringNode && ((unsigned __int8)p_EmptyStringNode & 1) == 0 && p_EmptyStringNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}
