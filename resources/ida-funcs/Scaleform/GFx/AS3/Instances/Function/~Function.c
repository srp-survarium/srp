void __thiscall Scaleform::GFx::AS3::Instances::Function::~Function(Scaleform::GFx::AS3::Instances::Function *this)
{
  Scaleform::GFx::ASStringNode *pNode; // ecx
  Scaleform::GFx::AS3::Value *p_This; // ecx
  Scaleform::GFx::AS3::Object *pObject; // ecx
  unsigned int RefCount; // eax

  pNode = this->Name.pNode;
  this->__vftable = (Scaleform::GFx::AS3::Instances::Function_vtbl *)&Scaleform::GFx::AS3::Instances::Function::`vftable';
  if ( pNode->RefCount-- == 1 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  p_This = (Scaleform::GFx::AS3::Value *)&this->This;
  if ( (this->This.Flags & 0x1F) > 9 )
  {
    if ( (this->This.Flags & 0x200) != 0 )
      Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_This);
    else
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_This);
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::DestructArray(
    this->StoredScopeStack.Data.Data,
    this->StoredScopeStack.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->StoredScopeStack.Data.Data);
  this->__vftable = (Scaleform::GFx::AS3::Instances::Function_vtbl *)&Scaleform::GFx::AS3::Instances::FunctionBase::`vftable';
  pObject = this->Prototype.pObject;
  if ( pObject )
  {
    if ( ((unsigned __int8)pObject & 1) != 0 )
    {
      this->Prototype.pObject = (Scaleform::GFx::AS3::Object *)((char *)pObject - 1);
      Scaleform::GFx::AS3::Instance::~Instance(this);
      return;
    }
    RefCount = pObject->RefCount;
    if ( (RefCount & 0x3FFFFF) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(pObject);
    }
  }
  Scaleform::GFx::AS3::Instance::~Instance(this);
}
