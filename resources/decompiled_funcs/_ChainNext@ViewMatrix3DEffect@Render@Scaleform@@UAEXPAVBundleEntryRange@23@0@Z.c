void __thiscall Scaleform::Render::ViewMatrix3DEffect::ChainNext(
        Scaleform::Render::UserDataEffect *this,
        Scaleform::Render::BundleEntryRange *chain,
        Scaleform::Render::BundleEntryRange *__formal)
{
  unsigned int v3; // edi

  this->StartEntry.pNextPattern = chain->pFirst;
  this->StartEntry.pChain = 0;
  this->StartEntry.ChainHeight = 0;
  chain->pLast->pNextPattern = &this->EndEntry;
  this->EndEntry.pChain = 0;
  this->EndEntry.ChainHeight = 0;
  v3 = (chain->Length & 0x7FFFFFFF) + 2;
  this->Length = v3;
  chain->Length = v3;
  chain->pFirst = &this->StartEntry;
  chain->pLast = &this->EndEntry;
}
