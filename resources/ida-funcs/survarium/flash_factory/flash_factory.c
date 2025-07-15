void __thiscall survarium::flash_factory::flash_factory(
        survarium::flash_factory *this,
        Scaleform::RefCountVImpl *game_engine,
        survarium::scaleform_game_engine *game_enginea)
{
  survarium::scaleform_game_engine *v3; // ebp
  char v4; // bl
  Scaleform::GFx::Loader *v5; // esi
  Scaleform::GFx::ZlibSupportBase *v6; // eax
  survarium::scaleform_game_engine *v7; // eax
  survarium::scaleform_game_engine_vtbl *v8; // eax
  Scaleform::GFx::FontProviderWin32 *v9; // esi
  HDC DC; // eax
  Scaleform::RefCountVImpl *v11; // eax
  survarium::scaleform_game_engine *v12; // eax
  Scaleform::GFx::AS3Support *v13; // eax
  Scaleform::RefCountVImpl *v14; // eax
  Scaleform::RefCountVImpl *v15; // ebx
  Scaleform::GFx::ImageFileHandlerRegistry *v16; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v17; // eax
  Scaleform::GFx::ImageFileHandlerRegistry *v18; // esi
  survarium::scaleform_game_engine_vtbl *v19; // edi
  void (__thiscall *v20)(survarium::scaleform_game_engine *, survarium::scaleform_render_command); // eax
  survarium::scaleform_game_engine *v21; // ecx
  Scaleform::RefCountVImpl *v22; // [esp+48h] [ebp-8h]
  Scaleform::Ptr<Scaleform::GFx::ZlibSupportBase> pzlib; // [esp+4Ch] [ebp-4h] BYREF

  v3 = (survarium::scaleform_game_engine *)game_engine;
  v4 = 0;
  game_engine = 0;
  v5 = (Scaleform::GFx::Loader *)operator new(0x10u);
  if ( v5 )
  {
    v6 = (Scaleform::GFx::ZlibSupportBase *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
    if ( v6 )
    {
      v6->__vftable = (Scaleform::GFx::ZlibSupportBase_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v6->RefCount = 1;
      v6->SType = State_ZlibSupport;
      v6->__vftable = (Scaleform::GFx::ZlibSupportBase_vtbl *)&Scaleform::GFx::ZlibSupport::`vftable';
    }
    else
    {
      v6 = 0;
    }
    pzlib.pObject = v6;
    v7 = (survarium::scaleform_game_engine *)Scaleform::Memory::pGlobalHeap->Alloc(
                                               Scaleform::Memory::pGlobalHeap,
                                               12,
                                               0);
    if ( v7 )
    {
      v7->__vftable = (survarium::scaleform_game_engine_vtbl *)&Scaleform::RefCountImplCore::`vftable';
      v7[1].__vftable = (survarium::scaleform_game_engine_vtbl *)1;
      v7[2].__vftable = (survarium::scaleform_game_engine_vtbl *)9;
      GFx_Compile_with_SF_BUILD_DEBUG = 0;
      v7->__vftable = (survarium::scaleform_game_engine_vtbl *)&Scaleform::GFx::FileOpener::`vftable';
    }
    else
    {
      v7 = 0;
    }
    game_engine = (Scaleform::RefCountVImpl *)v7;
    v4 = 3;
    Scaleform::GFx::Loader::Loader(v5, (const Scaleform::Ptr<Scaleform::GFx::FileOpenerBase> *)&game_engine, &pzlib);
  }
  else
  {
    v8 = 0;
  }
  v3->__vftable = v8;
  if ( (v4 & 2) != 0 )
  {
    v4 &= ~2u;
    if ( game_engine )
      Scaleform::RefCountImpl::Release(game_engine);
  }
  if ( (v4 & 1) != 0 && pzlib.pObject )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)pzlib.pObject);
  (*((void (__thiscall **)(survarium::scaleform_game_engine_vtbl *, int, survarium::vostok_file_opener *))v3->execute_scaleform_command
   + 2))(
    v3->__vftable,
    9,
    &g_file_opener);
  Scaleform::GFx::StateBag::SetLog(
    (Scaleform::GFx::StateBag *)v3->__vftable,
    (Scaleform::GFx::Resource *)&g_vostok_logger);
  v9 = (Scaleform::GFx::FontProviderWin32 *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 16, 0);
  if ( v9 )
  {
    DC = GetDC(0);
    Scaleform::GFx::FontProviderWin32::FontProviderWin32(v9, DC);
    v22 = v11;
    (*((void (__thiscall **)(survarium::scaleform_game_engine_vtbl *, int, Scaleform::RefCountVImpl *))v3->execute_scaleform_command
     + 2))(
      v3->__vftable,
      19,
      v11);
  }
  else
  {
    v22 = 0;
    (*((void (__thiscall **)(survarium::scaleform_game_engine_vtbl *, int, _DWORD))v3->execute_scaleform_command + 2))(
      v3->__vftable,
      19,
      0);
  }
  v12 = (survarium::scaleform_game_engine *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
  if ( v12 )
  {
    v12->__vftable = (survarium::scaleform_game_engine_vtbl *)&Scaleform::RefCountImplCore::`vftable';
    v12[1].__vftable = (survarium::scaleform_game_engine_vtbl *)1;
    v12[2].__vftable = (survarium::scaleform_game_engine_vtbl *)35;
    v12->__vftable = (survarium::scaleform_game_engine_vtbl *)&Scaleform::GFx::AS2Support::`vftable';
    game_engine = (Scaleform::RefCountVImpl *)v12;
  }
  else
  {
    game_engine = 0;
  }
  (*((void (__thiscall **)(survarium::scaleform_game_engine_vtbl *, int, Scaleform::RefCountVImpl *))v3->execute_scaleform_command
   + 2))(
    v3->__vftable,
    35,
    game_engine);
  v13 = (Scaleform::GFx::AS3Support *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 12, 0);
  if ( v13 )
  {
    Scaleform::GFx::AS3Support::AS3Support(v13);
    v15 = v14;
  }
  else
  {
    v15 = 0;
  }
  (*((void (__thiscall **)(survarium::scaleform_game_engine_vtbl *, int, Scaleform::RefCountVImpl *))v3->execute_scaleform_command
   + 2))(
    v3->__vftable,
    36,
    v15);
  v16 = (Scaleform::GFx::ImageFileHandlerRegistry *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                      Scaleform::Memory::pGlobalHeap,
                                                      28,
                                                      0);
  if ( v16 )
  {
    Scaleform::GFx::ImageFileHandlerRegistry::ImageFileHandlerRegistry(v16, NoInit);
    v18 = v17;
  }
  else
  {
    v18 = 0;
  }
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v18, &Scaleform::Render::JPEG::FileReader::Instance);
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v18, &Scaleform::Render::PNG::FileReader::Instance);
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v18, &Scaleform::Render::TGA::FileReader::Instance);
  Scaleform::GFx::ImageFileHandlerRegistry::AddHandler(v18, &Scaleform::Render::DDS::FileReader::Instance);
  (*((void (__thiscall **)(survarium::scaleform_game_engine_vtbl *, int, Scaleform::GFx::ImageFileHandlerRegistry *))v3->execute_scaleform_command
   + 2))(
    v3->__vftable,
    12,
    v18);
  v19 = (survarium::scaleform_game_engine_vtbl *)operator new(4u);
  if ( v19 )
  {
    v20 = (void (__thiscall *)(survarium::scaleform_game_engine *, survarium::scaleform_render_command))operator new(0x18u);
    if ( v20 )
    {
      v21 = game_enginea;
      *(_DWORD *)v20 = &survarium::scaleform_render_command_queue_impl::`vftable';
      *((_DWORD *)v20 + 5) = v21;
      v19->execute_scaleform_command = v20;
    }
    else
    {
      v19->execute_scaleform_command = 0;
    }
  }
  else
  {
    v19 = 0;
  }
  v3[1].__vftable = v19;
  if ( v18 )
    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18);
  if ( v15 )
    Scaleform::RefCountImpl::Release(v15);
  if ( game_engine )
    Scaleform::RefCountImpl::Release(game_engine);
  if ( v22 )
    Scaleform::RefCountImpl::Release(v22);
}
