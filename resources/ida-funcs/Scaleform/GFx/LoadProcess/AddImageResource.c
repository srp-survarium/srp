void __thiscall Scaleform::GFx::LoadProcess::AddImageResource(
        Scaleform::GFx::LoadProcess *this,
        Scaleform::GFx::ResourceId rid,
        Scaleform::Render::ImageSource *pimage)
{
  Scaleform::AmpStats *v4; // edi
  void (__thiscall **v5)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 v6; // rax
  Scaleform::GFx::MovieDefBindStates *pObject; // eax
  Scaleform::GFx::ImageCreator *v8; // ecx
  Scaleform::Render::Image *(__thiscall *CreateImage)(Scaleform::GFx::ImageCreator *, const Scaleform::GFx::ImageCreateInfo *, Scaleform::Render::ImageSource *); // edx
  Scaleform::Render::Image *v10; // ebp
  Scaleform::GFx::ImageResource *v11; // eax
  Scaleform::GFx::Resource *v12; // eax
  Scaleform::GFx::Resource *v13; // edi
  Scaleform::MemoryHeap *pHeap; // eax
  Scaleform::Render::Image *v15; // ebp
  Scaleform::Render::WrapperImageSource *v16; // eax
  Scaleform::Render::ImageSource *v17; // eax
  Scaleform::Render::ImageSource *v18; // edi
  Scaleform::AmpStats *Stats; // edi
  void (__thiscall **p_NativePopCallstack)(Scaleform::AmpStats *, unsigned __int64); // esi
  unsigned __int64 ProfileTicks; // rax
  Scaleform::GFx::ResourceData result; // [esp+10h] [ebp-60h] BYREF
  Scaleform::GFx::ResourceHandle v23; // [esp+18h] [ebp-58h] BYREF
  Scaleform::AmpFunctionTimer v24; // [esp+20h] [ebp-50h] BYREF
  Scaleform::GFx::ImageCreator v25; // [esp+30h] [ebp-40h] BYREF
  int v26; // [esp+40h] [ebp-30h]
  int v27; // [esp+44h] [ebp-2Ch]
  int v28; // [esp+48h] [ebp-28h]
  int v29; // [esp+4Ch] [ebp-24h]
  Scaleform::GFx::ImageCreateInfo info; // [esp+50h] [ebp-20h] BYREF

  Scaleform::AmpFunctionTimer::AmpFunctionTimer(
    &v24,
    this->LoadProcessStats.pObject,
    "LoadProcess::AddImageResource",
    Amp_Profile_Level_Low,
    Amp_Native_Function_Id_Invalid);
  if ( pimage )
  {
    if ( SLOBYTE(this->LoadFlags) >= 0
      && (pObject = this->pLoadStates.pObject->pBindStates.pObject, pObject->pImageCreator.pObject)
      && (v8 = pObject->pImageCreator.pObject) != 0 )
    {
      CreateImage = v8->CreateImage;
      v25.RefCount = (volatile int)this->pLoadData.pObject->pHeap;
      v25.__vftable = (Scaleform::GFx::ImageCreator_vtbl *)1;
      v25.SType = State_Translator;
      v25.pTextureManager.pObject = (Scaleform::Render::TextureManager *)1;
      v26 = 0;
      v27 = 0;
      v28 = 0;
      v29 = 0;
      v10 = CreateImage(v8, (const Scaleform::GFx::ImageCreateInfo *)&v25, pimage);
      v11 = (Scaleform::GFx::ImageResource *)(*(int (__thiscall **)(volatile int, int, _DWORD))(*(_DWORD *)v25.RefCount
                                                                                              + 40))(
                                               v25.RefCount,
                                               52,
                                               0);
      if ( v11 )
      {
        Scaleform::GFx::ImageResource::ImageResource(v11, v10, Use_Bitmap);
        v13 = v12;
      }
      else
      {
        v13 = 0;
      }
      if ( this->LoadState == LS_LoadingRoot )
        Scaleform::GFx::MovieDataDef::LoadTaskData::AddResource(this->pLoadData.pObject, rid, v13);
      if ( v13 )
        Scaleform::GFx::Resource::Release(v13);
      if ( v10 )
        v10->Release(v10);
    }
    else
    {
      pHeap = this->pLoadData.pObject->pHeap;
      info.Type = Create_FileImage;
      info.pHeap = pHeap;
      info.Use = 1;
      info.RUse = Use_Bitmap;
      memset(&info.pLog, 0, 16);
      Scaleform::GFx::ImageCreator::ImageCreator(&v25, 0);
      v15 = Scaleform::GFx::ImageCreator::CreateImage(&v25, &info, pimage);
      v16 = (Scaleform::Render::WrapperImageSource *)info.pHeap->Alloc(info.pHeap, 12, 0);
      if ( v16 )
      {
        Scaleform::Render::WrapperImageSource::WrapperImageSource(v16, v15);
        v18 = v17;
      }
      else
      {
        v18 = 0;
      }
      Scaleform::GFx::ImageResourceCreator::CreateImageResourceData(&result, v18);
      Scaleform::GFx::LoadProcess::AddDataResource(this, &v23, rid, &result);
      if ( v23.HType == RH_Pointer && v23.BindIndex )
        Scaleform::GFx::Resource::Release(v23.pResource);
      if ( result.pInterface )
        result.pInterface->Release(result.pInterface, result.hData);
      if ( v18 )
        v18->Release(v18);
      if ( v15 )
        v15->Release(v15);
      if ( v25.pTextureManager.pObject )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v25.pTextureManager.pObject);
      v25.__vftable = (Scaleform::GFx::ImageCreator_vtbl *)&Scaleform::GFx::State::`vftable';
      Scaleform::RefCountImplCore::~RefCountImplCore(&v25);
    }
    Stats = v24.Stats;
    if ( v24.Stats )
    {
      p_NativePopCallstack = &v24.Stats->NativePopCallstack;
      ProfileTicks = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*p_NativePopCallstack)(
        Stats,
        ProfileTicks - LODWORD(v24.StartTicks),
        (ProfileTicks - v24.StartTicks) >> 32);
    }
  }
  else
  {
    v4 = v24.Stats;
    if ( v24.Stats )
    {
      v5 = &v24.Stats->NativePopCallstack;
      v6 = Scaleform::Timer::GetProfileTicks();
      ((void (__thiscall *)(Scaleform::AmpStats *, _DWORD, _DWORD))*v5)(
        v4,
        v6 - LODWORD(v24.StartTicks),
        (v6 - v24.StartTicks) >> 32);
    }
  }
}
