void __thiscall Scaleform::GFx::AS2::Object::Watchpoint::~Watchpoint(Scaleform::GFx::AS2::Object::Watchpoint *this)
{
  bool v2; // cf
  Scaleform::GFx::AS2::Value *p_UserData; // ecx
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v6; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v8; // eax

  v2 = this->UserData.T.Type < 5u;
  p_UserData = &this->UserData;
  if ( !v2 )
    Scaleform::GFx::AS2::Value::DropRefs(p_UserData);
  if ( (this->Callback.Flags & 2) == 0 )
  {
    Function = this->Callback.Function;
    if ( this->Callback.Function )
    {
      RefCount = Function->RefCount;
      if ( (RefCount & 0x3FFFFFF) != 0 )
      {
        Function->RefCount = RefCount - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(Function);
      }
    }
  }
  v6 = (this->Callback.Flags & 1) == 0;
  this->Callback.Function = 0;
  if ( v6 )
  {
    pLocalFrame = this->Callback.pLocalFrame;
    if ( pLocalFrame )
    {
      v8 = pLocalFrame->RefCount;
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->Callback.pLocalFrame = 0;
}
