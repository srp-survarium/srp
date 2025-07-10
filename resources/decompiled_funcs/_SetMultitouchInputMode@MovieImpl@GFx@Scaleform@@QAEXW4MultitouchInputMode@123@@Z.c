void __thiscall Scaleform::GFx::MovieImpl::SetMultitouchInputMode(
        Scaleform::GFx::MovieImpl *this,
        Scaleform::GFx::MovieImpl::MultitouchInputMode mode)
{
  Scaleform::RefCountVImpl *v3; // esi

  v3 = (Scaleform::RefCountVImpl *)this->GetStateAddRef(&this->Scaleform::GFx::StateBag, 7);
  if ( v3 )
  {
    if ( ((unsigned __int8 (__thiscall *)(Scaleform::RefCountVImpl *, Scaleform::GFx::MovieImpl::MultitouchInputMode))v3->__vftable[1].~Scaleform::RefCountVImpl)(
           v3,
           mode) )
    {
      this->MultitouchMode = mode;
    }
    Scaleform::RefCountImpl::Release(v3);
  }
}
