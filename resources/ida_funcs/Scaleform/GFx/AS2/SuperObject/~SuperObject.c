void __thiscall Scaleform::GFx::AS2::SuperObject::~SuperObject(Scaleform::GFx::AS2::SuperObject *this)
{
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v4; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v6; // eax
  Scaleform::GFx::AS2::Object *pObject; // ecx
  unsigned int v8; // eax
  Scaleform::GFx::AS2::Object *v9; // ecx
  unsigned int v10; // eax

  if ( (this->Constructor.Flags & 2) == 0 )
  {
    Function = this->Constructor.Function;
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
  v4 = (this->Constructor.Flags & 1) == 0;
  this->Constructor.Function = 0;
  if ( v4 )
  {
    pLocalFrame = this->Constructor.pLocalFrame;
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
  this->Constructor.pLocalFrame = 0;
  pObject = this->SavedProto.pObject;
  if ( pObject )
  {
    v8 = pObject->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v8) != 0 )
    {
      pObject->RefCount = v8 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pObject);
    }
  }
  v9 = this->SuperProto.pObject;
  if ( v9 )
  {
    v10 = v9->RefCount;
    if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v10) != 0 )
    {
      v9->RefCount = v10 - 1;
      Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v9);
    }
  }
  Scaleform::GFx::AS2::Object::~Object(this);
}
