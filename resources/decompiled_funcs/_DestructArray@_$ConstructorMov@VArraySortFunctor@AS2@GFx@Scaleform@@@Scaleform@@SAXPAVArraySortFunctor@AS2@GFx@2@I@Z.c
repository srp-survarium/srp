void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::DestructArray(
        Scaleform::GFx::AS2::ArraySortFunctor *p,
        unsigned int count)
{
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // esi
  unsigned int v3; // edi
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v4; // ecx
  unsigned int RefCount; // eax
  bool v6; // zf
  Scaleform::GFx::AS2::RefCountBaseGC<323> *v7; // ecx
  unsigned int v8; // eax

  if ( count )
  {
    p_pLocalFrame = &p[count - 1].Func.pLocalFrame;
    v3 = count;
    do
    {
      if ( ((_BYTE)p_pLocalFrame[1] & 2) == 0 )
      {
        v4 = *(p_pLocalFrame - 1);
        if ( v4 )
        {
          RefCount = v4->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & RefCount) != 0 )
          {
            v4->RefCount = RefCount - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v4);
          }
        }
      }
      v6 = ((_BYTE)p_pLocalFrame[1] & 1) == 0;
      *(p_pLocalFrame - 1) = 0;
      if ( v6 )
      {
        v7 = *p_pLocalFrame;
        if ( *p_pLocalFrame )
        {
          v8 = v7->RefCount;
          if ( ((unsigned int)&vostok::memory::s_CRT_arena[55905847] & v8) != 0 )
          {
            v7->RefCount = v8 - 1;
            Scaleform::GFx::AS2::RefCountBaseGC<323>::ReleaseInternal(v7);
          }
        }
      }
      *p_pLocalFrame = 0;
      p_pLocalFrame -= 7;
      --v3;
    }
    while ( v3 );
  }
}
