void __cdecl Scaleform::GFx::AS3::XMLParser::EndElementExpatCallback(
        Scaleform::GFx::AS3::XMLParser *userData,
        const char *name)
{
  Scaleform::GFx::AS3::XMLParser *v2; // esi
  void *pObject; // edi
  void **p_pObject; // ebp
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v5; // ebx
  unsigned int v6; // eax
  Scaleform::GFx::AS3::RefCountBaseGC<328> *v7; // ecx
  unsigned int RefCount; // eax
  unsigned int v9; // eax
  unsigned int v10; // eax

  v2 = userData;
  Scaleform::GFx::AS3::XMLParser::SetNodeKind(userData, kElement);
  Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy>>::Pop((Scaleform::ArrayBase<Scaleform::ArrayDataDH<unsigned long,Scaleform::AllocatorDH<unsigned long,2>,Scaleform::ArrayDefaultPolicy> > *)&v2->KindStack);
  pObject = v2->pCurrElem.pObject;
  p_pObject = (void **)&v2->pCurrElem.pObject;
  if ( pObject )
  {
    do
    {
      v5 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*((_DWORD *)pObject + 9);
      if ( !v5 )
        break;
      v6 = (v5->RefCount + 1) & 0x8FBFFFFF;
      v5->RefCount = v6;
      if ( &userData != (Scaleform::GFx::AS3::XMLParser **)p_pObject )
      {
        v5->RefCount = (v6 + 1) & 0x8FBFFFFF;
        v7 = (Scaleform::GFx::AS3::RefCountBaseGC<328> *)*p_pObject;
        if ( *p_pObject )
        {
          if ( ((unsigned __int8)v7 & 1) != 0 )
          {
            *p_pObject = (char *)&v7[-1].RefCount + 3;
          }
          else
          {
            RefCount = v7->RefCount;
            if ( ((unsigned int)&byte_3FFFFF & RefCount) != 0 )
            {
              v7->RefCount = RefCount - 1;
              Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v7);
            }
          }
        }
        *p_pObject = (void *)v5;
      }
      if ( !strcmp(**((const char ***)pObject + 8), name) )
      {
        if ( ((unsigned __int8)v5 & 1) == 0 )
        {
          v10 = v5->RefCount;
          if ( ((unsigned int)&byte_3FFFFF & v10) != 0 )
          {
            v5->RefCount = v10 - 1;
            Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
          }
        }
        return;
      }
      if ( ((unsigned __int8)v5 & 1) == 0 )
      {
        v9 = v5->RefCount;
        if ( ((unsigned int)&byte_3FFFFF & v9) != 0 )
        {
          v5->RefCount = v9 - 1;
          Scaleform::GFx::AS3::RefCountBaseGC<328>::ReleaseInternal(v5);
        }
      }
      pObject = *p_pObject;
    }
    while ( *p_pObject );
  }
}
