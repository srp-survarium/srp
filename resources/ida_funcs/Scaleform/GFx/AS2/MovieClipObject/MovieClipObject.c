void __thiscall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::Environment *penv)
{
  Scaleform::GFx::AS2::Object *ActualPrototype; // eax

  Scaleform::GFx::AS2::Object::Object(this, penv);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MovieClipObject_vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->pSprite.pProxy.pObject = 0;
  this->ButtonEventMask = 0;
  this->HasButtonHandlers = 0;
  ActualPrototype = Scaleform::GFx::AS2::GlobalContext::GetActualPrototype(
                      penv->StringContext.pContext,
                      penv,
                      ASBuiltin_MovieClip);
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)&this->Scaleform::GFx::AS2::ObjectInterface,
    &penv->StringContext,
    ActualPrototype);
}


void __thiscall Scaleform::GFx::AS2::MovieClipObject::MovieClipObject(
        Scaleform::GFx::AS2::MovieClipObject *this,
        Scaleform::GFx::AS2::GlobalContext *gCtxt,
        Scaleform::GFx::Sprite *psprite)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // eax
  Scaleform::WeakPtrProxy *WeakProxy; // eax
  int v7; // eax

  pMovieRoot = gCtxt->pMovieRoot;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::MovieClipObject_vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::MovieClipObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( psprite )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy(psprite);
  else
    WeakProxy = 0;
  this->pSprite.pProxy.pObject = WeakProxy;
  this->ButtonEventMask = 0;
  this->HasButtonHandlers = 0;
  v7 = (*(int (__thiscall **)(char *))(*((_DWORD *)&psprite->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
                                       + psprite->AvmObjOffset)
                                     + 124))(
         (char *)&psprite->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable
       + 4 * psprite->AvmObjOffset);
  Scaleform::GFx::AS2::MovieClipObject::Set__proto__(
    (Scaleform::GFx::AS2::MovieClipObject *)&this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)(v7 + 116),
    *((Scaleform::GFx::AS2::Object **)&psprite->Scaleform::GFx::DisplayObjContainer::Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable
    + psprite->AvmObjOffset));
}
