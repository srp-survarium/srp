void __thiscall Scaleform::GFx::AS2::GASPrototypeBase::~GASPrototypeBase(Scaleform::GFx::AS2::GASPrototypeBase *this)
{
  Scaleform::GFx::AS2::GASPrototypeBase::InterfacesArray *pInterfaces; // edi
  Scaleform::GFx::AS2::FunctionObject *Function; // ecx
  unsigned int RefCount; // eax
  bool v5; // zf
  Scaleform::GFx::AS2::LocalFrame *pLocalFrame; // ecx
  unsigned int v7; // eax
  Scaleform::GFx::AS2::FunctionObject *v8; // ecx
  unsigned int v9; // eax
  Scaleform::GFx::AS2::LocalFrame *v10; // ecx
  unsigned int v11; // eax

  pInterfaces = this->pInterfaces;
  this->__vftable = (Scaleform::GFx::AS2::GASPrototypeBase_vtbl *)&Scaleform::GFx::AS2::GASPrototypeBase::`vftable';
  if ( pInterfaces )
  {
    Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AS2::Object>>::DestructArray(
      (Scaleform::Ptr<Scaleform::GFx::AS2::LocalFrame> *)pInterfaces->Data.Data,
      pInterfaces->Data.Size);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces->Data.Data);
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pInterfaces);
  }
  if ( (this->__Constructor__.Flags & 2) == 0 )
  {
    Function = this->__Constructor__.Function;
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
  v5 = (this->__Constructor__.Flags & 1) == 0;
  this->__Constructor__.Function = 0;
  if ( v5 )
  {
    pLocalFrame = this->__Constructor__.pLocalFrame;
    if ( pLocalFrame )
    {
      v7 = pLocalFrame->RefCount;
      if ( (v7 & 0x3FFFFFF) != 0 )
      {
        pLocalFrame->RefCount = v7 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(pLocalFrame);
      }
    }
  }
  this->__Constructor__.pLocalFrame = 0;
  if ( (this->Constructor.Flags & 2) == 0 )
  {
    v8 = this->Constructor.Function;
    if ( v8 )
    {
      v9 = v8->RefCount;
      if ( (v9 & 0x3FFFFFF) != 0 )
      {
        v8->RefCount = v9 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v8);
      }
    }
  }
  v5 = (this->Constructor.Flags & 1) == 0;
  this->Constructor.Function = 0;
  if ( v5 )
  {
    v10 = this->Constructor.pLocalFrame;
    if ( v10 )
    {
      v11 = v10->RefCount;
      if ( (v11 & 0x3FFFFFF) != 0 )
      {
        v10->RefCount = v11 - 1;
        Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v10);
      }
    }
  }
  this->Constructor.pLocalFrame = 0;
}
