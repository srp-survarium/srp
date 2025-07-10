void __thiscall Scaleform::Render::HAL::endDisplay(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // ebx
  void *v3; // edi
  Scaleform::String v4; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&v4, 0);
  v2 = this->GetEvent(this, 4);
  v3 = (void *)(v4.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v4.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( (this->HALState & 8) != 0 )
  {
    this->endMaskDisplay(this);
    if ( (this->HALState & 0x200) != 0 )
    {
      this->EndScene(this);
      this->HALState &= ~0x200u;
    }
    this->HALState &= ~8u;
  }
  v2->End(v2);
}
