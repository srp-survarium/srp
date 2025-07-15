void __thiscall Scaleform::GFx::AS2::Environment::CheckTryBlocks(
        Scaleform::GFx::AS2::Environment *this,
        unsigned int pc,
        int *plocalTryBlockCount)
{
  int v3; // ebx
  unsigned int Size; // eax
  unsigned int v6; // ebp
  Scaleform::GFx::AS2::Environment::TryDescr *v7; // eax
  unsigned int TryBeginPC; // edx

  v3 = *plocalTryBlockCount;
  if ( *plocalTryBlockCount > 0 )
  {
    Size = this->TryBlocks.Data.Size;
    if ( Size )
    {
      v6 = pc;
      do
      {
        if ( v3 < 0 )
          break;
        v7 = &this->TryBlocks.Data.Data[Size - 1];
        TryBeginPC = v7->TryBeginPC;
        if ( v6 >= TryBeginPC )
        {
          v6 = pc;
          if ( pc < TryBeginPC + *(unsigned __int16 *)(v7->pTryBlock + 1) )
            break;
        }
        --*plocalTryBlockCount;
        Scaleform::ArrayData<Scaleform::GFx::AS2::Environment::TryDescr,Scaleform::AllocatorLH<Scaleform::GFx::AS2::Environment::TryDescr,2>,Scaleform::ArrayDefaultPolicy>::Resize(
          &this->TryBlocks.Data,
          this->TryBlocks.Data.Size - 1);
        Size = this->TryBlocks.Data.Size;
        --v3;
      }
      while ( Size );
    }
  }
}
