Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats *__thiscall Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats::`vector deleting destructor'(
        Scaleform::GFx::AMP::MovieInstructionStats::ScriptBufferStats *this,
        char a2)
{
  Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this->InstructionTimesArray.Data.Data);
  Scaleform::RefCountImplCore::~RefCountImplCore(this);
  if ( (a2 & 1) != 0 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, this);
  return this;
}
