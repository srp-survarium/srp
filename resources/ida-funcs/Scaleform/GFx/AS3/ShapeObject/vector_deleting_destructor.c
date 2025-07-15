Scaleform::GFx::AS3::ShapeObject *__thiscall Scaleform::GFx::AS3::ShapeObject::`vector deleting destructor'(
        Scaleform::GFx::AS3::ShapeObject *this,
        char a2)
{
  Scaleform::GFx::AS3::AvmDisplayObj *v3; // edi
  Scaleform::GFx::DrawingContext *pObject; // ecx
  Scaleform::GFx::ShapeBaseCharacterDef *v5; // ecx

  v3 = &this->Scaleform::GFx::AS3::AvmDisplayObj;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::AS3::ShapeObject_vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  this->Scaleform::GFx::AS3::AvmDisplayObj::Scaleform::GFx::AvmDisplayObjBase::__vftable = (Scaleform::GFx::AS3::AvmDisplayObj_vtbl *)&Scaleform::GFx::AS3::ShapeObject::`vftable';
  this->AvmObjOffset = 0;
  pObject = this->pDrawing.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  v5 = this->pDef.pObject;
  if ( v5 )
    Scaleform::GFx::Resource::Release(v5);
  Scaleform::GFx::AS3::AvmDisplayObj::~AvmDisplayObj(v3);
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}


void *__thiscall Scaleform::GFx::AS3::ShapeObject::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::AS3::ShapeObject::`vector deleting destructor'(
           (Scaleform::GFx::AS3::ShapeObject *)(this - 84),
           a2);
}


void *__thiscall Scaleform::GFx::AS3::ShapeObject::`vector deleting destructor'(char *this, unsigned int a2)
{
  return Scaleform::GFx::AS3::ShapeObject::`vector deleting destructor'(
           (Scaleform::GFx::AS3::ShapeObject *)(this - 12),
           a2);
}
