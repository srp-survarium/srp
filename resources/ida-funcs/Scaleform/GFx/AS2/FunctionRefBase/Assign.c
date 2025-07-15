void __thiscall Scaleform::GFx::AS2::FunctionRefBase::Assign(
        Scaleform::GFx::AS2::FunctionRefBase *this,
        const Scaleform::GFx::AS2::FunctionRefBase *orig)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // edi
  unsigned int RefCount; // eax
  Scaleform::GFx::AS2::FunctionObject *v5; // ecx
  bool v6; // zf
  Scaleform::GFx::AS2::FunctionObject *v7; // eax
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // eax
  Scaleform::GFx::AS2::LocalFrame *v9; // ecx
  unsigned int v10; // eax

  if ( this != orig )
  {
    Function = this->Function;
    if ( (this->Flags & 2) == 0 )
    {
      if ( Function )
      {
        if ( Function != orig->Function )
        {
          RefCount = Function->RefCount;
          if ( (RefCount & 0x3FFFFFF) != 0 )
          {
            v5 = this->Function;
            Function->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v5);
          }
        }
      }
    }
    v6 = (this->Flags & 2) == 0;
    this->Function = orig->Function;
    if ( v6 )
    {
      v7 = orig->Function;
      if ( orig->Function )
      {
        if ( Function != v7 )
          v7->RefCount = (v7->RefCount + 1) & 0x8FFFFFFF;
      }
    }
    pLocalFrame = orig->pLocalFrame;
    if ( pLocalFrame )
    {
      Scaleform::GFx::AS2::FunctionRefBase::SetLocalFrame(this, pLocalFrame, orig->Flags & 1);
    }
    else
    {
      v9 = this->pLocalFrame;
      if ( v9 && (this->Flags & 1) == 0 )
      {
        v10 = v9->RefCount;
        if ( (v10 & 0x3FFFFFF) != 0 )
        {
          v9->RefCount = v10 - 1;
          Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
        }
      }
      this->Flags &= ~1u;
      this->pLocalFrame = 0;
    }
  }
}
