void __cdecl Scaleform::ConstructorCPP<Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr>::DestructArray(
        Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::Instances::fl_display::MovieClip::FrameScript::Descr *v2; // esi
  unsigned int v3; // edi

  v2 = &p[count - 1];
  if ( count )
  {
    v3 = count;
    do
    {
      if ( (v2->Method.Flags & 0x1F) > 9 )
      {
        if ( (v2->Method.Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(&v2->Method);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(&v2->Method);
      }
      --v2;
      --v3;
    }
    while ( v3 );
  }
}


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
