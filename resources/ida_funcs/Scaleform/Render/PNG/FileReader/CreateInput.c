void __thiscall Scaleform::Render::PNG::FileReader::CreateInput(
        Scaleform::Render::PNG::FileReader *this,
        Scaleform::GFx::Resource *pin)
{
  Scaleform::Render::PNG::LibPNGInput *v2; // eax
  int v3; // eax

  if ( pin )
  {
    if ( (unsigned __int8)pin->GetResourceTypeCode(pin) )
    {
      v2 = (Scaleform::Render::PNG::LibPNGInput *)Scaleform::Memory::pGlobalHeap->Alloc(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    400,
                                                    0);
      if ( v2 )
      {
        Scaleform::Render::PNG::LibPNGInput::LibPNGInput(v2, pin);
        if ( v3 )
        {
          if ( !*(_BYTE *)(v3 + 396) )
            (**(void (__thiscall ***)(int, int))v3)(v3, 1);
        }
      }
    }
  }
}
