void __thiscall Scaleform::ResourceFormatter::Convert(Scaleform::ResourceFormatter *this)
{
  const Scaleform::ResouceProvider *pRP; // ecx
  unsigned int v3; // ecx
  _DWORD v4[2]; // [esp+4h] [ebp-10h] BYREF
  _DWORD v5[2]; // [esp+Ch] [ebp-8h] BYREF

  if ( !this->IsConverted )
  {
    pRP = this->pRP;
    v4[0] = 0;
    v4[1] = 0;
    if ( pRP )
    {
      pRP->MakeString(pRP, (Scaleform::StringDataPtr *)v5, &this->Value, (const Scaleform::FmtResource::TAttrs *)v4);
      v3 = v5[1];
      this->Result.pStr = (const char *)v5[0];
      this->Result.Size = v3;
    }
    else
    {
      this->Result.pStr = 0;
      this->Result.Size = 0;
    }
    this->IsConverted = 1;
  }
}
