char __thiscall Scaleform::GFx::AS3::MovieRoot::Init(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::MovieDefImpl *pmovieDef)
{
  Scaleform::RefCountVImpl *v3; // edi
  Scaleform::GFx::ASMovieRootBase *pObject; // ebx
  int v5; // eax

  this->CheckAvm(this);
  Scaleform::GFx::AS3::MovieRoot::CreateStage(this, pmovieDef);
  Scaleform::GFx::MovieImpl::SetLevelMovie(this->pMovieImpl, 0, this->pStage.pObject);
  v3 = (Scaleform::RefCountVImpl *)this->pMovieImpl->pStateBag.pObject->GetStateAddRef(
                                     &this->pMovieImpl->pStateBag.pObject->Scaleform::GFx::StateBag,
                                     30);
  if ( v3 && ((int (__thiscall *)(Scaleform::RefCountVImpl *))v3->Release)(v3) )
  {
    pObject = this->pMovieImpl->pASMovieRoot.pObject;
    v5 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v3->Release)(v3);
    (*(void (__thiscall **)(int, Scaleform::GFx::ASMovieRootBase_vtbl *))(*(_DWORD *)v5 + 8))(v5, pObject[2].__vftable);
  }
  this->ResolveStickyVariables(this, this->pStage.pObject);
  if ( v3 )
    Scaleform::RefCountImpl::Release(v3);
  return 1;
}
