void __thiscall Scaleform::Render::DICommand_FloodFill::ExecuteSW(
        Scaleform::Render::DICommand_FloodFill *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::ImagePlane *pPlanes; // eax
  int Width; // edx
  int Height; // eax
  int x; // ecx
  int y; // ecx
  Scaleform::Render::TextureManager *v11; // eax
  Scaleform::Render::TextureManager *v12; // eax
  int v13; // eax
  unsigned int Size; // esi
  int v15; // ebx
  signed int v16; // ebp
  unsigned int v17; // edi
  int x2; // eax
  int v19; // edx
  int y2; // ecx
  unsigned int Raw; // ebx
  int v22; // ebx
  unsigned int v23; // esi
  int v24; // ebx
  Scaleform::Render::Point<long> *v25; // eax
  unsigned int v26; // edi
  Scaleform::Render::Point<long> *v27; // eax
  unsigned int v28; // esi
  Scaleform::Render::Point<long> *v29; // eax
  unsigned int v30; // edi
  Scaleform::Render::Point<long> *v31; // eax
  Scaleform::Render::Color overwriteColor; // [esp+3Ch] [ebp-6Ch] BYREF
  int v33; // [esp+40h] [ebp-68h] BYREF
  Scaleform::Render::Point<long> pt; // [esp+44h] [ebp-64h] BYREF
  Scaleform::Array<Scaleform::Render::Point<long>,2,Scaleform::ArrayDefaultPolicy> toProcess; // [esp+4Ch] [ebp-5Ch] BYREF
  Scaleform::Render::Rect<long> imageRect; // [esp+58h] [ebp-50h]
  Scaleform::Render::Rect<long> intersection; // [esp+68h] [ebp-40h]
  Scaleform::Render::ImageSwizzlerContext srcSwiz; // [esp+78h] [ebp-30h] BYREF
  Scaleform::Render::ImageSwizzlerContext dstSwiz; // [esp+90h] [ebp-18h] BYREF
  Scaleform::Render::DICommandContext *contexta; // [esp+ACh] [ebp+4h]
  unsigned int fillColor; // [esp+B0h] [ebp+8h]

  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  x = this->Pt.x;
  imageRect.x2 = Width;
  imageRect.y2 = Height;
  if ( x <= Width && x >= 0 )
  {
    y = this->Pt.y;
    if ( y <= Height && y >= 0 )
    {
      fillColor = this->FillColor.Raw;
      if ( !this->pImage.pObject->Transparent )
        fillColor |= 0xFF000000;
      v11 = context->pHAL->GetTextureManager(context->pHAL);
      dstSwiz.Swizzler = v11->GetImageSwizzler(v11);
      dstSwiz.pCurrentScanline = 0;
      dstSwiz.pImage = dest;
      memset(&dstSwiz.CachedBlockY, 0, 12);
      dstSwiz.Swizzler->Initialize(dstSwiz.Swizzler, &dstSwiz);
      v12 = context->pHAL->GetTextureManager(context->pHAL);
      srcSwiz.Swizzler = v12->GetImageSwizzler(v12);
      srcSwiz.pCurrentScanline = 0;
      srcSwiz.pImage = dest;
      memset(&srcSwiz.CachedBlockY, 0, 12);
      srcSwiz.Swizzler->Initialize(srcSwiz.Swizzler, &srcSwiz);
      srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, this->Pt.y);
      srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, &overwriteColor, &srcSwiz, this->Pt.x);
      v13 = this->Pt.x;
      pt.y = this->Pt.y;
      memset(&toProcess, 0, sizeof(toProcess));
      pt.x = v13;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        &toProcess,
        &pt);
      Size = toProcess.Data.Size;
      while ( Size )
      {
        v15 = toProcess.Data.Data[Size - 1].x;
        v16 = toProcess.Data.Data[Size - 1].y;
        v17 = Size - 1;
        pt.x = v15;
        pt.y = v16;
        if ( Size )
        {
          if ( v17 < toProcess.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
              &toProcess,
              Size - 1);
        }
        else if ( v17 >= toProcess.Data.Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
            &toProcess,
            v17 + (v17 >> 2));
        }
        x2 = 0;
        --Size;
        v19 = 0;
        y2 = 0;
        toProcess.Data.Size = v17;
        intersection.x1 = 0;
        contexta = (Scaleform::Render::DICommandContext *)(v15 + 1);
        if ( imageRect.y2 >= v16 && v16 + 1 >= 0 && (int)contexta >= 0 )
        {
          if ( imageRect.x2 < pt.x )
          {
            v16 = pt.y;
          }
          else
          {
            x2 = v15 + 1;
            LOBYTE(y2) = pt.x < 0;
            intersection.x1 = pt.x & (y2 - 1);
            if ( imageRect.x2 <= (int)contexta )
              x2 = imageRect.x2;
            v16 = pt.y;
            y2 = pt.y + 1;
            v19 = pt.y < 0 ? 0 : pt.y;
            if ( imageRect.y2 <= pt.y + 1 )
              y2 = imageRect.y2;
          }
        }
        if ( (y2 - v19) * (x2 - intersection.x1) > 0 )
        {
          srcSwiz.Swizzler->CacheScanline(srcSwiz.Swizzler, &srcSwiz, v16);
          Raw = overwriteColor.Raw;
          srcSwiz.Swizzler->GetPixelInScanline(srcSwiz.Swizzler, (Scaleform::Render::Color *)&v33, &srcSwiz, pt.x);
          if ( v33 == Raw )
          {
            dstSwiz.Swizzler->CacheScanline(dstSwiz.Swizzler, &dstSwiz, v16);
            v22 = pt.x;
            dstSwiz.Swizzler->SetPixelInScanline(dstSwiz.Swizzler, &dstSwiz, pt.x, fillColor);
            v23 = v17 + 1;
            v24 = v22 - 1;
            if ( v17 + 1 >= v17 )
            {
              if ( v23 >= toProcess.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                  &toProcess,
                  v23 + (v23 >> 2));
            }
            else if ( v23 < toProcess.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                &toProcess,
                v17 + 1);
            }
            v25 = &toProcess.Data.Data[v23 - 1];
            toProcess.Data.Size = v17 + 1;
            if ( &toProcess.Data.Data[v23] != (Scaleform::Render::Point<long> *)8 )
            {
              v25->x = v24;
              v25->y = v16;
            }
            v26 = v17 + 2;
            if ( v23 + 1 >= v23 )
            {
              if ( v26 >= toProcess.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                  &toProcess,
                  v26 + (v26 >> 2));
            }
            else if ( v26 < toProcess.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                &toProcess,
                v23 + 1);
            }
            v27 = &toProcess.Data.Data[v26 - 1];
            toProcess.Data.Size = v23 + 1;
            if ( &toProcess.Data.Data[v26] != (Scaleform::Render::Point<long> *)8 )
            {
              v27->x = pt.x;
              v27->y = v16 - 1;
            }
            v28 = v23 + 2;
            if ( v26 + 1 >= v26 )
            {
              if ( v28 >= toProcess.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                  &toProcess,
                  v28 + (v28 >> 2));
            }
            else if ( v28 < toProcess.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                &toProcess,
                v26 + 1);
            }
            v29 = &toProcess.Data.Data[v28 - 1];
            toProcess.Data.Size = v26 + 1;
            if ( &toProcess.Data.Data[v28] != (Scaleform::Render::Point<long> *)8 )
            {
              v29->x = pt.x;
              v29->y = v16 + 1;
            }
            v30 = v26 + 2;
            if ( v28 + 1 >= v28 )
            {
              if ( v30 >= toProcess.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                  &toProcess,
                  v30 + (v30 >> 2));
            }
            else if ( v30 < toProcess.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&toProcess,
                &toProcess,
                v28 + 1);
            }
            v31 = &toProcess.Data.Data[v30 - 1];
            Size = v28 + 1;
            toProcess.Data.Size = v30;
            if ( &toProcess.Data.Data[v30] != (Scaleform::Render::Point<long> *)8 )
            {
              v31->x = (int)contexta;
              v31->y = v16;
            }
          }
        }
      }
      if ( toProcess.Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, toProcess.Data.Data);
    }
  }
}
