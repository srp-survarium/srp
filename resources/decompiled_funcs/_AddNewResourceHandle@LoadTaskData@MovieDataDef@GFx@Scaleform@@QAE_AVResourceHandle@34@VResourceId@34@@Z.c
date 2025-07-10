Scaleform::GFx::ResourceHandle *__thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::AddNewResourceHandle(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::ResourceHandle *result,
        Scaleform::GFx::ResourceId rid)
{
  unsigned int ResIndexCounter; // eax
  Scaleform::GFx::MovieDataDef::LoadTaskData *v5; // ebx
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef key; // [esp+Ch] [ebp-8h] BYREF

  ResIndexCounter = this->ResIndexCounter;
  result->HType = RH_Index;
  result->BindIndex = ResIndexCounter;
  ++this->ResIndexCounter;
  v5 = 0;
  if ( this->LoadState < LS_LoadFinished )
  {
    v5 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  key.pFirst = &rid;
  key.pSecond = result;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef>(
    &this->Resources.mHash,
    (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> *)&this->Resources,
    &key,
    rid.Id ^ (rid.Id >> 8));
  if ( v5 )
    LeaveCriticalSection(&v5->ResourceLock.cs);
  return result;
}
