void __thiscall Scaleform::Render::FilterEffect::ChainNext(
        Scaleform::Render::FilterEffect *this,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *__formal)
{
  Scaleform::Render::FilterSet *Data; // ecx
  bool v5; // al
  unsigned int v6; // edi

  Data = (Scaleform::Render::FilterSet *)this->StartEntry.Key.Data;
  v5 = Data && Scaleform::Render::FilterSet::IsContributing(Data);
  this->Contributing = v5;
  this->StartEntry.pNextPattern = chain->pFirst;
  if ( v5 )
  {
    this->StartEntry.pChain = 0;
    this->StartEntry.ChainHeight = 0;
    chain->pLast->pNextPattern = &this->EndEntry;
    this->EndEntry.ChainHeight = 0;
    this->EndEntry.pChain = 0;
    v6 = (chain->Length & 0x7FFFFFFF) + 2;
    this->Length = v6;
    chain->Length = v6;
    chain->pFirst = &this->StartEntry;
    chain->pLast = &this->EndEntry;
  }
  else
  {
    this->EndEntry.pNextPattern = chain->pLast;
    this->Length = chain->Length & 0x7FFFFFFF;
  }
}
