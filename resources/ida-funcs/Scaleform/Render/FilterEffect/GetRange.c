void __thiscall Scaleform::Render::FilterEffect::GetRange(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::BundleEntryRange *result)
{
  unsigned int Length; // edx
  unsigned int v3; // esi
  Scaleform::Render::BundleEntry *pNextPattern; // edx
  Scaleform::Render::BundleEntry *v5; // ecx

  if ( this->Contributing )
  {
    Length = this->Length;
    result->pFirst = &this->StartEntry;
    result->pLast = &this->EndEntry;
    result->Length = Length;
  }
  else
  {
    v3 = this->Length;
    pNextPattern = this->EndEntry.pNextPattern;
    v5 = this->StartEntry.pNextPattern;
    result->Length = v3;
    result->pFirst = v5;
    result->pLast = pNextPattern;
  }
}
