void __thiscall Scaleform::Render::ContextImpl::Entry::destroyHelper(Scaleform::Render::ContextImpl::Entry *this)
{
  unsigned int v2; // ebx
  int v3; // ebp
  int v4; // edi
  _RTL_CRITICAL_SECTION *v5; // edi
  Scaleform::Render::ContextImpl::Entry *pPrev; // [esp+10h] [ebp-8h]
  void *v7; // [esp+14h] [ebp-4h]

  v2 = (unsigned int)this & 0xFFFFF000;
  v3 = *(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0xC);
  v4 = (int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28;
  pPrev = this->pPrev;
  v7 = *(void **)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10) + 4 * v4 + 20);
  (*(void (__fastcall **)(void *))(*(_DWORD *)v7 + 12))(v7);
  if ( this->PNode.pPrev )
  {
    this->PNode.pPrev->pNext = this->PNode.pNext;
    this->PNode.pNext->pPrev = this->PNode.pPrev;
    this->PNode.pNext = 0;
    this->PNode.pPrev = 0;
  }
  if ( pPrev )
  {
    (*(void (__thiscall **)(void *))(*(_DWORD *)v7 + 16))(v7);
    if ( (int)pPrev->pNext >= 0 )
    {
      *(_DWORD *)(*(_DWORD *)(v2 + 16) + 4 * v4 + 20) |= 1u;
      this->pPrev = *(Scaleform::Render::ContextImpl::Entry **)(v3 + 40);
      this->RefCount = v3 + 40;
      *(_DWORD *)(*(_DWORD *)(v3 + 40) + 4) = this;
      *(_DWORD *)(v3 + 40) = this;
      pPrev->pPrev = 0;
      pPrev->RefCount = *(_DWORD *)(v3 + 28);
      *(_DWORD *)(v3 + 28) = pPrev;
    }
    else
    {
      if ( ((int)this->pNative & 1) != 0 )
      {
        v5 = (_RTL_CRITICAL_SECTION *)(*(_DWORD *)(*(_DWORD *)(v3 + 8) + 56) + 8);
        EnterCriticalSection(v5);
        Scaleform::Render::ContextImpl::Context::clearRTHandle(
          *(Scaleform::Render::ContextImpl::Context **)(v3 + 8),
          this);
        LeaveCriticalSection(v5);
      }
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v7);
      Scaleform::Render::ContextImpl::EntryTable::FreeEntry(
        (Scaleform::Render::ContextImpl::EntryTable *)(*(_DWORD *)(v3 + 8) + 8),
        (unsigned int)this);
      pPrev->pPrev = 0;
      pPrev->RefCount = *(_DWORD *)(v3 + 28);
      *(_DWORD *)(v3 + 28) = pPrev;
    }
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)(v2 + 16) + 4 * v4 + 20) |= 1u;
    this->pPrev = *(Scaleform::Render::ContextImpl::Entry **)(v3 + 40);
    this->RefCount = v3 + 40;
    *(_DWORD *)(*(_DWORD *)(v3 + 40) + 4) = this;
    *(_DWORD *)(v3 + 40) = this;
  }
}
