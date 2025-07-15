void __thiscall Scaleform::GFx::MovieImpl::ProcessMovieDefToKillList(Scaleform::GFx::MovieImpl *this)
{
  unsigned int Size; // esi
  unsigned int FinalizedFrameId_high; // ebx
  unsigned int v3; // eax
  unsigned int FinalizedFrameId; // edi
  Scaleform::GFx::MovieImpl::MDKillListEntry *Data; // edx
  Scaleform::Array<Scaleform::GFx::MovieImpl::MDKillListEntry,327,Scaleform::ArrayDefaultPolicy> *p_MovieDefKillList; // ecx

  Size = this->MovieDefKillList.Data.Size;
  if ( Size )
  {
    FinalizedFrameId_high = HIDWORD(this->RenderContext.FinalizedFrameId);
    v3 = 0;
    FinalizedFrameId = this->RenderContext.FinalizedFrameId;
    Data = this->MovieDefKillList.Data.Data;
    p_MovieDefKillList = &this->MovieDefKillList;
    while ( __PAIR64__(FinalizedFrameId_high, FinalizedFrameId) <= Data->KillFrameId )
    {
      ++v3;
      ++Data;
      if ( v3 >= Size )
        return;
    }
    Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::GFx::MovieImpl::MDKillListEntry,Scaleform::AllocatorGH<Scaleform::GFx::MovieImpl::MDKillListEntry,327>,Scaleform::ArrayDefaultPolicy>>::RemoveAt(
      p_MovieDefKillList,
      v3);
  }
}
