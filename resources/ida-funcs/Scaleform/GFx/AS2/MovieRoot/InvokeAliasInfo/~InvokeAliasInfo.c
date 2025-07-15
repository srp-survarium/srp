void __thiscall Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo::~InvokeAliasInfo(
        Scaleform::GFx::AS2::MovieRoot::InvokeAliasInfo *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::CharacterHandle *pObject; // esi
  Scaleform::GFx::AS2::Object *v8; // ecx
  unsigned int v9; // eax

  if ( (this->Function.Flags & 2) == 0 )
  {
    Function = this->Function.Function;
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
  v4 = (this->Function.Flags & 1) == 0;
  this->Function.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->Function.pLocalFrame;
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
  this->Function.pLocalFrame = 0;
  pObject = this->ThisChar.pObject;
  if ( pObject )
  {
    if ( --pObject->RefCount <= 0 )
    {
      Scaleform::GFx::CharacterHandle::~CharacterHandle(pObject);
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pObject);
    }
  }
  v8 = this->ThisObject.pObject;
  if ( this->ThisObject.pObject )
  {
    v9 = v8->RefCount;
    if ( (v9 & 0x3FFFFFF) != 0 )
    {
      v8->RefCount = v9 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
    }
  }
}
