void __thiscall Scaleform::GFx::AS3::MovieRoot::AddNewLoadQueueEntry(
        Scaleform::GFx::AS3::MovieRoot *this,
        Scaleform::GFx::AS3::Instances::fl_utils::ByteArray *bytes,
        Scaleform::GFx::AS3::Instances::fl_display::Loader *loader,
        Scaleform::GFx::LoadQueueEntry::LoadMethod method)
{
  Scaleform::GFx::AS3::LoadQueueEntry *v5; // eax
  Scaleform::GFx::LoadQueueEntry *v6; // eax

  v5 = (Scaleform::GFx::AS3::LoadQueueEntry *)this->pMovieImpl->pHeap->Alloc(this->pMovieImpl->pHeap, 56, 0);
  if ( v5 )
  {
    Scaleform::GFx::AS3::LoadQueueEntry::LoadQueueEntry(v5, bytes, loader, method);
    if ( v6 )
      Scaleform::GFx::MovieImpl::AddLoadQueueEntry(this->pMovieImpl, v6);
  }
}
