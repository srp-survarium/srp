void __thiscall Scaleform::GFx::AS2::ValueGuard::~ValueGuard(Scaleform::GFx::AS2::ValueGuard *this)
{
  Scaleform::GFx::InteractiveObject *pChar; // ecx

  pChar = this->pChar;
  if ( pChar )
    Scaleform::RefCountNTSImpl::Release(pChar);
  if ( this->mValue.T.Type >= 5u )
    Scaleform::GFx::AS2::Value::DropRefs(&this->mValue);
}
