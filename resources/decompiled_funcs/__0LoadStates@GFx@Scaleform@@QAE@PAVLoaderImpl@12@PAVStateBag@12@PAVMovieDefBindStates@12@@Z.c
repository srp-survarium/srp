void __thiscall Scaleform::GFx::LoadStates::LoadStates(
        Scaleform::GFx::LoadStates *this,
        Scaleform::GFx::Resource *pimpl,
        Scaleform::GFx::StateBag *pstates,
        Scaleform::GFx::MovieDefBindStates *pbindStates)
{
  Scaleform::RefCountVImpl *pObject; // ecx
  Scaleform::GFx::ResourceWeakLib *pLib; // edi
  Scaleform::GFx::ResourceWeakLib *v7; // ecx
  Scaleform::GFx::StateBag *p_pLib; // edi
  Scaleform::GFx::MovieDefBindStates *v9; // eax
  Scaleform::GFx::MovieDefBindStates *v10; // eax
  Scaleform::GFx::MovieDefBindStates *v11; // ebp
  Scaleform::GFx::MovieDefBindStates *v12; // eax
  Scaleform::RefCountVImpl *v13; // ecx
  Scaleform::GFx::Resource **LogState; // ebp
  Scaleform::RefCountVImpl *v15; // ecx
  Scaleform::GFx::Resource *v16; // eax
  Scaleform::GFx::ParseControl *v17; // ebp
  Scaleform::RefCountVImpl *v18; // ecx
  Scaleform::GFx::Resource *v19; // eax
  Scaleform::GFx::ProgressHandler *v20; // ebp
  Scaleform::RefCountVImpl *v21; // ecx
  Scaleform::GFx::Resource *v22; // eax
  Scaleform::GFx::TaskManager *v23; // ebp
  Scaleform::RefCountVImpl *v24; // ecx
  Scaleform::GFx::Resource *v25; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v26; // ebp
  Scaleform::RefCountVImpl *v27; // ecx
  Scaleform::GFx::Resource *v28; // eax
  Scaleform::GFx::ZlibSupportBase *v29; // ebp
  Scaleform::RefCountVImpl *v30; // ecx
  Scaleform::GFx::Resource *v31; // eax
  Scaleform::GFx::ASSupport *v32; // ebp
  Scaleform::RefCountVImpl *v33; // ecx
  Scaleform::GFx::Resource *v34; // eax
  Scaleform::GFx::ASSupport *v35; // ebp
  Scaleform::RefCountVImpl *v36; // ecx
  Scaleform::GFx::Resource *v37; // eax
  Scaleform::GFx::Video::VideoBase *v38; // ebp
  Scaleform::RefCountVImpl *v39; // ecx
  Scaleform::GFx::Resource *v40; // eax
  Scaleform::GFx::AudioBase *v41; // edi
  Scaleform::RefCountVImpl *v42; // ecx
  Scaleform::Ptr<Scaleform::GFx::LogState> result; // [esp+10h] [ebp-4h] BYREF

  this->__vftable = (Scaleform::GFx::LoadStates_vtbl *)&Scaleform::RefCountImplCore::`vftable';
  this->RefCount = 1;
  this->__vftable = (Scaleform::GFx::LoadStates_vtbl *)&Scaleform::GFx::LoadStates::`vftable';
  this->pBindStates.pObject = 0;
  this->pLog.pObject = 0;
  this->pParseControl.pObject = 0;
  this->pProgressHandler.pObject = 0;
  this->pTaskManager.pObject = 0;
  this->pImageFileHandlerRegistry.pObject = 0;
  this->pZlibSupport.pObject = 0;
  this->pVideoPlayerState.pObject = 0;
  this->pAudioState.pObject = 0;
  this->pAS2Support.pObject = 0;
  this->pAS3Support.pObject = 0;
  this->pWeakResourceLib.pObject = 0;
  this->pLoaderImpl.pObject = 0;
  Scaleform::String::String(&this->RelativePath);
  this->ThreadedLoading = 0;
  this->SubstituteFontMovieDefs.Data.Data = 0;
  this->SubstituteFontMovieDefs.Data.Size = 0;
  this->SubstituteFontMovieDefs.Data.Policy.Capacity = 0;
  if ( pimpl )
    Scaleform::RefCountImpl::AddRef(pimpl);
  pObject = (Scaleform::RefCountVImpl *)this->pLoaderImpl.pObject;
  if ( pObject )
    Scaleform::RefCountImpl::Release(pObject);
  this->pLoaderImpl.pObject = (Scaleform::GFx::LoaderImpl *)pimpl;
  pLib = (Scaleform::GFx::ResourceWeakLib *)pimpl[1].pLib;
  if ( pLib )
    Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)pimpl[1].pLib);
  v7 = this->pWeakResourceLib.pObject;
  if ( v7 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v7);
  this->pWeakResourceLib.pObject = pLib;
  p_pLib = pstates;
  if ( !pstates )
    p_pLib = (Scaleform::GFx::StateBag *)&pimpl->pLib;
  v9 = (Scaleform::GFx::MovieDefBindStates *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               40,
                                               0);
  if ( pbindStates )
  {
    if ( v9 )
    {
      Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v9, pbindStates);
      v11 = v10;
      goto LABEL_17;
    }
  }
  else if ( v9 )
  {
    Scaleform::GFx::MovieDefBindStates::MovieDefBindStates(v9, p_pLib);
    v11 = v12;
    goto LABEL_17;
  }
  v11 = 0;
LABEL_17:
  v13 = (Scaleform::RefCountVImpl *)this->pBindStates.pObject;
  if ( v13 )
    Scaleform::RefCountImpl::Release(v13);
  this->pBindStates.pObject = v11;
  LogState = (Scaleform::GFx::Resource **)Scaleform::GFx::StateBag::GetLogState(p_pLib, &result);
  if ( *LogState )
    Scaleform::RefCountImpl::AddRef(*LogState);
  v15 = (Scaleform::RefCountVImpl *)this->pLog.pObject;
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  this->pLog.pObject = (Scaleform::GFx::LogState *)*LogState;
  if ( result.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
  v16 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_ParseControl);
  v17 = (Scaleform::GFx::ParseControl *)v16;
  if ( v16 )
    Scaleform::RefCountImpl::AddRef(v16);
  v18 = (Scaleform::RefCountVImpl *)this->pParseControl.pObject;
  if ( v18 )
    Scaleform::RefCountImpl::Release(v18);
  this->pParseControl.pObject = v17;
  if ( v17 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v17);
  v19 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_ProgressHandler);
  v20 = (Scaleform::GFx::ProgressHandler *)v19;
  if ( v19 )
    Scaleform::RefCountImpl::AddRef(v19);
  v21 = (Scaleform::RefCountVImpl *)this->pProgressHandler.pObject;
  if ( v21 )
    Scaleform::RefCountImpl::Release(v21);
  this->pProgressHandler.pObject = v20;
  if ( v20 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v20);
  v22 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_TaskManager);
  v23 = (Scaleform::GFx::TaskManager *)v22;
  if ( v22 )
    Scaleform::RefCountImpl::AddRef(v22);
  v24 = (Scaleform::RefCountVImpl *)this->pTaskManager.pObject;
  if ( v24 )
    Scaleform::RefCountImpl::Release(v24);
  this->pTaskManager.pObject = v23;
  if ( v23 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v23);
  v25 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_ImageFileHandlerRegistry);
  v26 = (Scaleform::GFx::ImageFileHandlerRegistry *)v25;
  if ( v25 )
    Scaleform::RefCountImpl::AddRef(v25);
  v27 = (Scaleform::RefCountVImpl *)this->pImageFileHandlerRegistry.pObject;
  if ( v27 )
    Scaleform::RefCountImpl::Release(v27);
  this->pImageFileHandlerRegistry.pObject = v26;
  if ( v26 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v26);
  v28 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_ZlibSupport);
  v29 = (Scaleform::GFx::ZlibSupportBase *)v28;
  if ( v28 )
    Scaleform::RefCountImpl::AddRef(v28);
  v30 = (Scaleform::RefCountVImpl *)this->pZlibSupport.pObject;
  if ( v30 )
    Scaleform::RefCountImpl::Release(v30);
  this->pZlibSupport.pObject = v29;
  if ( v29 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v29);
  v31 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_AS2Support);
  v32 = (Scaleform::GFx::ASSupport *)v31;
  if ( v31 )
    Scaleform::RefCountImpl::AddRef(v31);
  v33 = (Scaleform::RefCountVImpl *)this->pAS2Support.pObject;
  if ( v33 )
    Scaleform::RefCountImpl::Release(v33);
  this->pAS2Support.pObject = v32;
  if ( v32 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v32);
  v34 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_AS3Support);
  v35 = (Scaleform::GFx::ASSupport *)v34;
  if ( v34 )
    Scaleform::RefCountImpl::AddRef(v34);
  v36 = (Scaleform::RefCountVImpl *)this->pAS3Support.pObject;
  if ( v36 )
    Scaleform::RefCountImpl::Release(v36);
  this->pAS3Support.pObject = v35;
  if ( v35 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v35);
  v37 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_Video);
  v38 = (Scaleform::GFx::Video::VideoBase *)v37;
  if ( v37 )
    Scaleform::RefCountImpl::AddRef(v37);
  v39 = (Scaleform::RefCountVImpl *)this->pVideoPlayerState.pObject;
  if ( v39 )
    Scaleform::RefCountImpl::Release(v39);
  this->pVideoPlayerState.pObject = v38;
  if ( v38 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v38);
  v40 = (Scaleform::GFx::Resource *)p_pLib->GetStateAddRef(p_pLib, State_Audio);
  v41 = (Scaleform::GFx::AudioBase *)v40;
  if ( v40 )
    Scaleform::RefCountImpl::AddRef(v40);
  v42 = (Scaleform::RefCountVImpl *)this->pAudioState.pObject;
  if ( v42 )
    Scaleform::RefCountImpl::Release(v42);
  this->pAudioState.pObject = v41;
  if ( v41 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v41);
}
