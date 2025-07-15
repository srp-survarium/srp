void __thiscall Scaleform::GFx::ConstShapeWithStyles::SetStyles(
        Scaleform::GFx::ConstShapeWithStyles *this,
        unsigned int fillStyleCount,
        const Scaleform::Render::FillStyleType *fillStyles,
        unsigned int strokeStyleCount,
        const Scaleform::Render::StrokeStyleType *strokeStyles)
{
  unsigned __int8 *Styles; // eax
  unsigned int v7; // ecx
  unsigned int v8; // eax
  unsigned __int8 *v9; // eax
  unsigned __int8 *v10; // ebx
  Scaleform::GFx::Resource **p_pFill; // edi
  Scaleform::Render::ComplexFill *v12; // eax
  int v13; // eax
  int v14; // esi
  Scaleform::RefCountVImpl *v15; // ecx
  bool v16; // zf
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v17; // edi
  const Scaleform::Render::FillStyleType *v18; // eax
  unsigned __int8 *v19; // esi
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::Render::ComplexFill *v21; // eax
  unsigned int v22; // eax
  Scaleform::RefCountVImpl *v23; // ecx

  Styles = this->Styles;
  if ( Styles )
    Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Styles);
  v7 = fillStyleCount;
  v8 = strokeStyleCount;
  this->FillStylesNum = fillStyleCount;
  this->StrokeStylesNum = v8;
  if ( v7 || v8 )
  {
    v9 = (unsigned __int8 *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                              Scaleform::Memory::pGlobalHeap,
                              this,
                              28 * v8 + 8 * v7,
                              0);
    this->Styles = v9;
    v10 = v9;
    fillStyleCount = 0;
    if ( this->FillStylesNum )
    {
      p_pFill = (Scaleform::GFx::Resource **)&fillStyles->pFill;
      do
      {
        if ( v10 )
        {
          *(_DWORD *)v10 = *(p_pFill - 1);
          if ( *p_pFill )
            Scaleform::RefCountImpl::AddRef(*p_pFill);
          *((_DWORD *)v10 + 1) = *p_pFill;
        }
        if ( *((_DWORD *)v10 + 1) )
        {
          strokeStyleCount = 2;
          v12 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    64,
                                                    &strokeStyleCount);
          if ( v12 )
          {
            Scaleform::Render::ComplexFill::ComplexFill(v12, *((const Scaleform::Render::ComplexFill **)v10 + 1));
            v14 = v13;
          }
          else
          {
            v14 = 0;
          }
          v15 = (Scaleform::RefCountVImpl *)*((_DWORD *)v10 + 1);
          if ( v15 )
            Scaleform::RefCountImpl::Release(v15);
          *((_DWORD *)v10 + 1) = v14;
        }
        v10 += 8;
        p_pFill += 2;
        ++fillStyleCount;
      }
      while ( fillStyleCount < this->FillStylesNum );
    }
    v16 = this->StrokeStylesNum == 0;
    strokeStyleCount = 0;
    if ( !v16 )
    {
      v17 = &strokeStyles->pFill;
      v18 = (const Scaleform::Render::FillStyleType *)((char *)strokeStyles - (char *)v10);
      v19 = v10 + 4;
      for ( fillStyles = (const Scaleform::Render::FillStyleType *)((char *)strokeStyles - (char *)v10); ; v18 = fillStyles )
      {
        if ( v19 != (unsigned __int8 *)4 )
        {
          *((float *)v19 - 1) = *(float *)&v17[-5].pObject;
          *(float *)v19 = *(float *)&v19[(_DWORD)v18];
          *((Scaleform::Ptr<Scaleform::Render::ComplexFill> *)v19 + 1) = v17[-3];
          *((float *)v19 + 2) = *(float *)&v17[-2].pObject;
          *((Scaleform::Ptr<Scaleform::Render::ComplexFill> *)v19 + 3) = v17[-1];
          if ( v17->pObject )
            Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v17->pObject);
          *((Scaleform::Ptr<Scaleform::Render::ComplexFill> *)v19 + 4) = (Scaleform::Ptr<Scaleform::Render::ComplexFill>)v17->pObject;
          pObject = (Scaleform::GFx::Resource *)v17[1].pObject;
          if ( pObject )
            Scaleform::RefCountImpl::AddRef(pObject);
          *((Scaleform::Ptr<Scaleform::Render::ComplexFill> *)v19 + 5) = v17[1];
        }
        if ( *((_DWORD *)v10 + 5) )
        {
          fillStyleCount = 2;
          v21 = (Scaleform::Render::ComplexFill *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                    Scaleform::Memory::pGlobalHeap,
                                                    this,
                                                    64,
                                                    &fillStyleCount);
          if ( v21 )
          {
            Scaleform::Render::ComplexFill::ComplexFill(v21, *((const Scaleform::Render::ComplexFill **)v10 + 5));
            fillStyleCount = v22;
          }
          else
          {
            fillStyleCount = 0;
          }
          v23 = (Scaleform::RefCountVImpl *)*((_DWORD *)v10 + 5);
          if ( v23 )
            Scaleform::RefCountImpl::Release(v23);
          *((_DWORD *)v10 + 5) = fillStyleCount;
        }
        v17 += 7;
        v19 += 28;
        if ( ++strokeStyleCount >= this->StrokeStylesNum )
          break;
      }
    }
  }
  else
  {
    this->Styles = 0;
  }
}
