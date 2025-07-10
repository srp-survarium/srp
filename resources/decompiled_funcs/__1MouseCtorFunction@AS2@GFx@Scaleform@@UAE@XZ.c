void __thiscall Scaleform::GFx::AS2::MouseCtorFunction::~MouseCtorFunction(
        Scaleform::GFx::AS2::MouseCtorFunction *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::ArrayObject *pObject; // ecx
  unsigned int v8; // eax

  if ( (this->SetCursorTypeFunc.Flags & 2) == 0 )
  {
    Function = this->SetCursorTypeFunc.Function;
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
  v4 = (this->SetCursorTypeFunc.Flags & 1) == 0;
  this->SetCursorTypeFunc.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->SetCursorTypeFunc.pLocalFrame;
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
  this->SetCursorTypeFunc.pLocalFrame = 0;
  pObject = this->pListenersArray.pObject;
  if ( pObject )
  {
    v8 = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v8) != 0 )
    {
      pObject->RefCount = v8 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->Scaleform::GFx::AS2::MouseListener::__vftable = (Scaleform::GFx::AS2::MouseListener_vtbl *)&Scaleform::GFx::AS2::MouseListener::`vftable';
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MouseCtorFunction_vtbl *)&Scaleform::GFx::AS2::FunctionObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::CFunctionObject::Scaleform::GFx::AS2::FunctionObject::Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextSnapshotCtorFunction::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  Scaleform::GFx::AS2::Object::~Object(this);
}
