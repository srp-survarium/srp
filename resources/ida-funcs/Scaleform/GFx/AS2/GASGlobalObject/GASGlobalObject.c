void __thiscall Scaleform::GFx::AS2::GASGlobalObject::GASGlobalObject(
        Scaleform::GFx::AS2::GASGlobalObject *this,
        Scaleform::GFx::AS2::GlobalContext *pgc)
{
  Scaleform::GFx::MovieImpl *pMovieRoot; // eax
  Scaleform::GFx::AS2::ASRefCountCollector *pLoadQueueHead; // eax

  pMovieRoot = pgc->pMovieRoot;
  if ( pMovieRoot )
    pLoadQueueHead = (Scaleform::GFx::AS2::ASRefCountCollector *)pMovieRoot->pASMovieRoot.pObject[1].pMovieImpl->pLoadQueueHead;
  else
    pLoadQueueHead = 0;
  Scaleform::GFx::AS2::Object::Object(this, pLoadQueueHead);
  this->pGC = pgc;
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>::Scaleform::GFx::AS2::RefCountBaseGC<323>::__vftable = (Scaleform::GFx::AS2::GASGlobalObject_vtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable'{for `Scaleform::GFx::AS2::ASRefCountBase<Scaleform::GFx::AS2::Object>'};
  this->Scaleform::GFx::AS2::Object::Scaleform::GFx::AS2::ObjectInterface::__vftable = (Scaleform::GFx::AS2::ObjectInterface_vtbl *)&Scaleform::GFx::AS2::GASGlobalObject::`vftable'{for `Scaleform::GFx::AS2::ObjectInterface'};
}
