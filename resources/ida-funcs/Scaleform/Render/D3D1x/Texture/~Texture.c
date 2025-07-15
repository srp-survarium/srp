void __usercall Scaleform::Render::D3D1x::Texture::~Texture(
        Scaleform::Render::D3D1x::Texture *this@<ecx>,
        int a2@<esi>)
{
  Scaleform::Mutex *v2; // edi
  int v3; // eax
  int v4; // eax

  v2 = (Scaleform::Mutex *)(*(_DWORD *)(a2 + 16) + 36);
  *(_DWORD *)a2 = &Scaleform::Render::D3D1x::Texture::`vftable';
  Scaleform::Mutex::DoLock(v2);
  v3 = *(_DWORD *)(a2 + 32);
  if ( v3 == 2 || v3 == 3 )
  {
    *(_DWORD *)(*(_DWORD *)(a2 + 8) + 12) = *(_DWORD *)(a2 + 12);
    *(_DWORD *)(*(_DWORD *)(a2 + 12) + 8) = *(_DWORD *)(a2 + 8);
    *(_DWORD *)(a2 + 8) = 0;
    *(_DWORD *)(a2 + 12) = 0;
    Scaleform::Render::D3D1x::Texture::ReleaseHWTextures((Scaleform::Render::D3D1x::Texture *)a2, 1);
  }
  v4 = *(_DWORD *)(a2 + 52);
  if ( v4 != a2 + 56 && v4 )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, *(void **)(a2 + 52));
  Scaleform::Mutex::Unlock(v2);
  Scaleform::Render::Texture::~Texture((Scaleform::Render::Texture *)a2);
}
