void __thiscall Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>::~HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::AS3::Object::DynAttrsKey,Scaleform::GFx::AS3::Value,Scaleform::GFx::AS3::Object::DynAttrsKey::HashFunctor> *this)
{
  Scaleform::GFx::AS3::Value *p_Second; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v4; // zf
  Scaleform::GFx::ASStringNode *pNode; // ecx

  p_Second = &this->Second;
  if ( (this->Second.Flags & 0x1F) > 9 )
  {
    if ( (this->Second.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Second.Bonus.pWeakProxy;
      v4 = pWeakProxy->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_Second->Flags &= 0xFFFFFDE0;
      p_Second->Bonus.pWeakProxy = 0;
      p_Second->value.VS._1.VInt = 0;
      p_Second->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Second);
    }
  }
  pNode = this->First.Name.pNode;
  v4 = pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>::~HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS2::FunctionRef,Scaleform::GFx::ASStringHashFunctor> *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::ASStringNode *pNode; // ecx

  if ( (this->Second.Flags & 2) == 0 )
  {
    Function = this->Second.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v4 = (this->Second.Flags & 1) == 0;
  this->Second.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->Second.pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v6) != 0 )
      {
        pLocalFrame->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->Second.pLocalFrame = 0;
  pNode = this->First.pNode;
  v4 = this->First.pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}


void __thiscall Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>::~HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor>(
        Scaleform::HashNode<Scaleform::GFx::ASString,Scaleform::GFx::AS3::Value,Scaleform::GFx::ASStringHashFunctor> *this)
{
  Scaleform::GFx::AS3::Value *p_Second; // esi
  Scaleform::GFx::AS3::WeakProxy *pWeakProxy; // eax
  bool v4; // zf
  Scaleform::GFx::ASStringNode *pNode; // ecx

  p_Second = &this->Second;
  if ( (this->Second.Flags & 0x1F) > 9 )
  {
    if ( (this->Second.Flags & 0x200) != 0 )
    {
      pWeakProxy = this->Second.Bonus.pWeakProxy;
      v4 = pWeakProxy->RefCount-- == 1;
      if ( v4 )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pWeakProxy);
      p_Second->Flags &= 0xFFFFFDE0;
      p_Second->Bonus.pWeakProxy = 0;
      p_Second->value.VS._1.VInt = 0;
      p_Second->value.VS._2.VObj = 0;
    }
    else
    {
      Scaleform::GFx::AS3::Value::ReleaseInternal(p_Second);
    }
  }
  pNode = this->First.pNode;
  v4 = this->First.pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
}
