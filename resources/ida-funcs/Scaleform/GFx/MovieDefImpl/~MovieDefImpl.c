void __thiscall Scaleform::GFx::MovieDefImpl::~MovieDefImpl(Scaleform::GFx::MovieDefImpl *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // ecx
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::RefCountVImpl *v4; // ecx
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::RefCountVImpl *v6; // ecx

  pObject = this->pBindData.pObject;
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDefImpl_vtbl *)&Scaleform::GFx::MovieDefImpl::`vftable'{for `Scaleform::GFx::Resource'};
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::MovieDefImpl::`vftable'{for `Scaleform::GFx::StateBag'};
  Scaleform::GFx::MovieDefImpl::BindTaskData::OnMovieDefRelease(pObject);
  v3 = (Scaleform::RefCountVImpl *)this->pBindData.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  v4 = (Scaleform::RefCountVImpl *)this->pBindStates.pObject;
  if ( v4 )
    Scaleform::RefCountImpl::Release(v4);
  v5 = (Scaleform::RefCountVImpl *)this->pLoaderImpl.pObject;
  if ( v5 )
    Scaleform::RefCountImpl::Release(v5);
  v6 = (Scaleform::RefCountVImpl *)this->pStateBag.pObject;
  if ( v6 )
    Scaleform::RefCountImpl::Release(v6);
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDefImpl_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->Scaleform::GFx::MovieDef::Scaleform::GFx::StateBag::__vftable = (Scaleform::GFx::StateBag_vtbl *)&Scaleform::GFx::StateBag::`vftable';
}
