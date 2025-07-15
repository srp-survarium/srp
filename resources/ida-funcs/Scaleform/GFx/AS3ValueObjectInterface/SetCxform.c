char __thiscall Scaleform::GFx::AS3ValueObjectInterface::SetCxform(
        Scaleform::GFx::AS3ValueObjectInterface *this,
        _DWORD *pdata,
        const Scaleform::Render::Cxform *cx)
{
  int v3; // eax
  Scaleform::GFx::DisplayObjectBase *v5; // esi

  v3 = pdata[5];
  if ( (unsigned int)(*(_DWORD *)(v3 + 60) - 17) >= 0xC || (*(_DWORD *)(v3 + 56) & 0x20) != 0 )
    return 0;
  v5 = (Scaleform::GFx::DisplayObjectBase *)pdata[12];
  Scaleform::GFx::DisplayObjectBase::SetCxform(v5, cx);
  v5->SetAcceptAnimMoves(v5, 0);
  return 1;
}
