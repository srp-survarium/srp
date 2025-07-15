void __thiscall Scaleform::GFx::AS2::IntervalTimer::~IntervalTimer(Scaleform::GFx::AS2::IntervalTimer *this)
{
  Scaleform::GFx::CharacterHandle *pObject; // edi
  Scaleform::GFx::ASStringNode *pNode; // ecx
  bool v4; // zf
  Scaleform::WeakPtrProxy *v5; // eax
  Scaleform::GFx::AS2::Object *v6; // ecx
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v11; // eax

  pObject = this->LevelHandle.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::DestructArray(this->Params.Data.Data, this->Params.Data.Size);
  if ( this->Params.Data.Data )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Params.Data.Data);
  pNode = this->MethodName.pNode;
  v4 = pNode->RefCount-- == 1;
  if ( v4 )
    Scaleform::GFx::ASStringNode::ReleaseNode(pNode);
  v5 = this->Character.pProxy.pObject;
  if ( v5 )
  {
    v4 = v5->RefCount-- == 1;
    if ( v4 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
  }
  v6 = this->pObject.pObject;
  if ( v6 )
  {
    RefCount = v6->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      v6->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v6);
    }
  }
  if ( (this->Function.Flags & 2) == 0 )
  {
    Function = this->Function.Function;
    if ( Function )
    {
      v9 = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v9) != 0 )
      {
        Function->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v4 = (this->Function.Flags & 1) == 0;
  this->Function.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->Function.pLocalFrame;
    if ( pLocalFrame )
    {
      v11 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v11) != 0 )
      {
        pLocalFrame->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->Function.pLocalFrame = 0;
  this->__vftable = (Scaleform::GFx::AS2::IntervalTimer_vtbl *)&Scaleform::GFx::ASIntervalTimerIntf::`vftable';
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
}
