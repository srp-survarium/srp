void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::MovieDataDef::FrameLabelInfo>::ConstructArray(
        Scaleform::StringDH *p,
        unsigned int count,
        const Scaleform::GFx::MovieDataDef::FrameLabelInfo *psource)
{
  unsigned int i; // ebx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      Scaleform::StringDH::CopyConstructHelper(p, &psource->Name, psource->Name.pHeap);
      p[1].HeapTypeBits = psource->Number;
    }
    ++psource;
    p = (Scaleform::StringDH *)((char *)p + 12);
  }
}
