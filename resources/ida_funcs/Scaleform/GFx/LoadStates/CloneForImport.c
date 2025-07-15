Scaleform::GFx::LoadStates *__thiscall Scaleform::GFx::LoadStates::CloneForImport(Scaleform::GFx::LoadStates *this)
{
  Scaleform::GFx::MovieDefBindStates *v2; // eax
  Scaleform::GFx::Resource *v3; // eax
  Scaleform::GFx::Resource *v4; // ebx
  Scaleform::GFx::LoadStates *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // esi
  Scaleform::RefCountVImpl *v8; // ecx
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::RefCountVImpl *v10; // ecx
  Scaleform::GFx::Resource *v11; // ecx
  Scaleform::RefCountVImpl *v12; // ecx
  Scaleform::GFx::Resource *v13; // ecx
  Scaleform::RefCountVImpl *v14; // ecx
  Scaleform::GFx::Resource *v15; // ecx
  Scaleform::RefCountVImpl *v16; // ecx
  Scaleform::GFx::Resource *v17; // ecx
  Scaleform::RefCountVImpl *v18; // ecx
  Scaleform::GFx::Resource *v19; // ecx
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::GFx::Resource *v21; // ecx
  Scaleform::RefCountVImpl *v22; // ecx
  Scaleform::GFx::Resource *v23; // ecx
  Scaleform::RefCountVImpl *v24; // ecx
  Scaleform::GFx::Resource *v25; // ecx
  Scaleform::RefCountVImpl *v26; // ecx
  Scaleform::GFx::Resource *v27; // ecx
  Scaleform::RefCountVImpl *v28; // ecx
  Scaleform::GFx::Resource *v29; // ecx
  Scaleform::RefCountVImpl *v30; // ecx
  Scaleform::GFx::Resource *v31; // ecx
  Scaleform::RefCountVImpl *v32; // ecx

  v2 = (Scaleform::GFx::MovieDefBindStates *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               40,
                                               0);
  if ( v2 )
  {
    Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v2, this->pBindStates.pObject);
    v4 = v3;
  }
  else
  {
    v4 = 0;
  }
  v5 = (Scaleform::GFx::LoadStates *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 80, 0);
  if ( v5 )
  {
    Scaleform::GFx::LoadStates::LoadStates(v5);
    v7 = v6;
    if ( v6 )
    {
      if ( v4 )
        Scaleform::RefCountImpl::AddRef(v4);
      v8 = (Scaleform::RefCountVImpl *)v7[2];
      if ( v8 )
        Scaleform::RefCountImpl::Release(v8);
      v7[2] = v4;
      pObject = (Scaleform::GFx::Resource *)this->pLoaderImpl.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::AddRef(pObject);
      v10 = (Scaleform::RefCountVImpl *)v7[14];
      if ( v10 )
        Scaleform::RefCountImpl::Release(v10);
      v7[14] = this->pLoaderImpl.pObject;
      v11 = (Scaleform::GFx::Resource *)this->pLog.pObject;
      if ( v11 )
        Scaleform::RefCountImpl::AddRef(v11);
      v12 = (Scaleform::RefCountVImpl *)v7[3];
      if ( v12 )
        Scaleform::RefCountImpl::Release(v12);
      v7[3] = this->pLog.pObject;
      v13 = (Scaleform::GFx::Resource *)this->pProgressHandler.pObject;
      if ( v13 )
        Scaleform::RefCountImpl::AddRef(v13);
      v14 = (Scaleform::RefCountVImpl *)v7[5];
      if ( v14 )
        Scaleform::RefCountImpl::Release(v14);
      v7[5] = this->pProgressHandler.pObject;
      v15 = (Scaleform::GFx::Resource *)this->pTaskManager.pObject;
      if ( v15 )
        Scaleform::RefCountImpl::AddRef(v15);
      v16 = (Scaleform::RefCountVImpl *)v7[6];
      if ( v16 )
        Scaleform::RefCountImpl::Release(v16);
      v7[6] = this->pTaskManager.pObject;
      v17 = (Scaleform::GFx::Resource *)this->pParseControl.pObject;
      if ( v17 )
        Scaleform::RefCountImpl::AddRef(v17);
      v18 = (Scaleform::RefCountVImpl *)v7[4];
      if ( v18 )
        Scaleform::RefCountImpl::Release(v18);
      v7[4] = this->pParseControl.pObject;
      v19 = (Scaleform::GFx::Resource *)this->pWeakResourceLib.pObject;
      if ( v19 )
        Scaleform::RefCountImpl::AddRef(v19);
      v20 = (Scaleform::RefCountVImpl *)v7[13];
      if ( v20 )
        Scaleform::RefCountImpl::Release(v20);
      v7[13] = this->pWeakResourceLib.pObject;
      v21 = (Scaleform::GFx::Resource *)this->pImageFileHandlerRegistry.pObject;
      if ( v21 )
        Scaleform::RefCountImpl::AddRef(v21);
      v22 = (Scaleform::RefCountVImpl *)v7[7];
      if ( v22 )
        Scaleform::RefCountImpl::Release(v22);
      v7[7] = this->pImageFileHandlerRegistry.pObject;
      v23 = (Scaleform::GFx::Resource *)this->pZlibSupport.pObject;
      if ( v23 )
        Scaleform::RefCountImpl::AddRef(v23);
      v24 = (Scaleform::RefCountVImpl *)v7[8];
      if ( v24 )
        Scaleform::RefCountImpl::Release(v24);
      v7[8] = this->pZlibSupport.pObject;
      v25 = (Scaleform::GFx::Resource *)this->pAS2Support.pObject;
      if ( v25 )
        Scaleform::RefCountImpl::AddRef(v25);
      v26 = (Scaleform::RefCountVImpl *)v7[11];
      if ( v26 )
        Scaleform::RefCountImpl::Release(v26);
      v7[11] = this->pAS2Support.pObject;
      v27 = (Scaleform::GFx::Resource *)this->pAS3Support.pObject;
      if ( v27 )
        Scaleform::RefCountImpl::AddRef(v27);
      v28 = (Scaleform::RefCountVImpl *)v7[12];
      if ( v28 )
        Scaleform::RefCountImpl::Release(v28);
      v7[12] = this->pAS3Support.pObject;
      v29 = (Scaleform::GFx::Resource *)this->pAudioState.pObject;
      if ( v29 )
        Scaleform::RefCountImpl::AddRef(v29);
      v30 = (Scaleform::RefCountVImpl *)v7[10];
      if ( v30 )
        Scaleform::RefCountImpl::Release(v30);
      v7[10] = this->pAudioState.pObject;
      v31 = (Scaleform::GFx::Resource *)this->pVideoPlayerState.pObject;
      if ( v31 )
        Scaleform::RefCountImpl::AddRef(v31);
      v32 = (Scaleform::RefCountVImpl *)v7[9];
      if ( v32 )
        Scaleform::RefCountImpl::Release(v32);
      v7[9] = this->pVideoPlayerState.pObject;
    }
  }
  else
  {
    v7 = 0;
  }
  if ( v4 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v4);
  return (Scaleform::GFx::LoadStates *)v7;
}
