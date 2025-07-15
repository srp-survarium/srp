void __thiscall Scaleform::Render::PNG::LibPNGInput::LibPNGInput(
        Scaleform::Render::PNG::LibPNGInput *this,
        Scaleform::GFx::Resource *pin)
{
  const char *v3; // eax
  unsigned __int8 pbSig[8]; // [esp+8h] [ebp-8h] BYREF

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
      strcpy_s(this->Context.filePath, 0x100u, v3);
      if ( ((int (__thiscall *)(Scaleform::GFx::Resource *, unsigned __int8 *, int))pin->__vftable[2].GetResourceTypeCode)(
             pin,
             pbSig,
             8) == 8
        && !png_sig_cmp((int)pbSig, 0, 8u) )
      {
        Scaleform::Render::PNG::LibPNGInput::StartImage(this);
      }
    }
  }
}
