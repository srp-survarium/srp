void __thiscall Scaleform::Render::MaskEffect::GetRange(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::BundleEntryRange *result)
{
  unsigned int Length; // edx
  unsigned int v3; // esi
  Scaleform::Render::BundleEntry *pNextPattern; // edx
  Scaleform::Render::BundleEntry *v5; // ecx

  if ( this->StartEntry.pNextPattern )
  {
    Length = this->Length;
    result->pFirst = &this->StartEntry;
    result->pLast = &this->PopEntry;
    result->Length = Length;
  }
  else
  {
    v3 = this->Length;
    pNextPattern = this->PopEntry.pNextPattern;
    v5 = this->EndEntry.pNextPattern;
    result->Length = v3;
    result->pFirst = v5;
    result->pLast = pNextPattern;
  }
}
