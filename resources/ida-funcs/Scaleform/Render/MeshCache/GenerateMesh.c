Scaleform::Render::MeshCache::MeshResult *__userpurge Scaleform::Render::MeshCache::GenerateMesh@<eax>(
        Scaleform::Render::MeshCache *this@<ecx>,
        Scaleform::Render::MeshCache::MeshResult *result,
        Scaleform::Render::Mesh *mesh,
        const Scaleform::Render::VertexFormat *sourceFormat,
        const Scaleform::Render::VertexFormat *singleFormat,
        const Scaleform::Render::VertexFormat *batchFormat,
        int waitForCache,
        int a8,
        int a9,
        char a10)
{
  Scaleform::AmpServer *Instance; // eax
  Scaleform::AmpStats *v12; // eax
  Scaleform::Render::SystemVertexFormat *pObject; // esi
  unsigned int Size; // ecx
  int v15; // ebx
  unsigned __int64 ProfileTicks; // rax
  const char *v18; // [esp+0h] [ebp-48h]
  Scaleform::AmpProfileLevel v19; // [esp+4h] [ebp-44h]
  Scaleform::AmpNativeFunctionId v20; // [esp+8h] [ebp-40h]
  __int64 v21; // [esp+Ch] [ebp-3Ch]
  int *v22; // [esp+14h] [ebp-34h]
  Scaleform::AmpFunctionTimer v23; // [esp+18h] [ebp-30h] BYREF
  _DWORD v24[2]; // [esp+28h] [ebp-20h] BYREF
  int v25; // [esp+30h] [ebp-18h]
  const Scaleform::Render::VertexFormat *v26; // [esp+34h] [ebp-14h]
  int v27; // [esp+38h] [ebp-10h]
  int v28; // [esp+3Ch] [ebp-Ch]
  int v29; // [esp+40h] [ebp-8h]
  int v30; // [esp+44h] [ebp-4h]
  _UNKNOWN *retaddr; // [esp+48h] [ebp+0h]

  Instance = Scaleform::AmpServer::GetInstance();
  v12 = (Scaleform::AmpStats *)((int (__thiscall *)(Scaleform::AmpServer *, const char *, int, int))Instance->GetDisplayStats)(
                                 Instance,
                                 "MeshCache::GenerateMesh",
                                 2,
                                 -1);
  Scaleform::AmpFunctionTimer::AmpFunctionTimer(&v23, v12, v18, v19, v20);
  v24[1] = this;
  pObject = batchFormat[8].pSysFormat.pObject;
  LOBYTE(v25) = a10;
  v27 = waitForCache;
  v28 = a8;
  Size = batchFormat[4].Size;
  v26 = batchFormat;
  v24[0] = &Scaleform::Render::MeshVertexOutput::`vftable';
  v29 = a9;
  v30 = 6;
  retaddr = 0;
  (*(void (__thiscall **)(unsigned int, const Scaleform::Render::VertexFormat *, _DWORD *, Scaleform::Render::SystemVertexFormat *))(*(_DWORD *)Size + 12))(
    Size,
    batchFormat,
    v24,
    pObject);
  MEMORY[0] = v27;
  HIDWORD(v23.StartTicks) = &Scaleform::GFx::AS3::ArrayBase::`vftable';
  if ( v22 )
  {
    v15 = *v22;
    ProfileTicks = Scaleform::Timer::GetProfileTicks();
    (*(void (__thiscall **)(int *, _DWORD, _DWORD))(v15 + 8))(v22, ProfileTicks - v21, (ProfileTicks - v21) >> 32);
  }
  return 0;
}
