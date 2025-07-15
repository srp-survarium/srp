void __thiscall Scaleform::GFx::Loader::InitLoader(
        Scaleform::GFx::Loader *this,
        const Scaleform::GFx::Loader::LoaderConfig *cfg)
{
  unsigned int DefLoadFlags; // ebx
  bool v4; // bl
  Scaleform::GFx::ResourceLib *v5; // eax
  Scaleform::GFx::ResourceLib *v6; // eax
  Scaleform::GFx::LoaderImpl *v7; // eax
  Scaleform::GFx::LoaderImpl *v8; // eax
  Scaleform::GFx::State *v9; // edi
  Scaleform::GFx::State *v10; // eax
  Scaleform::AmpServer *Instance; // eax

  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
  DefLoadFlags = cfg->DefLoadFlags;
  this->DefLoadFlags = cfg->DefLoadFlags;
  v4 = (DefLoadFlags & 0x10000000) != 0;
  v5 = (Scaleform::GFx::ResourceLib *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 20, 0);
  if ( v5 )
    Scaleform::GFx::ResourceLib::ResourceLib(v5, v4);
  else
    v6 = 0;
  this->pStrongResourceLib = v6;
  v7 = (Scaleform::GFx::LoaderImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 60, 0);
  if ( v7 )
    Scaleform::GFx::LoaderImpl::LoaderImpl(v7, this->pStrongResourceLib, v4);
  else
    v8 = 0;
  this->pImpl = v8;
  if ( v8 )
  {
    this->SetState(this, State_FileOpener, cfg->pFileOpener.pObject);
    v9 = 0;
    v10 = (Scaleform::GFx::State *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 16, 0);
    if ( v10 )
    {
      v10->__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v10[1].__vftable = 0;
      v10->RefCount = 1;
      v10->SType = State_ParseControl;
      v10->__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::GFx::ParseControl::`vftable';
      v9 = v10;
    }
    this->SetState(this, State_ParseControl, v9);
    if ( v9 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v9);
    this->SetState(this, State_ZlibSupport, cfg->pZLibSupport.pObject);
  }
  if ( !v4 )
  {
    Instance = Scaleform::AmpServer::GetInstance();
    Instance->AddLoader(Instance, this);
  }
}
