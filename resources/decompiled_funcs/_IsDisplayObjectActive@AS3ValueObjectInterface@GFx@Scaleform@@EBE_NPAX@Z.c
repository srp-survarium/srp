bool __thiscall Scaleform::GFx::AS3ValueObjectInterface::IsDisplayObjectActive(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata)
{
  int v2; // eax

  v2 = pdata[5];
  return (unsigned int)(*(_DWORD *)(v2 + 60) - 17) < 0xC && (*(_DWORD *)(v2 + 56) & 0x20) == 0 && pdata[12] != 0;
}
