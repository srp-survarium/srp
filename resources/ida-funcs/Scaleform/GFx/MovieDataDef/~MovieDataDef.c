void __thiscall Scaleform::GFx::MovieDataDef::~MovieDataDef(Scaleform::GFx::MovieDataDef *this)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *pObject; // eax
  Scaleform::RefCountVImpl *v3; // ecx
  Scaleform::GFx::ResourceKey::KeyInterface *pKeyInterface; // ecx

  pObject = this->pData.pObject;
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDataDef_vtbl *)&Scaleform::GFx::MovieDataDef::`vftable'{for `Scaleform::GFx::TimelineDef'};
  this->Scaleform::GFx::ResourceReport::__vftable = (Scaleform::GFx::ResourceReport_vtbl *)&Scaleform::GFx::MovieDataDef::`vftable'{for `Scaleform::GFx::ResourceReport'};
  if ( pObject->LoadState <= LS_LoadingFrames )
    pObject->LoadingCanceled = 1;
  v3 = (Scaleform::RefCountVImpl *)this->pData.pObject;
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  pKeyInterface = this->mResourceKey.pKeyInterface;
  if ( pKeyInterface )
    pKeyInterface->Release(pKeyInterface, this->mResourceKey.hKeyData);
  this->Scaleform::GFx::TimelineDef::Scaleform::GFx::CharacterDef::Scaleform::GFx::Resource::__vftable = (Scaleform::GFx::MovieDataDef_vtbl *)&Scaleform::GFx::Resource::`vftable';
  this->Scaleform::GFx::ResourceReport::__vftable = (Scaleform::GFx::ResourceReport_vtbl *)&Scaleform::GFx::ResourceReport::`vftable';
}
