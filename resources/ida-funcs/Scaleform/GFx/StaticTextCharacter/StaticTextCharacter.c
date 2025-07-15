void __thiscall Scaleform::GFx::StaticTextCharacter::StaticTextCharacter(
        Scaleform::GFx::StaticTextCharacter *this,
        Scaleform::GFx::StaticTextDef *pdef,
        Scaleform::GFx::MovieDefImpl *pbindingDefImpl,
        Scaleform::GFx::ASMovieRootBase *pasRoot,
        Scaleform::GFx::InteractiveObject *parent,
        Scaleform::GFx::ResourceId id)
{
  Scaleform::GFx::StaticTextCharacter *v6; // esi
  Scaleform::GFx::StaticTextDef *v7; // edi
  Scaleform::GFx::StaticTextRecord *v8; // edi
  Scaleform::GFx::MovieDefImpl::BindTaskData *pObject; // eax
  Scaleform::GFx::ResourceBinding *p_ResourceBinding; // ecx
  volatile bool Frozen; // dl
  volatile unsigned int BindIndex; // eax
  Scaleform::GFx::ResourceBindData *v13; // esi
  Scaleform::GFx::Resource *v14; // eax
  Scaleform::GFx::Resource *pResource; // esi
  Scaleform::GFx::ImportData *volatile Value; // esi
  int v17; // ebx
  Scaleform::Log *v18; // edi
  Scaleform::StringLH *v19; // eax
  Scaleform::StringLH *v20; // esi
  Scaleform::GFx::Resource *v21; // edi
  unsigned int v22; // ebx
  Scaleform::Render::Text::LineBuffer::Line *inserted; // eax
  Scaleform::Render::Text::LineBuffer::Line *v24; // edi
  Scaleform::GFx::Resource *v25; // esi
  Scaleform::GFx::ResourceKey *(__thiscall *GetKey)(Scaleform::GFx::Resource *, Scaleform::GFx::ResourceKey *); // eax
  double v27; // st7
  double TextHeight; // st6
  double v29; // st7
  double v30; // st6
  double v31; // st6
  bool v32; // c0
  bool v33; // c3
  double v34; // st7
  double v35; // st7
  Scaleform::Render::Text::LineBuffer::FormatDataEntry *FormatData; // eax
  int v37; // esi
  _DWORD *p_ColorV; // ebx
  _WORD *v39; // esi
  int GlyphAdvance; // eax
  Scaleform::GFx::Resource *v41; // ecx
  unsigned int *v42; // ebx
  unsigned int Raw; // eax
  double v44; // st7
  double v45; // st7
  int v46; // eax
  int v47; // ecx
  int OffsetY; // esi
  unsigned int Height; // edx
  int OffsetX; // ecx
  unsigned int Width; // edi
  Scaleform::Log *v52; // esi
  unsigned int v53; // [esp+20h] [ebp-B0h]
  Scaleform::GFx::StaticTextRecord *v54; // [esp+24h] [ebp-ACh]
  float v55; // [esp+28h] [ebp-A8h]
  int v56; // [esp+2Ch] [ebp-A4h]
  float v57; // [esp+30h] [ebp-A0h]
  float v58; // [esp+30h] [ebp-A0h]
  float v59; // [esp+34h] [ebp-9Ch]
  float v60; // [esp+34h] [ebp-9Ch]
  float v61; // [esp+34h] [ebp-9Ch]
  unsigned int v62; // [esp+38h] [ebp-98h]
  unsigned int v63; // [esp+38h] [ebp-98h]
  float v64; // [esp+3Ch] [ebp-94h]
  unsigned int lineIdx; // [esp+40h] [ebp-90h]
  Scaleform::GFx::ResourceBindData pdata; // [esp+48h] [ebp-88h] BYREF
  unsigned int v68; // [esp+50h] [ebp-80h]
  Scaleform::GFx::Resource *v69; // [esp+54h] [ebp-7Ch]
  Scaleform::GFx::Resource *v70; // [esp+58h] [ebp-78h]
  char *v71; // [esp+5Ch] [ebp-74h]
  Scaleform::Render::Rect<float> v72; // [esp+60h] [ebp-70h] BYREF
  Scaleform::Ptr<Scaleform::Log> v73; // [esp+7Ch] [ebp-54h] BYREF
  float x; // [esp+80h] [ebp-50h]
  float y; // [esp+84h] [ebp-4Ch]
  unsigned int Size; // [esp+88h] [ebp-48h]
  Scaleform::Ptr<Scaleform::Log> result; // [esp+8Ch] [ebp-44h] BYREF
  Scaleform::Render::Matrix2x4<float> v78; // [esp+90h] [ebp-40h] BYREF
  unsigned int v79; // [esp+B8h] [ebp-18h]
  unsigned int v80; // [esp+C4h] [ebp-Ch]

  v6 = this;
  Scaleform::GFx::DisplayObject::DisplayObject(this, pasRoot, parent, id);
  v7 = pdef;
  v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountWeakSupportImpl,322>::Scaleform::RefCountWeakSupportImpl::Scaleform::RefCountNTSImpl::Scaleform::RefCountNTSImplCore::__vftable = (Scaleform::GFx::StaticTextCharacter_vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable'{for `Scaleform::RefCountBaseWeakSupport<Scaleform::GFx::DisplayObjectBase,322>'};
  v6->Scaleform::GFx::DisplayObject::Scaleform::GFx::DisplayObjectBase::Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>::__vftable = (Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>_vtbl *)&Scaleform::GFx::StaticTextCharacter::`vftable'{for `Scaleform::GFx::LogBase<Scaleform::GFx::DisplayObjectBase>'};
  if ( pdef )
    Scaleform::RefCountImpl::AddRef(pdef);
  v6->OrigMatrix.M[0][0] = 1.0;
  v6->pDef.pObject = pdef;
  v6->OrigMatrix.M[0][1] = 0.0;
  v6->OrigMatrix.M[0][2] = 0.0;
  v6->OrigMatrix.M[0][3] = 0.0;
  v6->OrigMatrix.M[1][0] = 0.0;
  v6->OrigMatrix.M[1][2] = 0.0;
  v6->OrigMatrix.M[1][3] = 0.0;
  v6->OrigMatrix.M[1][1] = 1.0;
  Scaleform::Render::Text::LineBuffer::LineBuffer(&v6->TextGlyphRecords);
  Scaleform::Render::Text::TextFilter::TextFilter(&v6->Filter);
  v6->pHighlight = 0;
  v6->Flags = 0;
  v78.M[0][0] = pdef->MatrixPriv.M[0][0];
  v78.M[0][1] = pdef->MatrixPriv.M[0][1];
  v78.M[0][2] = pdef->MatrixPriv.M[0][2];
  v78.M[0][3] = pdef->MatrixPriv.M[0][3];
  v78.M[1][0] = pdef->MatrixPriv.M[1][0];
  v78.M[1][1] = pdef->MatrixPriv.M[1][1];
  v78.M[1][2] = pdef->MatrixPriv.M[1][2];
  v78.M[1][3] = pdef->MatrixPriv.M[1][3];
  Scaleform::Render::Matrix2x4<float>::Invert(&v78);
  Scaleform::Render::Matrix2x4<float>::EncloseTransform(&v78, (__m128 *)&v72, (__m128 *)&pdef->TextRect);
  v68 = 0;
  Scaleform::Render::Rect<float>::ExpandToPoint(&v72, 0.0, 0.0);
  lineIdx = 0;
  Size = pdef->TextRecords.Records.Data.Size;
  if ( Size )
  {
    while ( 1 )
    {
      v8 = pdef->TextRecords.Records.Data.Data[lineIdx];
      pObject = pbindingDefImpl->pBindData.pObject;
      pdata.pResource.pObject = 0;
      pdata.pBinding = 0;
      v54 = v8;
      p_ResourceBinding = &pObject->ResourceBinding;
      if ( v8->pFont.HType == RH_Index )
      {
        Frozen = pObject->ResourceBinding.Frozen;
        BindIndex = v8->pFont.BindIndex;
        if ( Frozen && BindIndex < p_ResourceBinding->ResourceCount )
        {
          v13 = &p_ResourceBinding->pResources[BindIndex];
          if ( v13->pResource.pObject )
          {
            Scaleform::RefCountImpl::AddRef(v13->pResource.pObject);
            if ( pdata.pResource.pObject )
              Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
          }
          v14 = v13->pResource.pObject;
          pdata = *v13;
        }
        else
        {
          Scaleform::GFx::ResourceBinding::GetResourceData_Locked(p_ResourceBinding, &pdata, v8->pFont.BindIndex);
          v14 = pdata.pResource.pObject;
        }
      }
      else
      {
        pdata.pBinding = &pObject->ResourceBinding;
        if ( v8->pFont.HType )
        {
          pResource = 0;
        }
        else
        {
          pResource = v8->pFont.pResource;
          if ( pResource )
          {
            Scaleform::RefCountImpl::AddRef(v8->pFont.pResource);
            if ( pdata.pResource.pObject )
              Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
          }
        }
        v14 = pResource;
        pdata.pResource.pObject = pResource;
      }
      v70 = v14;
      if ( !v14 )
        break;
      if ( (pdef->Flags & 2) == 0 )
      {
        Value = pbindingDefImpl->pBindData.pObject->pDataDef.pObject->pData.pObject->BindData.pImports.Value;
        if ( Value )
        {
          do
          {
            v62 = 0;
            if ( Value->Imports.Data.Size )
            {
              v17 = 0;
              do
              {
                if ( Value->Imports.Data.Data[v17].BindIndex == v54->pFont.BindIndex )
                {
                  v18 = Scaleform::GFx::StateBag::GetLog(&pbindingDefImpl->Scaleform::GFx::StateBag, &result)->pObject;
                  if ( result.pObject )
                    Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)result.pObject);
                  if ( v18 )
                    Scaleform::Log::LogWarning(
                      v18,
                      "Static text uses imported font! FontId = %d, import name = %s",
                      v54->FontId,
                      (const char *)((Value->Imports.Data.Data[v17].SymbolName.HeapTypeBits & 0xFFFFFFFC) + 8));
                }
                ++v17;
                ++v62;
              }
              while ( v62 < Value->Imports.Data.Size );
            }
            Value = Value->pNext.Value;
          }
          while ( Value );
          v8 = v54;
        }
      }
      v19 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->Alloc(Scaleform::Memory::pGlobalHeap, 32, 0);
      v20 = v19;
      if ( v19 )
      {
        v21 = (Scaleform::GFx::Resource *)v70[1].__vftable;
        v19->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
        v19[1].HeapTypeBits = 1;
        v19->HeapTypeBits = (unsigned int)&Scaleform::Render::Text::FontHandle::`vftable';
        v19[2].HeapTypeBits = 0;
        v19[3].HeapTypeBits = 0;
        Scaleform::StringLH::StringLH(v19 + 4);
        *(float *)&v20[5].pData = 1.0;
        if ( v21 )
          Scaleform::RefCountImpl::AddRef(v21);
        v20[6].HeapTypeBits = (unsigned int)v21;
        v8 = v54;
        v20->HeapTypeBits = (unsigned int)&Scaleform::GFx::FontHandle::`vftable';
        v20[7].HeapTypeBits = 0;
        v69 = (Scaleform::GFx::Resource *)v20;
      }
      else
      {
        v69 = 0;
      }
      v22 = v8->Glyphs.Data.Size;
      v63 = v22;
      if ( v22 > 0xFF || ((int)v70[1].__vftable[1].GetKey & 0x2000) != 0 )
        inserted = Scaleform::Render::Text::LineBuffer::InsertNewLine(
                     &this->TextGlyphRecords,
                     lineIdx,
                     v22,
                     2u,
                     (Scaleform::Render::Text::LineBuffer::Line *)1);
      else
        inserted = Scaleform::Render::Text::LineBuffer::InsertNewLine(&this->TextGlyphRecords, lineIdx, v22, 2u, 0);
      v24 = inserted;
      if ( (inserted->MemSize & 0x80000000) == 0 )
        inserted->Data32.TextPos = v68;
      else
        inserted->Data32.TextPos ^= (v68 ^ inserted->Data32.TextPos) & 0xFFFFFF;
      v25 = v70;
      GetKey = v70[1].__vftable[1].GetKey;
      v57 = v54->Offset.x;
      v68 += v22;
      v59 = v54->Offset.y;
      if ( ((unsigned __int16)GetKey & 0x2000) != 0 )
      {
        v27 = v54->TextHeight * 0.0009765625;
        v60 = v59 - v54->TextHeight;
        v58 = v57 - v72.x1;
        v61 = v60 - v72.y1;
        TextHeight = v54->TextHeight;
        if ( (v24->MemSize & 0x80000000) == 0 )
          v24->Data32.BaseLineOffset = (int)TextHeight;
        else
          v24->Data8.BaseLineOffset = (int)TextHeight;
        v55 = v27 * *(float *)&v25[1].GetResourceReport + v54->TextHeight;
        v29 = 0.0;
      }
      else
      {
        v58 = v57 - v72.x1;
        v61 = v59 - v72.y1;
        v29 = 0.0;
        v55 = 0.0;
      }
      v30 = v61;
      if ( v61 <= v29 )
        v31 = v30 - 0.5;
      else
        v31 = v30 + 0.5;
      v32 = v58 < v29;
      v33 = v58 == v29;
      v34 = v58;
      if ( v32 || v33 )
        v35 = v34 - 0.5;
      else
        v35 = v34 + 0.5;
      v24->Data32.OffsetX = (int)v35;
      v24->Data32.OffsetY = (int)v31;
      if ( (v24->MemSize & 0x80000000) == 0 )
      {
        v24->Data32.Width = 0;
        v24->Data32.Height = 0;
      }
      else
      {
        v24->Data8.Width = 0;
        v24->Data8.Height = 0;
      }
      if ( (v24->MemSize & 0x80000000) == 0 )
        v71 = (char *)&v24->Data8 + 38;
      else
        v71 = &v24->Data8.Leading + 1;
      FormatData = Scaleform::Render::Text::LineBuffer::Line::GetFormatData(v24);
      v37 = 0;
      v80 = 0;
      v56 = 0;
      v53 = 0;
      if ( v22 )
      {
        p_ColorV = &FormatData->ColorV;
        v39 = v71 + 6;
        do
        {
          *v39 = 0;
          *(v39 - 1) = 4096;
          *(v39 - 3) = v54->Glyphs.Data.Data[v53].GlyphIndex;
          GlyphAdvance = (int)v54->Glyphs.Data.Data[v53].GlyphAdvance;
          if ( GlyphAdvance < 0 )
          {
            *(v39 - 2) = -(__int16)GlyphAdvance;
            *v39 = 64;
          }
          else
          {
            *(v39 - 2) = GlyphAdvance;
            *v39 = 0;
          }
          v56 += (int)v54->Glyphs.Data.Data[v53].GlyphAdvance;
          v64 = v54->TextHeight * 0.05000000074505806;
          Scaleform::Render::Text::LineBuffer::GlyphEntry::SetFontSize(
            (Scaleform::Render::Text::LineBuffer::GlyphEntry *)(v39 - 3),
            v64);
          if ( !v53 )
          {
            v41 = v69;
            *v39 |= 0x4000u;
            *v39 |= 0x2000u;
            *p_ColorV = v41;
            v42 = p_ColorV + 1;
            Scaleform::RefCountImpl::AddRef(v41);
            Raw = v54->ColorV.Raw;
            *v39 |= 0x4000u;
            *v39 |= 0x1000u;
            *v42 = Raw;
            v79 = Raw;
            p_ColorV = v42 + 1;
          }
          ++v53;
          if ( v71 && v80 < v63 )
          {
            ++v80;
            v39 += 4;
          }
        }
        while ( v53 < v63 );
        v37 = v56;
        v22 = v63;
      }
      if ( ((int)v70[1].__vftable[1].GetKey & 0x2000) != 0 )
      {
        v44 = v55;
        if ( v55 <= 0.0 )
          v45 = v44 - 0.5;
        else
          v45 = v44 + 0.5;
        v46 = (int)v45;
        v47 = v37 < 0 ? 0 : v37;
        if ( (v24->MemSize & 0x80000000) == 0 )
        {
          v24->Data32.Width = v47;
          v24->Data32.Height = v46;
        }
        else
        {
          v24->Data8.Width = v47;
          v24->Data8.Height = v46;
        }
        if ( (v24->MemSize & 0x80000000) == 0 )
          v24->Data32.TextLength = v22;
        else
          HIBYTE(v24->Data8.TextPosAndLength) = v22;
        OffsetY = v24->Data32.OffsetY;
        if ( (v24->MemSize & 0x80000000) == 0 )
          Height = v24->Data32.Height;
        else
          Height = v24->Data8.Height;
        OffsetX = v24->Data32.OffsetX;
        if ( (v24->MemSize & 0x80000000) == 0 )
          Width = v24->Data32.Width;
        else
          Width = v24->Data8.Width;
        x = (float)(int)(OffsetX + Width);
        y = (float)(int)(OffsetY + Height);
        Scaleform::Render::Rect<float>::ExpandToPoint(&v72, x, y);
      }
      if ( v69 )
        Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v69);
      if ( pdata.pResource.pObject )
        Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
      if ( ++lineIdx >= Size )
      {
        v7 = pdef;
        v6 = this;
        goto LABEL_96;
      }
    }
    v52 = Scaleform::GFx::StateBag::GetLog(&pbindingDefImpl->Scaleform::GFx::StateBag, &v73)->pObject;
    if ( v73.pObject )
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v73.pObject);
    if ( v52 )
      Scaleform::Log::LogError(v52, "Text style with undefined font; FontId = %d", v8->FontId);
    if ( pdata.pResource.pObject )
      Scaleform::GFx::Resource::Release(pdata.pResource.pObject);
  }
  else
  {
LABEL_96:
    v6->TextGlyphRecords.Geom.VisibleRect = v72;
    v6->TextGlyphRecords.Geom.Flags |= 4u;
    Scaleform::Render::Text::TextFilter::SetDefaultShadow(&v6->Filter);
    v7->Flags |= 2u;
    Scaleform::GFx::StaticTextCharacter::RecreateVisibleTextLayout(v6);
  }
}
