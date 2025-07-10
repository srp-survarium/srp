void __thiscall Scaleform::GFx::AS2::AsFunctionObject::AsFunctionObject(
        Scaleform::GFx::AS2::AsFunctionObject *this,
        Scaleform::GFx::AS2::Environment *penv,
        Scaleform::GFx::AS2::ActionBuffer *ab,
        unsigned int start,
        unsigned int length,
        const Scaleform::ArrayLH_POD<Scaleform::GFx::AS2::WithStackEntry,323,Scaleform::ArrayDefaultPolicy> *pwithStack,
        Scaleform::GFx::AS2::ActionBuffer::ExecuteType execType)
{
  Scaleform::GFx::ASStringNode *RefCount; // ecx
  bool v9; // zf
  Scaleform::GFx::AS2::ActionBuffer::ExecuteType v10; // eax
  Scaleform::GFx::InteractiveObject *Target; // ecx
  Scaleform::GFx::CharacterHandle *pObject; // eax
  Scaleform::GFx::CharacterHandle *v13; // ebp
  Scaleform::GFx::CharacterHandle *v14; // edi
  Scaleform::GFx::AS2::ActionBuffer::ExecuteType execTypea; // [esp+24h] [ebp+18h]

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::AsFunctionObject_vtbl *)&Scaleform::GFx::AS2::AsFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AsFunctionObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pMovieRoot = 0;
  this->TargetHandle.pObject = 0;
  if ( ab )
    ++ab->RefCount;
  this->pActionBuffer.pObject = ab;
  this->WithStack.Data.Data = 0;
  this->WithStack.Data.Size = 0;
  this->WithStack.Data.Policy.Capacity = 0;
  this->StartPc = start;
  this->Length = length;
  RefCount = (Scaleform::GFx::ASStringNode *)penv->StringContext.pContext->pMovieRoot->pASMovieRoot.pObject[8].RefCount;
  ++RefCount->RefCount;
  this->Args.Data.Data = 0;
  this->Args.Data.Size = 0;
  this->Args.Data.Policy.Capacity = 0;
  this->Args.Data.DefaultValue.Register = 0;
  this->Args.Data.DefaultValue.Name.pNode = RefCount;
  v9 = ++RefCount->RefCount == 1;
  --RefCount->RefCount;
  if ( v9 )
    Scaleform::GFx::ASStringNode::ReleaseNode(RefCount);
  v10 = execType;
  this->Function2Flags = 0;
  *(_WORD *)&this->ExecType = (unsigned __int8)execType;
  if ( pwithStack )
  {
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::AS2::WithStackEntry,Scaleform::AllocatorLH_POD<Scaleform::GFx::AS2::WithStackEntry,323>,Scaleform::ArrayDefaultPolicy>>::operator=(
      &this->WithStack,
      pwithStack);
    v10 = execType;
  }
  if ( v10 != Exec_Event && v10 != Exec_SpecialEvent )
  {
    Target = penv->Target;
    pObject = Target->pNameHandle.pObject;
    execTypea = (Scaleform::GFx::AS2::ActionBuffer::ExecuteType)Target;
    if ( !pObject )
      pObject = Scaleform::GFx::DisplayObject::CreateCharacterHandle(Target);
    v13 = pObject;
    if ( pObject )
      ++pObject->RefCount;
    v14 = this->TargetHandle.pObject;
    if ( v14 )
    {
      if ( --v14->RefCount <= 0 )
      {
        Scaleform::GFx::CharacterHandle::~CharacterHandle(v14);
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v14);
      }
    }
    this->TargetHandle.pObject = v13;
    this->pMovieRoot = *(Scaleform::GFx::MovieImpl **)(*(_DWORD *)(execTypea + 16) + 8);
  }
}
