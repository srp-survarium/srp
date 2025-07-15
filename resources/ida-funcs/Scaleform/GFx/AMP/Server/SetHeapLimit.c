void __thiscall Scaleform::GFx::AMP::Server::SetHeapLimit(Scaleform::GFx::AMP::Server *this, unsigned int memLimit)
{
  Scaleform::MemoryHeap *v2; // eax

  v2 = Scaleform::Memory::pGlobalHeap->GetAllocHeap(
         Scaleform::Memory::pGlobalHeap,
         &this[-1].RecordingStateLock.cs.LockSemaphore);
  v2->SetLimit(v2, memLimit);
}
