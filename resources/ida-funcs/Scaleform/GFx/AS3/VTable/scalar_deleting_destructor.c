Scaleform::GFx::AS3::VTable *__thiscall Scaleform::GFx::AS3::VTable::`scalar deleting destructor'(
        Scaleform::GFx::AS3::VTable *this,
        char a2)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx

  pNode = this->Names.Data.DefaultValue.pNode;
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,323>,Scaleform::ArrayDefaultPolicy>(&this->Names.Data);
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->VTMethods.Data.Data,
    this->VTMethods.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->VTMethods.Data.Data);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
