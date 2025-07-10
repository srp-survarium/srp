void __thiscall Scaleform::GFx::InteractiveObject::~InteractiveObject(Scaleform::GFx::InteractiveObject *this)
{
  Scaleform::GFx::ASMovieRootBase *pASRoot; // eax
  Scaleform::GFx::MovieImpl *pMovieImpl; // edi
  Scaleform::GFx::InteractiveObject *pPlayNext; // eax
  Scaleform::GFx::InteractiveObject *pPlayPrev; // eax
  Scaleform::GFx::MovieDefImpl *pObject; // ecx

  pASRoot = this->pASRoot;
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::InteractiveObject_vtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  this->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::InteractiveObject::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  pMovieImpl = pASRoot->pMovieImpl;
  Scaleform::GFx::InteractiveObject::RemoveFromOptimizedPlayList(this);
  pPlayNext = this->pPlayNext;
  if ( pPlayNext )
    pPlayNext->pPlayPrev = this->pPlayPrev;
  pPlayPrev = this->pPlayPrev;
  if ( pPlayPrev )
  {
    pPlayPrev->pPlayNext = this->pPlayNext;
  }
  else if ( pMovieImpl->pPlayListHead == this )
  {
    pMovieImpl->pPlayListHead = this->pPlayNext;
  }
  this->pPlayPrev = 0;
  this->pPlayNext = 0;
  pObject = this->pDefImpl.pObject;
  if ( pObject )
    Scaleform::GFx::Resource::Release(pObject);
  Scaleform::GFx::DisplayObject::~DisplayObject(this);
}
