void __thiscall Scaleform::GFx::AS2::ArraySortFunctor::~ArraySortFunctor(Scaleform::GFx::AS2::ArraySortFunctor *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax

  if ( (this->Func.Flags & 2) == 0 )
  {
    Function = this->Func.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v4 = (this->Func.Flags & 1) == 0;
  this->Func.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->Func.pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = pLocalFrame->RefCount;
      if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v6) != 0 )
      {
        pLocalFrame->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->Func.pLocalFrame = 0;
}
