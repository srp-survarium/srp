int __thiscall Scaleform::Render::TreeContainer::GetSize(Scaleform::Render::TreeContainer *this)
{
  int v1; // eax
  int v2; // ecx
  int v3; // eax

  v1 = *(_DWORD *)(*(_DWORD *)(((unsigned int)this & 0xFFFFF000) + 0x10)
                 + 4 * ((int)((int)&this[-1] - ((unsigned int)this & 0xFFFFF000)) / 28)
                 + 20);
  v2 = *(_DWORD *)(v1 + 144);
  v3 = v1 + 144;
  if ( !v2 )
    return 0;
  if ( (v2 & 1) != 0 )
    return *(_DWORD *)((v2 & 0xFFFFFFFE) + 4);
  return (*(_DWORD *)(v3 + 4) != 0) + 1;
}
