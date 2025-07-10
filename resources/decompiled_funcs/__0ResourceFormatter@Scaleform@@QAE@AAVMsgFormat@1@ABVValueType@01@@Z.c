void __thiscall Scaleform::ResourceFormatter::ResourceFormatter(
        Scaleform::ResourceFormatter *this,
        Scaleform::MsgFormat *f,
        const Scaleform::ResourceFormatter::ValueType *v)
{
  const Scaleform::ResouceProvider *RC_Provider; // ecx
  const Scaleform::ResouceProvider *v5; // eax
  const Scaleform::LocaleProvider *pLocaleProvider; // ecx

  this->pParentFmt = f;
  this->IsConverted = 0;
  this->__vftable = (Scaleform::ResourceFormatter_vtbl *)&Scaleform::ResourceFormatter::`vftable';
  this->Value.Resource.RLong = v->Resource.RLong;
  *(_DWORD *)&this->Value.IsString = *(_DWORD *)&v->IsString;
  RC_Provider = v->RC_Provider;
  this->pRP = 0;
  this->Value.RC_Provider = RC_Provider;
  this->Result.pStr = 0;
  this->Result.Size = 0;
  v5 = v->RC_Provider;
  this->pRP = v5;
  if ( !v5 )
  {
    pLocaleProvider = this->pParentFmt->pLocaleProvider;
    if ( pLocaleProvider )
      this->pRP = pLocaleProvider->GetDefaultRCProvider(pLocaleProvider);
  }
}
