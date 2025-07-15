void __thiscall Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(
        Scaleform::GFx::MovieDataDef::LoadTaskData *this,
        Scaleform::GFx::ResourceId rid,
        Scaleform::GFx::Resource *pres)
{
  Scaleform::GFx::MovieDataDef::LoadTaskData *v4; // edi
  int v5; // [esp+8h] [ebp-10h] BYREF
  Scaleform::GFx::Resource *v6; // [esp+Ch] [ebp-Ch]
  Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef v7; // [esp+10h] [ebp-8h] BYREF

  v4 = 0;
  if ( this->LoadState < LS_LoadFinished )
  {
    v4 = this;
    EnterCriticalSection(&this->ResourceLock.cs);
  }
  v5 = 0;
  v6 = pres;
  if ( pres )
    Scaleform::RefCountImpl::AddRef(pres);
  v7.pSecond = (const Scaleform::GFx::ResourceHandle *)&v5;
  v7.pFirst = &rid;
  Scaleform::HashSetBase<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeAltHashF,Scaleform::AllocatorLH<Scaleform::GFx::ResourceId,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF>>::add<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeRef>(
    &this->Resources.mHash,
    (Scaleform::HashsetNodeEntry<Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>,Scaleform::HashNode<Scaleform::GFx::ResourceId,Scaleform::GFx::ResourceHandle,Scaleform::GFx::ResourceId::HashOp>::NodeHashF> *)&this->Resources,
    &v7,
    rid.Id ^ (rid.Id >> 8));
  if ( !v5 && v6 )
    Scaleform::GFx::Resource::Release(v6);
  if ( v4 )
    LeaveCriticalSection(&v4->ResourceLock.cs);
}
