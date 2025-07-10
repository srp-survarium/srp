Scaleform::GFx::StateBag *__thiscall Scaleform::GFx::LoaderImpl::GetStateBagImpl(Scaleform::GFx::LoaderImpl *this)
{
  Scaleform::GFx::StateBag_vtbl *v1; // eax

  v1 = this->Scaleform::GFx::StateBag::__vftable;
  if ( v1 )
    return (Scaleform::GFx::StateBag *)&v1->SetState;
  else
    return 0;
}
