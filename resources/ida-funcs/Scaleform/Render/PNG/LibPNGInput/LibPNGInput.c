void __thiscall Scaleform::Render::PNG::LibPNGInput::LibPNGInput(
        Scaleform::Render::PNG::LibPNGInput *this,
        Scaleform::GFx::Resource *pin)
{
  const char *v3; // eax
  _BYTE v4[8]; // [esp+8h] [ebp-8h] BYREF

  this->__vftable = (Scaleform::Render::PNG::LibPNGInput_vtbl *)&Scaleform::Render::PNG::LibPNGInput::`vftable';
  if ( pin )
    Scaleform::RefCountImpl::AddRef(pin);
  this->pFile.pObject = (Scaleform::File *)pin;
  this->IsInitialized = 0;
  if ( pin )
  {
    if ( (unsigned __int8)pin->GetResourceTypeCode(pin) )
    {
      memset((int)&this->Context, 0, sizeof(this->Context));
      v3 = (const char *)((int (__thiscall *)(Scaleform::GFx::Resource *))pin->GetKey)(pin);
      strcpy_s((int)this, this->Context.filePath, 256, v3);
      if ( ((int (__thiscall *)(Scaleform::GFx::Resource *, _BYTE *, int))pin->__vftable[2].GetResourceTypeCode)(
             pin,
             v4,
             8) == 8
        && !png_sig_cmp(v4, 0, 8) )
      {
        Scaleform::Render::PNG::LibPNGInput::StartImage(this);
      }
    }
  }
}
