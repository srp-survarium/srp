void __thiscall Scaleform::Render::MatrixPoolImpl::EntryHandle::ReleaseHandle(
        Scaleform::Render::MatrixPoolImpl::EntryHandle *this)
{
  void *v1; // eax
  int v2; // edx
  int v3; // esi
  bool v4; // zf

  v1 = (void *)((unsigned int)this & 0xFFFFF800);
  if ( !*(_DWORD *)(((unsigned int)this & 0xFFFFF800) + 0xC) )
  {
    *(_DWORD *)(*(_DWORD *)v1 + 4) = *(_DWORD *)(((unsigned int)this & 0xFFFFF800) + 4);
    **(_DWORD **)(((unsigned int)this & 0xFFFFF800) + 4) = *(_DWORD *)((unsigned int)this & 0xFFFFF800);
    v2 = *(_DWORD *)(((unsigned int)this & 0xFFFFF800) + 0x10);
    v3 = *(_DWORD *)(v2 + 20);
    v2 += 16;
    *(_DWORD *)(((unsigned int)this & 0xFFFFF800) + 4) = v3;
    *(_DWORD *)v1 = v2;
    **(_DWORD **)(v2 + 4) = v1;
    *(_DWORD *)(v2 + 4) = v1;
  }
  this->pHeader = *(Scaleform::Render::MatrixPoolImpl::DataHeader **)(((unsigned int)this & 0xFFFFF800) + 0xC);
  v4 = (*(_DWORD *)(((unsigned int)this & 0xFFFFF800) + 8))-- == 1;
  *(_DWORD *)(((unsigned int)this & 0xFFFFF800) + 0xC) = this;
  if ( v4 )
  {
    *(_DWORD *)(*(_DWORD *)((unsigned int)this & 0xFFFFF800) + 4) = *(_DWORD *)(((unsigned int)this & 0xFFFFF800) + 4);
    **(_DWORD **)(((unsigned int)this & 0xFFFFF800) + 4) = *(_DWORD *)((unsigned int)this & 0xFFFFF800);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v1);
  }
}
