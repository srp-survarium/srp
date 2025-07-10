void __thiscall Scaleform::LongFormatter::AppendSignCharLeft(Scaleform::LongFormatter *this, bool negative)
{
  Scaleform::MsgFormat *pParentFmt; // eax
  const Scaleform::LocaleProvider *pLocaleProvider; // ecx
  int v5; // eax
  char *appended; // eax

  pParentFmt = this->pParentFmt;
  if ( pParentFmt && (pLocaleProvider = pParentFmt->pLocaleProvider) != 0 )
  {
    v5 = (int)pLocaleProvider->GetLocale(pLocaleProvider);
    if ( negative )
    {
      appended = Scaleform::AppendCharLeft(this->ValueStr, *(_DWORD *)(v5 + 24), this->Buff);
    }
    else
    {
      if ( *((char *)&this->Scaleform::NumericBase + 5) >= 0 )
        return;
      appended = Scaleform::AppendCharLeft(this->ValueStr, *(_DWORD *)(v5 + 20), this->Buff);
    }
    this->ValueStr = appended;
  }
  else if ( negative )
  {
    *--this->ValueStr = 45;
  }
  else if ( *((char *)&this->Scaleform::NumericBase + 5) < 0 )
  {
    *--this->ValueStr = 43;
  }
}
