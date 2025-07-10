void __thiscall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_net::URLRequest *urlRequest,
        Scaleform::GFx::AS3::Instances::fl_net::URLLoader *loader,
        Scaleform::RefCountVImpl *method)
{
  char v5; // bl
  Scaleform::GFx::AS3::LoadQueueEntry *v6; // eax
  int v7; // eax
  Scaleform::GFx::AS3::LoadQueueEntry *v8; // edi
  Scaleform::RefCountVImpl *v9; // eax
  char methoda; // [esp+18h] [ebp+Ch]

  v5 = 0;
  v6 = (Scaleform::GFx::AS3::LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 56, 0);
  if ( !v6 )
    return;
  Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(
    v6,
    urlRequest,
    loader,
    (Scaleform::GFx::LoadQueueEntry::LoadMethod)method,
    0);
  v8 = (Scaleform::GFx::AS3::LoadQueueEntry *)v7;
  if ( !v7 )
    return;
  *(_DWORD *)(v7 + 8) = Scaleform::GFx::AS3::Instances::fl_net::URLLoader::IsLoadingBinary(loader) ? 32 : 4;
  if ( Scaleform::String::GetLength(&v8->URL) )
  {
    v5 = 1;
    v9 = (Scaleform::RefCountVImpl *)this->pMovieImpl->GetStateAddRef(&this->pMovieImpl->Scaleform::GFx::StateBag, 21);
    if ( v9 )
    {
      methoda = 1;
      goto LABEL_8;
    }
  }
  else
  {
    v9 = method;
  }
  methoda = 0;
LABEL_8:
  if ( (v5 & 1) != 0 && v9 )
    Scaleform::RefCountImpl::Release(v9);
  if ( methoda )
    Scaleform::GFx::AS3::MovieRoot::AddLoadQueueEntryMT(this, v8);
  else
    Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v8);
}
