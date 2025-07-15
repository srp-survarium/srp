void __thiscall Scaleform::GFx::AS3::VTable::VTable(Scaleform::GFx::AS3::VTable *this, Scaleform::GFx::AS3::Traits *tr)
{
  Scaleform::GFx::ASStringNode *p_EmptyStringNode; // ecx
  bool v4; // zf

  this->pTraits = tr;
  this->VTMethods.Data.Data = 0;
  this->VTMethods.Data.Size = 0;
  this->VTMethods.Data.Policy.Capacity = 0;
  p_EmptyStringNode = &tr->pVM->StringManagerRef->pStringManager->EmptyStringNode;
  ++p_EmptyStringNode->RefCount;
  this->Names.Data.Data = 0;
  this->Names.Data.Size = 0;
  this->Names.Data.Policy.Capacity = 0;
  this->Names.Data.DefaultValue.pNode = p_EmptyStringNode;
  v4 = ++p_EmptyStringNode->RefCount == 1;
  --p_EmptyStringNode->RefCount;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(p_EmptyStringNode);
}


void __thiscall Scaleform::GFx::AS3::VTable::VTable(
        Scaleform::GFx::AS3::VTable *this,
        Scaleform::GFx::AS3::Traits *tr,
        const Scaleform::GFx::AS3::VTable *parent)
{
  Scaleform::ArrayLH<Scaleform::GFx::AS3::Value,331,Scaleform::ArrayDefaultPolicy> *p_VTMethods; // esi
  unsigned int Size; // eax
  Scaleform::GFx::AS3::Value *Data; // edx
  unsigned int v8; // ebp
  Scaleform::GFx::ASStringNode *pNode; // eax
  unsigned int v10; // ebp
  unsigned int v11; // edi
  Scaleform::GFx::AS3::Value *tra; // [esp+14h] [ebp+4h]
  Scaleform::GFx::ASString *trb; // [esp+14h] [ebp+4h]
  const Scaleform::GFx::AS3::VTable *parenta; // [esp+18h] [ebp+8h]

  this->pTraits = tr;
  p_VTMethods = &this->VTMethods;
  this->VTMethods.Data.Data = 0;
  this->VTMethods.Data.Size = 0;
  this->VTMethods.Data.Policy.Capacity = 0;
  Size = parent->VTMethods.Data.Size;
  Data = parent->VTMethods.Data.Data;
  parenta = (const Scaleform::GFx::AS3::VTable *)Size;
  tra = Data;
  if ( Size )
  {
    v8 = this->VTMethods.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::AS3::Value,Scaleform::AllocatorLH<Scaleform::GFx::AS3::Value,331>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->VTMethods.Data,
      &this->VTMethods,
      v8 + Size);
    Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(
      &p_VTMethods->Data.Data[v8].Flags,
      (unsigned int)parenta,
      tra);
  }
  this->Names.Data.Data = 0;
  this->Names.Data.Size = 0;
  this->Names.Data.Policy.Capacity = 0;
  pNode = parent->Names.Data.DefaultValue.pNode;
  this->Names.Data.DefaultValue.pNode = pNode;
  ++pNode->RefCount;
  v10 = parent->Names.Data.Size;
  trb = parent->Names.Data.Data;
  if ( v10 )
  {
    v11 = this->Names.Data.Size;
    Scaleform::ArrayDataBase<Scaleform::GFx::ASString,Scaleform::AllocatorLH<Scaleform::GFx::ASString,331>,Scaleform::ArrayDefaultPolicy>::ResizeNoConstruct(
      &this->Names.Data,
      &this->Names,
      v11 + v10);
    Scaleform::ConstructorMov<Scaleform::GFx::ASString>::ConstructArray(&this->Names.Data.Data[v11], v10, trb);
  }
}
