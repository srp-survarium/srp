void __thiscall Scaleform::GFx::AS3::Stage::OnInsertionAsLevel(Scaleform::GFx::AS3::Stage *this, int level)
{
  Scaleform::GFx::InteractiveObject *v3; // esi
  Scaleform::GFx::InteractiveObject *pObject; // ecx
  int v5; // [esp+8h] [ebp-4h] BYREF

  v5 = 322;
  v3 = (Scaleform::GFx::InteractiveObject *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                              Scaleform::Memory::pGlobalHeap,
                                              this,
                                              128,
                                              &v5);
  if ( v3 )
  {
    Scaleform::GFx::InteractiveObject::InteractiveObject(v3, this->pDefImpl.pObject, this->pASRoot, 0, 0);
    v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::InteractiveObject_vtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
    v3->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::AS3::FrameCounter::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
    v3[1].Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = 0;
  }
  else
  {
    v3 = 0;
  }
  pObject = this->FrameCounterObj.pObject;
  if ( pObject )
    Scaleform::RefCountNTSImpl::Release(pObject);
  this->FrameCounterObj.pObject = v3;
  Scaleform::GFx::InteractiveObject::AddToPlayList(v3);
  Scaleform::GFx::DisplayObjContainer::OnInsertionAsLevel(this, level);
}
