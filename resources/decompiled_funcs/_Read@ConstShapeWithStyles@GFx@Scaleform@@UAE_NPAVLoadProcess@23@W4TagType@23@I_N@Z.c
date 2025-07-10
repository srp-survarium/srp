char __thiscall Scaleform::GFx::ConstShapeWithStyles::Read(
        Scaleform::GFx::ConstShapeWithStyles *this,
        Scaleform::GFx::LoadProcess *p,
        Scaleform::Render::FillStyleType *tagType,
        unsigned int lenInBytes,
        bool withStyle)
{
  Scaleform::Render::StrokeStyleType *v6; // edi
  unsigned int Size; // edi
  unsigned int v9; // esi
  unsigned __int8 *v10; // eax
  unsigned int v11; // edi
  unsigned __int8 *v12; // ebp
  Scaleform::GFx::Resource **p_pFill; // esi
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v14; // edi
  char *v15; // eax
  float *v16; // esi
  Scaleform::GFx::Resource *pObject; // ecx
  Scaleform::Render::StrokeStyleType *Data; // edx
  Scaleform::Ptr<Scaleform::Render::ComplexFill> *v19; // ebx
  Scaleform::RefCountVImpl *v20; // ecx
  Scaleform::RefCountVImpl **v21; // esi
  unsigned int v22; // ebx
  Scaleform::GFx::ShapeSwfReader reader; // [esp+10h] [ebp-20h] BYREF
  unsigned int i; // [esp+34h] [ebp+4h]
  char *withStylea; // [esp+40h] [ebp+10h]

  reader.pAllocator = p->pLoadData.pObject->pPathAllocator;
  reader.Shape = this;
  memset(&reader.FillStyles, 0, 24);
  if ( Scaleform::GFx::ShapeSwfReader::Read(&reader, p, tagType, lenInBytes, withStyle) )
  {
    Size = reader.FillStyles.Data.Size;
    v9 = reader.StrokeStyles.Data.Size;
    this->FillStylesNum = reader.FillStyles.Data.Size;
    this->StrokeStylesNum = v9;
    if ( Size || v9 )
    {
      v10 = (unsigned __int8 *)p->pLoadData.pObject->pHeap->Alloc(p->pLoadData.pObject->pHeap, 8 * Size + 28 * v9, 0);
      v11 = 0;
      this->Styles = v10;
      v12 = v10;
      if ( this->FillStylesNum )
      {
        p_pFill = (Scaleform::GFx::Resource **)&reader.FillStyles.Data.Data->pFill;
        do
        {
          if ( v12 )
          {
            *(_DWORD *)v12 = *(p_pFill - 1);
            if ( *p_pFill )
              Scaleform::RefCountImpl::AddRef(*p_pFill);
            *((_DWORD *)v12 + 1) = *p_pFill;
          }
          ++v11;
          v12 += 8;
          p_pFill += 2;
        }
        while ( v11 < this->FillStylesNum );
        v9 = reader.StrokeStyles.Data.Size;
      }
      i = 0;
      if ( this->StrokeStylesNum )
      {
        v14 = &reader.StrokeStyles.Data.Data->pFill;
        v15 = (char *)((char *)reader.StrokeStyles.Data.Data - (char *)v12);
        v16 = (float *)(v12 + 4);
        withStylea = (char *)((char *)reader.StrokeStyles.Data.Data - (char *)v12);
        do
        {
          if ( v16 != (float *)4 )
          {
            *(v16 - 1) = *(float *)&v14[-5].pObject;
            *v16 = *(float *)((char *)v16 + (_DWORD)v15);
            v16[1] = *(float *)&v14[-3].pObject;
            v16[2] = *(float *)&v14[-2].pObject;
            v16[3] = *(float *)&v14[-1].pObject;
            if ( v14->pObject )
              Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v14->pObject);
            v16[4] = *(float *)&v14->pObject;
            pObject = (Scaleform::GFx::Resource *)v14[1].pObject;
            if ( pObject )
              Scaleform::RefCountImpl::AddRef(pObject);
            v15 = withStylea;
            v16[5] = *(float *)&v14[1].pObject;
          }
          v14 += 7;
          v16 += 7;
          ++i;
        }
        while ( i < this->StrokeStylesNum );
        v9 = reader.StrokeStyles.Data.Size;
      }
      Size = reader.FillStyles.Data.Size;
    }
    else
    {
      this->Styles = 0;
    }
    Data = reader.StrokeStyles.Data.Data;
    if ( v9 )
    {
      v19 = &reader.StrokeStyles.Data.Data[v9 - 1].pFill;
      do
      {
        v20 = (Scaleform::RefCountVImpl *)v19[1].pObject;
        if ( v20 )
          Scaleform::RefCountImpl::Release(v20);
        if ( v19->pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v19->pObject);
        v19 -= 7;
        --v9;
      }
      while ( v9 );
      Data = reader.StrokeStyles.Data.Data;
    }
    if ( Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, Data);
    if ( Size )
    {
      v21 = (Scaleform::RefCountVImpl **)&reader.FillStyles.Data.Data[Size - 1].pFill;
      v22 = Size;
      do
      {
        if ( *v21 )
          Scaleform::RefCountImpl::Release(*v21);
        v21 -= 2;
        --v22;
      }
      while ( v22 );
    }
    if ( reader.FillStyles.Data.Data )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, reader.FillStyles.Data.Data);
    return 1;
  }
  else
  {
    v6 = reader.StrokeStyles.Data.Data;
    Scaleform::ConstructorMov<Scaleform::Render::StrokeStyleType>::DestructArray(
      reader.StrokeStyles.Data.Data,
      reader.StrokeStyles.Data.Size);
    if ( v6 )
      Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, v6);
    Scaleform::ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::Render::FillStyleType,Scaleform::AllocatorGH<Scaleform::Render::FillStyleType,259>,Scaleform::ArrayDefaultPolicy>(&reader.FillStyles.Data);
    return 0;
  }
}
