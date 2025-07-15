char __thiscall Scaleform::GFx::ConstShapeWithStyles::Read(
        Scaleform::GFx::ConstShapeWithStyles *this,
        __int64 p,
        unsigned int lenInBytes,
        bool withStyle)
{
  Scaleform::Render::StrokeStyleType *v5; // edi
  unsigned int Size; // edi
  unsigned int v8; // esi
  unsigned __int8 *v9; // eax
  unsigned int v10; // edi
  unsigned __int8 *v11; // ebp
  Scaleform::GFx::Resource **p_pFill; // esi
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v13; // edi
  char *v14; // eax
  float *v15; // esi
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::Render::StrokeStyleType *Data; // edx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v18; // ebx
  Scaleform::RefCountVImpl *v19; // ecx
  Scaleform::RefCountVImpl **v20; // esi
  unsigned int v21; // ebx
  Scaleform::GFx::ShapeSwfReader v22; // [esp+10h] [ebp-20h] BYREF
  unsigned int v23; // [esp+34h] [ebp+4h]
  char *v24; // [esp+40h] [ebp+10h]

  v22.pAllocator = *(Scaleform::GFx::PathAllocator **)(*(_DWORD *)(p + 32) + 24);
  v22.Shape = this;
  memset(&v22.FillStyles, 0, 24);
  if ( Scaleform::GFx::ShapeSwfReader::Read(&v22, p, lenInBytes, withStyle) )
  {
    Size = v22.FillStyles.Data.Size;
    v8 = v22.StrokeStyles.Data.Size;
    this->FillStylesNum = v22.FillStyles.Data.Size;
    this->StrokeStylesNum = v8;
    if ( Size || v8 )
    {
      v9 = (unsigned __int8 *)(*(int (__thiscall **)(_DWORD, unsigned int, _DWORD))(**(_DWORD **)(*(_DWORD *)(p + 32)
                                                                                                + 28)
                                                                                  + 40))(
                                *(_DWORD *)(*(_DWORD *)(p + 32) + 28),
                                8 * Size + 28 * v8,
                                0);
      v10 = 0;
      this->Styles = v9;
      v11 = v9;
      if ( this->FillStylesNum )
      {
        p_pFill = (Scaleform::GFx::Resource **)&v22.FillStyles.Data.Data->pFill;
        do
        {
          if ( v11 )
          {
            *(_DWORD *)v11 = *(p_pFill - 1);
            if ( *p_pFill )
              Scaleform::RefCountImpl::AddRef(*p_pFill);
            *((_DWORD *)v11 + 1) = *p_pFill;
          }
          ++v10;
          v11 += 8;
          p_pFill += 2;
        }
        while ( v10 < this->FillStylesNum );
        v8 = v22.StrokeStyles.Data.Size;
      }
      v23 = 0;
      if ( this->StrokeStylesNum )
      {
        v13 = &v22.StrokeStyles.Data.Data->pFill;
        v14 = (char *)((char *)v22.StrokeStyles.Data.Data - (char *)v11);
        v15 = (float *)(v11 + 4);
        v24 = (char *)((char *)v22.StrokeStyles.Data.Data - (char *)v11);
        do
        {
          if ( v15 != (float *)4 )
          {
            *(v15 - 1) = *(float *)&v13[-5].pObject;
            *v15 = *(float *)((char *)v15 + (_DWORD)v14);
            v15[1] = *(float *)&v13[-3].pObject;
            v15[2] = *(float *)&v13[-2].pObject;
            v15[3] = *(float *)&v13[-1].pObject;
            if ( v13->pObject )
              Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v13->pObject);
            v15[4] = *(float *)&v13->pObject;
            pObject = (Scaleform::GFx::Resource *)v13[1].pObject;
            if ( pObject )
              Scaleform::RefCountImpl::AddRef(pObject);
            v14 = v24;
            v15[5] = *(float *)&v13[1].pObject;
          }
          v13 += 7;
          v15 += 7;
          ++v23;
        }
        while ( v23 < this->StrokeStylesNum );
        v8 = v22.StrokeStyles.Data.Size;
      }
      Size = v22.FillStyles.Data.Size;
    }
    else
    {
      this->Styles = 0;
    }
    Data = v22.StrokeStyles.Data.Data;
    if ( v8 )
    {
      v18 = &v22.StrokeStyles.Data.Data[v8 - 1].pFill;
      do
      {
        v19 = (Scaleform::RefCountVImpl *)v18[1].pObject;
        if ( v19 )
          Scaleform::RefCountImpl::Release(v19);
        if ( v18->pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v18->pObject);
        v18 -= 7;
        --v8;
      }
      while ( v8 );
      Data = v22.StrokeStyles.Data.Data;
    }
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    if ( Size )
    {
      v20 = (Scaleform::RefCountVImpl **)&v22.FillStyles.Data.Data[Size - 1].pFill;
      v21 = Size;
      do
      {
        if ( *v20 )
          Scaleform::RefCountImpl::Release(*v20);
        v20 -= 2;
        --v21;
      }
      while ( v21 );
    }
    if ( v22.FillStyles.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v22.FillStyles.Data.Data);
    return 1;
  }
  else
  {
    v5 = v22.StrokeStyles.Data.Data;
    Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
      v22.StrokeStyles.Data.Data,
      v22.StrokeStyles.Data.Size);
    if ( v5 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v5);
    Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>(&v22.FillStyles.Data);
    return 0;
  }
}
