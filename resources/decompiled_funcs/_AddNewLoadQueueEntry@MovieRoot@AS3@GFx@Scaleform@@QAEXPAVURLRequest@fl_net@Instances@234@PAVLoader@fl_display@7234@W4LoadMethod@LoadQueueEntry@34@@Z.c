void __userpurge Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this@<ecx>,
        int a2@<ebx>,
        int a3@<ebp>,
        int a4@<edi>,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *urlRequest,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *loader,
        Scaleform::RefCountVImpl *method)
{
  Scaleform::GFx::AS3::LoadQueueEntry *v8; // eax
  Scaleform::String *v9; // eax
  Scaleform::GFx::AS3::LoadQueueEntry *v10; // ebp
  char IsProtocolImage; // bl
  Scaleform::GFx::LoadStates *v12; // ebx
  Scaleform::GFx::MovieImpl *pMovieImpl; // eax
  Scaleform::GFx::Resource *pObject; // edi
  Scaleform::GFx::StateBag *v15; // eax
  Scaleform::GFx::LoadStates *v16; // eax
  Scaleform::GFx::LoadStates *v17; // edi
  char v18; // bl
  Scaleform::RefCountVImpl *v19; // eax

  v8 = (Scaleform::GFx::AS3::LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 56, 0);
  if ( !v8 )
    return;
  Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
    v8,
    urlRequest,
    loader,
    (Scaleform::GFx::LoadQueueEntry::LoadMethod)method,
    0);
  v10 = (Scaleform::GFx::AS3::LoadQueueEntry *)v9;
  if ( !v9 )
    return;
  IsProtocolImage = Scaleform::GFx::LoaderImpl::IsProtocolImage(v9 + 4, 0, (bool *)&loader);
  if ( IsProtocolImage && (_BYTE)loader )
  {
    v12 = (Scaleform::GFx::LoadStates *)((int (__thiscall *)(Scaleform::MemoryHeap *, int, _DWORD, int, int, int))Scaleform::Memory::pGlobalHeap->Alloc)(
                                          Scaleform::Memory::pGlobalHeap,
                                          80,
                                          0,
                                          a4,
                                          a2,
                                          a3);
    if ( v12 )
    {
      pMovieImpl = this->pMovieImpl;
      pObject = (Scaleform::GFx::Resource *)pMovieImpl->pMainMovieDef.pObject->pLoaderImpl.pObject;
      v15 = (Scaleform::GFx::StateBag *)pMovieImpl->GetStateBagImpl(&pMovieImpl->Scaleform::GFx::StateBag);
      Scaleform::GFx::LoadStates::LoadStates(v12, pObject, v15, 0);
      v17 = v16;
    }
    else
    {
      v17 = 0;
    }
    this->ProcessLoadQueueEntry(this, v10, v17);
    ((void (__thiscall *)(Scaleform::GFx::AS3::LoadQueueEntry *, int))v10->~Scaleform::GFx::AS3::LoadQueueEntry)(v10, 1);
    if ( v17 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17);
    return;
  }
  if ( !Scaleform::String::GetLength(&v10->URL) || IsProtocolImage )
  {
    v19 = method;
    v18 = 0;
  }
  else
  {
    v18 = 1;
    v19 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
    if ( v19 )
    {
      LOBYTE(method) = 1;
      goto LABEL_16;
    }
  }
  LOBYTE(method) = 0;
LABEL_16:
  if ( (v18 & 1) != 0 && v19 )
    Scaleform::RefCountImpl::Release(v19);
  if ( (_BYTE)method )
    Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(this, v10);
  else
    Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v10);
}
