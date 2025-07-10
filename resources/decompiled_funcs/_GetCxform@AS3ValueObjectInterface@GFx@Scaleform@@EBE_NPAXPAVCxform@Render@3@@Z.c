char __thiscall Scaleform::GFx::AS3ValueObjectInterface::GetCxform(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        void *pdata,
        Scaleform::Render::Cxform *pcx)
{
  int v3; // eax

  v3 = *((_DWORD *)pdata + 5);
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  qmemcpy(
    pcx,
    Scaleform::GFx::DisplayObjectBase::GetCxform(*((Scaleform::GFx::DisplayObjectBase **)pdata + 12)),
    sizeof(Scaleform::Render::Cxform));
  return 1;
}
