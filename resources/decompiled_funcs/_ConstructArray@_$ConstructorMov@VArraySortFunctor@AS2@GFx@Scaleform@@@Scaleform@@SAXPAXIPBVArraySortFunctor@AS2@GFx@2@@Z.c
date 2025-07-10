void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::ConstructArray(
        char *p,
        unsigned int count,
        const Scaleform::GFx::AS2::ArraySortFunctor *psource)
{
  const Scaleform::GFx::AS2::ArraySortFunctor *v3; // edi
  char *v4; // eax
  Scaleform::GFx::AS2::LocalFrame **p_pLocalFrame; // ecx
  unsigned int v6; // ebp
  int v7; // edx
  Scaleform::GFx::AS2::LocalFrame *v8; // esi
  bool v9; // zf

  if ( count )
  {
    v3 = psource;
    v4 = p + 16;
    p_pLocalFrame = &psource->Func.pLocalFrame;
    v6 = count;
    do
    {
      if ( v4 != (char *)16 )
      {
        *((_DWORD *)v4 - 4) = v3->This;
        *((_DWORD *)v4 - 3) = *(p_pLocalFrame - 2);
        *v4 = 0;
        v7 = (int)*(p_pLocalFrame - 1);
        *((_DWORD *)v4 - 2) = v7;
        if ( v7 )
          *(_DWORD *)(v7 + 12) = (*(_DWORD *)(v7 + 12) + 1) & 0x8FFFFFFF;
        *((_DWORD *)v4 - 1) = 0;
        v8 = *p_pLocalFrame;
        if ( *p_pLocalFrame )
        {
          v9 = ((_BYTE)p_pLocalFrame[1] & 1) == 0;
          *((_DWORD *)v4 - 1) = v8;
          if ( v9 )
            *v4 &= ~1u;
          else
            *v4 |= 1u;
          if ( v8 )
          {
            if ( (*v4 & 1) == 0 )
              v8->RefCount = (v8->RefCount + 1) & 0x8FFFFFFF;
          }
        }
        *((_DWORD *)v4 + 1) = p_pLocalFrame[2];
        *((_DWORD *)v4 + 2) = p_pLocalFrame[3];
      }
      ++v3;
      p_pLocalFrame += 7;
      v4 += 28;
      --v6;
    }
    while ( v6 );
  }
}
