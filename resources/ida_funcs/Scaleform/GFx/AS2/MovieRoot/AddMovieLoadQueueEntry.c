void __userpurge Scaleform::GFx::AS2::MovieRoot::AddMovieLoadQueueEntry(
        Scaleform::GFx::AS2::MovieRoot *this@<ecx>,
        int a2@<ebx>,
        int a3@<esi>,
        Scaleform::GFx::LoadQueueEntry *pentry)
{
  char IsProtocolImage; // bl
  Scaleform::GFx::LoadStates *v7; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::Resource *pObject; // esi
  Scaleform::GFx::StateBag *v10; // eax
  Scaleform::GFx::LoadStates *v11; // eax
  Scaleform::GFx::LoadStates *v12; // esi
  char v13; // bl
  Scaleform::RefCountVImpl *v14; // eax
  bool sync; // [esp+Bh] [ebp-5h] BYREF
  int v17; // [esp+Ch] [ebp-4h]
  char pentrya; // [esp+14h] [ebp+4h]

  v17 = 0;
  if ( !pentry )
    return;
  IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(&pentry->URL, 0, &sync);
  if ( IsProtocolImage && sync )
  {
    v7 = (Scaleform::GFx::LoadStates *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int))Scaleform::Memory::pGlobalHeap->Alloc)(
                                         Scaleform::Memory::pGlobalHeap,
                                         80,
                                         0,
                                         a3,
                                         a2);
    if ( v7 )
    {
      pMovieImpl = this->pMovieImpl;
      pObject = (Scaleform::GFx::Resource *)pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
      v10 = (Scaleform::GFx::StateBag *)pMovieImpl->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
      Scaleform::GFx::LoadStates::LoadStates(v7, pObject, v10, 0);
      v12 = v11;
    }
    else
    {
      v12 = 0;
    }
    this->ProcessLoadQueueEntry(this, pentry, v12);
    ((void (__thiscall *)(Scaleform::GFx::LoadQueueEntry *, int))pentry->~Scaleform::GFx::LoadQueueEntry)(pentry, 1);
    if ( v12 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v12);
    return;
  }
  if ( !Scaleform::String::GetLength(&pentry->URL) || IsProtocolImage )
  {
    v14 = (Scaleform::RefCountVImpl *)pentry;
    v13 = v17;
  }
  else
  {
    v13 = 1;
    v14 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
    if ( v14 )
    {
      pentrya = 1;
      goto LABEL_15;
    }
  }
  pentrya = 0;
LABEL_15:
  if ( (v13 & 1) != 0 && v14 )
    Scaleform::RefCountImpl::Release(v14);
  if ( pentrya )
    Scaleform::GFx::AS2::MovieRoot::AddLoadQueueEntryMT(this, pentry);
  else
    Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, pentry);
}
