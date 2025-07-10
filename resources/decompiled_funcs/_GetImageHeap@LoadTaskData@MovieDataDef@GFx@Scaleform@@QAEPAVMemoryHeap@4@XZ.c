Scaleform::MemoryHeap *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::GetImageHeap(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this)
{
  Scaleform::MemoryHeap *pHeap; // ecx
  int v3; // eax
  Scaleform::MemoryHeap *pObject; // ecx
  Scaleform::MemoryHeap *v5; // ebx
  Scaleform::MemoryHeap::HeapDesc desc; // [esp+4h] [ebp-20h] BYREF

  if ( this->pImageHeap.pObject )
    return this->pImageHeap.pObject;
  pHeap = this->pHeap;
  desc.Arena = 0;
  desc.Flags = 4;
  desc.MinAlign = 32;
  desc.Granularity = 4096;
  desc.Reserve = 0;
  desc.Threshold = -1;
  desc.Limit = 0;
  desc.HeapId = 5;
  v3 = (int)pHeap->CreateHeap(pHeap, "_Images", &desc);
  pObject = this->pImageHeap.pObject;
  v5 = (Scaleform::MemoryHeap *)v3;
  if ( pObject )
    pObject->Release(pObject);
  this->pImageHeap.pObject = v5;
  return v5;
}
