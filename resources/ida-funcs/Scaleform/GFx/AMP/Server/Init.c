void Scaleform::GFx::AMP::Server::Init()
{
  Scaleform::MemoryHeap *(__thiscall *CreateHeap)(Scaleform::MemoryHeap *, const char *, const Scaleform::MemoryHeap::HeapDesc *); // eax
  Scaleform::MemoryHeap *v1; // esi
  Scaleform::GFx::AMP::Server *v2; // eax
  Scaleform::AmpServer *v3; // eax
  _DWORD v4[8]; // [esp+8h] [ebp-20h] BYREF

  v4[2] = 0x4000;
  v4[3] = 0x4000;
  CreateHeap = Scaleform::Memory::pGlobalHeap->CreateHeap;
  v4[0] = 4096;
  v4[1] = 16;
  v4[4] = -1;
  memset(&v4[5], 0, 12);
  v1 = CreateHeap(Scaleform::Memory::pGlobalHeap, "AMP", (const Scaleform::MemoryHeap::HeapDesc *)v4);
  v1->SetLimit(v1, (unsigned int)&loc_100000);
  v2 = (Scaleform::GFx::AMP::Server *)v1->Alloc(v1, 624u, 0);
  if ( v2 )
  {
    Scaleform::GFx::AMP::Server::Server(v2);
    if ( v3 )
    {
      Scaleform::AmpServer::AmpServerSingleton = v3 + 2;
      Scaleform::MemoryHeap::ReleaseOnFree(v1, v3);
      return;
    }
  }
  else
  {
    v3 = 0;
  }
  Scaleform::AmpServer::AmpServerSingleton = 0;
  Scaleform::MemoryHeap::ReleaseOnFree(v1, v3);
}
