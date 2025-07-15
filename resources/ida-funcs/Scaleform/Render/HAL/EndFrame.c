void __thiscall Scaleform::Render::HAL::EndFrame(Scaleform::Render::HAL *this)
{
  Scaleform::Render::RenderEvent *v2; // ebx
  void *v3; // edi
  Scaleform::Render::RenderBufferManager *v4; // eax
  Scaleform::Render::MeshCache *v5; // eax
  Scaleform::Render::TextureManager *v6; // eax
  Scaleform::String v7; // [esp+Ch] [ebp-4h] BYREF

  Scaleform::String::String(&v7, 0);
  v2 = this->GetEvent(this, 1);
  v3 = (void *)(v7.HeapTypeBits & 0xFFFFFFFC);
  if ( InterlockedExchangeAdd((volatile LONG *)((v7.HeapTypeBits & 0xFFFFFFFC) + 4), -1) == 1 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v3);
  if ( (this->HALState & 3) == 3 )
  {
    v4 = this->GetRenderBufferManager(this);
    if ( v4 )
      v4->EndFrame(v4);
    v5 = this->GetMeshCache(this);
    v5->EndFrame(v5);
    v6 = this->GetTextureManager(this);
    v6->EndFrame(v6);
    this->HALState &= ~2u;
  }
  v2->End(v2);
}
