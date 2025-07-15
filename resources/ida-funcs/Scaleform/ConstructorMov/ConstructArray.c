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


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Text::HighlightDesc>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // edx
  char *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 28;
    do
    {
      if ( v3 != (char *)28 )
      {
        *((_DWORD *)v3 - 7) = -1;
        *((_DWORD *)v3 - 6) = 0;
        *((_DWORD *)v3 - 5) = -1;
        *((_DWORD *)v3 - 4) = 0;
        *((_DWORD *)v3 - 3) = 0;
        *((_DWORD *)v3 - 2) = 0;
        *((_DWORD *)v3 + 1) = 0;
        *(_DWORD *)v3 = 0;
        *((_DWORD *)v3 - 1) = 0;
        v3[8] = 0;
      }
      v3 += 40;
      --v2;
    }
    while ( v2 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::MaskStackEntry>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int i; // edi

  for ( i = count; i; --i )
  {
    Scaleform::ConstructorMov<Scaleform::Render::HAL::MaskStackEntry>::Construct(p);
    p += 24;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::HAL::RenderTargetEntry>::ConstructArray(
        Scaleform::Render::HAL::RenderTargetEntry *p,
        unsigned int count)
{
  unsigned int i; // edi

  for ( i = count; i; --i )
  {
    if ( p )
      Scaleform::Render::HAL::RenderTargetEntry::RenderTargetEntry(p);
    ++p;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::TextureGlyph>::ConstructArray(char *p, unsigned int count)
{
  unsigned int v2; // ecx
  char *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 24;
    do
    {
      if ( v3 != (char *)24 )
      {
        *((_DWORD *)v3 - 6) = &Scaleform::RefCountImplCore::`vftable';
        *((_DWORD *)v3 - 5) = 1;
        *((_DWORD *)v3 - 6) = &Scaleform::Render::TextureGlyph::`vftable';
        *((float *)v3 - 2) = 0.0;
        *((float *)v3 - 1) = 0.0;
        *((_DWORD *)v3 - 4) = 0;
        *(float *)v3 = 0.0;
        *((float *)v3 + 1) = 0.0;
        *((_DWORD *)v3 + 4) = -1;
      }
      v3 += 48;
      --v2;
    }
    while ( v2 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::Text::CSSToken<wchar_t>>::ConstructArray(
        _DWORD *p,
        unsigned int count)
{
  unsigned int i; // ecx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      *p = 11;
      p[1] = 0;
      p[2] = 0;
    }
    p += 3;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::ArraySortFunctor>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // ecx
  char *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 12;
    do
    {
      if ( v3 != (char *)12 )
      {
        v3[4] = 0;
        *((_DWORD *)v3 - 1) = 0;
        *(_DWORD *)v3 = 0;
      }
      v3 += 28;
      --v2;
    }
    while ( v2 );
  }
}


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


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::ASString>::ConstructArray(
        Scaleform::GFx::ASString *p,
        unsigned int count,
        const Scaleform::GFx::ASString *psource)
{
  unsigned int v5; // esi
  Scaleform::GFx::ASStringNode *pNode; // eax

  if ( count )
  {
    v5 = count;
    do
    {
      if ( p )
      {
        pNode = psource->pNode;
        p->pNode = psource->pNode;
        ++pNode->RefCount;
      }
      ++psource;
      ++p;
      --v5;
    }
    while ( v5 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::ButtonRecord>::ConstructArray(char *p, unsigned int count)
{
  unsigned int v2; // edi
  double v3; // st7
  double v4; // st6
  char *v5; // esi

  v2 = count;
  if ( count )
  {
    v3 = 1.0;
    v4 = 0.0;
    v5 = p + 8;
    do
    {
      if ( v5 != (char *)8 )
      {
        *((float *)v5 - 2) = v3;
        *((float *)v5 + 3) = v3;
        *((float *)v5 - 1) = v4;
        *(float *)v5 = v4;
        *((float *)v5 + 1) = v4;
        *((float *)v5 + 2) = v4;
        *((float *)v5 + 4) = v4;
        *((float *)v5 + 5) = v4;
        Scaleform::Render::Cxform::Cxform((Scaleform::Render::Cxform *)(v5 + 24));
        v3 = 1.0;
        *((_DWORD *)v5 + 14) = 0;
        v4 = 0.0;
        *((_DWORD *)v5 + 15) = 0x40000;
        v5[72] = 0;
      }
      v5 += 96;
      --v2;
    }
    while ( v2 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::DisplayList::DisplayEntry>::ConstructArray(
        _DWORD *p,
        unsigned int count)
{
  unsigned int i; // ecx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      *p = 0;
      p[2] = -1;
      p[1] = -1;
    }
    p += 3;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Waitable::HandlerStruct>::ConstructArray(
        void (__cdecl **p)(void *),
        unsigned int count,
        const Scaleform::Waitable::HandlerStruct *psource)
{
  unsigned int i; // edx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      *p = psource->Handler;
      p[1] = (void (__cdecl *)(void *))psource->pUserData;
    }
    ++psource;
    p += 2;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS3::Abc::NamespaceInfo>::ConstructArray(
        _DWORD *p,
        unsigned int count)
{
  unsigned int i; // ecx

  for ( i = count; i; --i )
  {
    if ( p )
    {
      *p = -1;
      p[1] = 0;
      p[2] = 0;
    }
    p += 3;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::String>::ConstructArray(
        Scaleform::String *p,
        unsigned int count,
        const Scaleform::String *psource)
{
  unsigned int i; // ebx

  for ( i = count; i; --i )
  {
    if ( p )
      Scaleform::String::String(p, psource);
    ++psource;
    ++p;
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::GFx::AS2::Value>::ConstructArray(
        Scaleform::GFx::AS2::Value *p,
        unsigned int count,
        const Scaleform::GFx::AS2::Value *psource)
{
  unsigned int i; // ebx

  for ( i = count; i; --i )
  {
    if ( p )
      Scaleform::GFx::AS2::Value::Value(p, psource);
    ++psource;
    ++p;
  }
}


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


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Matrix2x4<float>>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // ecx
  float *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = (float *)(p + 8);
    do
    {
      if ( v3 != (float *)8 )
      {
        *(v3 - 2) = 1.0;
        v3[3] = 1.0;
        *(v3 - 1) = 0.0;
        *v3 = 0.0;
        v3[1] = 0.0;
        v3[2] = 0.0;
        v3[4] = 0.0;
        v3[5] = 0.0;
      }
      v3 += 8;
      --v2;
    }
    while ( v2 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Matrix3x4<float>>::ConstructArray(
        float *p,
        unsigned int count)
{
  unsigned int v3; // edi

  if ( count )
  {
    v3 = count;
    do
    {
      if ( p )
      {
        memset((int)p, 0, 48);
        *p = 1.0;
        p[5] = 1.0;
        p[10] = 1.0;
      }
      p += 12;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Render::Matrix4x4<float>>::ConstructArray(
        float *p,
        unsigned int count)
{
  unsigned int v3; // edi

  if ( count )
  {
    v3 = count;
    do
    {
      if ( p )
      {
        memset((int)p, 0, 64);
        *p = 1.0;
        p[5] = 1.0;
        p[10] = 1.0;
        p[15] = 1.0;
      }
      p += 16;
      --v3;
    }
    while ( v3 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem>>::ConstructArray(
        Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *p,
        unsigned int count,
        const Scaleform::Ptr<Scaleform::GFx::AMP::FuncTreeItem> *psource)
{
  unsigned int v5; // ebx

  if ( count )
  {
    v5 = count;
    do
    {
      if ( p )
      {
        if ( psource->pObject )
          Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)psource->pObject);
        p->pObject = psource->pObject;
      }
      ++psource;
      ++p;
      --v5;
    }
    while ( v5 );
  }
}


void __cdecl Scaleform::ConstructorMov<Scaleform::RangeData<Scaleform::GFx::TextField::CSSHolderBase::UrlZone>>::ConstructArray(
        char *p,
        unsigned int count)
{
  unsigned int v2; // ecx
  char *v3; // eax

  v2 = count;
  if ( count )
  {
    v3 = p + 16;
    do
    {
      if ( v3 != (char *)16 )
      {
        *((_DWORD *)v3 - 4) = 0;
        *((_DWORD *)v3 - 3) = 0;
        *((_DWORD *)v3 - 2) = 0;
        *((_DWORD *)v3 - 1) = 0;
        *(_DWORD *)v3 = 0;
      }
      v3 += 20;
      --v2;
    }
    while ( v2 );
  }
}
