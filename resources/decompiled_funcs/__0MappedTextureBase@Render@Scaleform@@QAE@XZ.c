void __usercall Scaleform::Render::MappedTextureBase::MappedTextureBase(
        Scaleform::Render::MappedTextureBase *this@<ecx>,
        int a2@<esi>)
{
  *(_DWORD *)(a2 + 4) = 0;
  *(_DWORD *)(a2 + 8) = 0;
  *(_DWORD *)(a2 + 12) = 0;
  *(_DWORD *)a2 = &Scaleform::Render::MappedTextureBase::`vftable';
  *(_DWORD *)(a2 + 16) = 0;
  *(_DWORD *)(a2 + 20) = 0;
  *(_BYTE *)(a2 + 24) = 0;
  *(_BYTE *)(a2 + 25) = 0;
  *(_WORD *)(a2 + 26) = 1;
  *(_DWORD *)(a2 + 28) = a2 + 36;
  *(_DWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 36) = 0;
  *(_DWORD *)(a2 + 40) = 0;
  *(_DWORD *)(a2 + 44) = 0;
  *(_DWORD *)(a2 + 48) = 0;
  *(_DWORD *)(a2 + 52) = 0;
  `vector constructor iterator'(
    (char *)(a2 + 56),
    0x14u,
    4,
    (void *(__thiscall *)(void *))Scaleform::Render::ImagePlane::ImagePlane);
}
