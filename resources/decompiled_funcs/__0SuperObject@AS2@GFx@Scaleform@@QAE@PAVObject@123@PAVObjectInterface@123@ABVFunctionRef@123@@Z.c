void __thiscall Scaleform::GFx::AS2::SuperObject::SuperObject(
        Scaleform::GFx::AS2::SuperObject *this,
        Scaleform::GFx::AS2::Object *superProto,
        Scaleform::GFx::AS2::ObjectInterface *_this,
        const Scaleform::GFx::AS2::FunctionRef *ctor)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int RefCount; // eax

  Scaleform::GFx::AS2::Object::Object(this, (Scaleform::GFx::AS2::ASRefCountCollector *)superProto->pRCC);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::SuperObject_vtbl *)&Scaleform::GFx::AS2::SuperObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::SuperObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  superProto->RefCount = (superProto->RefCount + 1) & 0x8FFFFFFF;
  this->SuperProto.pObject = superProto;
  this->SavedProto.pObject = 0;
  this->RealThis = _this;
  this->Constructor.Flags = 0;
  Function = ctor->Function;
  this->Constructor.Function = ctor->Function;
  if ( Function )
    Function->RefCount = (Function->RefCount + 1) & 0x8FFFFFFF;
  this->Constructor.pLocalFrame = 0;
  pLocalFrame = ctor->pLocalFrame;
  if ( pLocalFrame )
    Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(&this->Constructor, pLocalFrame, ctor->Flags & 1);
  superProto->RefCount = (superProto->RefCount + 1) & 0x8FFFFFFF;
  pObject = this->pProto.pObject;
  if ( pObject )
  {
    RefCount = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
    {
      pObject->RefCount = RefCount - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  this->pProto.pObject = superProto;
}
