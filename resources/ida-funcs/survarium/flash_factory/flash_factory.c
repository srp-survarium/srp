void __userpurge survarium::flash_factory::flash_factory(
        survarium::flash_factory *this@<ecx>,
        _DWORD *a2@<esi>,
        survarium::scaleform_game_engine *game_engine)
{
  Scaleform::GFx::ZlibSupportBase *v3; // eax
  Scaleform::GFx::FileOpenerBase *v4; // eax
  int v5; // eax
  bool v6; // zf
  Scaleform::GFx::FontProviderWin32 *v7; // edi
  HDC DC; // eax
  Scaleform::GFx::FileOpenerBase *v9; // eax
  Scaleform::GFx::ASSupport *v10; // eax
  Scaleform::GFx::ZlibSupportBase *v11; // edi
  Scaleform::GFx::AS3Support *v12; // eax
  Scaleform::RefCountVImpl *v13; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v14; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v15; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v16; // edi
  Scaleform::GFx::Loader_vtbl *v17; // eax
  Scaleform::GFx::Loader *v18; // eax
  Scaleform::GFx::Loader *v19; // [esp+8h] [ebp-10h]
  Scaleform::GFx::Loader *v20; // [esp+8h] [ebp-10h]
  Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> pfileOpener; // [esp+Ch] [ebp-Ch] BYREF
  Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> pzlib; // [esp+10h] [ebp-8h] BYREF
  Scaleform::RefCountVImpl *v23; // [esp+14h] [ebp-4h]

  v23 = 0;
  v19 = (Scaleform::GFx::Loader *)operator new(0x10u);
  if ( v19 )
  {
    v3 = (Scaleform::GFx::ZlibSupportBase *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
    if ( v3 )
    {
      v3->__vftable = (Scaleform::GFx::ZlibSupportBase_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v3->RefCount = 1;
      v3->SType = State_ZlibSupport;
      v3->__vftable = (Scaleform::GFx::ZlibSupportBase_vtbl *)&Scaleform::GFx::ZlibSupport::`vftable';
    }
    else
    {
      v3 = 0;
    }
    pzlib.pObject = v3;
    v4 = (Scaleform::GFx::FileOpenerBase *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
    if ( v4 )
    {
      v4->__vftable = (Scaleform::GFx::FileOpenerBase_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v4->RefCount = 1;
      v4->SType = State_FileOpener;
      GFx_Compile_with_SF_BUILD_DEBUG = 0;
      v4->__vftable = (Scaleform::GFx::FileOpenerBase_vtbl *)&Scaleform::GFx::FileOpener::`vftable';
    }
    else
    {
      v4 = 0;
    }
    pfileOpener.pObject = v4;
    v23 = (Scaleform::RefCountVImpl *)3;
    Scaleform::GFx::Loader::Loader(v19, &pfileOpener, &pzlib);
  }
  else
  {
    v5 = 0;
  }
  v6 = ((unsigned __int8)v23 & 2) == 0;
  *a2 = v5;
  if ( !v6 )
  {
    v23 = (Scaleform::RefCountVImpl *)((unsigned int)v23 & 0xFFFFFFFD);
    if ( pfileOpener.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfileOpener.pObject);
  }
  if ( ((unsigned __int8)v23 & 1) != 0 && pzlib.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pzlib.pObject);
  g_log_output_ptr(0, "flash_factory created");
  (*(void (__thiscall **)(_DWORD, int, survarium::vostok_file_opener *))(*(_DWORD *)*a2 + 8))(*a2, 9, &g_file_opener);
  Scaleform::GFx::StateBag::SetLog((Scaleform::GFx::StateBag *)*a2, (Scaleform::GFx::Resource *)&g_vostok_logger);
  v7 = (Scaleform::GFx::FontProviderWin32 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 16, 0);
  if ( v7 )
  {
    DC = GetDC(0);
    Scaleform::GFx::FontProviderWin32::FontProviderWin32(v7, DC);
    pfileOpener.pObject = v9;
  }
  else
  {
    pfileOpener.pObject = 0;
  }
  (*(void (__thiscall **)(_DWORD, int, Scaleform::GFx::FileOpenerBase *))(*(_DWORD *)*a2 + 8))(
    *a2,
    19,
    pfileOpener.pObject);
  v10 = (Scaleform::GFx::ASSupport *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
  v11 = (Scaleform::GFx::ZlibSupportBase *)v10;
  if ( v10 )
  {
    Scaleform::GFx::ASSupport::ASSupport(v10, State_AS2Support);
    v11->__vftable = (Scaleform::GFx::ZlibSupportBase_vtbl *)&Scaleform::GFx::AS2Support::`vftable';
    pzlib.pObject = v11;
  }
  else
  {
    pzlib.pObject = 0;
  }
  (*(void (__thiscall **)(_DWORD, int, Scaleform::GFx::ZlibSupportBase *))(*(_DWORD *)*a2 + 8))(*a2, 35, pzlib.pObject);
  v12 = (Scaleform::GFx::AS3Support *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
  if ( v12 )
  {
    Scaleform::GFx::AS3Support::AS3Support(v12);
    v23 = v13;
  }
  else
  {
    v23 = 0;
  }
  (*(void (__thiscall **)(_DWORD, int, Scaleform::RefCountVImpl *))(*(_DWORD *)*a2 + 8))(*a2, 36, v23);
  v14 = (Scaleform::GFx::ImageFileHandlerRegistry *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      28,
                                                      0);
  if ( v14 )
  {
    Scaleform::GFx::ImageFileHandlerRegistry::ImageFileHandlerRegistry(v14, NoInit);
    v16 = v15;
  }
  else
  {
    v16 = 0;
  }
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v16, &Scaleform::Render::JPEG::FileReader::Instance);
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v16, &Scaleform::Render::PNG::FileReader::Instance);
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v16, &Scaleform::Render::TGA::FileReader::Instance);
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v16, &Scaleform::Render::DDS::FileReader::Instance);
  (*(void (__thiscall **)(_DWORD, int, Scaleform::GFx::ImageFileHandlerRegistry *))(*(_DWORD *)*a2 + 8))(*a2, 12, v16);
  v20 = (Scaleform::GFx::Loader *)operator new(4u);
  if ( v20 )
  {
    v17 = (Scaleform::GFx::Loader_vtbl *)operator new(0x18u);
    if ( v17 )
    {
      v17->GetStateBagImpl = (Scaleform::GFx::StateBag *(__thiscall *)(struct Scaleform::GFx::Loader *))&survarium::scaleform_render_command_queue_impl::`vftable';
      v17->CheckTagLoader = (bool (__thiscall *)(Scaleform::GFx::Loader *, int))game_engine;
    }
    else
    {
      v17 = 0;
    }
    v20->__vftable = v17;
    v18 = v20;
  }
  else
  {
    v18 = 0;
  }
  a2[1] = v18;
  if ( v16 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v16);
  if ( v23 )
    Scaleform::RefCountImpl::Release(v23);
  if ( pzlib.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pzlib.pObject);
  if ( pfileOpener.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pfileOpener.pObject);
}
