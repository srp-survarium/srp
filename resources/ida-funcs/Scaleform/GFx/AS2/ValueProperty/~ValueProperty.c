void __thiscall Scaleform::GFx::AS2::ValueProperty::~ValueProperty(Scaleform::GFx::AS2::ValueProperty *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::FunctionObject *v7; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::LocalFrame *v9; // ecx
  unsigned int v10; // eax

  if ( (this->SetterMethod.Flags & 2) == 0 )
  {
    Function = this->SetterMethod.Function;
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
  v4 = (this->SetterMethod.Flags & 1) == 0;
  this->SetterMethod.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->SetterMethod.pLocalFrame;
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
  this->SetterMethod.pLocalFrame = 0;
  if ( (this->GetterMethod.Flags & 2) == 0 )
  {
    v7 = this->GetterMethod.Function;
    if ( v7 )
    {
      v8 = v7->RefCount;
      if ( (v8 & 0x3FFFFFF) != 0 )
      {
        v7->RefCount = v8 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
      }
    }
  }
  v4 = (this->GetterMethod.Flags & 1) == 0;
  this->GetterMethod.Function = 0;
  if ( v4 )
  {
    v9 = this->GetterMethod.pLocalFrame;
    if ( v9 )
    {
      v10 = v9->RefCount;
      if ( (v10 & 0x3FFFFFF) != 0 )
      {
        v9->RefCount = v10 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
      }
    }
  }
  this->GetterMethod.pLocalFrame = 0;
  this->__vftable = (Scaleform::GFx::AS2::ValueProperty_vtbl *)&Scaleform::GFx::AS2::RefCountBaseGC<323>::`vftable';
}
