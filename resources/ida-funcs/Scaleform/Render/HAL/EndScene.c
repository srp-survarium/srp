char __thiscall Scaleform::Render::HAL::EndScene(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // ebx
  void *v3; // edi
  Scaleform::Render::TextureManager *v5; // eax
  Scaleform::String v6; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&v6, 0);
  v2 = this->GetEvent(this, 2);
  v3 = (void *)(v6.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v6.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( (this->HALState & 6) == 6 )
  {
    this->Flush(this);
    if ( this->GetTextureManager(this) )
    {
      v5 = this->GetTextureManager(this);
      v5->EndScene(v5);
    }
    this->HALState &= ~4u;
    v2->End(v2);
    return 1;
  }
  else
  {
    v2->End(v2);
    return 0;
  }
}
