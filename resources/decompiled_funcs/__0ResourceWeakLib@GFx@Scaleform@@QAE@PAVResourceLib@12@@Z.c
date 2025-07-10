void __thiscall Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::ResourceLib *pstrongLib)
{
  int v3; // eax
  Scaleform::MemoryHeap *v4; // eax
  Scaleform::MemoryHeap *pObject; // ecx
  Scaleform::MemoryHeap *v6; // edi
  Scaleform::MemoryHeap::HeapDesc desc; // [esp+Ch] [ebp-20h] BYREF

  this->__vftable = (Scaleform::GFx::ResourceWeakLib_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::ResourceWeakLib_vtbl *)&Scaleform::GFx::ResourceWeakLib::`vftable';
  Scaleform::Lock::Lock(&this->ResourceLock, 0);
  this->Resources.pTable = 0;
  this->pImageHeap.pObject = 0;
  this->pStrongLib = pstrongLib;
  if ( pstrongLib && pstrongLib->DebugFlag )
    v3 = 4096;
  else
    v3 = 0;
  desc.Flags = v3 | 4;
  desc.Arena = 0;
  desc.MinAlign = 64;
  desc.Granularity = 4096;
  desc.Reserve = 0;
  desc.Threshold = -1;
  desc.Limit = 0;
  desc.HeapId = 5;
  v4 = Scaleform::Memory::pGlobalHeap->CreateHeap(Scaleform::Memory::pGlobalHeap, "_ResourceLib_Images", &desc);
  pObject = this->pImageHeap.pObject;
  v6 = v4;
  if ( pObject )
    pObject->Release(pObject);
  this->pImageHeap.pObject = v6;
}
