void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::MouseCtorFunction(
        Scaleform::GFx::AS2::MouseCtorFunction *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::MovieRoot *proot)
{
  Scaleform::GFx::AS2::LocalFrame **v4; // ebp
  Scaleform::GFx::AS2::Object *Prototype; // eax
  unsigned __int8 *p_SetCursorTypeFunc; // ebx
  Scaleform::GFx::AS2::Value *v7; // eax
  Scaleform::GFx::AS2::FunctionRef *v8; // eax
  unsigned int RefCount; // edx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int v11; // edx
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  int v13; // [esp+0h] [ebp-2Ch]
  int v14; // [esp+0h] [ebp-2Ch]
  int v15; // [esp+4h] [ebp-28h]
  Scaleform::GFx::AS2::FunctionRef result; // [esp+10h] [ebp-1Ch] BYREF
  Scaleform::GFx::AS2::Value v17; // [esp+1Ch] [ebp-10h] BYREF

  Scaleform::GFx::AS2::Object::Object(this, psc);
  v4 = (Scaleform::GFx::AS2::LocalFrame **)&this->Scaleform::GFx::AS2::ObjectInterface;
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MouseCtorFunction_vtbl *)&Scaleform::GFx::AS2::AmpMarkerCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pFunction = Scaleform::GFx::AS2::MouseCtorFunction::GlobalCtor;
  Prototype = Scaleform::GFx::AS2::GlobalContext::GetPrototype(psc->pContext, ASBuiltin_Function);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Prototype);
  this->Scaleform::GFx::AS2::MouseListener::__vftable = (Scaleform::GFx::AS2::MouseListener_vtbl *)&Scaleform::GFx::AS2::MouseListener::`vftable';
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MouseCtorFunction_vtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Scaleform::GFx::AS2::MouseListener::__vftable = (Scaleform::GFx::AS2::MouseListener_vtbl *)&Scaleform::GFx::AS2::MouseCtorFunction::`vftable';
  this->pListenersArray.pObject = 0;
  p_SetCursorTypeFunc = (unsigned __int8 *)&this->SetCursorTypeFunc;
  this->SetCursorTypeFunc.Flags = 0;
  this->SetCursorTypeFunc.Function = 0;
  this->SetCursorTypeFunc.pLocalFrame = 0;
  proot->pASMouseListener = &this->Scaleform::GFx::AS2::MouseListener;
  if ( this != (Scaleform::GFx::AS2::MouseCtorFunction *)-16 )
    Scaleform::GFx::AS2::NameFunction::AddConstMembers(
      p_SetCursorTypeFunc,
      v4,
      &this->Scaleform::GFx::AS2::ObjectInterface,
      psc,
      GAS_AsBcFunctionTable,
      1u,
      v13);
  Scaleform::GFx::AS2::AsBroadcaster::InitializeInstance(
    (int)psc,
    (int)this,
    psc,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    v13,
    v15);
  Scaleform::GFx::AS2::MouseCtorFunction::UpdateListenersArray(this, psc, 0);
  Scaleform::GFx::AS2::NameFunction::AddConstMembers(
    p_SetCursorTypeFunc,
    v4,
    &this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    Scaleform::GFx::AS2::MouseCtorFunction::StaticFunctionTable,
    7u,
    v14);
  Scaleform::GFx::AS2::Value::Value(&v17, psc, Scaleform::GFx::AS2::MouseCtorFunction::SetCursorType);
  v8 = Scaleform::GFx::AS2::Value::ToFunction(v7, &result, 0);
  Scaleform::GFx::AS2::FunctionRefBase::Assign(&this->SetCursorTypeFunc, v8);
  if ( (result.Flags & 2) == 0 )
  {
    if ( result.Function )
    {
      RefCount = result.Function->RefCount;
      Function = result.Function;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        result.Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  result.Function = 0;
  if ( (result.Flags & 1) == 0 )
  {
    if ( result.pLocalFrame )
    {
      v11 = result.pLocalFrame->RefCount;
      pLocalFrame = result.pLocalFrame;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v11) != 0 )
      {
        result.pLocalFrame->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  result.pLocalFrame = 0;
  if ( v17.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&v17);
  this->LastClickTime = 0;
}
