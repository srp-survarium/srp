void __thiscall Scaleform::MemItem::Read(Scaleform::MemItem *this, Scaleform::File *str, unsigned int version)
{
  Scaleform::File *v3; // edi
  int (__thiscall *Read)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::MemItem *v5; // ebp
  int i; // esi
  int (__thiscall *v7)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v8)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v9)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v10)(Scaleform::File *, unsigned __int8 *, int); // edx
  int (__thiscall *v11)(Scaleform::File *, unsigned __int8 *, int); // edx
  bool v12; // cc
  int (__thiscall *v13)(Scaleform::File *, unsigned __int8 *, int); // edx
  Scaleform::MemItemExtra *v14; // eax
  Scaleform::MemItemExtra *v15; // esi
  Scaleform::RefCountVImpl *v16; // ecx
  unsigned int v17; // esi
  Scaleform::MemItemExtra *v18; // eax
  Scaleform::MemItemExtra *v19; // esi
  Scaleform::RefCountVImpl *pObject; // ecx
  int (__thiscall *v21)(Scaleform::File *, unsigned __int8 *, int); // edx
  unsigned int Size; // edx
  unsigned int v23; // eax
  Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *p_Children; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *Data; // esi
  Scaleform::RefCountVImpl **v26; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v27; // ecx
  unsigned int v28; // esi
  Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits> *v29; // ecx
  Scaleform::StringLH *v30; // eax
  Scaleform::StringLH *v31; // esi
  Scaleform::Ptr<Scaleform::MemItem> *v32; // esi
  int v33; // ebp
  Scaleform::RefCountVImpl *v34; // ecx
  int *v35; // esi
  unsigned int v36; // ecx
  unsigned int v37; // [esp+40h] [ebp-40h]
  char v38; // [esp+55h] [ebp-2Bh] BYREF
  char v39; // [esp+56h] [ebp-2Ah] BYREF
  char v40; // [esp+57h] [ebp-29h] BYREF
  unsigned int v41; // [esp+58h] [ebp-28h] BYREF
  int v42; // [esp+5Ch] [ebp-24h]
  Scaleform::MemItem *v43; // [esp+60h] [ebp-20h]
  int v44; // [esp+64h] [ebp-1Ch] BYREF
  unsigned int v45; // [esp+68h] [ebp-18h] BYREF
  unsigned int v46; // [esp+6Ch] [ebp-14h] BYREF
  unsigned int v47; // [esp+70h] [ebp-10h] BYREF
  int v48; // [esp+74h] [ebp-Ch] BYREF
  int v49; // [esp+78h] [ebp-8h] BYREF
  int v50; // [esp+7Ch] [ebp-4h] BYREF

  v3 = str;
  Read = str->Read;
  v5 = this;
  v43 = this;
  v44 = 0;
  Read(str, (unsigned __int8 *)&v44, 4);
  for ( i = v44; i; --i )
  {
    v7 = v3->Read;
    LOBYTE(str) = 0;
    v7(v3, (unsigned __int8 *)&str, 1);
    Scaleform::String::AppendChar(&v5->Name, (char)str);
  }
  v8 = v3->Read;
  v38 = 0;
  v8(v3, (unsigned __int8 *)&v38, 1);
  v5->HasValue = v38 != 0;
  v9 = v3->Read;
  v39 = 0;
  v9(v3, (unsigned __int8 *)&v39, 1);
  v5->StartExpanded = v39 != 0;
  v10 = v3->Read;
  v45 = 0;
  v10(v3, (unsigned __int8 *)&v45, 4);
  v5->Value = v45;
  v11 = v3->Read;
  v46 = 0;
  v11(v3, (unsigned __int8 *)&v46, 4);
  v12 = version <= 0xB;
  v5->ID = v46;
  v13 = v3->Read;
  if ( v12 )
  {
    v47 = 0;
    v13(v3, (unsigned __int8 *)&v47, 4);
    v17 = v47;
    if ( v47 )
    {
      v50 = 2;
      v18 = (Scaleform::MemItemExtra *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         v5,
                                         32,
                                         &v50);
      if ( v18 )
      {
        v18->__vftable = (Scaleform::MemItemExtra_vtbl *)&Scaleform::RefCountImplCore::`vftable';
        v18->ImageId = v17;
        v18->RefCount = 1;
        v18->__vftable = (Scaleform::MemItemExtra_vtbl *)&Scaleform::Render::Matrix4x4Ref<float>::`vftable';
        v18->AtlasId = 0;
        v18->AtlasRectTop = 0;
        v18->AtlasRectBottom = 0;
        v18->AtlasRectLeft = 0;
        v18->AtlasRectRight = 0;
        v19 = v18;
      }
      else
      {
        v19 = 0;
      }
      pObject = (Scaleform::RefCountVImpl *)v5->ImageExtraData.pObject;
      if ( pObject )
        Scaleform::RefCountImpl::Release(pObject);
      v5->ImageExtraData.pObject = v19;
    }
  }
  else
  {
    v40 = 0;
    v13(v3, (unsigned __int8 *)&v40, 1);
    if ( v40 )
    {
      v49 = 2;
      v14 = (Scaleform::MemItemExtra *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                         Scaleform::Memory::pGlobalHeap,
                                         v5,
                                         32,
                                         &v49);
      if ( v14 )
      {
        v14->__vftable = (Scaleform::MemItemExtra_vtbl *)&Scaleform::RefCountImplCore::`vftable';
        v14->RefCount = 1;
        v14->__vftable = (Scaleform::MemItemExtra_vtbl *)&Scaleform::Render::Matrix4x4Ref<float>::`vftable';
        v14->ImageId = 0;
        v14->AtlasId = 0;
        v14->AtlasRectTop = 0;
        v14->AtlasRectBottom = 0;
        v14->AtlasRectLeft = 0;
        v14->AtlasRectRight = 0;
        v15 = v14;
      }
      else
      {
        v15 = 0;
      }
      v16 = (Scaleform::RefCountVImpl *)v5->ImageExtraData.pObject;
      if ( v16 )
        Scaleform::RefCountImpl::Release(v16);
      v37 = version;
      v5->ImageExtraData.pObject = v15;
      Scaleform::MemItemExtra::Read(v15, v3, v37);
    }
  }
  v21 = v3->Read;
  v41 = 0;
  v21(v3, (unsigned __int8 *)&v41, 4);
  Size = v5->Children.Data.Size;
  v23 = v41;
  p_Children = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Children;
  v42 = Size;
  if ( v41 >= Size )
  {
    if ( v41 >= v5->Children.Data.Policy.Capacity )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Children,
        p_Children,
        v41 + (v41 >> 2));
      goto LABEL_27;
    }
  }
  else
  {
    Data = p_Children->Data;
    v48 = Size - v41;
    v26 = (Scaleform::RefCountVImpl **)&Data[Size - 1];
    if ( Size != v41 )
    {
      do
      {
        if ( *v26 )
        {
          Scaleform::RefCountImpl::Release(*v26);
          Size = v42;
          v23 = v41;
        }
        --v26;
        --v48;
      }
      while ( v48 );
    }
    p_Children = (Scaleform::ArrayDataBase<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,Scaleform::AllocatorLH<Scaleform::GFx::AS3::SPtr<Scaleform::GFx::AS3::ClassTraits::Traits>,2>,Scaleform::ArrayDefaultPolicy> *)&v5->Children;
    if ( v23 < v5->Children.Data.Policy.Capacity >> 1 )
    {
      Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
        p_Children,
        p_Children,
        v23);
LABEL_27:
      v23 = v41;
      Size = v42;
    }
  }
  p_Children->Size = v23;
  if ( v23 > Size )
  {
    v27 = p_Children->Data;
    v28 = v23 - Size;
    v29 = &v27[Size];
    if ( v23 != Size )
    {
      do
      {
        if ( v29 )
          v29->pObject = 0;
        ++v29;
        --v28;
      }
      while ( v28 );
    }
  }
  v42 = 0;
  if ( v23 )
  {
    while ( 1 )
    {
      v48 = 2;
      v30 = (Scaleform::StringLH *)Scaleform::Memory::pGlobalHeap->AllocAutoHeap(
                                     Scaleform::Memory::pGlobalHeap,
                                     v5,
                                     40,
                                     &v48);
      v31 = v30;
      if ( v30 )
      {
        v30->HeapTypeBits = (unsigned int)&Scaleform::RefCountImplCore::`vftable';
        v30[1].HeapTypeBits = 1;
        v30->HeapTypeBits = (unsigned int)&Scaleform::MemItem::`vftable';
        Scaleform::StringLH::StringLH(v30 + 2);
        v31[3].HeapTypeBits = 0;
        LOBYTE(v31[4].pData) = 0;
        BYTE1(v31[4].pData) = 0;
        v31[5].HeapTypeBits = 0;
        v31[6].HeapTypeBits = 0;
        v31[7].HeapTypeBits = 0;
        v31[8].HeapTypeBits = 0;
        v31[9].HeapTypeBits = 0;
        v48 = (int)v31;
      }
      else
      {
        v48 = 0;
      }
      v32 = v43->Children.Data.Data;
      v33 = v42;
      v34 = (Scaleform::RefCountVImpl *)v32[v42].pObject;
      v35 = (int *)&v32[v42];
      if ( v34 )
        Scaleform::RefCountImpl::Release(v34);
      v36 = version;
      *v35 = v48;
      Scaleform::MemItem::Read(v43->Children.Data.Data[v33].pObject, v3, v36);
      if ( ++v42 >= v41 )
        break;
      v5 = v43;
    }
  }
}
