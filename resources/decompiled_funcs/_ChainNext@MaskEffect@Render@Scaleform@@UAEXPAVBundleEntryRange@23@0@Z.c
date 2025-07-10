void __thiscall Scaleform::Render::MaskEffect::ChainNext(
        Scaleform::Render::MaskEffect *this,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *maskChain)
{
  unsigned int v3; // edx

  if ( this->MES && maskChain && (maskChain->Length & 0x7FFFFFFF) != 0 )
  {
    this->StartEntry.pNextPattern = maskChain->pFirst;
    this->StartEntry.pChain = 0;
    this->StartEntry.ChainHeight = 0;
    maskChain->pLast->pNextPattern = &this->EndEntry;
    this->EndEntry.pNextPattern = chain->pFirst;
    this->EndEntry.pChain = 0;
    this->EndEntry.ChainHeight = 0;
    chain->pLast->pNextPattern = &this->PopEntry;
    this->PopEntry.pChain = 0;
    this->PopEntry.ChainHeight = 0;
    v3 = (chain->Length & 0x7FFFFFFF) + (maskChain->Length & 0x7FFFFFFF) + 3;
    this->Length = v3;
    chain->pLast = &this->PopEntry;
    chain->pFirst = &this->StartEntry;
    chain->Length = v3;
  }
  else
  {
    this->StartEntry.pNextPattern = 0;
    this->EndEntry.pNextPattern = chain->pFirst;
    this->PopEntry.pNextPattern = chain->pLast;
    this->Length = chain->Length & 0x7FFFFFFF;
  }
}
