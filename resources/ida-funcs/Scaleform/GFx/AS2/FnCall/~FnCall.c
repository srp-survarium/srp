void __thiscall Scaleform::GFx::AS2::FnCall::~FnCall(Scaleform::GFx::AS2::FnCall *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax

  this->__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::AS2::FnCall::`vftable';
  if ( (this->ThisFunctionRef.Flags & 2) == 0 )
  {
    Function = this->ThisFunctionRef.Function;
    if ( Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v4 = (this->ThisFunctionRef.Flags & 1) == 0;
  this->ThisFunctionRef.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->ThisFunctionRef.pLocalFrame;
    if ( pLocalFrame )
    {
      v6 = pLocalFrame->RefCount;
      if ( (v6 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v6 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->ThisFunctionRef.pLocalFrame = 0;
  this->__vftable = (Scaleform::GFx::AS2::FnCall_vtbl *)&Scaleform::GFx::LogBase<Scaleform::GFx::AS2::ActionLogger>::`vftable';
}
