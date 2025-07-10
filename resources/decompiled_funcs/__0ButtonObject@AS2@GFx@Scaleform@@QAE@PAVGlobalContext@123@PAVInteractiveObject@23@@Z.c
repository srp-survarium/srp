void __thiscall Scaleform::GFx::AS2::ButtonObject::ButtonObject(
        Scaleform::GFx::AS2::ButtonObject *this,
        Scaleform::GFx::AS2::GlobalContext *gCtxt,
        Scaleform::GFx::AS2::Object **pbutton)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // eax
  Scaleform::GFx::AS2::Object **v6; // edi
  Scaleform::WeakPtrProxy *WeakProxy; // eax
  int v8; // eax

  pMovieRoot = gCtxt->pMovieRoot;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  v6 = pbutton;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::ButtonObject_vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ButtonObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  if ( pbutton )
    WeakProxy = Scaleform::RefCountWeakSupportImpl::CreateWeakProxy((Scaleform::RefCountWeakSupportImpl *)pbutton);
  else
    WeakProxy = 0;
  this->pButton.pProxy.pObject = WeakProxy;
  if ( pbutton )
    v6 = (Scaleform::GFx::AS2::Object **)((int (__thiscall *)(Scaleform::GFx::AS2::Object **))pbutton[*((unsigned __int8 *)pbutton + 65)]->pRCC)(&pbutton[*((unsigned __int8 *)pbutton + 65)]);
  v8 = ((int (__thiscall *)(Scaleform::GFx::AS2::Object **))(*v6)[2].pUserDataHolder)(v6);
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    (Scaleform::GFx::AS2::ASStringContext *)(v8 + 116),
    v6[3]);
}
