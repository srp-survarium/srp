Scaleform::MemoryHeap *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetImageHeap(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  int v3; // eax
  Scaleform::MemoryHeap *pObject; // ecx
  Scaleform::MemoryHeap *v5; // ebx
  _DWORD v7[8]; // [esp+4h] [ebp-20h] BYREF

  if ( this->pImageHeap.pObject )
    return this->pImageHeap.pObject;
  pHeap = this->pHeap;
  v7[7] = 0;
  v7[0] = 4;
  v7[1] = 32;
  v7[2] = 4096;
  v7[3] = 0;
  v7[4] = -1;
  v7[5] = 0;
  v7[6] = 5;
  v3 = (int)pHeap->CreateHeap(pHeap, "_Images", (const Scaleform::MemoryHeap::HeapDesc *)v7);
  pObject = this->pImageHeap.pObject;
  v5 = (Scaleform::MemoryHeap *)v3;
  if ( pObject )
    pObject->Release(pObject);
  this->pImageHeap.pObject = v5;
  return v5;
}
