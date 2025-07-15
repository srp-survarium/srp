survarium::flash_movie *__userpurge survarium::flash_factory::build_movie@<eax>(
        survarium::flash_factory *this@<ecx>,
        _DWORD *a2@<edi>,
        void *raw_data,
        unsigned int raw_data_size,
        char *movie_name)
{
  Scaleform::MemoryHeap_vtbl *v5; // eax
  Scaleform::GFx::ImageCreator *v6; // esi
  int v7; // ecx
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::RefCountVImpl *v9; // eax
  Scaleform::RefCountVImpl *v10; // esi
  _DWORD *v11; // eax
  Scaleform::GFx::MovieDef **v12; // esi
  Scaleform::GFx::MovieDef *v13; // ecx
  Scaleform::GFx::MovieDef_vtbl *v14; // eax
  int v15; // eax
  Scaleform::Render::ThreadCommandQueue *v17; // [esp-4h] [ebp-48h]
  _DWORD v18[15]; // [esp+8h] [ebp-3Ch] BYREF

  if ( !created_image_creator )
  {
    v5 = Scaleform::Memory::pGlobalHeap->__vftable;
    created_image_creator = 1;
    v6 = (Scaleform::GFx::ImageCreator *)v5->Alloc(Scaleform::Memory::pGlobalHeap, 16u, 0);
    if ( v6 )
    {
      v7 = *(_DWORD *)(*(_DWORD *)a2[1] + 4);
      v8 = (Scaleform::GFx::Resource *)(*(int (__thiscall **)(int))(*(_DWORD *)v7 + 220))(v7);
      Scaleform::GFx::ImageCreator::ImageCreator(v6, v8);
      v10 = v9;
    }
    else
    {
      v10 = 0;
    }
    (*(void (__thiscall **)(_DWORD, int, Scaleform::RefCountVImpl *))(*(_DWORD *)*a2 + 8))(*a2, 11, v10);
    if ( v10 )
      Scaleform::RefCountImpl::Release(v10);
  }
  g_file_opener.cached_file.raw_data = raw_data;
  g_file_opener.cached_file.raw_data_size = raw_data_size;
  v11 = operator new(0x1Cu);
  if ( v11 )
  {
    v11[3] = 0;
    v11[4] = 0;
    v11[5] = 0;
    *((_BYTE *)v11 + 24) = 0;
    v12 = (Scaleform::GFx::MovieDef **)v11;
  }
  else
  {
    v12 = 0;
  }
  *v12 = Scaleform::GFx::Loader::CreateMovie((Scaleform::GFx::Loader *)*a2, movie_name, 0, 0);
  g_file_opener.cached_file.raw_data = 0;
  g_file_opener.cached_file.raw_data_size = 0;
  v13 = *v12;
  v17 = *(Scaleform::Render::ThreadCommandQueue **)a2[1];
  v18[2] = 0x2000;
  v18[3] = 0x2000;
  v18[4] = -1;
  memset(&v18[9], 255, 24);
  v14 = v13->Scaleform::GFx::Resource::__vftable;
  v18[0] = 0;
  v18[1] = 16;
  memset(&v18[5], 0, 12);
  *(float *)&v18[8] = FLOAT_0_25;
  v15 = (int)v14->CreateInstance(v13, (const Scaleform::GFx::MemoryParams *)v18, 1, 0, v17);
  v12[1] = (Scaleform::GFx::MovieDef *)v15;
  (*(void (__thiscall **)(int, Scaleform::GFx::MovieDef **))(*(_DWORD *)v15 + 156))(v15, v12);
  v12[1]->Scaleform::GFx::Resource::__vftable[1].WaitForFrame(v12[1], 1u);
  ((void (__thiscall *)(Scaleform::GFx::MovieDef *, int))v12[1]->Scaleform::GFx::Resource::__vftable[1].GetMetadata)(
    v12[1],
    1);
  v12[2] = (Scaleform::GFx::MovieDef *)((int (__thiscall *)(Scaleform::GFx::MovieDef *))v12[1]->VisitImportedMovies)(v12[1]);
  return (survarium::flash_movie *)v12;
}
