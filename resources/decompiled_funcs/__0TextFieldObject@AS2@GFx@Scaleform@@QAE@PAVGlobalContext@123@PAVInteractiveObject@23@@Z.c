void __thiscall Scaleform::GFx::AS2::TextFieldObject::TextFieldObject(
        Scaleform::GFx::AS2::TextFieldObject *this,
        Scaleform::GFx::AS2::GlobalContext *gCtxt,
        Scaleform::GFx::InteractiveObject *ptextfield)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // eax
  Scaleform::WeakPtrProxy *WeakProxy; // eax
  Scaleform::GFx::AS2::Object **v7; // edi
  int v8; // eax

  pMovieRoot = gCtxt->pMovieRoot;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::TextFieldObject_vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::TextFieldObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( ptextfield )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(ptextfield);
  else
    WeakProxy = 0;
  this->pTextField.pProxy.pObject = WeakProxy;
  v7 = (Scaleform::GFx::AS2::Object **)(&ptextfield->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                      + ptextfield->AvmObjOffset);
  v8 = ((int (__thiscall *)(Scaleform::GFx::AS2::Object **))(*v7)[2].pUserDataHolder)(v7);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)(v8 + 116),
    v7[3]);
  this->pIMECompositionStringStyles = 0;
}
