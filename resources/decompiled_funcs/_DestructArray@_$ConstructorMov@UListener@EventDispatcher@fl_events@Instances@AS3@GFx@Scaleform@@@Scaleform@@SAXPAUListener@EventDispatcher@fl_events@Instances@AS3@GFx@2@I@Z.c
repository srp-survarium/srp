void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener>::DestructArray(
        Scaleform::GFx::AS3::Instances::fl_events::EventDispatcher::Listener *p,
        unsigned int count)
{
  Scaleform::GFx::AS3::Value *p_mFunction; // esi
  unsigned int v3; // edi

  if ( count )
  {
    p_mFunction = &p[count - 1].mFunction;
    v3 = count;
    do
    {
      if ( (p_mFunction->Flags & 0x1F) > 9 )
      {
        if ( (p_mFunction->Flags & 0x200) != 0 )
          Scaleform::GFx::AS3::Value::ReleaseWeakRef(p_mFunction);
        else
          Scaleform::GFx::AS3::Value::ReleaseInternal(p_mFunction);
      }
      p_mFunction = (Scaleform::GFx::AS3::Value *)((char *)p_mFunction - 24);
      --v3;
    }
    while ( v3 );
  }
}
