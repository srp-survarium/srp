survarium::flash_movie *__userpurge survarium::flash_factory::build_movie@<eax>(
        survarium::flash_factory *this@<ecx>,
        _DWORD *a2@<edi>,
        void *raw_data,
        unsigned int raw_data_size,
        const char *movie_name)
{
  void *(__thiscall *Alloc)(Scaleform::MemoryHeap *, unsigned int, const Scaleform::AllocInfo *); // edx
  Scaleform::GFx::ImageCreator *v6; // esi
  int v7; // ecx
  Scaleform::GFx::Resource *v8; // eax
  Scaleform::RefCountVImpl *v9; // eax
  Scaleform::RefCountVImpl *v10; // esi
  _DWORD *v11; // eax
  int *v12; // esi
  int v13; // ecx
  int (__thiscall *v14)(int, _DWORD *, int, _DWORD, int); // eax
  int v15; // eax
  int v17; // [esp+4h] [ebp-48h]
  _DWORD v18[15]; // [esp+10h] [ebp-3Ch] BYREF

  if ( !created_image_creator )
  {
    Alloc = Scaleform::Memory::pGlobalHeap->Alloc;
    created_image_creator = 1;
    v6 = (Scaleform::GFx::ImageCreator *)Alloc(Scaleform::Memory::pGlobalHeap, 16u, 0);
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
    v12 = v11;
  }
  else
  {
    v12 = 0;
  }
  *v12 = (int)Scaleform::GFx::Loader::CreateMovie((Scaleform::GFx::Loader *)*a2, movie_name, 0, 0);
  g_file_opener.cached_file.raw_data = 0;
  g_file_opener.cached_file.raw_data_size = 0;
  v13 = *v12;
  v17 = *(_DWORD *)a2[1];
  v18[2] = 0x2000;
  v18[3] = 0x2000;
  v18[4] = -1;
  memset(&v18[9], 255, 24);
  v14 = *(int (__thiscall **)(int, _DWORD *, int, _DWORD, int))(*(_DWORD *)v13 + 96);
  v18[0] = 0;
  v18[1] = 16;
  memset(&v18[5], 0, 12);
  v18[8] = 1048576000;
  v15 = v14(v13, v18, 1, 0, v17);
  v12[1] = v15;
  (*(void (__thiscall **)(int, int *))(*(_DWORD *)v15 + 156))(v15, v12);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v12[1] + 168))(v12[1], 1);
  (*(void (__thiscall **)(int, int))(*(_DWORD *)v12[1] + 176))(v12[1], 1);
  v12[2] = (*(int (__thiscall **)(int))(*(_DWORD *)v12[1] + 100))(v12[1]);
  return (survarium::flash_movie *)v12;
}
