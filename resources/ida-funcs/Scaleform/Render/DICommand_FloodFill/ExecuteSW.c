void __thiscall Scaleform::Render::DICommand_FloodFill::ExecuteSW(
        Scaleform::Render::DICommand_FloodFill *this,
        Scaleform::Render::DICommandContext *context,
        Scaleform::Render::ImageData *dest,
        Scaleform::Render::ImageData **__formal)
{
  Scaleform::Render::ImagePlane *pPlanes; // eax
  signed int Width; // edx
  signed int Height; // eax
  int x; // ecx
  int y; // ecx
  Scaleform::Render::TextureManager *v11; // eax
  Scaleform::Render::TextureManager *v12; // eax
  int v13; // eax
  unsigned int Size; // esi
  int v15; // ebx
  int v16; // ebp
  unsigned int v17; // edi
  int v18; // eax
  int v19; // edx
  int v20; // ecx
  int v21; // ebx
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
  int v32; // [esp+3Ch] [ebp-6Ch] BYREF
  int v33; // [esp+40h] [ebp-68h] BYREF
  Scaleform::Render::Point<long> val; // [esp+44h] [ebp-64h] BYREF
  Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy> > pheapAddr; // [esp+4Ch] [ebp-5Ch] BYREF
  int v36; // [esp+60h] [ebp-48h]
  int v37; // [esp+64h] [ebp-44h]
  int v38; // [esp+68h] [ebp-40h]
  _DWORD v39[6]; // [esp+78h] [ebp-30h] BYREF
  _DWORD v40[6]; // [esp+90h] [ebp-18h] BYREF
  int v41; // [esp+ACh] [ebp+4h]
  unsigned int Raw; // [esp+B0h] [ebp+8h]

  pPlanes = dest->pPlanes;
  Width = pPlanes->Width;
  Height = pPlanes->Height;
  x = this->Pt.x;
  v36 = Width;
  v37 = Height;
  if ( x <= Width && x >= 0 )
  {
    y = this->Pt.y;
    if ( y <= Height && y >= 0 )
    {
      Raw = this->FillColor.Raw;
      if ( !this->pImage.pObject->Transparent )
        Raw |= 0xFF000000;
      v11 = context->pHAL->GetTextureManager(context->pHAL);
      v40[0] = v11->GetImageSwizzler(v11);
      v40[1] = 0;
      v40[2] = dest;
      memset(&v40[3], 0, 12);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v40[0] + 4))(v40[0], v40);
      v12 = context->pHAL->GetTextureManager(context->pHAL);
      v39[0] = v12->GetImageSwizzler(v12);
      v39[1] = 0;
      v39[2] = dest;
      memset(&v39[3], 0, 12);
      (*(void (__thiscall **)(_DWORD, _DWORD *))(*(_DWORD *)v39[0] + 4))(v39[0], v39);
      (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v39[0] + 8))(v39[0], v39, this->Pt.y);
      (*(void (__thiscall **)(_DWORD, int *, _DWORD *, int))(*(_DWORD *)v39[0] + 20))(v39[0], &v32, v39, this->Pt.x);
      v13 = this->Pt.x;
      val.y = this->Pt.y;
      memset(&pheapAddr, 0, sizeof(pheapAddr));
      val.x = v13;
      Scaleform::ArrayBase<Scaleform::ArrayData<Scaleform::Render::Point<long>,Scaleform::AllocatorGH<Scaleform::Render::Point<long>,2>,Scaleform::ArrayDefaultPolicy>>::PushBack(
        &pheapAddr,
        &val);
      Size = pheapAddr.Data.Size;
      while ( Size )
      {
        v15 = pheapAddr.Data.Data[Size - 1].x;
        v16 = pheapAddr.Data.Data[Size - 1].y;
        v17 = Size - 1;
        val.x = v15;
        val.y = v16;
        if ( Size )
        {
          if ( v17 < pheapAddr.Data.Policy.Capacity >> 1 )
            Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
              (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
              &pheapAddr,
              Size - 1);
        }
        else if ( v17 >= pheapAddr.Data.Policy.Capacity )
        {
          Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
            (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
            &pheapAddr,
            v17 + (v17 >> 2));
        }
        v18 = 0;
        --Size;
        v19 = 0;
        v20 = 0;
        pheapAddr.Data.Size = v17;
        v38 = 0;
        v41 = v15 + 1;
        if ( v37 >= v16 && v16 + 1 >= 0 && v41 >= 0 )
        {
          if ( v36 < val.x )
          {
            v16 = val.y;
          }
          else
          {
            v18 = v15 + 1;
            LOBYTE(v20) = val.x < 0;
            v38 = val.x & (v20 - 1);
            if ( v36 <= v41 )
              v18 = v36;
            v16 = val.y;
            v20 = val.y + 1;
            v19 = val.y < 0 ? 0 : val.y;
            if ( v37 <= val.y + 1 )
              v20 = v37;
          }
        }
        if ( (v20 - v19) * (v18 - v38) > 0 )
        {
          (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v39[0] + 8))(v39[0], v39, v16);
          v21 = v32;
          (*(void (__thiscall **)(_DWORD, int *, _DWORD *, int))(*(_DWORD *)v39[0] + 20))(v39[0], &v33, v39, val.x);
          if ( v33 == v21 )
          {
            (*(void (__thiscall **)(_DWORD, _DWORD *, int))(*(_DWORD *)v40[0] + 8))(v40[0], v40, v16);
            v22 = val.x;
            (*(void (__thiscall **)(_DWORD, _DWORD *, int, unsigned int))(*(_DWORD *)v40[0] + 12))(
              v40[0],
              v40,
              val.x,
              Raw);
            v23 = v17 + 1;
            v24 = v22 - 1;
            if ( v17 + 1 >= v17 )
            {
              if ( v23 >= pheapAddr.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                  &pheapAddr,
                  v23 + (v23 >> 2));
            }
            else if ( v23 < pheapAddr.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                &pheapAddr,
                v17 + 1);
            }
            v25 = &pheapAddr.Data.Data[v23 - 1];
            pheapAddr.Data.Size = v17 + 1;
            if ( &pheapAddr.Data.Data[v23] != (Scaleform::Render::Point<long> *)8 )
            {
              v25->x = v24;
              v25->y = v16;
            }
            v26 = v17 + 2;
            if ( v23 + 1 >= v23 )
            {
              if ( v26 >= pheapAddr.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                  &pheapAddr,
                  v26 + (v26 >> 2));
            }
            else if ( v26 < pheapAddr.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                &pheapAddr,
                v23 + 1);
            }
            v27 = &pheapAddr.Data.Data[v26 - 1];
            pheapAddr.Data.Size = v23 + 1;
            if ( &pheapAddr.Data.Data[v26] != (Scaleform::Render::Point<long> *)8 )
            {
              v27->x = val.x;
              v27->y = v16 - 1;
            }
            v28 = v23 + 2;
            if ( v26 + 1 >= v26 )
            {
              if ( v28 >= pheapAddr.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                  &pheapAddr,
                  v28 + (v28 >> 2));
            }
            else if ( v28 < pheapAddr.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                &pheapAddr,
                v26 + 1);
            }
            v29 = &pheapAddr.Data.Data[v28 - 1];
            pheapAddr.Data.Size = v26 + 1;
            if ( &pheapAddr.Data.Data[v28] != (Scaleform::Render::Point<long> *)8 )
            {
              v29->x = val.x;
              v29->y = v16 + 1;
            }
            v30 = v26 + 2;
            if ( v28 + 1 >= v28 )
            {
              if ( v30 >= pheapAddr.Data.Policy.Capacity )
                Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                  (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                  &pheapAddr,
                  v30 + (v30 >> 2));
            }
            else if ( v30 < pheapAddr.Data.Policy.Capacity >> 1 )
            {
              Scaleform::ArrayDataBase<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,Scaleform::AllocatorGH<Scaleform::GFx::XML::DOMBuilder::PrefixOwnership,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
                (Scaleform::ArrayDataBase<tagKERNINGPAIR,Scaleform::AllocatorGH<tagKERNINGPAIR,2>,Scaleform::ArrayDefaultPolicy> *)&pheapAddr,
                &pheapAddr,
                v28 + 1);
            }
            v31 = &pheapAddr.Data.Data[v30 - 1];
            Size = v28 + 1;
            pheapAddr.Data.Size = v30;
            if ( &pheapAddr.Data.Data[v30] != (Scaleform::Render::Point<long> *)8 )
            {
              v31->x = v41;
              v31->y = v16;
            }
          }
        }
      }
      if ( pheapAddr.Data.Data )
        Scaleform::Memory::pGlobalHeap->Free(Scaleform::Memory::pGlobalHeap, pheapAddr.Data.Data);
    }
  }
}
