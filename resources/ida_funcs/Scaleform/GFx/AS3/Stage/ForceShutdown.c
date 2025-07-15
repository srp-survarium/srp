void __thiscall Scaleform::GFx::AS3::Stage::ForceShutdown(Scaleform::GFx::AS3::Stage *this)
{
  Scaleform::GFx::DisplayObjContainer *pObject; // ecx
  Scaleform::GFx::DisplayObjContainer *v3; // ecx

  Scaleform::GFx::InteractiveObject::RemoveFromPlayList(this->FrameCounterObj.pObject);
  Scaleform::GFx::DisplayList::Clear(&this->mDisplayList, this);
  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
  pObject = this->pRoot.pObject;
  if ( pObject )
    pObject->ForceShutdown(pObject);
  v3 = this->pRoot.pObject;
  if ( v3 )
    Scaleform::RefCountNTSImpl::Release(v3);
  this->pRoot.pObject = 0;
  Scaleform::GFx::DisplayObjContainer::ForceShutdown(this);
}
