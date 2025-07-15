int __thiscall Scaleform::GFx::MovieImpl::GetSupportedGesturesMask(Scaleform::GFx::MovieImpl *this)
{
  Scaleform::RefCountVImpl *v1; // esi
  int v2; // edi

  v1 = (Scaleform::RefCountVImpl *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 7);
  if ( !v1 )
    return 0;
  v2 = ((int (__thiscall *)(Scaleform::RefCountVImpl *))v1->Release)(v1);
  Scaleform::RefCountImpl::Release(v1);
  return v2;
}
