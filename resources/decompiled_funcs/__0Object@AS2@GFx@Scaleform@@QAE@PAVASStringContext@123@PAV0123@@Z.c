void __thiscall Scaleform::GFx::AS2::Object::Object(
        Scaleform::GFx::AS2::Object *this,
        Scaleform::GFx::AS2::ASStringContext *psc,
        Scaleform::GFx::AS2::Object *proto)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // ecx
  Scaleform::GFx::AS2::RefCountCollector<323> *pLoadQueueHead; // ecx

  if ( psc->pContext && (pMovieRoot = psc->pContext->pMovieRoot) != 0 )
    pLoadQueueHead = (Scaleform::GFx::AS2::RefCountCollector<323> *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0;
  this->pRCC = pLoadQueueHead;
  this->RefCount = 1;
  this->pUserDataHolder = 0;
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::ObjectInterface::`vftable';
  this->pProto.pObject = 0;
  this->Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::Object_vtbl *)&Scaleform::GFx::AS2::Object::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::AmpMarker::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
  this->Members.mHash.pTable = 0;
  this->ResolveHandler.Flags = 0;
  this->ResolveHandler.Function = 0;
  this->ResolveHandler.pLocalFrame = 0;
  this->pWatchpoints = 0;
  this->ArePropertiesSet = 0;
  this->IsListenerSet = 0;
  Scaleform::GFx::AS2::Object::Set__proto__(
    (Scaleform::GFx::AS2::Object *)&this->Scaleform::GFx::AS2::ObjectInterface,
    psc,
    proto);
}
