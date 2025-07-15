Scaleform::GFx::AS3::CheckResult *__thiscall Scaleform::GFx::AS3::Tracer::UpdateBlock(
        Scaleform::GFx::AS3::Tracer *this,
        Scaleform::GFx::AS3::CheckResult *result,
        unsigned int bcp)
{
  Scaleform::GFx::AS3::TR::Block *pPrev; // eax
  Scaleform::GFx::AS3::TR::Block *CurrBlock; // edx
  Scaleform::GFx::AS3::CheckResult *v5; // eax

  pPrev = this->Blocks.Root.pPrev;
  CurrBlock = this->CurrBlock;
  if ( pPrev )
  {
    while ( bcp < pPrev->From )
    {
      pPrev = pPrev->pPrev;
      if ( !pPrev )
      {
        v5 = result;
        result->Result = 1;
        return v5;
      }
    }
    if ( pPrev->From == bcp )
    {
      this->CurrBlock = pPrev;
      if ( (*((_BYTE *)pPrev + 8) & 1) != 0 )
      {
        if ( pPrev != CurrBlock
          && !Scaleform::GFx::AS3::Tracer::MergeBlock(this, (Scaleform::GFx::AS3::CheckResult *)&bcp, pPrev, CurrBlock)->Result )
        {
          v5 = result;
          result->Result = 0;
          return v5;
        }
      }
      else
      {
        Scaleform::GFx::AS3::Tracer::InitializeBlock(this, pPrev, CurrBlock);
      }
    }
  }
  v5 = result;
  result->Result = 1;
  return v5;
}
