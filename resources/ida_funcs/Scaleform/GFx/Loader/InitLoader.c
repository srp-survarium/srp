void __thiscall Scaleform::GFx::Loader::InitLoader(
        Scaleform::GFx::Loader *this,
        const Scaleform::GFx::Loader::LoaderConfig *cfg)
{
  bool v4; // cl
  Scaleform::GFx::ResourceLib *v5; // eax
  Scaleform::GFx::ResourceLib *v6; // eax
  Scaleform::GFx::LoaderImpl *v7; // eax
  Scaleform::GFx::LoaderImpl *v8; // eax
  Scaleform::GFx::State *v9; // eax
  Scaleform::GFx::State *v10; // edi
  bool debugHeap; // [esp+10h] [ebp+4h]

  Scaleform::Render::JPEG::JPEGRwSource::TermSource((Scaleform::GFx::AS3::RefCountBaseGC<328> *)this);
  v4 = (cfg->DefLoadFlags & 0x10000000) != 0;
  this->DefLoadFlags = cfg->DefLoadFlags;
  debugHeap = v4;
  v5 = (Scaleform::GFx::ResourceLib *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 20, 0);
  if ( v5 )
    Scaleform::GFx::ResourceLib::ResourceLib(v5, debugHeap);
  else
    v6 = 0;
  this->pStrongResourceLib = v6;
  v7 = (Scaleform::GFx::LoaderImpl *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 60, 0);
  if ( v7 )
    Scaleform::GFx::LoaderImpl::LoaderImpl(v7, this->pStrongResourceLib, debugHeap);
  else
    v8 = 0;
  this->pImpl = v8;
  if ( v8 )
  {
    this->SetState(this, State_FileOpener, cfg->pFileOpener.pObject);
    v9 = (Scaleform::GFx::State *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 16, 0);
    if ( v9 )
    {
      v9->__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v9->RefCount = 1;
      v9->SType = State_ParseControl;
      v9->__vftable = (Scaleform::GFx::State_vtbl *)&Scaleform::GFx::ParseControl::`vftable';
      v9[1].__vftable = 0;
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    this->SetState(this, State_ParseControl, v10);
    if ( v10 )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
    this->SetState(this, State_ZlibSupport, cfg->pZLibSupport.pObject);
  }
}
