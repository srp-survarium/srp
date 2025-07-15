void __thiscall Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        Scaleform::GFx::AS2::LocalFrame *localFrame,
        bool internal)
{
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int RefCount; // eax

  pLocalFrame = this->pLocalFrame;
  if ( pLocalFrame )
  {
    if ( (this->Flags & 1) == 0 )
    {
      RefCount = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        pLocalFrame->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->pLocalFrame = localFrame;
  if ( internal )
    this->Flags |= 1u;
  else
    this->Flags &= ~1u;
  if ( localFrame )
  {
    if ( (this->Flags & 1) == 0 )
      localFrame->RefCount = (localFrame->RefCount + 1) & 0x8FFFFFFF;
  }
}
