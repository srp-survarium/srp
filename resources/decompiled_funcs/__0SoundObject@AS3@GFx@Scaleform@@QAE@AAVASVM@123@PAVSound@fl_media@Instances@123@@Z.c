void __thiscall Scaleform::GFx::AS3::SoundObject::SoundObject(
        Scaleform::GFx::AS3::SoundObject *this,
        Scaleform::GFx::AS3::ASVM *asvm,
        Scaleform::GFx::AS3::Instances::fl_vec::Vector_object *psound)
{
  Scaleform::GFx::AS3::Stage *pObject; // edx
  Scaleform::GFx::DisplayObjContainer *v5; // eax

  this->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::SoundObject_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->Scaleform::GFx::ASSoundIntf::__vftable = (Scaleform::GFx::ASSoundIntf_vtbl *)&Scaleform::GFx::ASSoundIntf::`vftable';
  this->Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,323>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::GFx::AS3::SoundObject_vtbl *)&Scaleform::GFx::AS3::SoundObject::`vftable'{for `Scaleform::RefCountBase<Scaleform::GFx::AS3::SoundObject,323>'};
  this->Scaleform::GFx::ASSoundIntf::__vftable = (Scaleform::GFx::ASSoundIntf_vtbl *)&Scaleform::GFx::AS3::SoundObject::`vftable'{for `Scaleform::GFx::ASSoundIntf'};
  this->Volume = 100;
  this->Pan = 0;
  this->pSound.pObject = 0;
  this->pSample.pObject = 0;
  this->pResource.pObject = 0;
  this->pTargetHandle.pObject = 0;
  this->pMovieRoot = asvm->pMovieRoot->pMovieImpl;
  pObject = asvm->pMovieRoot->pStage.pObject;
  v5 = pObject->pRoot.pObject;
  if ( v5
    && (v5->Scaleform::GFx::InteractiveObject::Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Flags
      & 0x400) != 0 )
  {
    Scaleform::GFx::AS3::SoundObject::AttachToTarget(this, (Scaleform::GFx::Sprite *)pObject->pRoot.pObject);
  }
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_display::InteractiveObject>::SetPtr(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::Instances::fl_vec::Vector_object> *)&this->pSound,
    psound);
}
