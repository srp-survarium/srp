void __thiscall PPM_CONTEXT::makeSuffix(PPM_CONTEXT *this)
{
  PPM_CONTEXT *Suffix; // eax
  char *i; // eax
  PPM_CONTEXT::STATE *Stats; // edi
  PPM_CONTEXT::STATE *j; // eax
  PPM_CONTEXT *Successor; // edx
  PPM_CONTEXT *v7; // eax
  PPM_CONTEXT::STATE *k; // eax

  while ( !this->NumStats )
  {
    if ( !this->Stats )
      return;
    Suffix = this->Suffix;
    if ( Suffix->NumStats )
    {
      for ( i = (char *)Suffix->Stats; *i != LOBYTE(this->SummFreq); i += 6 )
        ;
    }
    else
    {
      i = (char *)&Suffix->SummFreq;
    }
    this->Stats[1].Successor = *(PPM_CONTEXT **)(i + 2);
    this = (PPM_CONTEXT *)this->Stats;
  }
  Stats = this->Stats;
  for ( j = &Stats[this->NumStats]; Stats <= j; j = &this->Stats[this->NumStats] )
  {
    Successor = Stats->Successor;
    if ( Successor )
    {
      v7 = this->Suffix;
      if ( v7 )
      {
        for ( k = v7->Stats; k->Symbol != Stats->Symbol; ++k )
          ;
        Successor->Suffix = k->Successor;
      }
      else
      {
        Successor->Suffix = this;
      }
      PPM_CONTEXT::makeSuffix(Stats->Successor);
    }
    ++Stats;
  }
}
