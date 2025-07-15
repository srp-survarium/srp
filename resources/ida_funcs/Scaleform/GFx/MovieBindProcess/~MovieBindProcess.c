void __thiscall Scaleform::GFx::MovieBindProcess::~MovieBindProcess(Scaleform::GFx::MovieBindProcess *this)
{
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // eax
  Scaleform::GFx::LoadUpdateSync *v3; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *v4; // eax
  Scaleform::RefCountVImpl *v5; // ecx
  Scaleform::GFx::TempBindData *pTempBindData; // ebx
  Scaleform::GFx::ImagePacker *v7; // ecx
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::GFx::ImagePacker *v9; // ecx

  pObject = this->pBindData.pObject;
  this->__vftable = (Scaleform::GFx::MovieBindProcess_vtbl *)&Scaleform::GFx::MovieBindProcess::`vftable';
  if ( pObject )
  {
    v3 = pObject->pBindUpdate.pObject;
    if ( v3 )
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pObject->pBindUpdate.pObject);
  }
  else
  {
    v3 = 0;
  }
  v4 = this->pBindData.pObject;
  if ( v4 )
  {
    if ( v4->BindState == 1 )
      Scaleform::GFx::MovieDefImpl::BindTaskData::SetBindState(this->pBindData.pObject, 3u);
    v5 = (Scaleform::RefCountVImpl *)this->pBindData.pObject;
    if ( v5 )
      Scaleform::RefCountImpl::Release(v5);
    this->pBindData.pObject = 0;
  }
  pTempBindData = this->pTempBindData;
  if ( pTempBindData )
  {
    Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short>>::NodeHashF>>::Clear((Scaleform::HashSetBase<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeAltHashF,Scaleform::AllocatorLH<unsigned short,2>,Scaleform::HashsetNodeEntry<Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >,Scaleform::HashNode<unsigned short,unsigned int,Scaleform::IdentityHash<unsigned short> >::NodeHashF> > *)this->pTempBindData);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pTempBindData);
  }
  v7 = this->pImagePacker.pObject;
  if ( v7 )
    Scaleform::RefCountNTSImpl::Release(v7);
  this->pImagePacker.pObject = 0;
  if ( v3 )
  {
    Scaleform::Mutex::DoLock(&v3->mMutex);
    v3->LoadFinished = 1;
    Scaleform::WaitCondition::NotifyAll(&v3->WC);
    Scaleform::Mutex::Unlock(&v3->mMutex);
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v3);
  }
  v8 = (Scaleform::RefCountVImpl *)this->pBindData.pObject;
  if ( v8 )
    Scaleform::RefCountImpl::Release(v8);
  v9 = this->pImagePacker.pObject;
  if ( v9 )
    Scaleform::RefCountNTSImpl::Release(v9);
  Scaleform::GFx::LoaderTask::~LoaderTask(this);
}
