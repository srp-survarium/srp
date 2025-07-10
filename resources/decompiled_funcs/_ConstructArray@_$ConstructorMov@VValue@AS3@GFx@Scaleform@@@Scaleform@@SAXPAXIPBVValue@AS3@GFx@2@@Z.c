void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Value>::ConstructArray(
        unsigned int *p,
        unsigned int count,
        Scaleform::GFx::AS3::Value *psource)
{
  Scaleform::GFx::AS3::Value *v4; // ebx
  Scaleform::GFx::AS3::Value::VU *p_value; // edi
  unsigned int v6; // ebp

  if ( count )
  {
    v4 = psource;
    p_value = &psource->value;
    v6 = count;
    do
    {
      if ( p )
      {
        *p = v4->Flags;
        p[1] = (unsigned int)p_value[-1].VS._2.VObj;
        p[2] = p_value->VS._1.VInt;
        p[3] = (unsigned int)p_value->VS._2.VObj;
        if ( (v4->Flags & 0x1F) > 9 )
        {
          if ( (v4->Flags & 0x200) != 0 )
            Scaleform::GFx::AS3::Value::AddRefWeakRef(v4);
          else
            Scaleform::GFx::AS3::Value::AddRefInternal(v4);
        }
      }
      ++v4;
      p_value += 2;
      p += 4;
      --v6;
    }
    while ( v6 );
  }
}
