void __thiscall Scaleform::GFx::AS3::Tracer::~Tracer(Scaleform::GFx::AS3::Tracer *this)
{
  Scaleform::GFx::AS3::TR::Block *pNext; // eax
  Scaleform::List<Scaleform::GFx::AS3::TR::Block,Scaleform::GFx::AS3::TR::Block> *p_Blocks; // edi
  Scaleform::GFx::AS3::TR::Block *v4; // ebx
  unsigned int Size; // ebp
  unsigned int i; // ebx
  Scaleform::GFx::AS3::TR::State **Data; // ecx
  Scaleform::GFx::AS3::TR::State *v8; // edi

  pNext = this->Blocks.Root.pNext;
  p_Blocks = &this->Blocks;
  this->__vftable = (Scaleform::GFx::AS3::Tracer_vtbl *)&Scaleform::GFx::AS3::Tracer::`vftable';
  if ( pNext != (Scaleform::GFx::AS3::TR::Block *)&this->Blocks )
  {
    do
    {
      v4 = pNext->pNext;
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pNext);
      pNext = v4;
    }
    while ( v4 != (Scaleform::GFx::AS3::TR::Block *)p_Blocks );
  }
  p_Blocks->Root.pPrev = (Scaleform::GFx::AS3::TR::Block *)p_Blocks;
  p_Blocks->Root.pNext = (Scaleform::GFx::AS3::TR::Block *)p_Blocks;
  Size = this->States.Data.Size;
  for ( i = 0; i < Size; ++i )
  {
    Data = this->States.Data.Data;
    v8 = Data[i];
    if ( v8 )
    {
      Scaleform::GFx::AS3::TR::State::~State(Data[i]);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v8);
    }
  }
  Scaleform::ConstructorMov<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::InstanceTraits::fl::Catch>>::DestructArray(
    (Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::VMAbcFile> *)this->CatchTraits.Data.Data,
    this->CatchTraits.Data.Size);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->CatchTraits.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->States.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->Orig2newPosMap.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->PosToRecalculate.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->NewOpcodePos.Data.Data);
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->OrigOpcodePos.Data.Data);
  this->__vftable = (Scaleform::GFx::AS3::Tracer_vtbl *)&Scaleform::GFx::AMP::SocketImplFactory::`vftable';
}
