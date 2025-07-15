void __cdecl Scaleform::ConstructorCPP<Scaleform::GFx::Value>::DestructArray(
        Scaleform::GFx::Value *p,
        unsigned int count)
{
  Scaleform::GFx::Value *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( (v2->Type & 0x40) != 0 )
      {
        ((void (__stdcall *)(Scaleform::GFx::Value *, int))v2->pObjectInterface->ObjectRelease)(v2, v2->mValue.IValue);
        v2->pObjectInterface = 0;
      }
      v2->Type = VT_Undefined;
      --v2;
      --v3;
    }
    while ( v3 );
  }
}
