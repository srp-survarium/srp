void __thiscall Scaleform::Render::ShapeMeshProvider::countComplexFills(
        Scaleform::Render::ShapeMeshProvider *this,
        const Scaleform::ArrayStaticBuffPOD<Scaleform::Render::ShapeMeshProvider::TmpPathInfoType,32,2> *paths,
        unsigned int i1,
        unsigned int i2,
        Scaleform::Render::ShapeMeshProvider::DrawLayerType *dl)
{
  unsigned int Size; // edx
  unsigned int v7; // ebx
  unsigned int v8; // ecx
  Scaleform::Render::ShapeMeshProvider::TmpPathInfoType *Data; // eax
  unsigned int v10; // edi
  unsigned int v11; // esi
  unsigned int v12; // edi
  unsigned int *v13; // edx
  unsigned int v14; // edi
  unsigned int v15; // esi
  unsigned int v16; // edi
  unsigned int *v17; // edx
  bool v18; // zf
  Scaleform::Render::FillStyleType fill; // [esp+Ch] [ebp-18h] BYREF
  Scaleform::Render::BitSet fills; // [esp+14h] [ebp-10h] BYREF
  unsigned int i1a; // [esp+2Ch] [ebp+8h]
  unsigned int i2a; // [esp+30h] [ebp+Ch]

  Size = this->FillToStyleTable.Data.Size;
  fills.pData = &fills.Local;
  fills.pHeap = Scaleform::Memory::pGlobalHeap;
  dl->StartFill = Size;
  dl->FillCount = 0;
  fills.Size = 32;
  fills.Local = 0;
  if ( i1 < i2 )
  {
    v7 = 24 * i1;
    v8 = i2 - i1;
    i1a = 24 * i1;
    i2a = v8;
    do
    {
      if ( *(unsigned int *)((char *)paths->Data->Styles + v7) != *(unsigned int *)((char *)&paths->Data->Styles[1] + v7) )
      {
        Data = paths->Data;
        fill.pFill.pObject = 0;
        v10 = *(unsigned int *)((char *)Data->Styles + v7);
        if ( v10 )
        {
          this->pShapeData.pObject->GetFillStyle(this->pShapeData.pObject, v10, &fill);
          v11 = fill.pFill.pObject != 0 ? v10 : 0;
          if ( v11 >= fills.Size || (fills.pData[v11 >> 5] & (1 << (v11 & 0x1F))) == 0 )
          {
            v12 = this->FillToStyleTable.Data.Size + 1;
            if ( v12 >= this->FillToStyleTable.Data.Size )
            {
              if ( v12 >= this->FillToStyleTable.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FillToStyleTable,
                  &this->FillToStyleTable,
                  v12 + (v12 >> 2));
            }
            else if ( v12 < this->FillToStyleTable.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FillToStyleTable,
                &this->FillToStyleTable,
                this->FillToStyleTable.Data.Size + 1);
            }
            v13 = this->FillToStyleTable.Data.Data;
            this->FillToStyleTable.Data.Size = v12;
            v13[v12 - 1] = v11;
            ++dl->FillCount;
            if ( v11 >= fills.Size )
              Scaleform::Render::BitSet::resize(&fills, v11 + 1);
            v7 = i1a;
            fills.pData[v11 >> 5] |= 1 << (v11 & 0x1F);
          }
        }
        v14 = *(unsigned int *)((char *)&paths->Data->Styles[1] + v7);
        if ( v14 )
        {
          this->pShapeData.pObject->GetFillStyle(this->pShapeData.pObject, v14, &fill);
          v15 = fill.pFill.pObject != 0 ? v14 : 0;
          if ( v15 >= fills.Size || (fills.pData[v15 >> 5] & (1 << (v15 & 0x1F))) == 0 )
          {
            v16 = this->FillToStyleTable.Data.Size + 1;
            if ( v16 >= this->FillToStyleTable.Data.Size )
            {
              if ( v16 >= this->FillToStyleTable.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FillToStyleTable,
                  &this->FillToStyleTable,
                  v16 + (v16 >> 2));
            }
            else if ( v16 < this->FillToStyleTable.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&this->FillToStyleTable,
                &this->FillToStyleTable,
                this->FillToStyleTable.Data.Size + 1);
            }
            v17 = this->FillToStyleTable.Data.Data;
            this->FillToStyleTable.Data.Size = v16;
            v17[v16 - 1] = v15;
            ++dl->FillCount;
            if ( v15 >= fills.Size )
              Scaleform::Render::BitSet::resize(&fills, v15 + 1);
            v7 = i1a;
            fills.pData[v15 >> 5] |= 1 << (v15 & 0x1F);
          }
        }
        if ( fill.pFill.pObject )
          Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)fill.pFill.pObject);
      }
      v7 += 24;
      v18 = i2a-- == 1;
      i1a = v7;
    }
    while ( !v18 );
    if ( fills.pData != &fills.Local )
      fills.pHeap->Free(fills.pHeap, fills.pData);
  }
}
