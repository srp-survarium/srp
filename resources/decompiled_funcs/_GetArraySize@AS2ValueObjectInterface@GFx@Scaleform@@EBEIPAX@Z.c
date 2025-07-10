unsigned int __thiscall Scaleform::GFx::AS2ValueObjectInterface::GetArraySize(
        Scaleform::GFx::AS2ValueObjectInterface *this,
        _DWORD *pdata)
{
  if ( pdata )
    return pdata[11];
  else
    return MEMORY[0x3C];
}
