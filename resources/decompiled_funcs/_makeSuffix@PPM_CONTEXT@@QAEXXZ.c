void __thiscall PPM_CONTEXT::makeSuffix(PPM_CONTEXT *this)
{
  PPM_CONTEXT *v1; // esi
  PPM_CONTEXT *v2; // eax
  char *p_SummFreq; // eax
  char j; // cl
  unsigned int Stats; // edi
  int v6; // edx
  PPM_CONTEXT *Suffix; // eax
  PPM_CONTEXT::STATE *i; // eax

  v1 = this;
  if ( this->NumStats )
  {
LABEL_8:
    Stats = (unsigned int)v1->Stats;
    if ( Stats <= Stats + 6 * v1->NumStats )
    {
      do
      {
        v6 = *(_DWORD *)(Stats + 2);
        if ( v6 )
        {
          Suffix = v1->Suffix;
          if ( Suffix )
          {
            for ( i = Suffix->Stats; i->Symbol != *(_BYTE *)Stats; ++i )
              ;
            *(_DWORD *)(v6 + 8) = i->Successor;
          }
          else
          {
            *(_DWORD *)(v6 + 8) = v1;
          }
          PPM_CONTEXT::makeSuffix(*(PPM_CONTEXT **)(Stats + 2));
        }
        Stats += 6;
      }
      while ( (PPM_CONTEXT::STATE *)Stats <= &v1->Stats[v1->NumStats] );
    }
  }
  else
  {
    while ( v1->Stats )
    {
      v2 = v1->Suffix;
      if ( v2->NumStats )
      {
        p_SummFreq = (char *)v2->Stats;
        for ( j = v1->SummFreq; *p_SummFreq != j; p_SummFreq += 6 )
          ;
      }
      else
      {
        p_SummFreq = (char *)&v2->SummFreq;
      }
      v1->Stats[1].Successor = *(PPM_CONTEXT **)(p_SummFreq + 2);
      v1 = (PPM_CONTEXT *)v1->Stats;
      if ( v1->NumStats )
        goto LABEL_8;
    }
  }
}
