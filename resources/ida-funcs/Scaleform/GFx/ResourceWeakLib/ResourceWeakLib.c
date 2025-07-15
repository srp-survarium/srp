void __thiscall Scaleform::GFx::ResourceWeakLib::ResourceWeakLib(
        Scaleform::GFx::ResourceWeakLib *this,
        Scaleform::GFx::ResourceLib *pstrongLib)
{
  int v3; // eax
  Scaleform::MemoryHeap *v4; // eax
  Scaleform::MemoryHeap *pObject; // ecx
  Scaleform::MemoryHeap *v6; // edi
  _DWORD v7[8]; // [esp+Ch] [ebp-20h] BYREF

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
  v7[0] = v3 | 4;
  v7[7] = 0;
  v7[1] = 64;
  v7[2] = 4096;
  v7[3] = 0;
  v7[4] = -1;
  v7[5] = 0;
  v7[6] = 5;
  v4 = Scaleform::Memory::pGlobalHeap->CreateHeap(Scaleform::Memory::pGlobalHeap, "_ResourceLib_Images", v7);
  pObject = this->pImageHeap.pObject;
  v6 = v4;
  if ( pObject )
    pObject->Release(pObject);
  this->pImageHeap.pObject = v6;
}
