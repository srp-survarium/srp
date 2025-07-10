Scaleform::GFx::AS2::FunctionRef *__thiscall Scaleform::GFx::AS2::FunctionRef::`scalar deleting destructor'(
        Scaleform::GFx::AS2::FunctionRef *this,
        char a2)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v5; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v7; // eax

  if ( (this->Flags & 2) == 0 )
  {
    Function = this->Function;
    if ( this->Function )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v5 = (this->Flags & 1) == 0;
  this->Function = 0;
  if ( v5 )
  {
    pLocalFrame = this->pLocalFrame;
    if ( pLocalFrame )
    {
      v7 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v7) != 0 )
      {
        pLocalFrame->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->pLocalFrame = 0;
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
