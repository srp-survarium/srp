char __thiscall Scaleform::Render::TextPrimitiveBundle::addAndPinBatchLayers(
        Scaleform::Render::TextPrimitiveBundle *this,
        Scaleform::Render::TreeCacheText *textCache,
        Scaleform::Render::TextMeshProvider *tm)
{
  Scaleform::Render::TextMeshProvider *v3; // ebp
  Scaleform::Render::TextPrimitiveBundle *v4; // esi
  unsigned int v5; // ebx
  unsigned int Size; // edx
  Scaleform::Render::TextMeshLayer *v7; // edi
  Scaleform::Render::TextLayerType Type; // ecx
  int v9; // eax
  char *v10; // esi
  Scaleform::Render::TextLayerType v11; // eax
  Scaleform::Render::PrimitiveFill *pObject; // ebp
  Scaleform::Render::TextLayerType v13; // ebx
  Scaleform::Render::HAL *HAL; // eax
  Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive> *inserted; // ebp
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *v16; // edi
  unsigned int v17; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // eax
  Scaleform::Render::BundleEntry **v19; // esi
  Scaleform::Render::MaskPrimitive *v20; // esi
  Scaleform::Render::HAL *v21; // eax
  Scaleform::RefCountVImpl *v23; // ecx
  Scaleform::Render::MatrixPoolImpl::EntryHandle *pHandle; // eax
  const Scaleform::Render::MatrixPoolImpl::HMatrix *updated; // eax
  unsigned int index; // [esp+1Ch] [ebp-14h]
  unsigned int indexa; // [esp+1Ch] [ebp-14h]
  int v29; // [esp+20h] [ebp-10h]
  int v30; // [esp+24h] [ebp-Ch]
  int v31; // [esp+28h] [ebp-8h] BYREF
  Scaleform::Render::MatrixPoolImpl::HMatrix result; // [esp+2Ch] [ebp-4h] BYREF

  v3 = tm;
  v4 = this;
  v5 = 0;
  result.pHandle = (Scaleform::Render::MatrixPoolImpl::EntryHandle *)tm->GetLayerCount(tm);
  v30 = 0;
  index = 0;
  if ( result.pHandle )
  {
    v29 = 0;
    while ( 1 )
    {
      Size = v4->Layers.Size;
      v7 = &v3->Layers.Data.Data[v29];
      if ( v5 < Size )
      {
        Type = v7->Type;
        indexa = v4->Layers.Size;
        while ( 1 )
        {
          v9 = indexa <= 2 ? (int)&v4->Layers.4 : (int)v4->Layers.AD.pData;
          v10 = *(char **)(v9 + 4 * v5);
          v11 = *((_DWORD *)v10 + 12);
          if ( v11 >= Type )
          {
            if ( v11 == Type && (Scaleform::Render::PrimitiveFill *)*((_DWORD *)v10 + 4) == v7->pFill.pObject )
            {
              index = v5;
              goto LABEL_22;
            }
            if ( v11 > Type || (Scaleform::Render::PrimitiveFill *)*((_DWORD *)v10 + 4) > v7->pFill.pObject )
              break;
          }
          v4 = this;
          if ( ++v5 >= Size )
            goto LABEL_17;
        }
        v4 = this;
LABEL_17:
        index = v5;
      }
      v31 = 68;
      v10 = (char *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(Scaleform::Memory::pGlobalHeap, v4, 64, &v31);
      if ( !v10 )
        return 0;
      pObject = v7->pFill.pObject;
      v13 = v7->Type;
      HAL = Scaleform::Render::TreeCacheNode::GetHAL(textCache);
      Scaleform::Render::Primitive::Primitive((Scaleform::Render::Primitive *)v10, HAL, pObject);
      *((_DWORD *)v10 + 12) = v13;
      *(_DWORD *)v10 = &Scaleform::Render::TextLayerPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::Primitive,68>'};
      *((_DWORD *)v10 + 2) = &Scaleform::Render::TextLayerPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
      *((_DWORD *)v10 + 13) = 0;
      *((_DWORD *)v10 + 14) = 0;
      *((_DWORD *)v10 + 15) = 0;
      Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v10);
      inserted = Scaleform::Render::ArrayReserveLH_Mov<Scaleform::Ptr<Scaleform::Render::TextLayerPrimitive>,2>::insertSpot(
                   &this->Layers,
                   index);
      if ( inserted )
      {
        Scaleform::RefCountImpl::AddRef((Scaleform::GFx::Resource *)v10);
        inserted->pObject = (Scaleform::Render::TextLayerPrimitive *)v10;
      }
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
      Scaleform::RefCountImpl::Release((Scaleform::RefCountVImpl *)v10);
      v5 = index;
LABEL_22:
      v3 = tm;
      if ( Scaleform::Render::Primitive::Insert(
             (Scaleform::Render::Primitive *)v10,
             *((void (__thiscall **)(struct Scaleform::Render::Primitive *))v10 + 9),
             (Scaleform::GFx::Resource *)v7->pMesh.pObject,
             &v7->M) )
      {
        v16 = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)(v10 + 52);
        v17 = *((_DWORD *)v10 + 14) + 1;
        if ( v17 >= v16->Size )
        {
          if ( v17 >= v16->Policy.Capacity )
            Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              v16,
              v16,
              v17 + (v17 >> 2));
        }
        else if ( v17 < v16->Policy.Capacity >> 1 )
        {
          Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            v16,
            v16,
            v17);
        }
        Data = v16->Data;
        v16->Size = v17;
        v19 = (Scaleform::Render::BundleEntry **)&Data[v17 - 1];
        if ( v19 )
          *v19 = &textCache->SorterShapeNode;
      }
      ++v3->PinCount;
      ++v29;
      v4 = this;
      if ( ++v30 >= (unsigned int)result.pHandle )
        goto LABEL_31;
    }
  }
  else
  {
LABEL_31:
    if ( (v3->Flags & 0x100) != 0 )
    {
      if ( v4->pMaskPrimitive.pObject )
        goto LABEL_40;
      tm = (Scaleform::Render::TextMeshProvider *)68;
      v20 = (Scaleform::Render::MaskPrimitive *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                                  Scaleform::Memory::pGlobalHeap,
                                                  v4,
                                                  32,
                                                  &tm);
      if ( v20 )
      {
        v21 = Scaleform::Render::TreeCacheNode::GetHAL(textCache);
        v20->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::MaskPrimitive_vtbl *)&Scaleform::RefCountImplCore::`vftable';
        v20->RefCount = 1;
        v20->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::RenderQueueItem::Interface::`vftable';
        v20->Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,68>::Scaleform::RefCountBaseStatImpl<Scaleform::RefCountImpl,68>::Scaleform::RefCountImpl::Scaleform::RefCountImplCore::__vftable = (Scaleform::Render::MaskPrimitive_vtbl *)&Scaleform::Render::MaskPrimitive::`vftable'{for `Scaleform::RefCountBase<Scaleform::Render::MaskPrimitive,68>'};
        v20->Scaleform::Render::RenderQueueItem::Interface::__vftable = (Scaleform::Render::RenderQueueItem::Interface_vtbl *)&Scaleform::Render::MaskPrimitive::`vftable'{for `Scaleform::Render::RenderQueueItem::Interface'};
        v20->pHAL = v21;
        v20->Type = Mask_Combinable;
        v20->MaskAreas.Data.Data = 0;
        v20->MaskAreas.Data.Size = 0;
        v20->MaskAreas.Data.Policy.Capacity = 0;
      }
      else
      {
        v20 = 0;
      }
      v23 = (Scaleform::RefCountVImpl *)this->pMaskPrimitive.pObject;
      if ( v23 )
        Scaleform::RefCountImpl::Release(v23);
      this->pMaskPrimitive.pObject = v20;
      v4 = this;
      if ( this->pMaskPrimitive.pObject )
      {
LABEL_40:
        pHandle = textCache->M.pHandle;
        if ( pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
          ++pHandle->pHeader->RefCount;
        updated = Scaleform::Render::TextMeshProvider::UpdateMaskClearBounds(
                    v3,
                    &result,
                    (Scaleform::Render::MatrixPoolImpl::HMatrix)pHandle);
        Scaleform::Render::MaskPrimitive::Insert(
          v4->pMaskPrimitive.pObject,
          v4->pMaskPrimitive.pObject->MaskAreas.Data.Size,
          updated);
        if ( result.pHandle != &Scaleform::Render::MatrixPoolImpl::HMatrix::NullHandle )
          Scaleform::Render::MatrixPoolImpl::DataHeader::Release(result.pHandle->pHeader);
      }
    }
    return 1;
  }
}
